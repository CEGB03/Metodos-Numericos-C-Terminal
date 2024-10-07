#include <stdio.h>
#include "Metodos/Localizacion De Raices/localizacion_raices.h"
#include "Metodos/Sistemas de Ecuaciones Lineales/sistemas_ecuaciones.h"  // Archivo de encabezado del sistema de ecuaciones
#include "Metodos/Ajuste de Curvas/ajuste_curvas.h"  // Archivo de encabezado del ajuste de curvas
#include "Metodos/Ajuste de Curvas/interpolacion_spline.h"  // Archivo de encabezado de interpolación
#include "Metodos/Integracion/integracion_numerica.h"  // Archivo de encabezado de integración numérica
#include "Metodos/Integracion/cuadratura_gauss.h"  // Archivo de encabezado de cuadratura de Gauss
#include "Metodos/Diferenciacion Numerica/Diferenciacion/diferenciacion_numerica.h"  // Archivo de encabezado de sistemas diferenciales
#include "Metodos/Diferenciacion Numerica/Ecuaciones Diferenciales/edo.h"  // Archivo de encabezado de sistemas diferenciales
#include "Metodos/Diferenciacion Numerica/Ecuaciones Diferenciales/runge_kutta.h"  // Archivo de encabezado de sistemas diferenciales
#include "Metodos/Diferenciacion Numerica/sistemas_diferenciales.h"  // Archivo de encabezado de sistemas diferenciales
// Incluye más archivos de cabecera si es necesario


/*
 *
 *  bash
 *  gcc main.c Metodos/Localizacion\ De\ Raices/localizacion_raices.c Metodos/Sistemas\ de\ Ecuaciones\ Lineales/sistemas_ecuaciones.c Metodos/Ajuste\ de\ Curvas/ajuste_curvas.c Metodos/Ajuste\ de\ Curvas/interpolacion_spline.c Metodos/Integracion/integracion_numerica.c Metodos/Integracion/cuadratura_gauss.c Metodos/Diferenciacion\ Numerica/Diferenciacion/diferenciacion_numerica.c Metodos/Diferenciacion\ Numerica/Ecuaciones\ Diferenciales/edo.c Metodos/Diferenciacion\ Numerica/Ecuaciones\ Diferenciales/runge_kutta.c -o metodos_numericos -lm
 **/
