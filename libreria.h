
//En este programa se utili

#ifndef LIBRERIA_H
#define LIBRERIA_H

#include<stdio.h>
#include<stdlib.h>
#define TAM 8

struct punto
{
        double x;
        double y;
};

struct recta
{
        double m;
        double b;
        struct punto P1,P2;
};


//Declaración función.
void crear_punto(double *variable, struct recta *R1, struct recta *R2);
void encontrar_recta(struct recta *R1, struct recta *R2);
void imprimir_punto(struct recta R1, struct recta R2);
void imprimir_recta(struct recta R1, struct recta R2);
char tipo_rectas(struct recta R1, struct recta R2);
void cruce_rectas(struct recta R1, struct recta R2, char temp);

#endif
