#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int seguir = 1;
    int opcion;
    ArrayList* logs = al_newArrayList();
    ArrayList* services = al_newArrayList();

    while (seguir == 1) {

        printf("\n\t\t~ Bienvenido ~\n\n");

        printf("1- Leer log\n");
        printf("2- Procesar informacion\n");
        printf("3- Mostrar estadisticas\n");
        printf("4- Salir\n");

        printf("\nIngrese la opcion deseada: ");
        opcion = getIntRange(1, 4);

        switch (opcion)
        {
            case 1:

                parseoLogs(logs);
                parseoServices(services);
                break;

            case 2:

                procesarInfo(logs, services);
                break;

            case 3:

                cantidadFallos(logs, services);
                break;

            case 4:

                seguir = 0;
                break;

        }

    printf("\n");
    system("pause");
    system("cls");

    }

    return 0;
}
