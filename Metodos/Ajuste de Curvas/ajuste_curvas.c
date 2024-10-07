#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ajuste_curvas.h"

#define MAXCOLUMNAS 2
#define FILAS 20

// Interpolaciones
// Funcion a interpolar
double func (double x){
    return x + 2/x;
}
void metodoInterpolacion() {
    int filas = 8;
    double m[filas][2];
    m[0][0] = -1; m[0][1] = 10;
    m[1][0] = 0; m[1][1] = 9;
    m[2][0] = 1; m[2][1] = 7;
    m[3][0] = 2; m[3][1] = 5;
    m[4][0] = 3; m[4][1] = 4;
    m[5][0] = 4; m[5][1] = 3;
    m[6][0] = 5; m[6][1] = 0;
    m[7][0] = 6; m[7][1] = -1;
    int seleccion;
    printf("\ncantidad de filas %d\n",filas);
    printf("\nPuntos guardados: ");
    printf("(X ; Y)\n\n");
    for(int i = 0; i < filas ; i++){
        printf("(%lf ; %lf)",m[i][0],m[i][1]);
        printf("\n");
    }
    printf("\nIngrese:\n 1 --> Lagrange\n 2 --> Polinomica\n");
    scanf("%d",&seleccion);
    switch (seleccion){
        case 1:
            interpolacionLagrange(m, filas);
        break;
        case 2:
            interpolacionPolinomica(m, filas);
        break;
        default:
            printf("\nSe selecciono mal la opcion");
        break;
    }
}
void interpolacionLagrange (double m[FILAS][], int fila){
    double x;//Coeficiente a interpolar
    double e;
    printf("Recuerde haber definido la funcion previamente\n");
    printf("Ingrese el valor a interpolar\n");
    scanf("%lf", &x);

    double sum = 0;
    for (int i = 0; i < fila; i++) {
        double producto = 1;
        for (int j = 0; j < fila; j++) {
            if (j != i) {
                producto *= ((x - m[i][0]) / (m[j][0] - m[i][0]));
            }
        }
        sum += m[i][1] * producto;
    }
    e = fabs(func(x) - sum);
    printf("El valor interpolado para %lf es: %lf, con un error de %lf", x, sum, e);
}
void interpolacionPolinomica (double m[FILAS][2], int fila){
    double a[FILAS][FILAS];
    double b[FILAS];

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < fila +1 ; j++) {
            a[i][j] = pow(m[i][0], j);
        }
        b[i] = m[i][1];
    }
    printf("\nMatriz a\n");
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < fila; j++) {
            printf("%lf",a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    printf("\nMatriz b\n");
    for (int i = 0; i < fila; i++) {
        printf("%lf",b[i]);
        printf("\t");
    }

    double* x = (double*)malloc(fila * sizeof(double));
    triangulacionInterpolacion(a, b, x, fila);

}
void triangulacionInterpolacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas){
    for (int i = 0 ; i < (filas - 1) ; i++){
        pivotInterpolacion(a, b, filas , i);
        for (int j = i + 1; j < filas; j++) {
            double factor = -a[j][i] / a[i][i];
            for (int k = 0; k < filas; ++k) {
                a[j][k] = a[i][k] * factor + a[j][k];
            }
            b[j] = b[i] * factor + b[j];
        }
    }

    double norma = determinanteInterpolacion(a,b,x,filas);
    if(norma == 0.0){
        printf("\n\nmatriz singular");
    }else{
        retrostutitucionInterpolacion(a, b, x, filas);
    }
}
void retrostutitucionInterpolacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas){
    double value = 0;
    value = b[filas - 1] / a[filas - 1][filas - 1];
    x[filas - 1] = value;
    for (int i = filas - 2; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < filas; ++j) {
            sum = sum + a[i][j] * x[j];
        }
        value = (b[i] - sum) / a[i][i];
        x[i] = value;
    }
    printf("\n\n\n\nConjunto soluci�n de las asubn: \n");
    for (int i = 0; i < filas; ++i) {
        printf("a%d = %lf\n", i , x[i]);
    }

    printf("\n\n");
    printf("Polinomio Interpolador: \n");
    int pow = 0;
    for (int i = 0; i <= filas - 1; i++) {
        if (pow == 0)
            printf("%lf", x[i]);
        else {
            if (x[i] >= 0)
                printf(" + %lf.x^%d ", x[i], pow);
            else
                printf(" %lf.x^%d", x[i], pow);
        }
        pow++;
    }
}
void pivotInterpolacion(double a[FILAS][FILAS], double b[FILAS], int filas, int i){
    if (fabs(a[i][i]) < 0.0001) {
        for (int j = i + 1; j < filas; j++) {
            if (fabs(a[j][i]) > fabs(a[i][i])) {
                for (int k = i; k < filas; ++k) {
                    printf("Se realizo pivoteo\n");
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
double determinanteInterpolacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas){
    double norma = 1;
    for(int i = 0; i < filas ; i++){
        norma = norma * a[i][i];
    }
    return norma;
}

// Regresiones
void imprimirMatriz(double matriz[FILAS][MAXCOLUMNAS], int filas) {
    printf("LOS ELEMENTOS DE LA MATRIZ SON:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < MAXCOLUMNAS; j++) {
            printf("%lf\t", matriz[i][j]);
        }
        printf("\n");
    }
}
void ensamblarMatriz(double nodos[FILAS][MAXCOLUMNAS], double matriz[FILAS][MAXCOLUMNAS], double b[FILAS], int filas, int grado) {
    double suma;
    for (int i = 0; i <= grado; i++) {
        for (int j = 0; j <= grado; j++) {
            suma = 0;
            for (int k = 0; k < filas; k++) {
                suma = suma + pow(nodos[k][0], j + i);
            }
            matriz[i][j] = suma;
        }
        suma = 0;
        for (int k = 0; k < filas; k++) {
            suma = suma + (pow(nodos[k][0], i) * nodos[k][1]);
        }
        b[i] = suma;
    }

    printf("\nMatriz de Vandermonde\n");
    for (int i = 0; i <= grado; i++) {
        for (int j = 0; j <= grado; j++) {
            printf("%lf ", matriz[i][j]);
        }
        printf(" ---> %lf\n", b[i]);
    }
}
double eliminacionGaussiana(double matriz[FILAS][MAXCOLUMNAS], double b[FILAS], double x[FILAS], int filas) {
    double aux;
    double factor;
    float e = pow(10, -3);

    for (int i = 0; i <= filas; i++) {
        int intercambiar = 0;
        if (fabs(matriz[i][i]) < e) {
            for (int j = i + 1; j <= filas - 1; j++) {
                if (fabs(matriz[j][i]) > fabs(matriz[i][i])) {
                    for (int k = i; k <= filas - 1; k++) {
                        aux = matriz[i][k];
                        matriz[i][k] = matriz[j][k];
                        matriz[j][k] = aux;
                    }
                    aux = b[i];
                    b[i] = b[j];
                    b[j] = aux;
                    intercambiar = 1;
                    break;
                }
            }
            if (intercambiar == 0) {
                printf("Advertencia: sistema singular, no se puede resolver\n");
                return 1;
            } else {
                printf("Pivoteo concretado\n");
            }
        }

        for (int j = i + 1; j <= filas; j++) {
            factor = (-matriz[j][i]) / (matriz[i][i]);
            for (int k = i; k <= filas; k++) {
                matriz[j][k] = matriz[j][k] + factor * matriz[i][k];
            }
            b[j] = b[j] + factor * b[i];
        }
    }

    printf("\nLa Matriz triangular superior quedó:\n");
    for (int i = 0; i <= filas; i++) {
        for (int j = 0; j <= filas; j++) {
            printf("%lf ", matriz[i][j]);
        }
        printf("%lf\n", b[i]);
    }

    double suma;
    x[filas] = b[filas] / matriz[filas][filas];

    for (int i = filas - 1; i >= 0; i--) {
        suma = b[i];
        for (int j = i + 1; j <= filas; j++) {
            suma -= matriz[i][j] * x[j];
        }
        x[i] = suma / matriz[i][i];
    }

    printf("\n********Soluciones********\n");
    for (int i = 0; i <= filas; i++) {
        printf("\nx%d = %lf", i, x[i]);
    }
    printf("\n");

    return 0.0;
}
void imprimirPolinomio(double x[FILAS], int grado) {
    printf("\n\nPOLINOMIO\n");
    int exponente = 0;
    for (int i = 0; i <= grado; i++) {
        if (exponente == 0) {
            printf("%lf", x[i]);
        } else {
            if (x[i] >= 0) {
                printf(" + %lf X^%d", x[i], exponente);
            } else {
                printf(" %lf X^%d", x[i], exponente);
            }
        }
        exponente++;
    }
}
void detalles(double nodos[FILAS][MAXCOLUMNAS], double x[FILAS], int filas, int grado) {
    // Detalles del polinomio ajustado
    printf("\nDetalles adicionales...\n");
    // (Esta función podría implementar cálculos adicionales si es necesario)
}
void triangulacionLineal(double a[MAXCOLUMNAS][MAXCOLUMNAS], double b[MAXCOLUMNAS], double x[FILAS], int filas) {
    for (int i = 0 ; i < (filas - 1) ; i++) {
        pivotLineal(a, b, filas , i);
        for (int j = i + 1; j < filas; j++) {
            double factor = -a[j][i] / a[i][i];
            for (int k = i; k < filas; k++) {
                a[j][k] = a[j][k] + factor * a[i][k];
            }
            b[j] = b[j] + factor * b[i];
        }
    }
}
void metodoRegresionLineal(double m[FILAS][MAXCOLUMNAS], int filas) {
    printf("\n--> Regresion Lineal\n");
    double a[filas-1][filas-1] = {{0}};
    double b[filas-1] = {0};
    double yProm = 0, r = 0, Sr = 0, St = 0, sum = 0;
    a[1][1] = filas;
    for(int i = 0 ; i < filas ; i++) {
        a[0][0] += pow(m[i][0], 2);
        a[0][1] += m[i][0];
        a[1][0] += m [i][0];
        b[0] += m[i][0] * m[i][1];
        b[1] += m[i][1];
    }

    printf("\nMatriz:\n");
    for(int i = 0 ; i < 2 ; i++) {
        for(int j = 0 ; j < 2 ; j++) {
            printf("\t%lf", a[i][j]);
        }
        printf("\t%lf", b[i]);
        printf("\n");
    }

    double* x = (double*)malloc(2 * sizeof(double));
    triangulacionLineal(a, b, x, 2);

    printf("\n\nConjunto solución: \n");
    for (int i = 0; i < 2; ++i) {
        printf("\nX%d = %lf\n", i, x[i]);
    }

    for(int i = 0; i < filas ; i++) {
        yProm += m[i][1];
    }
    yProm = yProm/filas;
    for(int i = 0; i < filas ; i++) {
        St += pow((m[i][1] - yProm), 2);
    }

    for(int i = 0; i < filas ; i++) {
        sum += pow((m[i][1] - (x[0]*m[i][0] + x[1])), 2);
    }

    Sr = sqrt(sum/filas);
    printf("\nError estándar residual: %lf", Sr);

    r = (St - sum) / St;
    printf("\nCoeficiente de determinación: %lf\n", r);

    free(x);
}
void retrostutitucionLienal(double a[MAXCOLUMNAS][MAXCOLUMNAS], double b[MAXCOLUMNAS], double x[MAXCOLUMNAS], int filas) {
    x[filas - 1] = b[filas - 1] / a[filas - 1][filas - 1];
    for (int i = filas - 2 ; i >= 0 ; i--) {
        double sum = 0;
        for (int j = i + 1 ; j < filas ; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
}
void pivotLineal(double a[MAXCOLUMNAS][MAXCOLUMNAS], double b[MAXCOLUMNAS], int filas, int i) {
    double max = fabs(a[i][i]);
    int maxRow = i;
    for (int k = i + 1 ; k < filas ; k++) {
        if (fabs(a[k][i]) > max) {
            max = fabs(a[k][i]);
            maxRow = k;
        }
    }

    if (maxRow != i) {
        for (int k = i ; k < filas ; k++) {
            double tmp = a[maxRow][k];
            a[maxRow][k] = a[i][k];
            a[i][k] = tmp;
        }

        double tmp = b[maxRow];
        b[maxRow] = b[i];
        b[i] = tmp;
    }
}
void metodoRegresionCuadradosMinimos(double nodos[6][MAXCOLUMNAS], int filas, int grado) {
    double matriz[FILAS][MAXCOLUMNAS];
    double b[FILAS];
    double x[FILAS];

    printf("\n--> Regresión Polinómica\n");
    ensamblarMatriz(nodos, matriz, b, filas, grado);
    eliminacionGaussiana(matriz, b, x, grado);
    imprimirPolinomio(x, grado);
    detalles(nodos, x, filas, grado);
}
void ejecutarRegresion() {
    int filas = 8;
    int grado = filas-1;
    double m[filas][MAXCOLUMNAS];
    m[0][0] = -1; m[0][1] = 10;
    m[1][0] = 0; m[1][1] = 9;
    m[2][0] = 1; m[2][1] = 7;
    m[3][0] = 2; m[3][1] = 5;
    m[4][0] = 3; m[4][1] = 4;
    m[5][0] = 4; m[5][1] = 3;
    m[6][0] = 5; m[6][1] = 0;
    m[7][0] = 6; m[7][1] = -1;
    int seleccion;
    printf("\ncantidad de filas %d\n",filas);
    printf("\nPuntos guardados: ");
    printf("(X ; Y)\n\n");
    for(int i = 0; i < filas ; i++){
        printf("(%lf ; %lf)",m[i][0],m[i][1]);
        printf("\n");
    }
    printf("\nIngrese:\n 1 --> Lagrange\n 2 --> Polinomica\n");
    scanf("%d",&seleccion);
    switch (seleccion){
        case 1:
            metodoRegresionLineal(m , filas);
        break;
        case 2:
            metodoRegresionCuadradosMinimos(m, filas, grado);
        break;
        default:
            printf("\nSe selecciono mal la opcion");
        break;
    }
}