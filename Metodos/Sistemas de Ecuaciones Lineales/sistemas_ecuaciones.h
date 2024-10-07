//
// Created by cegb03 on 06/10/24.
//

#ifndef SISTEMAS_ECUACIONES_H
#define SISTEMAS_ECUACIONES_H
#define FILAS 20
#define COLUMNAS 20
#include <stdbool.h>

void imprimirMatrices(double a[FILAS][COLUMNAS], double b[FILAS], int filas, int columnas);

// Eliminacion Gausiana
void fileReader (double m[FILAS][COLUMNAS], int* filas, int* columnas);
void matrizA (double a[FILAS][COLUMNAS], double m[FILAS][COLUMNAS], int filas, int columnas);
void matrizB (double b[FILAS], double m[FILAS][COLUMNAS], int filas, int columnas);
// Funci�n para triangular matriz
void triangulacion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
//Funcion para retrostutituir matriz
void retrostutitucion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
//Funcion para pibotear la matiz
void pivot(double a[FILAS][COLUMNAS], double b[FILAS], int filas, int i);
//verifica que en la diagonal no hayan ceros.
double determinante(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
void metodoEliminacionGaussiana();

// Metodos Iterativos
void jacobi (double a[FILAS][COLUMNAS] , double b[FILAS], int filas);
void gaussSeidel (double a[FILAS][COLUMNAS] , double b[FILAS], int filas);
void relajacion (double a[FILAS][COLUMNAS] , double b[FILAS], int filas);
bool diagonalmenteDominante(double a[FILAS][COLUMNAS], int filas);
void metodoIterativos();
#endif //SISTEMAS_ECUACIONES_H
