
#include "libreria.h"

//funcion principal
int main(int argc, char* argv[])
{
        char temp;
        struct recta R1;
        struct recta R2;


        //Declaración variables
        double variable[TAM];

        //Validación cant. argumentos

if (argc !=9)
        {
                printf("\nError en la cantidad de argumentos");
        }
        else
        {
                variable[0] = atof(argv[1]);
                variable[1] = atof(argv[2]);
                variable[2] = atof(argv[3]);
                variable[3] = atof(argv[4]);
                variable[4] = atof(argv[5]);
                variable[5] = atof(argv[6]);
                variable[6] = atof(argv[7]);
                variable[7] = atof(argv[8]);
        }

        //Invocación de funciones
        crear_punto(&variable[0], &R1, &R2);
        encontrar_recta(&R1, &R2);
        imprimir_punto(R1, R2);
        imprimir_recta(R1, R2);
        temp = tipo_rectas(R1, R2);
        cruce_rectas(R1, R2, temp);

        return 0;
}

