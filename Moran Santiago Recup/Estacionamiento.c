#include <stdio.h>
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

void mostrarMenu() {

    printf("\n\t\t ~ Estacionamiento UTN ~ \n\n");

    printf("1- Alta automovil\n");
    printf("2- Baja automovil\n");
    printf("3- Ingreso del automovil al estacionamiento\n");
    printf("4- Egreso del automovil\n");
    printf("5- Informar listados\n");
    printf("6- Salir\n");

    printf("\nIngrese la opcion deseada: ");

}

void startupVector(sAuto autos[], sEstacionamiento lugaresEst[], sEspera enEspera[], sEstacionado estacionado[], int profesoresE[], int tam1, int tam2) {

    int i;

    for (i = 0; i < tam1; i++) {

        autos[i].estado = 0;

    }

    for (i = 0; i < A; i++) {

        profesoresE[i] = i+1;

    }

    for (i = 0; i < B; i++) {

        lugaresEst[i].profesor = profesoresE[i];
        lugaresEst[i].estado = 0;
        enEspera[i].estado = 0;

    }

    for (i = 0; i < A; i++) {

        estacionado[i].estado = 0;

    }

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

int esLetraStrict(char a) {

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165)) {

        return 1;

    } else {

        return 0;

    }

}

int soloNumeros(char num[]) {

    int i;
    int testNum;
    int cantString;
    cantString = strlen(num);

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

        return num;

    } else {

        while (num < min || num > max) {

            printf("\nError. Reingrese un numero dentro del rango dado (%i - %i): ", min, max);
            scanf("%i", &num);

        }

        return num;

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

int esProfesor(int profesores[], int tam, int num) {

    int i;

    for (i = 0; i < tam; i++) {

        if (num == profesores[i]) {

            return 1;

        }

    }

    return 0;
}

int espaciosConsecutivos(char string[]) {

    int i;
    int esp = 32;
    int tam = strlen(string);
    int consecutivos = 0;

    for (i = 0; i < tam; i++) {

        if (string[i] == esp) {

            if (consecutivos == 1) {

                return 1;

            } else {

                consecutivos = 1;

            }

        } else {

            consecutivos = 0;

        }

    }

    return 0;

}

int patenteValida(char patente[]) {

    int i;
    int tam = strlen(patente);

    if (tam == 7) {

        for (i = 0; i < tam; i++) {

            if (i < 3) {

                if (esLetraStrict(patente[i]) != 1) {

                    return 0;

                }

            } else if (i == 3) {

                if (patente[i] != 32) {

                    return 0;

                }

            } else {

                if (esNum(patente[i]) != 1) {

                    return 0;

                }

            }

        }

        return 1;

    }

    return 0;

}

void bajaAutomovil(sAuto autos[]) {

    char auxChar[25];
    char confirm;
    int soloNum;
    int profesor;
    int index;

    printf("\nIngrese el numero del profesor: ");
    fflush(stdin);
    gets(auxChar);

    soloNum = soloNumeros(auxChar);

    while (soloNum == 0) {

        printf("\nError. El identificador debe ser un numero.");
        printf("\nReingrese: ");
        fflush(stdin);
        gets(auxChar);

        soloNum = soloNumeros(auxChar);

    }

    profesor = validarRangoInt(atoi(auxChar), 1, 99);

    index = buscarPorNumero(autos, profesor, A);


    if (index != -1) {

        confirm = confirmarBorrado();

        if (confirm == 's') {

            autos[index].estado = 0;
            printf("\nSe ha dado de baja el auto.");

        } else {

            printf("\nHa cancelado el borrado.");

        }

    } else {

        printf("\nNo hay ningun auto asociado con ese identificador.");

    }

}

void ingresoAutomovil(sEstacionamiento lugaresEst[], sAuto autos[], sEspera espera[], sEstacionado estacionado[]) {

    int numP;
    int encontrado;
    int index, indexE;
    int listo;
    int lleno;
    int repetido;
    char auxChar[25];

    printf("\nIngrese el numero de profesor: ");
    fflush(stdin);
    gets(auxChar);

    soloNumeros(auxChar);
    numP = validarRangoInt(atoi(auxChar), 1, 99);

    encontrado = buscarPorNumero(autos, numP, A);

    if (encontrado != -1) {

        index = buscarPorNumeroE(lugaresEst, numP, B);
        lleno = estacionamientoLleno(lugaresEst);
        listo = esperando(espera, numP);
        repetido = numRepetidoEspera(numP, espera, B);

        if (repetido == 1) {

            printf("\nEse profesor ya esta en espera para ingresar.");

        } else if (listo == 1) {

            index = libreEst(lugaresEst);
            indexE = libreEst2(estacionado);
            lugaresEst[index].profesor = numP;
            lugaresEst[index].estado = 1;

            estacionado[indexE].profesor = numP;
            estacionado[indexE].estado = 1;

            printf("\nEl profesor ha ingresado correctamente.");

            acomodarEspera(espera);

            } else if (index != -1 && index != -2) {

                lugaresEst[index].estado = 1;

                indexE = libreEst2(estacionado);

                estacionado[indexE].profesor = numP;
                estacionado[indexE].estado = 1;

                printf("\nEl profesor ha ingresado correctamente.");

            } else if (index == -2) {

                printf("\nEse profesor ya ha ingresado.");

            } else {

                if (lleno == 1) {

                    printf("\nEl estacionamiento esta lleno.");
                    ingresarAEspera(espera, numP);
                    printf("\n\nSe ha ingresado a espera al auto del profesor %i.", numP);

                } else {

                    index = libreEst(lugaresEst);
                    lugaresEst[index].profesor = numP;
                    lugaresEst[index].estado = 1;

                    indexE = libreEst2(estacionado);
                    estacionado[indexE].profesor = numP;
                    estacionado[indexE].estado = 1;

                    printf("\nEl profesor ha ingresado correctamente.");

                }

            }

    } else {

        printf("\nNo se ha encontrado un profesor con ese identificador.");

    }

}

int libreEst(sEstacionamiento lugaresEst[]) {

    int i;

    for (i = 0; i < B; i++) {

        if (lugaresEst[i].estado == 0) {

            return i;

        }

    }

    return -1;

}

int libreEst2(sEstacionado estacionado[]) {

    int i;

    for (i = 0; i < B; i++) {

        if (estacionado[i].estado == 0) {

            return i;

        }

    }

    return -1;

}

int esperando(sEspera espera[], int num) {

    if (espera[0].profesor == num) {

        if (espera[0].estado == -1) {

            return 1;

        }

    }

    return 0;
}

int estacionamientoLleno(sEstacionamiento lugaresEst[]) {

    int i;

    for (i = 0; i < B; i++) {

        if (lugaresEst[i].estado == 0) {

            return 0;

        }

    }

    return 1;

}

void egresoAutomovil(sEstacionamiento lugaresEst[], sAuto autos[], sEspera espera[], sEstacionado estacionado[]) {

    int numP;
    int encontrado;
    int index, indexE;
    char auxChar[25];

    printf("\nIngrese el numero de profesor: ");
    fflush(stdin);
    gets(auxChar);

    soloNumeros(auxChar);
    numP = validarRangoInt(atoi(auxChar), 1, 99);

    encontrado = buscarPorNumero(autos, numP, A);

    if (encontrado != -1) {

        index = buscarPorNumeroE2(lugaresEst, numP, B);

        if (index != -1) {

            printf("\nEl profesor ha egresado correctamente.");

            if (estacionamientoLleno(lugaresEst) == 1 && espera[0].estado == 1) {

                printf("\n\nEl profesor numero %i ya puede ser ingresado.", espera[0].profesor);
                espera[0].estado = -1;

            }

            lugaresEst[index].estado = 0;

            indexE = buscarPorNumeroE3(estacionado, numP, A);
            estacionado[indexE].estado = 0;

        } else {

            printf("\nEse profesor no ha ingresado al estacionamiento.");

        }

    } else {

        printf("\nNo se ha encontrado un profesor con ese identificador.");

    }

}

void acomodarEspera(sEspera espera[]) {

    int i;

    for (i = 0; i < B; i++) {

        if (i < B-1) {

            espera[i] = espera[i+1];

        } else {

            espera[i].estado = 0;

        }

    }

}

void ingresarAEspera(sEspera espera[], int profesor) {

    int i;

    for (i = 0; i < B; i++) {

        if (espera[i].estado == 0) {

            espera[i].profesor = profesor;
            espera[i].estado = 1;
            break;

        }

    }

}

void mostrarListas(sAuto autos[], sEstacionado lugaresEst[], int tam) {

    int opcion;
    char opcionC[25];

    printf("\n1- Listar autos habilitados ordenados por marca y patente");
    printf("\n2- Listar todos los autos estacionados");
    printf("\n3- Listar autos estacionados de marca FIAT");
    printf("\n4- Listar autos fuera del estacionamiento");
    printf("\n5- Listar todas las anteriores");

    printf("\n\nIngrese la opcion deseada: ");

    gets(opcionC);

    if (soloNumeros(opcionC) == 0) {

        opcion = -1;

    } else {

        opcion = atoi(opcionC);

    }

    switch (opcion)
    {
        case 1:

            mostrarLista1(autos, A);
            break;

        case 2:

            mostrarLista2(lugaresEst, autos, A);
            break;

        case 3:

            mostrarLista3(lugaresEst, autos, A);
            break;

        case 4:

            mostrarLista4(lugaresEst, autos, A);
            break;

        case 5:

            mostrarLista1(autos, A);
            mostrarLista2(lugaresEst, autos, A);
            mostrarLista3(lugaresEst, autos, A);
            mostrarLista4(lugaresEst, autos, A);
            break;

        default:

            printf("\nOpcion invalida.\n");

    }

}

void mostrarLista1(sAuto autos[], int tam) {

    int i, j;
    sAuto autosOrdenados[tam];
    sAuto auxAuto;

    for (i = 0; i < tam; i++) {

        autosOrdenados[i] = autos[i];

    }

    for (i = 0; i < (tam - 1); i++) {

        for (j = i+1; j < tam; j++) {

            if (autosOrdenados[i].estado != 0 && autosOrdenados[j].estado != 0) {

                if (autosOrdenados[i].marca == autosOrdenados[j].marca) {

                    if (strcmp(autosOrdenados[i].patente, autosOrdenados[j].patente) == 1) {

                        auxAuto = autosOrdenados[i];
                        autosOrdenados[i] = autosOrdenados[j];
                        autosOrdenados[j] = auxAuto;

                    }

                }

            }

        }

    }

    printf("\nListado de autos habilitados:\n");

    printf("\nPatente\t\tProfesor\tMarca\n");

    for (i = 0; i < tam; i++) {

        if (autosOrdenados[i].estado != 0) {

            printf("\n%s\t\t%i\t\t%i", autosOrdenados[i].patente, autosOrdenados[i].profesor, autosOrdenados[i].marca);

        }

    }

}

void mostrarLista2(sEstacionado lugaresEst[], sAuto autos[], int tam) {

    int i, j;

    printf("\n\nAutos estacionados en este momento:\n");
    printf("\nPatente\t\tModelo\t\tMarca\t\tProfesor\n");

    for (i = 0; i < A; i++) {

        if (lugaresEst[i].estado != 0) {

            for (j = 0; j < A; j++) {

                if (lugaresEst[i].profesor == autos[j].profesor) {

                    printf("\n%s\t\t%s\t\t", autos[j].patente, autos[j].modelo);

                    switch(autos[j].marca)
                    {
                        case FIAT:
                            printf("FIAT");
                            break;
                        case FORD:
                            printf("FORD");
                            break;
                        case PEUGEOT:
                            printf("PEUGEOT");
                            break;
                        case OTRO:
                            printf("OTRO");
                            break;

                    }

                    printf("\t\t%i", autos[j].profesor);
                }

            }

        }

    }

}

void mostrarLista3(sEstacionado lugaresEst[], sAuto autos[], int tam) {

    int i, j;

    printf("\n\nAutos de marca FIAT estacionados:\n");
    printf("\nPatente\t\tModelo\t\tProfesor\n");

    for (i = 0; i < A; i++) {

        if (lugaresEst[i].estado != 0) {

            for (j = 0; j < A; j++) {

                if (lugaresEst[i].profesor == autos[j].profesor) {

                    if (autos[j].marca == 1) {

                        printf("\n%s\t\t%s\t\t%i", autos[j].patente, autos[j].modelo, autos[j].profesor);

                    }

                }

            }

        }

    }

}

void mostrarLista4(sEstacionado estacionado[], sAuto autos[], int tam) {

    int i, j;
    int hay = 0;

    printf("\n\nAutos no estacionados:\n");
    printf("\nPatente\t\tProfesor\n");

    for (i = 0; i < tam; i++) {

        hay = 0;

        for (j = 0; j < tam; j++) {

            if (autos[i].profesor == estacionado[j].profesor) {

                hay = 1;

                if (estacionado[j].estado == 0) {

                    if (autos[i].estado == 1) {

                        printf("\n%s\t\t%i", autos[i].patente, autos[i].profesor);

                    }

                }

                break;

            }

        }

        if (hay == 0) {

            if (autos[i].estado == 1) {

                printf("\n%s\t\t%i", autos[i].patente, autos[i].profesor);

            }

        }

    }

}

//void listar1(sAuto autos[], int tam) {
//
//    int i, j, h;
//    sAuto autosOrdenados[tam];
//    sAuto auxAuto;
//
//    for (i = 0; i < tam; i++) {
//
//        autosOrdenados[i] = autos[i];
//
//    }
//
//    for (i = 0; i < (tam-1); i++) {
//
//        for (j = i+1; j < tam; j++) {
//
//            if (autosOrdenados[i].marca == 1) {
//
//                for (h = i+1; h < tam; h++) {
//
//                    if (autosOrdenados[h].marca == 1) {
//
//                        auxAuto = autosOrdenados[h];
//                        autosOrdenados[h] = autosOrdenados[j];
//                        autosOrdenados[j] = auxAuto;
//
//                    }
//
//                }
//
//            } else if (autosOrdenados[i].marca == 2) {
//
//                for (h = i+1; h < tam; h++) {
//
//                    if (autosOrdenados[h].marca == 2) {
//
//                        auxAuto = autosOrdenados[h];
//                        autosOrdenados[h] = autosOrdenados[j];
//                        autosOrdenados[j] = auxAuto;
//
//                    }
//
//                }
//
//            } else if (autosOrdenados[i].marca == 3) {
//
//                for (h = i+1; h < tam; h++) {
//
//                    if (autosOrdenados[h].marca == 3) {
//
//                        auxAuto = autosOrdenados[h];
//                        autosOrdenados[h] = autosOrdenados[j];
//                        autosOrdenados[j] = auxAuto;
//
//                    }
//
//                }
//
//            } else {
//
//                for (h = i+1; h < tam; h++) {
//
//                    if (autosOrdenados[h].marca == 4) {
//
//                        auxAuto = autosOrdenados[h];
//                        autosOrdenados[h] = autosOrdenados[j];
//                        autosOrdenados[j] = auxAuto;
//
//                    }
//
//                }
//
//            }
//
//        }
//
//    }
//
//    printf("\nPatente\t\tProfesor\t\tMarca\n");
//
//    for (i = 0; i < tam; i++) {
//
//        if (autosOrdenados[i].estado != 0) {
//
//            printf("\n%s\t\t%i\t\t%i", autosOrdenados[i].patente, autosOrdenados[i].profesor, autosOrdenados[i].marca);
//
//        }
//
//    }
//
//}

int buscarEspacioLibreE(sEstacionamiento lugarEst[]) {

    int i;

    for (i = 0; i < B; i++) {

        if (lugarEst[i].estado == 0) {

            return i;

        }

    }

    return -1;

}

int buscarPorNumeroE(sEstacionamiento lugarEst[], int num, int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (lugarEst[i].profesor == num) {

            if (lugarEst[i].estado == 0) {

                return i;

            } else {

                return -2;

            }

        }

    }

    return -1;

}

