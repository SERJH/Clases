#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Estacionamiento.h"

#define A 20
#define W "FIAT"
#define X "PEUGEOT"
#define Y "FORD"
#define Z "OTRO"

void mostrarMenu() {

    printf("1- Alta automovil\n");
    printf("2- Baja automovil\n");
    printf("3- Ingreso del automovil al estacionamiento\n");
    printf("4- Egreso del automovil\n");
    printf("5- Informar listados\n");
    printf("6- Salir\n");

    printf("\nIngrese la opcion deseada: ");

}

void startupVector(sAuto autos[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        autos[i].estado = 0;

    }

}

int validarSoloEnteros(float num) {

    return (int)num;

}

int soloEspacios(char nombre[]) {

    int i;
    int soloEsp = 1;
    int cantString = strlen(nombre);

    for (i = 0; i < cantString; i++) {

        if (nombre[i] != 32) {

            soloEsp = 0;
            return soloEsp;

        }

    }

    return soloEsp;

}

char confirmarBorrado() {

    char opcionBorrar;

    printf("\n%cEsta seguro que desea dar de baja el auto? (S/N): ", 168);
    opcionBorrar = tolower(getche());
    opcionBorrar = validarChar(opcionBorrar, 's', 'n');

    return opcionBorrar;

}

void borrarProfesor(int profesor, sAuto autos[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (profesor == autos[i].profesor) {

            autos[i].estado = 0;

        }

    }

    printf("\n\nSe ha dado de baja el automovil.\n");

}

int soloLetras(char nombre[]) {

    int i;
    int testLetra;
    int cantString = strlen(nombre);

    for (i = 0; i < cantString; i++) {

        testLetra = esLetra(nombre[i]);

        if (testLetra == 1) {

            if (i == (cantString - 1)) {

                return 1;

            }

        } else {

            return 0;

        }

    }

}

int esLetra(char a) {

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165) || (a == 32)) {

        return 1;

    } else {

        return 0;

    }

}

int soloNumeros(char num[]) {

    int i;
    int testNum;
    int cantString = strlen(num);

    for (i = 0; i < cantString; i++) {

        testNum = esNum(num[i]);

        if (testNum == 1) {

            if (i == (cantString - 1)) {

                return 1;

            }

        } else {

            return 0;

        }

    }

}

int esNum(char a) {

    if (a >= 48 && a <= 57) {

        return 1;

    } else {

        return 0;

    }

}

int validarRangoInt(int num, int min, int max) {

    if (num >= min && num <= max) {

        return 1;

    } else {

        return 0;

    }

}

char validarChar(char caracter, char opcion1, char opcion2) {

    if (caracter == opcion1 || caracter == opcion2) {

        return caracter;

    } else {

        while (caracter != opcion1 && caracter != opcion2) {

            printf("\n\nRespuesta invalida (%c/%c).", toupper(opcion1), toupper(opcion2));
            printf("\nReingrese: ");
            caracter = tolower(getche());

        }

        return caracter;

    }

}

char validarChar4(char caracter, char op1, char op2, char op3, char op4) {

    if (caracter == op1 || caracter == op2 || caracter == op3 || caracter == op4) {

        return caracter;

    } else {

        while (caracter != op1 && caracter != op2 && caracter != op3 && caracter != op4) {

            printf("\n\nRespuesta invalida (%c/%c/%c/%c).", toupper(op1), toupper(op2), toupper(op3), toupper(op4));
            printf("\nReingrese: ");
            caracter = toupper(getche());

        }

        return caracter;

    }

}

int esProfesor(int profesores[], int tam, int num) {

    int i;

    for (i = 0; i < tam; i++) {

        if (num == profesores[i]) {

            return 1;

        }

    }

    return 0;
}

void altaAutomovil(sAuto autos[], int libre) {

    char auxNum[25];
    char marca;
    int soloEsp;
    int soloNum;
    int validNum;
    int repetido;

    // Ingreso de patente

    printf("\nIngrese la patente del automovil: ");
    gets(autos[libre].patente);

    soloEsp = soloEspacios(autos[libre].patente);
    repetido = stringRepetida(autos[libre].patente, autos, A);

    while (soloEsp == 1 || repetido == 1) {

        if (repetido == 1) {

            printf("\nLa patente ingresada pertenece a otro auto.");
            printf("\nReingrese: ");
            gets(autos[libre].patente);

        } else {

            printf("\nLa patente es invalida.");
            printf("\nReingrese: ");
            gets(autos[libre].patente);

        }

        soloEsp = soloEspacios(autos[libre].patente);
        repetido = stringRepetida(autos[libre].patente, autos, A);

    }

    // Ingreso de marca

    printf("\nIngrese la marca: ");
    marca = toupper(getche());

    marca = validarChar4(marca, 'W', 'X', 'Y', 'Z');

    switch (marca)
    {
        case 'W':
            strcpy(autos[libre].marca, W);
            break;
        case 'X':
            strcpy(autos[libre].marca, X);
            break;
        case 'Y':
            strcpy(autos[libre].marca, Y);
            break;
        case 'Z':
            strcpy(autos[libre].marca, Z);
            break;
    }

    // Ingreso de modelo

    printf("\nIngrese el modelo: ");
    fflush(stdin);
    gets(autos[libre].modelo);

    soloEsp = soloEspacios(autos[libre].modelo);

    while (soloEsp == 1) {

        printf("\nError. El modelo debe contener al menos un caracter.\n");
        printf("\nReingrese: ");
        fflush(stdin);
        gets(autos[libre].modelo);

        soloEsp = soloEspacios(autos[libre].modelo);

    }

    // Ingreso de profesor

    printf("\nIngrese el identificador numerico del profesor: ");
    gets(auxNum);

    soloNum = soloNumeros(auxNum);

    while (soloNum == 0) {

        printf("\nEl identificador debe ser un numero.");
        printf("\nReingrese: ");
        gets(auxNum);

        soloNum = soloNumeros(auxNum);

    }

    autos[libre].profesor = atoi(auxNum);
    autos[libre].estado = 1;

}

int stringRepetida(char string[], sAuto autos[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (strcmp(autos[i].patente, string) == 0 && autos[i].estado == 1) {

            return 1;

        }

    }

    return 0;

}

int numRepetido(int num, sAuto autos[], int tam) {

    int i;

//    for (i = 0; i < tam; i++) {
//
//        if (autos[i].patente == num && abonados[i].estado == 1) {
//
//            return 1;
//
//        }
//
//    }

    return 0;

}

int obtenerEspacioLibre(sAuto autos[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (autos[i].estado == 0) {

            return i;

        }

    }

    return -1;

}
