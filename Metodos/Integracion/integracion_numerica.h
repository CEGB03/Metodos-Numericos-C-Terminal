#ifndef INTEGRACION_NUMERICA_H
#define INTEGRACION_NUMERICA_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define FILAS 20

// Prototipos de funciones
double funcion(double x);
void trapecioFuncion();
void trapecioTabla();
void simpsonCompuestoFuncion();
void simpsonCompuestoTabla();
bool sonEquidistantes(double arreglo[FILAS][2], int filas);

#endif // INTEGRACION_NUMERICA_H