int buscarPorNumeroE2(sEstacionamiento lugarEst[], int num, int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (lugarEst[i].profesor == num && lugarEst[i].estado == 1) {

            return i;

        }

    }

    return -1;

}

int buscarPorNumeroE3(sEstacionado estacionado[], int num, int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (estacionado[i].profesor == num && estacionado[i].estado == 1) {

            return i;

        }

    }

    return -1;

}

int buscarPorNumero(sAuto autos[], int num, int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (autos[i].profesor == num && autos[i].estado == 1) {

            return i;

        }

    }

    return -1;

}



void altaAutomovil(sAuto autos[], int libre) {

    char auxNum[25];
    int marca;
    int soloEsp;
    int espConsec;
    int soloNum;
    int valido;
    int repetido;

    // Ingreso de patente

    printf("\nIngrese la patente del automovil: ");
    fflush(stdin);
    gets(autos[libre].patente);
    strupr(autos[libre].patente);

    valido = patenteValida(autos[libre].patente);
    repetido = stringRepetida(autos[libre].patente, autos, A);

    while (valido != 1 || repetido == 1) {

        if (repetido == 1) {

            printf("\nLa patente ingresada pertenece a otro auto.");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(autos[libre].patente);
            strupr(autos[libre].patente);

        } else {

            printf("\nLa patente es invalida. El formato debe ser (ABC 123).");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(autos[libre].patente);
            strupr(autos[libre].patente);

        }

        valido = patenteValida(autos[libre].patente);
        repetido = stringRepetida(autos[libre].patente, autos, A);

    }

    // Ingreso de marca

    printf("\nIngrese la marca (1- FIAT | 2- PEUGEOT | 3- FORD | 4- OTRO): ");
    fflush(stdin);
    gets(auxNum);

    soloNum = soloNumeros(auxNum);

    while (soloNum == 0) {

        printf("\nLa marca debe ser ingresada con un numero.");
        printf("\nReingrese: ");
        fflush(stdin);
        gets(auxNum);

        soloNum = soloNumeros(auxNum);

    }

    marca = validarRangoInt(atoi(auxNum), 1, 4);

    switch (marca)
    {
        case 1:
            autos[libre].marca = FIAT;
            break;
        case 2:
            autos[libre].marca = PEUGEOT;
            break;
        case 3:
            autos[libre].marca = FORD;
            break;
        case 4:
            autos[libre].marca = OTRO;
            break;
    }

    // Ingreso de modelo

    printf("\nIngrese el modelo: ");
    fflush(stdin);
    gets(autos[libre].modelo);

    soloEsp = soloEspacios(autos[libre].modelo);
    espConsec = espaciosConsecutivos(autos[libre].modelo);

    while (soloEsp == 1 || espConsec == 1) {

        if (soloEsp == 1) {

            printf("\nError. El modelo debe contener al menos un caracter.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(autos[libre].modelo);

        }

        if (espConsec == 1) {

            printf("\nError. No puede haber dos espacios consecutivos.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(autos[libre].modelo);

        }

        soloEsp = soloEspacios(autos[libre].modelo);
        espConsec = espaciosConsecutivos(autos[libre].modelo);

    }

    // Ingreso de profesor

    printf("\nIngrese el identificador numerico del profesor: ");
    fflush(stdin);
    gets(auxNum);

    soloNum = soloNumeros(auxNum);
    repetido = numRepetido(atoi(auxNum), autos, A);

    while (soloNum == 0 || repetido == 1) {

        if (soloNum == 0) {

            printf("\nEl identificador debe ser un numero.");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(auxNum);

        }

        if (repetido == 1) {

            printf("\nEl identificador pertenece a otro profesor.");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(auxNum);

        }

        soloNum = soloNumeros(auxNum);
        repetido = numRepetido(atoi(auxNum), autos, A);

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

    for (i = 0; i < tam; i++) {

        if (autos[i].profesor == num && autos[i].estado == 1) {

            return 1;

        }

    }

    return 0;

}

int numRepetidoEspera(int num, sEspera espera[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (espera[i].profesor == num && espera[i].estado == 1) {

            return 1;

        }

    }

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
