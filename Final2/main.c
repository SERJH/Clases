#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int seguir = 1;
    int opcion;
    ArrayList* clientes = al_newArrayList();
    ArrayList* alquileres = al_newArrayList();

    while (seguir == 1) {

        printf("\n\t\t~ Bienvenido ~\n\n");

        printf("1- Alta cliente\n");
        printf("2- Modificar datos cliente\n");
        printf("3- Baja cliente\n");
        printf("4- Nuevo alquiler\n");
        printf("5- Fin de alquiler\n");
        printf("6- Informar\n");
        printf("7- Salir\n");

        printf("\nIngrese la opcion deseada: ");
        opcion = getIntRange(1, 7);

        switch (opcion)
        {
            case 1:

                altaCliente(clientes);
                break;

            case 2:

                modificarCliente(clientes);
                break;

            case 3:

                bajaCliente(clientes);
                break;

            case 4:

                nuevoAlquiler(clientes, alquileres);
                break;

            case 5:

                finAlquiler(alquileres);
                break;

            case 6:

                break;

            case 7:

                seguir = 0;
                break;

        }

    printf("\n");
    system("pause");
    system("cls");

    }

    return 0;
}
