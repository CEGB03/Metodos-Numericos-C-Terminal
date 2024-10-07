//
// Created by cegb03 on 06/10/24.
//

#include "sistemas_ecuaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Función para realizar la eliminación gaussiana
void metodoEliminacionGaussiana() {
    double m[FILAS][COLUMNAS];
    double a[FILAS][COLUMNAS];
    double b[FILAS];
    int filas = 0, columnas = 0;

    // Leer la matriz del archivo
    fileReader(m, &filas, &columnas);
    matrizA(a, m, filas, columnas);
    matrizB(b, m, filas, columnas);

    imprimirMatrices(a,b, filas, columnas);

    // Llamar a la función triangulación
    double* x = (double*)malloc(filas * sizeof(double));
    if (x == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }
    triangulacion(a, b, x, filas);
}

// Función para leer la matriz desde un archivo
void fileReader(double m[FILAS][COLUMNAS], int* filas, int* columnas) {
    FILE* fp;
    char c;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("No se puede abrir el archivo\n");
        exit(1);
    }

    int fila = 0;
    int columna;

    // Contar filas
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            fila++;
        }
    }

    fclose(fp);
    fp = fopen("data.txt", "r");

    int i, j;
    for (i = 0; i < fila; i++) {
        j = 0;
        do {
            fscanf(fp, "%lf", &(m[i][j]));
            j++;
        } while ((c = fgetc(fp)) != '\n');
    }
    columna = j;
    *columnas = columna;
    *filas = fila;

    fclose(fp); // Cerrar el archivo después de leer
}

// Función para triangular la matriz
void triangulacion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas) {
    for (int i = 0; i < (filas - 1); i++) {
        pivot(a, b, filas, i);
        for (int j = i + 1; j < filas; j++) {
            double factor = -a[j][i] / a[i][i];
            for (int k = 0; k < filas; ++k) {
                a[j][k] = a[i][k] * factor + a[j][k];
            }
            b[j] = b[i] * factor + b[j];
        }
    }

    double norma = determinante(a, b, x, filas);
    if (norma == 0.0) {
        printf("\n\nLa matriz es singular\n");
    } else {
        retrostutitucion(a, b, x, filas);
    }
}

// Función para realizar la retro sustitución
void retrostutitucion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas) {
    double value = b[filas - 1] / a[filas - 1][filas - 1];
    x[filas - 1] = value;

    for (int i = filas - 2; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < filas; ++j) {
            sum += a[i][j] * x[j];
        }
        value = (b[i] - sum) / a[i][i];
        x[i] = value;
    }

    printf("Conjunto solución: \n");
    for (int i = 0; i < filas; ++i) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}

// Función para realizar pivoteo
void pivot(double a[FILAS][COLUMNAS], double b[FILAS], int filas, int i) {
    if (fabs(a[i][i]) < 0.0001) {
        for (int j = i + 1; j < filas; j++) {
            if (fabs(a[j][i]) > fabs(a[i][i])) {
                for (int k = 0; k < filas; ++k) {
                    printf("Se realizó pivoteo\n");
                    double swap = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = swap;
                }
                double swap = b[i];
                b[i] = b[j];
                b[j] = swap;
            }
        }
    }
}

// Función para calcular el determinante
double determinante(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas) {
    double norma = 1;
    for (int i = 0; i < filas; i++) {
        norma *= a[i][i];
    }
    printf("\nLa norma es: %lf\n", norma);
    return norma;
}

// Función para manejar métodos iterativos
void metodoIterativos() {
    double m[FILAS][COLUMNAS];
    double a[FILAS][COLUMNAS];
    double b[FILAS];
    int filas = 0, columnas = 0;

    fileReader(m, &filas, &columnas);
    matrizA(a, m, filas, columnas);
    matrizB(b, m, filas, columnas);
    imprimirMatrices(a,b, filas, columnas);
    int scanner;
    printf("Seleccione:\n 1 --> Jacobi \n 2 --> Gauss-Seidel \n 3 --> Gauss-Seidel con Relajación\n");
    scanf("%d", &scanner);
    switch (scanner) {
        case 1:
            jacobi(a, b, filas);
            break;
        case 2:
            gaussSeidel(a, b, filas);
            break;
        case 3:
            relajacion(a, b, filas);
            break;
        default:
            printf("\nSe seleccionó mal la opción\n");
    }
}