// Ejecutar por consola:
void mostrarMenuPrincipal() {
    printf("Menú Principal de Métodos Numéricos\n");
    printf("1. Localización de Raíces\n");
    printf("2. Sistema de Ecuaciones Algebraicas Lineales\n");
    printf("3. Ajuste de Curvas\n");
    printf("4. Interpolación Segmentaria (Curvas Spline)\n");
    printf("5. Métodos de Integración Numérica\n");
    printf("6. Integración por Cuadratura de Gauss\n");
    printf("7. Diferenciación Numérica\n");
    printf("8. Ecuaciones Diferenciales Ordinarias\n");
    printf("9. Métodos de Runge-Kutta\n");
    printf("10. Sistema de Ecuaciones Diferenciales\n");
    printf("0. Salir\n");
}
void ejecutarLocalizacionRaices() {
    int opcion;
    do {
        printf("Localización de Raíces\n");
        printf("1. Método de Bisección\n");
        printf("2. Método de Falsa Posición (Regula-Falsi)\n");
        printf("3. Método de Iteración de Punto Fijo\n");
        printf("4. Método de Newton-Raphson\n");
        printf("5. Método de la Secante\n");
        printf("0. Regresar\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                metodoBiseccion();  // Llama al método de bisección
                break;
            case 2:
                metodoRegulaFalsi();  // Llama al método regula-falsi
                break;
            case 3:
                metodoPuntoFijo();  // Llama al método de punto fijo
                break;
            case 4:
                metodoNewtonRaphson();  // Llama al método Newton-Raphson
                break;
            case 5:
                metodoSecante();  // Llama al método de la secante
                break;
        }
    } while(opcion != 0);
}
void ejecutarSistemaEcuaciones() {
    int opcion;
    do {
        printf("Sistemas de Ecuaciones Algebraicas Lineales\n");
        printf("1. Eliminación Gaussiana\n");
        printf("2. Métodos Iterativos\n");
        printf("0. Regresar\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                metodoEliminacionGaussiana();
            break;
            case 2:
                metodoIterativos();
            break;
        }
    } while(opcion != 0);
}
void ejecutarAjusteCurvas() {
    int opcion;
    do {
        printf("Ajuste de Curvas\n");
        printf("1. Interpolación(Lagrange, Polinomial\n");
        printf("2. Regresión(Lineal, Polinomial)\n");
        printf("0. Regresar\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                metodoInterpolacion();
            break;
            case 2:
                ejecutarRegresion();
            break;
        }
    } while(opcion != 0);
}
void ejecutarInterpolacionSegmentaria() {
    int opcion;
    do {
        printf("Interpolación Segmentaria (Curvas Spline)\n");
        /*printf("1. Spline Lineal\n");
        printf("2. Spline Cuadrático\n");*/
        printf("3. Spline Cúbico\n");
        printf("0. Regresar\n");
        scanf("%d", &opcion);

        switch (opcion) {
            /*case 1:
                metodoSplineLineal();
            break;
            case 2:
                metodoSplineCuadratica();
            break;*/
            case 3:
                metodoSplineCubico();
            break;
        }
    } while(opcion != 0);
}
void ejecutarMetodosIntegracion() {
    int opcion = -1;
    int subopcion = -1;

    do {
        printf("\nMétodos de Integración Numérica\n");
        printf("1. Regla del Trapecio\n");
        printf("2. Regla del Trapecio Compuesta\n");
        printf("3. Regla de Simpson 1/3\n");
        printf("4. Regla de Simpson Compuesta\n");
        printf("5. Cuadratura de Gauss\n");
        printf("0. Regresar\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nSeleccione:\n");
                printf("1. Integrar función\n");
                printf("2. Integrar tabla de puntos\n");
                scanf("%d", &subopcion);

                if (subopcion == 1) {
                    trapecioFuncion();
                } else if (subopcion == 2) {
                    trapecioTabla();
                } else {
                    printf("\nOpción inválida\n");
                }
                break;

            case 2:
                printf("\nSeleccione:\n");
                printf("1. Integrar función\n");
                printf("2. Integrar tabla de puntos\n");
                scanf("%d", &subopcion);

                if (subopcion == 1) {
                    trapecioFuncion();
                } else if (subopcion == 2) {
                    trapecioTabla();
                } else {
                    printf("\nOpción inválida\n");
                }
                break;

            case 3:
                printf("\nSeleccione:\n");
                printf("1. Integrar función\n");
                printf("2. Integrar tabla de puntos\n");
                scanf("%d", &subopcion);

                if (subopcion == 1) {
                    simpsonCompuestoFuncion();
                } else if (subopcion == 2) {
                    simpsonCompuestoTabla();
                } else {
                    printf("\nOpción inválida\n");
                }
                break;

            case 4:
                printf("\nSeleccione:\n");
                printf("1. Integrar función\n");
                printf("2. Integrar tabla de puntos\n");
                scanf("%d", &subopcion);

                if (subopcion == 1) {
                    simpsonCompuestoFuncion();
                } else if (subopcion == 2) {
                    simpsonCompuestoTabla();
                } else {
                    printf("\nOpción inválida\n");
                }
                break;

            case 5:
                cuadratura_gauss();
                break;
            case 0:
                printf("\nSaliendo...\n");
                break;

            default:
                printf("\nOpción inválida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 0);

}
void menuDiferenciacionNumerica() {
    int opcion;

    do {
        printf("\nMétodos de Diferenciación Numérica\n");
        printf("1. Diferencias Finitas Centradas\n");
        printf("2. Diferencias Finitas hacia Adelante\n");
        printf("3. Diferencias Finitas hacia Atrás\n");
        printf("0. Regresar al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
            case 2:
            case 3:
                diferencia_numerica(opcion);
                break;
            case 0:
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
            break;
        }
    } while(opcion != 0);
}
void menuEcuacionesDiferenciales() {
    int opcion;

    do {
        printf("\nMétodos para Ecuaciones Diferenciales Ordinarias\n");
        printf("1. Método de Euler\n");
        printf("2. Método de Heun\n");
        printf("3. Método de Punto Medio\n");
        printf("4. Método de Runge-Kutta (RK4)\n");
        printf("0. Regresar al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            /*case 1:
                metodoEuler();
                break;
            case 2:
                metodoHeun();
                break;
            case 3:
                metodoPuntoMedio();
                break;*/
            case 4:
                metodoRunge_kutta4();
                break;
            case 0:
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
            break;
        }
    } while(opcion != 0);
}
void menuSistemasDiferenciales() {
    int opcion;

    do {
        printf("\nMétodos para Sistemas Diferenciales\n");
        printf("1. Método de Euler para sistemas\n");
        printf("2. Método de Runge-Kutta para sistemas\n");
        printf("0. Regresar al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Llamada a la función Método de Euler para sistemas
                    break;
            case 2:
                // Llamada a la función Método de Runge-Kutta para sistemas
                    break;
            case 0:
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
            break;
        }
    } while(opcion != 0);
}
int main() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ejecutarLocalizacionRaices();
                break;
            case 2:
                ejecutarSistemaEcuaciones();  // Método Gauss-Seidel, Jacobi, etc.
                break;
            case 3:
                ejecutarAjusteCurvas();  // Llama al submenú de ajuste de curvas
                break;
            case 4:
                ejecutarInterpolacionSegmentaria();
                break;
            case 5:
                ejecutarMetodosIntegracion();
                break;
            case 6:
                menuDiferenciacionNumerica();
                break;
            case 7:
                menuEcuacionesDiferenciales();
                break;
            case 8:
                menuSistemasDiferenciales();
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 0);

    return 0;
}

