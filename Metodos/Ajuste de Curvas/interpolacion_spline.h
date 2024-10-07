//
// Created by cegb03 on 06/10/24.
//

#ifndef INTERPOLACION_SPLINE_H
#define INTERPOLACION_SPLINE_H

#define FILAS 20
#define COLUMNAS 20

void buildMatrixSplineLineal(double m[FILAS][2], double a[FILAS][FILAS], double b[FILAS], int filas);
void metodoSplineLineal(double m[FILAS][2], double z[FILAS], int fila);

void buildMatrixSplineCuadratico(double m[FILAS][2], double a[FILAS][FILAS], double b[FILAS], int filas);
void metodoSplineCuadratica(double m[FILAS][2], double z[FILAS], int fila);

void buildMatrix (double m[FILAS][2] , double a[FILAS][FILAS] , double b[FILAS] , int filas);
void triangulacionInterpolacionSpline(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
void retrostutitucionInterpolacionSpline(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
void pivotInterpolacionSpline(double a[FILAS][COLUMNAS], double b[FILAS], int filas, int i);
double determinanteInterpolacionSpline(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
void interpolacion (double m[FILAS][2], double x[FILAS], int filas);
void metodoSplineCubico ();


#endif //INTERPOLACION_SPLINE_H
