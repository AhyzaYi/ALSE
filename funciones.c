
#include "libreria.h"

void crear_punto(double *variable, struct recta *R1, struct recta *R2)
{
	// Entrada de datos en la estructura
	
        (*R1).P1.x = variable[0];
        R1 -> P1.y = variable[1];
        R1 -> P2.x = variable[2];
        R1 -> P2.y = variable[3];
        R2 -> P1.x = variable[4];
        R2 -> P1.y = variable[5];
        R2 -> P2.x = variable[6];
        R2 -> P2.y = variable[7];
}

void encontrar_recta(struct recta *R1, struct recta *R2)
{
	//Recta1
        R1 -> m = ((R1 -> P2.y)-(R1 -> P1.y))/((R1 -> P2.x)-(R1 -> P1.x));
        R1 -> b = (R1 -> m)*(-(R1 -> P1.x))+(R1 -> P1.y);
       
	//Recta2
       	R2 -> m = ((R2 -> P2.y)-(R2 -> P1.y))/((R2 -> P2.x)-(R2 -> P1.x));
        R2 -> b = (R2 -> m)*(-(R2 -> P1.x))+(R2 -> P1.y);

}


void imprimir_recta(struct recta R1, struct recta R2)
{
        if (R1.P2.x - R1.P1.x == 0)
        {
                 printf("\n\tLa ecuación de la recta 1 es: x = %.2f\n", R1.P1.x);  //Recta1 vertical
        }
        else if (R1.P2.y - R1.P1.y == 0)
        {
                 printf("\n\tLa ecuación de la recta 1 es: y = %.2f\n", R1.P1.y);  //Recta1 horizontal
        }
        else
        {
                printf("\n\tLa ecuación de la recta 1 es: y = %.2fx + (%.2f)\n", R1.m, R1.b); //Recta1 con pendiente
        }

        if (R2.P2.x - R2.P1.x == 0)
        {
                 printf("\n\tLa ecuación de la recta 2 es: x = %.2f\n", R2.P1.x);  // Recta2 vertical
        }
        else if (R2.P2.y - R2.P1.y == 0)
        {
                 printf("\n\tLa ecuación de la recta 2 es: y = %.2f\n", R2.P1.y);  //Recta2 horizontal
        }
        else
        {
                printf("\n\tLa ecuación de la recta 2 es: y = %.2fx + (%.2f)\n", R2.m, R2.b);  //Recta2 con pendiente
		
        }
}

void imprimir_punto(struct recta R1, struct recta R2)
{
        printf("\n\tLos puntos de la recta 1 son: (%.2f,%.2f) y (%.2f,%.2f)", R1.P1.x, R1.P1.y, R1.P2.x, R1.P2.y);
        printf("\n\tLos puntos de la recta 2 son: (%.2f,%.2f) y (%.2f,%.2f)\n", R2.P1.x, R2.P1.y, R2.P2.x, R2.P2.y);
}


char tipo_rectas(struct recta R1, struct recta R2)
{
        char temp;
        if(R1.m == R2.m)
        {
                temp = 0;
                printf("\n\tLas rectas son paralelas \n\n");
        }
        else if ((R1.m)*(R2.m) == -1)
        {
                temp = -1;
                printf("\n\tLas rectas son perpendiculares \n\n");  
        }
        else if ((R1.P2.x - R1.P1.x == 0) && (R2.P2.y - R2.P1.y == 0))  //Recta1 vertical y Recta2 horizontal
        {
                temp = -1;
                printf("\n\tLas rectas son perpendiculares \n\n");
        }
        else if ((R2.P2.x - R2.P1.x == 0) && (R1.P2.y - R1.P1.y == 0) )  //Recta1 horizontal y Recta2 vertical
        {
                temp = -1;
                printf("\n\tLas rectas son perpendiculares \n\n");
        }
        else
        {
                temp = 2;
                printf("\n\tLas rectas no son ni paralelas ni perpendiculares \n\n");

        }
        return temp;

}

void cruce_rectas(struct recta R1, struct recta R2, char temp)
{
        float cx, cy;
        if (temp == -1 || temp == 2)
        {
                if (R1.P2.x - R1.P1.x == 0)  //Cuando Recta1 es vertical 
                {
                        cx = R1.P2.x;
                }
                else if (R2.P2.x - R2.P1.x == 0) //Cuando Recta2 es vertical
                {
                        cx = R2.P2.x;
                }
                else
                {
                        cx = ((R2.b)-(R1.b))/((R1.m)-(R2.m));  //Punto de cruce en x
                }

                if (R1.P2.y - R1.P1.y == 0)  //Cuando Recta1 es horizontal
                {
                        cy = R1.P2.y;
                }
                else if (R2.P2.y - R2.P1.y == 0)  //Cuando Recta2 es horizontal
                {
                        cy = R2.P2.y;
                }
                else
                {
                        cy = ((R1.m)*cx) + (R1.b);  //Punto de cruce en y
                }

                printf("\tEl punto donde las rectas se cruzan es (%.2f,%.2f) \n\n", cx, cy);
        }
}
 
