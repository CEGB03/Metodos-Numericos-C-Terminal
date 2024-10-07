//
// Created by cegb03 on 05/10/24.
//
#include <stdio.h>
#include <math.h>

#define MAX_ITER 150000

#include "localizacion_raices.h"
// Funciones a Evaluar
double f(double x){
    return x*x -4;////x^2-4
}
double g(double x){
    // Despejar la X
    return sqrt(4);////x^2- 4  --> raiz(4) = x
}
double fPrima(double x){
    return 2*x;////2*x
}
// Metodos Cerrados
void metodoBiseccion() {
    // Implementación del método de Bisección
    printf("Ejecutando el Método de Bisección...\n");
    double a, b, tolerancia;
    int iterator = 0;

    printf("Ingrese el límite inferior del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el límite superior del intervalo: ");
    scanf("%lf", &b);
    printf("Ingrese la tolerancia: ");
    scanf("%lf", &tolerancia);

    if (f(a) * f(b) < 0.0) {
        double c, error;

        do {
            iterator++;
            c = (a + b) / 2;

            if (f(a) * f(c) > 0) {
                a = c;
            } else if (f(a) * f(c) < 0) {
                b = c;
            } else {
                break;
            }

            error = (b - a) / 2;

        } while (error > tolerancia);

        printf("\nResultado de la raíz: %.10lf", c);
        printf("\nError estimado: %.10lf", error);
        printf("\nCantidad de iteraciones: %d\n", iterator);

    } else {
        printf("\nNo hay raíz o hay un número par de ellas\n");
    }
}
void metodoRegulaFalsi() {
    // Implementación del método de Regula Falsi
    printf("Ejecutando el Método de Regula Falsi...\n");
    double a, b, tolerancia, c, error;
    int contador = 0;

    printf("Ingrese el límite inferior del intervalo: ");
    scanf("%lf", &a);
    printf("Ingrese el límite superior del intervalo: ");
    scanf("%lf", &b);
    printf("Ingrese la tolerancia: ");
    scanf("%lf", &tolerancia);

    if (f(a) * f(b) < 0.0) {
        do {
            contador++;

            c = (a*f(b) - b*f(a)) / (f(b) - f(a));


            if (f(a) * f(c) > 0) {
                a = c;
            } else if (f(a) * f(c) < 0) {
                b = c;
            } else {
                break;
            }

            error = (b - a) / 2;

        } while (error > tolerancia);

        printf("\nResultado de la raíz: %.10lf", c);
        printf("\nError estimado: %.10lf", error);
        printf("\nCantidad de iteraciones: %d\n", contador);

    } else {
        printf("\nNo hay raíz o hay un número par de ellas\n");
    }

}
// Metodos Abiertos
void metodoPuntoFijo() {
    // Implementación del método de Newton-Raphson
    printf("Ejecutando el Método de Newton-Raphson...\n");
    // acordate que tenes que inicializarlo donde quieras, va a funcionar igual.
    // Te puede llevar +- iteraciones pero es lo mismo

    double xViejo; // es el punto de partida digamos
    double xNuevo;
    int contador = 0;
    double error = 0;
    double tolerancia;
    printf("Ingrese la tolerancia\n");
    scanf("%lf", &tolerancia);
    printf("Ingrese el punto inicial\n");
    scanf("%lf", &xViejo);
    do
    {

        contador++;

        if (fabs((g(xViejo + 0.01) - g(xViejo)) / 0.01) >= 1) // Derivada >= 1
        {

            printf("\n\nNo cumple con el criterio de convergencia. El metodo diverge (|g'(x)|>1)");
            break;
        }
        else
        {

            xNuevo = g(xViejo);
            error = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        }

    }while(error > tolerancia || contador < MAX_ITER );

    printf("\nEl punto fijo de g(x), es decir la raiz de f es: %.10lf", xNuevo);
    printf("\nEl valor del error en la raiz es de: %.10lf", error);
    printf("\nLa resolucion del proble tomó %d iteraciones", contador);
}
void metodoNewtonRaphson() {
    // Implementación del método de Newton-Raphson
    printf("Ejecutando el Método de Newton-Raphson...\n");
    double xViejo , error , tolerancia , xNuevo;
    int contador = 0;
    printf("Ingrese la tolerancia\n");
    scanf("%lf", &tolerancia);
    printf("Ingrese el punto inicial\n");
    scanf("%lf", &xViejo);
    do{
        contador ++ ;

        if(fabs(fPrima(xViejo) < 1e-5)){
            printf("\n********\nDERIVADA PEQUEÑA********\n");
            break;
        } else{
            xNuevo = xViejo - (f(xViejo)/fPrima(xViejo));
            error = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        }

    }while(error > tolerancia || contador < MAX_ITER );

    printf("\n\n\nLa raiz de f es: %.10lf", xNuevo);
    printf("\nEl valor del error en la raiz es de: %.10lf", error);
    printf("\nLa resolucion del proble tomó %d iteraciones", contador);
}
void metodoSecante() {
    // Implementación del método de Newton-Raphson
    printf("Ejecutando el Método de Newton-Raphson...\n");
    double x0, xv, tolerancia;

    // Lectura de valores iniciales
    printf("Ingrese x0: ");
    scanf("%lf", &x0);
    printf("Ingrese xv: ");
    scanf("%lf", &xv);
    printf("Ingrese tolerancia: ");
    scanf("%lf", &tolerancia);

    // Calcular la raíz
    double xn = 0.0;
    double error = 0.0;
    int cont = 0;

    cont = 0;
    do {
        xn = xv - (f(xv) * (xv - x0)) / (f(xv) - f(x0)); // Calcular el siguiente punto
        error = fabs(xn - xv); // Calcular el error
        x0 = xv; // Actualizar x0 con xv
        xv = xn; // Actualizar xv con xn
        cont++; // Incrementar el contador de iteraciones
    }while(error > tolerancia || cont < MAX_ITER );

    printf("El punto fijo mediante Secante Xn=%.12f, con un error=%.12f.\nLa cantidad de iteraciones fueron: %d.\n", xn, error, cont);
}