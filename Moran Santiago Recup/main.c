#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "Estacionamiento.h"

#define A 20
#define B 2

#define FIAT 1
#define PEUGEOT 2
#define FORD 3
#define OTRO 4

int main()
{
    int libre, encontrado, hayIngresados, i;
    int seguir = 1;
    int opcion;
    int profesor;
    char opcionC[100];
    char opcionBorrar;
    sAuto autos[A];
    sEstacionamiento lugaresEst[B];
    sEspera enEspera[A];
    sEstacionado estacionado[A];
    int profesoresE[A];

//    char patentes[20][50] = {"ABC 123", "AGH 443", "HRW 456", "FAF 333", "FAC 446", "MTV 557", "MWS 335", "AZX 546", "PPU 667", "TTY 422", "ASV 771", "LJL 990", "YUY 111", "LOL 456", "UJG 999", "ANM 121", "GHG 155", "PQE 669", "BMW 277", "UYY 123"};
//    char modelos[20][50] = {"Corsa", "Camax", "Palio", "Ranger", "Palio", "Uno", "Vega", "Lezer", "Ndeah", "X", "Zrot", "Ranger", "X", "Aden", "Bat", "330z", "270x", "Dram", "Luz", "Zrot"};
//    int marcas[20] = {FIAT, OTRO, FIAT, FORD, FIAT, FIAT, OTRO, PEUGEOT, PEUGEOT, OTRO, FORD, FORD, OTRO, PEUGEOT, OTRO, PEUGEOT, PEUGEOT, FIAT, FORD, FORD};
//    int profesores[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
//    int estados[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//
//    for (i = 0; i < A; i++) {
//
//        strcpy(autos[i].patente, patentes[i]);
//        strcpy(autos[i].modelo, modelos[i]);
//        autos[i].marca = marcas[i];
//        autos[i].profesor = profesores[i];
//        autos[i].estado = estados[i];
//
//    }

    startupVector(autos, lugaresEst, enEspera, estacionado, profesoresE, A, B);

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

                } else {

                    printf("\nNo es posible ingresar mas autos.");

                }

                break;

            case 2:

                bajaAutomovil(autos);
                break;

            case 3:

                ingresoAutomovil(lugaresEst, autos, enEspera, estacionado);
                break;

            case 4:

                egresoAutomovil(lugaresEst, autos, enEspera, estacionado);
                break;

            case 5:

                mostrarListas(autos, estacionado, A);
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
