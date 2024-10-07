//
// Created by cegb03 on 06/10/24.
//
#ifndef REGRESION_H
#define REGRESION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h> // Para malloc

#define MAXCOLUMNAS 2
#define FILAS 20



// Declaraciones de funciones para intergracion lineal e intergracion polinómica
void interpolacionLagrange (double m[FILAS][2], int fila);
void interpolacionPolinomica (double m[FILAS][2], int fila);
void triangulacionInterpolacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas);
void retrostutitucionInterpolacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas);
void pivotInterpolacion(double a[FILAS][FILAS], double b[FILAS], int filas, int i);
double determinanteInterpolacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas);
void metodoInterpolacion();

// Declaraciones de funciones para regresión lineal
void triangulacionLineal(double a[MAXCOLUMNAS][MAXCOLUMNAS], double b[MAXCOLUMNAS], double x[FILAS], int filas);
void retrostutitucionLineal(double a[MAXCOLUMNAS][MAXCOLUMNAS], double b[MAXCOLUMNAS], double x[FILAS], int filas);
void pivotLineal(double a[MAXCOLUMNAS][MAXCOLUMNAS], double b[MAXCOLUMNAS], int filas, int i);
double determinanteLineal(double a[MAXCOLUMNAS][MAXCOLUMNAS], double b[MAXCOLUMNAS], double x[FILAS], int filas);
void regresionLineal(double m[FILAS][MAXCOLUMNAS], int filas);
void metodoRegresionLineal(); // Función que llama a ejecutarRegresionLineal()

// Declaraciones de funciones para regresión polinómica
void imprimirMatriz(double matriz[FILAS][MAXCOLUMNAS], int filas);
void ensamblarMatriz(double nodos[FILAS][MAXCOLUMNAS], double matriz[FILAS][MAXCOLUMNAS], double b[FILAS], int filas, int grado);
double eliminacionGaussiana(double matriz[FILAS][MAXCOLUMNAS], double b[FILAS], double x[FILAS], int filas);
void imprimirPolinomio(double x[FILAS], int grado);
void detalles(double nodos[FILAS][MAXCOLUMNAS], double x[FILAS], int filas, int grado);
void metodoRegresionCuadradosMinimos(double nodos[6][MAXCOLUMNAS], int filas, int grado); // Función que llama a ensamblarMatriz(), eliminacionGaussiana(), etc.

void ejecutarRegresion();
#endif // REGRESION_H
