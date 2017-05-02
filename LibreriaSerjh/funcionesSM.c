#include "funcionesSM.h"

void mostrarMenu() {

    printf("1- Alta abonado\n");
    printf("2- Modificar datos abonado\n");
    printf("3- Baja del abonado\n");
    printf("4- Nueva llamada\n");
    printf("5- Fin llamada\n");
    printf("6- Informar\n");
    printf("7- Salir\n");

    printf("\nIngrese la opcion deseada: ");

}

void startupVector(sAbonado abonados[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        abonados[i].ID = i+1;
//        abonados[i].estado = 0;

    }

}

void invertirString(char string[]) {

    int i, j;
    int lenght;
    char aux;

    lenght = strlen(string);

    j = (lenght - 1);

    if (lenght != 1) {

        for (i = 0; i <= j-1; i++) {

            aux = string[i];
            string[i] = string[j];
            string[j] = aux;

            j--;

        }

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

int numRepetido(int num, sAbonado abonados[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (abonados[i].ID == num && abonados[i].estado == 1) {

            return 1;

        }

    }

    return 0;

}

int obtenerEspacioLibre(sAbonado abonados[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (abonados[i].estado == 0) {

            return i;

        }

    }

    return -1;

}

void modificarAbonado(sAbonado abonados[], int index) {

    int soloLet;
    int soloEsp;

    // Ingreso de nombre

    printf("\nIngrese el nuevo nombre del abonado: ");
    fflush(stdin);
    gets(abonados[index].nombre);

    soloLet = soloLetras(abonados[index].nombre);
    soloEsp = soloEspacios(abonados[index].nombre);

    while ((soloLet == 0) || (soloEsp == 1)) {

        if (soloEsp == 1) {

            printf("\nError. El nombre debe contener al menos una letra.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(abonados[index].nombre);

        } else {

            printf("\nError. El nombre solo puede contener letras y espacios.\n");
            printf("Reingrese: ");
            fflush(stdin);
            gets(abonados[index].nombre);

        }

        soloLet = soloLetras(abonados[index].nombre);
        soloEsp = soloEspacios(abonados[index].nombre);

    }

    // Ingreso de apellido

    printf("\nIngrese el nuevo apellido del abonado: ");
    fflush(stdin);
    gets(abonados[index].apellido);

    soloLet = soloLetras(abonados[index].apellido);
    soloEsp = soloEspacios(abonados[index].apellido);

    while ((soloLet == 0) || (soloEsp == 1)) {

        if (soloEsp == 1) {

            printf("\nError. El apellido debe contener al menos una letra.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(abonados[index].apellido);

        } else {

            printf("\nError. El apellido solo puede contener letras y espacios.\n");
            printf("Reingrese: ");
            fflush(stdin);
            gets(abonados[index].apellido);

        }

        soloLet = soloLetras(abonados[index].apellido);
        soloEsp = soloEspacios(abonados[index].apellido);

    }

    printf("\nSe han modificado con exito los datos del abonado numero %i.\n", abonados[index].ID);

}

void altaAbonado(sAbonado abonados[]) {

    char auxNum[25];
    int index;
    int minID = 1;
    int maxID = 20;
    int soloLet;
    int soloEsp;
    int soloNum;
    int validNum;
    int repetido;

    // Ingreso de ID

    index = cargarID(abonados);
    sprintf(auxNum, "%d", index + 1);

    soloNum = soloNumeros(auxNum);
    validNum = validarRangoInt(atoi(auxNum), minID, maxID);
    repetido = dniRepetido(atoi(auxNum), abonados, A);

    while (soloNum == 0 || validNum == 0 || repetido == 1) {

        if (repetido == 1 || index == -1) {

            printf("\nEl ID ingresado ya esta en uso.");
            printf("\nReingrese: ");
            gets(auxNum);

        } else {

            printf("\nEl ID debe ser un numero entre %i y %i.", minID, maxID);
            printf("\nReingrese: ");
            gets(auxNum);

        }

        soloNum = soloNumeros(auxNum);
        validNum = validarRangoInt(atoi(auxNum), minID, maxID);
        repetido = dniRepetido(atoi(auxNum), abonados, A);

    }

    index = atoi(auxNum) - 1;
    abonados[index].ID = atoi(auxNum);

    // Ingreso de telefono

    printf("\nIngrese el telefono: ");
    gets(auxNum);

    soloNum = soloNumeros(auxNum);
    validNum = validarRangoInt(atoi(auxNum), minID, maxID);
    repetido = dniRepetido(atoi(auxNum), abonados, A);

    while (soloNum == 0 || validNum == 0 || repetido == 1) {

        if (repetido == 1) {

            printf("\nEl telefono ingresado pertenece a otra persona.");
            printf("\nReingrese: ");
            gets(auxNum);

        } else {

            printf("\nEl ID debe ser un numero entre %i y %i.", minID, maxID);
            printf("\nReingrese: ");
            gets(auxNum);

        }

        soloNum = soloNumeros(auxNum);
        validNum = validarRangoInt(atoi(auxNum), minID, maxID);
        repetido = dniRepetido(atoi(auxNum), abonados, A);

    }

    strcpy(abonados[index].telefono, auxNum);

    // Ingreso de nombre

    printf("\nIngrese el nombre del abonado: ");
    fflush(stdin);
    gets(abonados[index].nombre);

    soloLet = soloLetras(abonados[index].nombre);
    soloEsp = soloEspacios(abonados[index].nombre);

    while ((soloLet == 0) || (soloEsp == 1)) {

        if (soloEsp == 1) {

            printf("\nError. El nombre debe contener al menos una letra.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(abonados[index].nombre);

        } else {

            printf("\nError. El nombre solo puede contener letras y espacios.\n");
            printf("Reingrese: ");
            fflush(stdin);
            gets(abonados[index].nombre);

        }

        soloLet = soloLetras(abonados[index].nombre);
        soloEsp = soloEspacios(abonados[index].nombre);

    }

    // Ingreso de apellido

    printf("\nIngrese el apellido del abonado: ");
    fflush(stdin);
    gets(abonados[index].apellido);

    soloLet = soloLetras(abonados[index].apellido);
    soloEsp = soloEspacios(abonados[index].apellido);

    while ((soloLet == 0) || (soloEsp == 1)) {

        if (soloEsp == 1) {

            printf("\nError. El apellido debe contener al menos una letra.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(abonados[index].apellido);

        } else {

            printf("\nError. El apellido solo puede contener letras y espacios.\n");
            printf("Reingrese: ");
            fflush(stdin);
            gets(abonados[index].apellido);

        }

        soloLet = soloLetras(abonados[index].apellido);
        soloEsp = soloEspacios(abonados[index].apellido);

    }

    abonados[index].estado = 1;

}

void cargarPersona(sPersona persona[], int libre) {

    int minEdad = 1;
    int maxEdad = 110;
    int minDNI = 5000000;
    int maxDNI = 50000000;
    char auxNum[25];

    printf("\nIngrese el nombre de la persona: ");
    fflush(stdin);
    gets(persona[libre].nombre);

    while ((soloLetras(persona[libre].nombre) == 0) || (soloEspacios(persona[libre].nombre) == 1)) {

        if (soloEspacios(persona[libre].nombre) == 1) {

            printf("\nError. El nombre debe contener al menos una letra.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(persona[libre].nombre);

        } else {

            printf("\nError. El nombre solo puede contener letras y espacios.\n");
            printf("Reingrese: ");
            fflush(stdin);
            gets(persona[libre].nombre);

        }

    }

    printf("\nIngrese la edad de %s: ", persona[libre].nombre);
    gets(auxNum);

    while (soloNumeros(auxNum) == 0 || validarRangoInt(atoi(auxNum), minEdad, maxEdad) == 0) {

        printf("\nLa edad debe ser un numero entre %i y %i.", minEdad, maxEdad);
        printf("\nReingrese: ");
        gets(auxNum);

    }

    persona[libre].edad = atoi(auxNum);

    printf("\nIngrese el DNI de %s: ", persona[libre].nombre);
    gets(auxNum);

    while (soloNumeros(auxNum) == 0 || validarRangoInt(atoi(auxNum), minDNI, maxDNI) == 0 || (dniRepetido(atoi(auxNum), persona, A) == 1)) {

        if (dniRepetido(atoi(auxNum), persona, A) == 1) {

            printf("\nEl DNI ingresado pertenece a otra persona.");
            printf("\nReingrese: ");
            gets(auxNum);

        } else {

            printf("\nEl DNI debe ser un numero entre %i y %i.", minDNI, maxDNI);
            printf("\nReingrese: ");
            gets(auxNum);

        }

    }

    persona[libre].dni = atoi(auxNum);
    persona[libre].estado = 1;

}

int masReclamos(sAbonado abonados[], sLlamada llamadas[], int tam1, int tam2) {

    int i, j;
    int mayor;
    int mayoresReclamos;
    int cant[20] = {0};
    int first = 0;

    for (i = 0; i < tam1; i++) {

        for (j = 0; j < tam2; j++) {

            if (llamadas[j].ID == abonados[i].ID) {

                cant[i]++;

            }

        }

        if (first == 0) {

            first = 1;
            mayor = cant[i];
            mayoresReclamos = i;

        } else {

            if (cant[i] > mayor) {

                mayor = cant[i];
                mayoresReclamos = i;

            }

        }

    }

    printf("\nMayor reclamador: %s %s\n", abonados[mayoresReclamos].nombre, abonados[mayoresReclamos].apellido);

}

int cargarID(sAbonado abonados[]) {

    int i;
    int num;
    int minNum = 1;
    int maxNum = 20;
    char numC[15];

    printf("\nIngrese el ID (1-20): ");
    gets(numC);

    while (soloNumeros(numC) == 0 || validarRangoInt(atoi(numC), minNum, maxNum) == 0) {

        printf("\nEl ID debe ser un numero entre %i y %i.", minNum, maxNum);
        printf("\nReingrese: ");
        gets(numC);

    }

    num = atoi(numC);


    if (abonados[num-1].ID == num && abonados[num-1].estado == 0) {

        return num - 1;

    }

    return -1;

}

int buscarPorNumero(sAbonado abonados[], int tam) {

    int i;
    int num;
    int minNum = 1;
    int maxNum = 20;
    char numC[15];

    printf("\nIngrese el ID (1-20): ");
    gets(numC);

    while (soloNumeros(numC) == 0 || validarRangoInt(atoi(numC), minNum, maxNum) == 0) {

        printf("\nEl ID debe ser un numero entre %i y %i.", minNum, maxNum);
        printf("\nReingrese: ");
        gets(numC);

    }

    num = atoi(numC);

    for (i = 0; i < tam; i++) {

        if (abonados[i].ID == num && abonados[i].estado == 1) {

            return i;

        }

    }

    return -1;

}

char confirmarBorrado(sAbonado abonados[], int index) {

    char opcionBorrar;

    printf("\n%cEsta seguro que desea borrar a %s? (S/N): ", 168, abonados[index].nombre);
    opcionBorrar = tolower(getche());
    opcionBorrar = validarChar(opcionBorrar, 's', 'n');

    return opcionBorrar;

}

void borrarPersona(sAbonado abonados[], int index) {

    abonados[index].estado = 0;
    printf("\n\nSe ha eliminado con exito a %s.\n", abonados[index].nombre);

}

void nuevaLlamada(sAbonado abonados[], sLlamada llamadas[], int tam1, int tam2) {

    int cliente, libre, motivo;

    printf("\nSe ha iniciado una nueva llamada.\n");

    cliente = buscarPorNumero(abonados, tam1);

    if (cliente != -1) {

        libre = obtenerEspacioLibre2(llamadas, tam2);

        if (libre != -1) {

            llamadas[libre].ID = abonados[cliente].ID;

            printf("\nIngrese el motivo de la llamada.\n");
            printf("(1- FALLA 3G | 2- FALLA LTE | 3- FALLA EQUIPO): ");
            scanf("%i", &motivo);

            switch (motivo)
            {
                case 1:
                    strcpy(llamadas[libre].motivo, "FALLA 3G");
                    break;
                case 2:
                    strcpy(llamadas[libre].motivo, "FALLA LTE");
                    break;
                case 3:
                    strcpy(llamadas[libre].motivo, "FALLA EQUIPO");
                    break;
            }

            strcpy(llamadas[libre].estado, D);

        }

    } else {

        printf("\nNo se encontro al abonado solicitado.\n");

    }

}

void finLlamada(sLlamada llamadas[], int tam) {

    int call;
    int tiempo;
    int opcion;

    call = buscarPorNumero2(llamadas, tam);

    if (call != -1) {

        printf("\nIngrese el tiempo que tomo la llamada: ");
        scanf("%i", &llamadas[call].tiempo);

        printf("\nIngrese el estado de la llamada al finalizar.");
        printf("\n(1- SOLUCIONADO | 2- NO SOLUCIONADO): ");
        scanf("%i", &opcion);

        switch (opcion)
        {
            case 1:
                strcpy(llamadas[call].estado, E);
                break;
            case 2:
                strcpy(llamadas[call].estado, F);
                break;
        }

    } else {

        printf("\nNo hay ninguna llamada en curso con esa ID.");

    }

}

int hayPersonas(sPersona personas[], int tam) {

    int i;
    int hay = 0;

    for (i = 0; i < tam; i++) {

        if (personas[i].estado == 1) {

            hay = 1;
            return hay;

        }

    }

    printf("\nNo hay ninguna persona en el sistema.");
    printf("\nPor favor utilize la opcion 1 para cargar una y vuelva a intentar.\n");

    return hay;

}

void mostrarLista(sPersona personas[], int tam) {

    int i, j;
    sPersona personasOrdenadas[tam];
    sPersona auxPersona[tam];

    for (i = 0; i < tam; i++) {

        personasOrdenadas[i] = personas[i];

    }

    for (i = 0; i < (tam - 1); i++) {

        for (j = i+1; j < tam; j++) {

            if (strcmp(personasOrdenadas[i].nombre, personasOrdenadas[j].nombre) == 1) {

                auxPersona[i] = personasOrdenadas[i];
                personasOrdenadas[i] = personasOrdenadas[j];
                personasOrdenadas[j] = auxPersona[i];

            }

        }

    }

    printf("\n\t\tNombre\t\t\tEdad\tDNI\n");

    for (i = 0; i < tam; i++) {

        if (personasOrdenadas[i].estado == 1) {

            if (strlen(personasOrdenadas[i].nombre) < 8) {

                printf("\n%s\t\t\t\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else if (strlen(personasOrdenadas[i].nombre) < 16) {

                printf("\n%s\t\t\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else if (strlen(personasOrdenadas[i].nombre) < 24) {

                printf("\n%s\t\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else if (strlen(personasOrdenadas[i].nombre) < 32){

                printf("\n%s\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else {

                printf("\n%s\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            }

        }

    }

}

void imprimirGrafico(sPersona personas[], int tam) {

    int i, j;

    int menores = 0;
    int media = 0;
    int mayores = 0;
    int max;

    char barra = 219;
    char graph[20][3];

    // Cantidad de personas en cada grupo de edad

    for (i = 0; i < tam; i++) {

        if (personas[i].edad < 18 && personas[i].estado == 1) {

            menores++;

        } else if (personas[i].edad >= 18 && personas[i].edad < 35 && personas[i].estado == 1) {

            media++;

        } else if (personas[i].estado == 1) {

            mayores++;

        }

    }

    // Encuentro el maximo para no dibujar lineas de mas

    if (menores >= media && menores >= mayores) {

        max = menores;

    } else if (media >= menores && media >= mayores) {

        max = media;

    } else if (mayores >= menores && mayores >= media) {

        max = mayores;

    }

    // Dibujar una barra donde corresponda en la matriz del grafico

    for (i = 0; i < 20; i++) {

        if (i < menores) {

            graph[i][0] = barra;

        }

        if (i < media) {

            graph[i][1] = barra;

        }

        if (i < mayores) {

            graph[i][2] = barra;

        }

    }

    // Printear el grafico terminado

    for (i = (max - 1); i >= 0; i--) {

        if (i < 9) {

            printf("\n0%i|\t", i+1);

        } else {

            printf("\n%i|\t", i+1);

        }

        for (j = 0; j < 3; j++) {

            if (graph[i][j] == barra) {

                printf("%c", graph[i][j]);

            }

            printf("\t");

        }

    }

    printf("\n--|---------------------------");

    printf("\n\t<18\t18-35\t>35");

    printf("\n\nCant:\t%i\t%i\t%i", menores, media, mayores);
}
