#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "Estacionamiento.h"
#define A 20


int main()
{
    int libre, encontrado, hayIngresados, i;
    int seguir = 1;
    int opcion;
    int profesor;
    char opcionC[100];
    char opcionBorrar;
    sAuto autos[A];
    int profesores[A];

    for (i = 0; i < A; i++) {

        profesores[i] = i;

    }

    startupVector(autos, A);

    while (seguir == 1) {

        mostrarMenu();

        gets(opcionC);

        system("cls");

        if (soloNumeros(opcionC) == 0) {

            opcion = -1;

        } else {

            opcion = atoi(opcionC);

        }

        switch (opcion)
        {
            case 1:

                libre = obtenerEspacioLibre(autos, A);

                if (libre != -1) {

                    altaAutomovil(autos, libre);

                }

                break;

            case 2:
                printf("\nIngrese el numero del profesor: ");
                scanf("%i", &profesor);
                opcionBorrar = confirmarBorrado();

                if (opcionBorrar == 's') {

                    borrarProfesor(profesor, autos, A);

                } else {

                    printf("\nHa cancelado la baja.");

                }

                break;

            case 3:
                printf("\nIngrese el numero de profesor: ");
                scanf("%i", &profesor);

                if (esProfesor(profesores, A, profesor) == 1) {

                    if (obtenerEspacioLibre(autos, A) != -1) {



                    }

                }
                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                seguir = 0;
                break;

            default:

                printf("\nOpcion invalida.\n");

        }

    printf("\n");
    system("pause");
    system("cls");

    }

    return 0;
}
