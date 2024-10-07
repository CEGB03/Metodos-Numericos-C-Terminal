//
// Created by cegb03 on 06/10/24.
//
#include "edo.h"
#include <stdio.h>
#include <stdlib.h>

// Definición de la función que describe la EDO (ejemplo)
double f_edo(double x, double y) {
    return y - x * x + 1; // Ejemplo: dy/dx = y - x^2 + 1
}

// Función para recibir la entrada del usuario
void recibirEntrada(double* a, double* b, int* n) {
    printf("\nIngresar intervalo [a,b]\n a:");
    scanf("%lf", a);
    printf("\nIngresar intervalo [a,b]\n b:");
    scanf("%lf", b);
    printf("\nIngresar la cantidad de puntos:");
    scanf("%d", n);
}

// Implementación del Método de Euler
void metodoEuler(double (*f)(double, double), double y0, double x0) {
    double a, b, h;
    int n;

    recibirEntrada(&a, &b, &n);
    h = (b-a)/n;
    double *x = (double *)malloc((n+1) * sizeof(double)); //con n+1 porq por ejemplo si tengo a y b y tengo 5 puntos, voy a necesitar el a,1,2,3,4,b
    double *y = (double *)malloc((n+1) * sizeof(double));
    printf("\nIngresar x0 e y0\nx0:");
    scanf("%lf",&x[0]);
    printf("ny0:");
    scanf("%lf",&y[0]);

    for(int i = 0 ; i < n ; i++){ //menor a n porq cuando llegue a n-1, el for calcula el n+1
        x[i+1] =  x[i]+ h;
        y[i+1] = y[i] + h*f(x[i],y[i]);
        printf("\nX%d = %lf\nY%d = %lf",i+1, x[i+1],i+1, y[i+1]);
    }
    free(x);
    free(y);
}

// Implementación del Método de Heun
void metodoHeun(double (*f)(double, double), double y0, double x0) {
    double a, b, h, yAprox;
    int n;

    recibirEntrada(&a, &b, &n);
    h = (b-a)/n;
    double *x = (double *)malloc((n+1) * sizeof(double)); //con n+1 porq por ejemplo si tengo a y b y tengo 5 puntos, voy a necesitar el a,1,2,3,4,b
    double *y = (double *)malloc((n+1) * sizeof(double));
    printf("\nIngresar el dato inicial y(x0)\ny0:");
    scanf("%lf",&y[0]);
    x[0] = a;

    for(int i = 0 ; i < n ; i++){ //menor a n porq cuando llegue a n-1, el for calcula el n+1
        x[i+1] =  x[i]+ h;
        yAprox = y[i] + h*f(x[i],y[i]);
        y[i+1] = y[i] + h*(f(x[i],y[i])+f(x[i+1],yAprox))/2;
        printf("\nX%d = %lf\nY%d = %lf",i+1, x[i+1],i+1, y[i+1]);
    }
    free(x);
    free(y);
}

// Implementación del Método del Punto Medio
void metodoPuntoMedio(double (*f)(double, double), double y0, double x0) {
    double a, b, h, ym, xm;
    int n;

    recibirEntrada(&a, &b, &n);
    h = (b-a)/n;
    double *x = (double *)malloc((n+1) * sizeof(double)); //con n+1 porq por ejemplo si tengo a y b y tengo 5 puntos, voy a necesitar el a,1,2,3,4,b
    double *y = (double *)malloc((n+1) * sizeof(double));
    printf("\nIngresar el dato inicial y(x0)\ny0:");
    scanf("%lf",&y[0]);
    x[0] = a;

    for(int i = 0 ; i < n ; i++){ //menor a n porq cuando llegue a n-1, el for calcula el n+1
        x[i+1] =  x[i]+ h;
        xm = x[i] + h/2;
        ym = y[i] + h/2*f(x[i],y[i]);
        y[i+1] = y[i] + h*f(xm,ym);
        printf("\nX%d = %lf\nY%d = %lf",i+1, x[i+1],i+1, y[i+1]);
    }
    free(x);
    free(y);
}