// Función para llenar matriz A
void matrizA(double a[FILAS][COLUMNAS], double m[FILAS][COLUMNAS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas - 1; j++) {
            a[i][j] = m[i][j];
        }
    }
}

// Función para llenar matriz B
void matrizB(double b[FILAS], double m[FILAS][COLUMNAS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        b[i] = m[i][columnas - 1];
    }
}

void imprimirMatrices(double a[FILAS][COLUMNAS], double b[FILAS], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas - 1; j++) {
            printf(" %lf", a[i][j]);
        }
        printf(" | %lf\n", b[i]);
    }
}

// Método de Jacobi
void jacobi(double a[FILAS][COLUMNAS], double b[FILAS], int filas) {
    printf("\n\n***Ha seleccionado método de Jacobi***\n\n");

    bool check = diagonalmenteDominante(a, filas);
    if (!check) {
        exit(0);
    }

    double suma_jacobi = 0;
    double* xNuevo = (double*)malloc(filas * sizeof(double));
    double* xViejo = (double*)malloc(filas * sizeof(double));

    if (xNuevo == NULL || xViejo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        xViejo[i] = 0.0;
        xNuevo[i] = xViejo[i];
    }

    double error_jacobi;
    double tolerancia_jacobi;
    int iteraciones_jacobi = 0;
    printf("\nIngrese la tolerancia\n");
    scanf("%lf", &tolerancia_jacobi);

    do {
        iteraciones_jacobi++;
        for (int i = 0; i < filas; i++) {
            suma_jacobi = 0;
            for (int j = 0; j < filas; j++) {
                if (j != i) {
                    suma_jacobi += a[i][j] * xViejo[j];
                }
            }
            xNuevo[i] = (b[i] - suma_jacobi) / a[i][i];
        }

        // Manejo del error
        suma_jacobi = 0;
        for (int i = 0; i < filas; i++) {
            suma_jacobi += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
        }
        error_jacobi = pow(suma_jacobi,0.5);

        // Reasignación del vector viejo para la próxima pasada.
        for (int i = 0; i < filas; i++) {
            xViejo[i] = xNuevo[i];
        }
    } while (error_jacobi > tolerancia_jacobi && iteraciones_jacobi < 10000);

    printf("\nEl resultado es: \nxNuevo = [\t");
    for (int i = 0; i < filas; i++) {
        printf("%lf\t", xNuevo[i]);
    }

    printf("]\nLa cantidad de iteraciones fue: %d \nEl error es de %lf\n", iteraciones_jacobi, error_jacobi);
}

