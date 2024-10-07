//
// Created by cegb03 on 06/10/24.
//
#ifndef RUNGE_KUTTA_H
#define RUNGE_KUTTA_H

// Prototipo de la función para resolver EDOs utilizando el método de Runge-Kutta
double f1(double y2);
double f2(double x, double y1);
double f_runge_kutta(double x, double y);
int metodoRunge_kutta4();
int metodoRunge_kutta2();

#endif // RUNGE_KUTTA_H
