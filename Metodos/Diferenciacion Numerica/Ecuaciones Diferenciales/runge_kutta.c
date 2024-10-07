//
// Created by cegb03 on 06/10/24.
//

#include "runge_kutta.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función que describe la EDO (ejemplo)
double f_runge_kutta(double x, double y) {
    return x * pow(y,0.5); // Ejemplo: dy/dx = x * sqrt(y)
}

int metodoRunge_kutta4() {
    double a, b, h, k1, k2, k3, k4;
    int n;

    // Solicitar el intervalo y la cantidad de puntos al usuario
    printf("\nIngresar intervalo [a,b]\n a:");
    scanf("%lf", &a);
    printf("\nIngresar intervalo [a,b]\n b:");
    scanf("%lf", &b);
    printf("\nIngresar la cantidad de puntos:"); // También puede ser ingresar directamente h. h = (b-a)/n
    scanf("%d", &n);
    h = (b - a) / n; // Calcular el tamaño del paso
    printf("\nh=%lf", h);

    // Reservar memoria para los arreglos x y y
    double *x = (double *)malloc((n + 1) * sizeof(double)); // n+1 para incluir a y b
    double *y = (double *)malloc((n + 1) * sizeof(double));

    // Solicitar el dato inicial y(x0)
    printf("\nIngresar el dato inicial y(x0)\ny0:");
    scanf("%lf", &y[0]);
    x[0] = a;

    printf("x0=%lf", x[0]);
    printf("y0=%lf", y[0]);

    // Implementar el método de Runge-Kutta
    for (int i = 0; i < n; i++) {
        x[i + 1] = x[i] + h;

        k1 = f_runge_kutta(x[i], y[i]);
        k2 = f_runge_kutta(x[i] + h / 2, y[i] + (h / 2) * k1);
        k3 = f_runge_kutta(x[i] + h / 2, y[i] + (h / 2) * k2);
        k4 = f_runge_kutta(x[i] + h, y[i] + k3 * h);

        y[i + 1] = y[i] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);

        printf("\nX%d = %lf\nY%d = %lf", i + 1, x[i + 1], i + 1, y[i + 1]);
    }

    // Liberar la memoria reservada
    free(x);
    free(y);

    return 0;
}

int metodoRunge_kutta2() {
    double a, b, h, k1, k2;
    int n;

    // Solicitar el intervalo y la cantidad de puntos al usuario
    printf("\nIngresar intervalo [a,b]\n a:");
    scanf("%lf", &a);
    printf("\nIngresar intervalo [a,b]\n b:");
    scanf("%lf", &b);
    printf("\nIngresar la cantidad de puntos:"); // También puede ser ingresar directamente h. h = (b-a)/n
    scanf("%d", &n);
    h = (b - a) / n; // Calcular el tamaño del paso
    printf("\nh=%lf", h);

    // Reservar memoria para los arreglos x y y
    double *x = (double *)malloc((n + 1) * sizeof(double)); // n+1 para incluir a y b
    double *y = (double *)malloc((n + 1) * sizeof(double));

    // Solicitar el dato inicial y(x0)
    printf("\nIngresar el dato inicial y(x0)\ny0:");
    scanf("%lf", &y[0]);
    x[0] = a;

    printf("x0=%lf", x[0]);
    printf("y0=%lf", y[0]);

    // Implementar el método de Runge-Kutta de segundo orden
    for (int i = 0; i < n; i++) {
        x[i + 1] = x[i] + h;

        // Cálculo de los coeficientes k
        k1 = f_runge_kutta(x[i], y[i]);
        k2 = f_runge_kutta(x[i] + h / 2, y[i] + (h / 2) * k1);

        // Actualización de y
        y[i + 1] = y[i] + h * k2;

        printf("\nX%d = %lf\nY%d = %lf", i + 1, x[i + 1], i + 1, y[i + 1]);
    }

    // Liberar la memoria reservada
    free(x);
    free(y);

    return 0;

}