// Método de Gauss-Seidel
void gaussSeidel(double a[FILAS][COLUMNAS], double b[FILAS], int filas) {
    printf("\n\n***Ha seleccionado método de Gauss-Seidel***\n\n");

    bool check = diagonalmenteDominante(a, filas);
    if (!check) {
        exit(0);
    }

    double* xNuevo = (double*)malloc(filas * sizeof(double));
    double* xViejo = (double*)malloc(filas * sizeof(double));

    if (xNuevo == NULL || xViejo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        xViejo[i] = 0.0;
        xNuevo[i] = xViejo[i];
    }

    double error_gaussSeidel;
    double tolerancia_gaussSeidel;
    int iteraciones_gaussSeidel = 0;
    printf("\nIngrese la tolerancia\n");
    scanf("%lf", &tolerancia_gaussSeidel);

    do {
        iteraciones_gaussSeidel++;
        for (int i = 0; i < filas; i++) {
            double suma_gaussSeidel = 0;
            for (int j = 0; j < i; j++) {
                suma_gaussSeidel += a[i][j] * xNuevo[j];
            }
            for (int j = i + 1; j < filas; j++) {
                suma_gaussSeidel += a[i][j] * xViejo[j];
            }
            xNuevo[i] = (b[i] - suma_gaussSeidel) / a[i][i];
        }

        // Manejo del error
        double sumaError = 0;
        for (int i = 0; i < filas; i++) {
            sumaError += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
        }
        error_gaussSeidel = sqrt(sumaError);

        // Reasignación del vector viejo para la próxima pasada.
        for (int i = 0; i < filas; i++) {
            xViejo[i] = xNuevo[i];
        }
    } while (error_gaussSeidel > tolerancia_gaussSeidel && iteraciones_gaussSeidel < 10000);

    printf("\nEl resultado es: \nxNuevo = [\t");
    for (int i = 0; i < filas; i++) {
        printf("%lf\t", xNuevo[i]);
    }

    printf("]\nLa cantidad de iteraciones fue: %d \nEl error es de %lf\n", iteraciones_gaussSeidel, error_gaussSeidel);
}

// Método de Gauss-Seidel con relajación
void relajacion(double a[FILAS][COLUMNAS], double b[FILAS], int filas) {
    printf("\n\n***Ha seleccionado método de Gauss-Seidel con Relajación***\n\n");

    bool check = diagonalmenteDominante(a, filas);
    if (!check) {
        exit(0);
    }

    double* xNuevo = (double*)malloc(filas * sizeof(double));
    double* xViejo = (double*)malloc(filas * sizeof(double));

    if (xNuevo == NULL || xViejo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        xViejo[i] = 0.0;
        xNuevo[i] = xViejo[i];
    }

    double error_relajacion;
    double tolerancia_relajacion;
    double w;
    int iteraciones_relajacion = 0;
    printf("\nIngrese la tolerancia\n");
    scanf("%lf", &tolerancia_relajacion);
    printf("\nIngrese el factor de relajación\n");
    scanf("%lf", &w);

    do {
        iteraciones_relajacion++;
        for (int i = 0; i < filas; i++) {
            double suma_relajacion = 0;
            for (int j = 0; j < i; j++) {
                suma_relajacion += a[i][j] * xNuevo[j];
            }
            for (int j = i + 1; j < filas; j++) {
                suma_relajacion += a[i][j] * xViejo[j];
            }
            xNuevo[i] = (1 - w) * xViejo[i] + (w * (b[i] - suma_relajacion) / a[i][i]);
        }

        // Manejo del error
        double sumaError = 0;
        for (int i = 0; i < filas; i++) {
            sumaError += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
        }
        error_relajacion = sqrt(sumaError);

        // Reasignación del vector viejo para la próxima pasada.
        for (int i = 0; i < filas; i++) {
            xViejo[i] = xNuevo[i];
        }
    } while (error_relajacion > tolerancia_relajacion && iteraciones_relajacion < 10000);

    printf("\nEl resultado es: \nxNuevo = [\t");
    for (int i = 0; i < filas; i++) {
        printf("%lf\t", xNuevo[i]);
    }

    printf("]\nLa cantidad de iteraciones fue: %d \nEl error es de %lf\n", iteraciones_relajacion, error_relajacion);
}

// Función para verificar si la matriz es diagonalmente dominante
bool diagonalmenteDominante(double a[FILAS][COLUMNAS], int filas) {
    for (int i = 0; i < filas; i++) {
        double suma_det = 0;
        for (int j = 0; j < filas; j++) {
            if (i != j) {
                suma_det += fabs(a[i][j]);
            }
        }
        if (fabs(a[i][i]) < suma_det) {
            printf("La matriz no es diagonalmente dominante\n");
            return false;
        }
    }
    return true;
}
