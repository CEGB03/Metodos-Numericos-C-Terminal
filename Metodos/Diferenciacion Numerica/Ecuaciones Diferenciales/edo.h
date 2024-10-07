//
// Created by cegb03 on 06/10/24.
//
#ifndef EDO_H
#define EDO_H

// Prototipos de las funciones para resolver EDOs
void metodoEuler(double (*f)(double, double), double y0, double x0);
void metodoHeun(double (*f)(double, double), double y0, double x0);
void metodoPuntoMedio(double (*f)(double, double), double y0, double x0);

#endif // EDO_H
