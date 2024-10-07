#include <stdio.h>
#include <math.h>

// Función objetivo para la que se desea calcular la derivada
double funcion_diferenciacion(double x) {
    return x; // Aquí puedes cambiar la función según sea necesario
}

// Método para calcular la derivada utilizando el esquema de diferencias finitas hacia adelante
double diferenciaFinitasHaciaAdelante(double x, double h) {
    return (funcion_diferenciacion(x + h) - funcion_diferenciacion(x)) / h; // Derivada hacia adelante
}

// Método para calcular la derivada utilizando el esquema de diferencias finitas hacia atrás
double diferenciaFinitasHaciaAtras(double x, double h) {
    return (funcion_diferenciacion(x) - funcion_diferenciacion(x - h)) / h; // Derivada hacia atrás
}

// Método para calcular la derivada utilizando el esquema de diferencias finitas centradas
double diferenciaFinitasCentrada(double x, double h) {
    return (funcion_diferenciacion(x + h) - funcion_diferenciacion(x - h)) / (2 * h); // Derivada centrada
}

int diferencia_numerica(int opcion) {
    double x = 2.0; // Punto donde se desea calcular la derivada
    double h = 0.01; // Tamaño del paso

    switch (opcion) {
        case 1:
            double derivadaHaciaAdelante = diferenciaFinitasHaciaAdelante(x, h);
            printf("Derivada hacia adelante en x = %lf: %lf\n", x, derivadaHaciaAdelante);
        break;
        case 2:
            double derivadaHaciaAtras = diferenciaFinitasHaciaAtras(x, h);
            printf("Derivada hacia atrás en x = %lf: %lf\n", x, derivadaHaciaAtras);
            break;
        case 3:
            double derivadaCentrada = diferenciaFinitasCentrada(x, h);
            printf("Derivada centrada en x = %lf: %lf\n", x, derivadaCentrada);
            break;
    }
    return 0;
}
