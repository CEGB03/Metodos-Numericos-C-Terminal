//
// Created by cegb03 on 06/10/24.
//
#ifndef DIFERENCIACION_NUMERICA_H
#define DIFERENCIACION_NUMERICA_H

// Prototipos de funciones
// Función objetivo para la que se desea calcular la derivada
double funcion_diferenciacion(double x);
// Método para calcular la derivada utilizando el esquema de diferencias finitas hacia adelante
double diferenciaFinitasHaciaAdelante(double x, double h);
// Método para calcular la derivada utilizando el esquema de diferencias finitas hacia atrás
double diferenciaFinitasHaciaAtras(double x, double h);
// Método para calcular la derivada utilizando el esquema de diferencias finitas centradas
double diferenciaFinitasCentrada(double x, double h);
int length(double a[], int tamanio);
int diferencia_numerica(int opcion);
#endif // DIFERENCIACION_NUMERICA_H
