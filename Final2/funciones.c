#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"

void mostrarMenu() {

    printf("\n\n\t\t\t\t~ Bienvenido ~\n\n");

    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");

    printf("\nIngrese la opcion deseada: ");

}

// Print Empleado

void printTramite(sTramite* tramite) {

    printf("TURNO: %i\tDNI: %i\n", tramite->turno, tramite->dni);

}

// Print ArrayList Empleados

void printTramiteArray(ArrayList* arrList) {

    int i;
    int tam;

    if (arrList != NULL) {

        tam = arrList->len(arrList);

        for (i = 0; i < tam; i++) {

            sTramite* aux = arrList->get(arrList,i);
            printTramite(aux);

        }

    }

}

// Comparar por atributo

int compararTramitePorDNI(void* pTramiteA, void* pTramiteB) {

    if(((sTramite*)pTramiteA)->dni > ((sTramite*)pTramiteB)->dni) {

        return 1;

    }

    if(((sTramite*)pTramiteA)->dni < ((sTramite*)pTramiteB)->dni) {

        return -1;

    }

    return 0;
}

// Atributo repetido

int nombreRepetido(ArrayList* arrList, char cad[]) {

    int i;
    int tam;

    if (arrList != NULL) {

        tam = arrList->len(arrList);

        for (i = 0; i < tam; i++) {

            if (strcmpi(cad, ((sEmpleado*)arrList->pElements[i])->nombre == 0)) {

                return 1;

            }

        }

    }

    return 0;
}

// Setter

int setSueldo(ArrayList* arrList, float sueldo) {

    int i;
    int tam;
    int indice;
    int retorno = -1;

    if (arrList != NULL) {

        tam = arrList->len(arrList);
        printf("Lista: \n");

        for (i = 0; i < tam; i++) {

            printf("\n%i- %s", i, ((sEmpleado*)arrList->pElements[i])->nombre);

        }

        //printf("\nIngrese la persona deseada segun su indice %i-%i: ", 0, tam-1);
        indice = getIntRange(0, tam-1);

        ((sEmpleado*)arrList->pElements[indice])->sueldo = sueldo;

        retorno = 0;

    }

    return retorno;

}

// Getter

float getSueldo(ArrayList* arrList) {

    int i;
    int tam;
    int indice;
    void* aux;
    float retorno = -1;

    if (arrList != NULL) {

        tam = arrList->len(arrList);
        printf("Lista: \n");

        for (i = 0; i < tam; i++) {

            printf("\n%i- %s", i, ((sEmpleado*)arrList->pElements[i])->nombre);

        }

        //printf("\nIngrese la persona deseada segun su indice %i-%i: ", 0, tam-1);
        indice = getIntRange(0, tam-1);

        aux = arrList->get(arrList, indice);

        if (aux != NULL) {

            retorno = ((sEmpleado*)aux)->sueldo;

        }

    }

    return retorno;
}

// Constructor vacio

sEmpleado* nuevoEmpleado() {

    sEmpleado* returnAux = NULL;
    sEmpleado* pEmpleado = malloc(sizeof(sEmpleado));

    if (pEmpleado != NULL) {

        returnAux = pEmpleado;

    }

    return returnAux;
}

// Constructor parametrizado

sEmpleado* nuevoEmpleadoParam(char nombre[], char apellido[], float sueldo, int sector) {

    sEmpleado* returnAux = NULL;
    sEmpleado* pEmpleado = malloc(sizeof(sEmpleado));

    if(pEmpleado != NULL) {

        strcpy(pEmpleado->nombre, nombre);
        strcpy(pEmpleado->apellido, apellido);
        pEmpleado->sueldo = sueldo;
        pEmpleado->sector = sector;
        pEmpleado->vacio = 0;
        returnAux = pEmpleado;

    }

    return returnAux;
}

sTramite* nuevoTramite(int dni, int turno) {

    sTramite* returnAux = NULL;
    sTramite* pTramite = malloc(sizeof(sTramite));

    if(pTramite != NULL) {

        pTramite->dni = dni;
        pTramite->turno = turno;
        returnAux = pTramite;

    }

    return returnAux;
}

S_LogEntry* nuevoLog() {

    S_LogEntry* returnAux = NULL;
    S_LogEntry* pLog = malloc(sizeof(S_LogEntry));

    if(pLog != NULL) {

        returnAux = pLog;

    }

    return returnAux;
}

S_Service* nuevoService() {

    S_Service* returnAux = NULL;
    S_Service* pService = malloc(sizeof(S_Service));

    if(pService != NULL) {

        returnAux = pService;

    }

    return returnAux;
}

S_LogEntry* nuevoLogParam(char fecha[], char hora[], int serviceId, int gravedad, char msg[]) {

    S_LogEntry* returnAux = NULL;
    S_LogEntry* pLog = nuevoLog();

    if(pLog != NULL) {

        strcpy(pLog->date, fecha);
        strcpy(pLog->time, hora);
        pLog->serviceId = serviceId;
        pLog->gravedad = gravedad;
        strcpy(pLog->msg, msg);
        returnAux = pLog;

    }

    return returnAux;
}

S_Service* nuevoServiceParam(int id, char nombre[], char mail[]) {

    S_Service* returnAux = NULL;
    S_Service* pService = nuevoService();

    if(pService != NULL) {

        pService->id = id;
        strcpy(pService->name, nombre);
        strcpy(pService->email, mail);
        returnAux = pService;

    }

    return returnAux;
}

void parseoLogs(ArrayList* logs) {

    int i;
    char auxFecha[11], auxHora[6], auxServiceId[3], auxGravedad[2], auxMsg[65];
    S_LogEntry* auxLog;
    FILE* aLog;

    if ((aLog = (fopen("log.txt", "r"))) == NULL) {

        printf("\nEl archivo log.txt no puede ser abierto.");
        exit(0);

    } else {

        while (!feof(aLog)) {

            fscanf(aLog, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", auxFecha, auxHora, auxServiceId, auxGravedad, auxMsg);
            auxLog = nuevoLogParam(auxFecha, auxHora, atoi(auxServiceId), atoi(auxGravedad), auxMsg);
            logs->add(logs, auxLog);

        }

    }

    fclose(aLog);
}

void parseoServices(ArrayList* services) {

    int i;
    char auxId[100], auxNombre[33], auxMail[65];
    S_Service* auxService;
    FILE* aService;

    if ((aService = (fopen("services.txt", "r"))) == NULL) {

        printf("\nEl archivo services.txt no puede ser abierto.");
        exit(0);

    } else {

        while (!feof(aService)) {

            fscanf(aService, "%[^;];%[^;];%[^\n]\n", auxId, auxNombre, auxMail);
            auxService = nuevoServiceParam(atoi(auxId), auxNombre, auxMail);
            services->add(services, auxService);

        }

    }

    fclose(aService);
}

int getServiceById(ArrayList* services, int id) {

    int i;
    int tam = al_len(services);

    for (i = 0; i < tam; i++) {

        if (((S_Service*)services->pElements[i])->id == id) {

            return i;

        }

    }

    return -1;
}

void procesarInfo(ArrayList* logs, ArrayList* services) {

    int i, auxId, indexS;
    int tamLogs = al_len(logs);
    int tamServices = al_len(services);
    S_LogEntry* auxLog;
    S_Service* auxService;
    FILE* warnings;
    FILE* errors;

    if ((warnings = (fopen("warnings.txt", "r+"))) == NULL) {

        if ((warnings = (fopen("warnings.txt", "w+"))) == NULL) {

            printf("\El archivo warnings.txt no pudo ser abierto.");
            exit(0);

        }

    } else {

        fseek(warnings, 0L, SEEK_END);

    }

    if ((errors = (fopen("errors.txt", "r+"))) == NULL) {

        if ((errors = (fopen("errors.txt", "w+"))) == NULL) {

            printf("\El archivo errors.txt no pudo ser abierto.");
            exit(0);

        }

    } else {

        fseek(errors, 0L, SEEK_END);

    }

    for (i = 0; i < tamLogs; i++) {

        auxLog = (S_LogEntry*)logs->pElements[i];

        if (auxLog->gravedad == 3 && auxLog->serviceId != 45) {

            auxId = auxLog->serviceId;
            indexS = getServiceById(services, auxId);
            auxService = (S_Service*)services->pElements[indexS];

            fprintf(warnings, "%s;%s;%s;%s;%s\n", auxLog->date, auxLog->time, auxService->name, auxLog->msg, auxService->email);

        }

        if (auxLog->gravedad >= 4 && auxLog->gravedad <= 7) {

            auxId = auxLog->serviceId;
            indexS = getServiceById(services, auxId);
            auxService = (S_Service*)services->pElements[indexS];

            printf("\n%s;%s;%s;%s;%i", auxLog->date, auxLog->time, auxService->name, auxLog->msg, auxLog->gravedad);

        }

        if (auxLog->gravedad > 7) {

            auxId = auxLog->serviceId;
            indexS = getServiceById(services, auxId);
            auxService = (S_Service*)services->pElements[indexS];

            fprintf(errors, "%s;%s;%s;%s;%s\n", auxLog->date, auxLog->time, auxService->name, auxLog->msg, auxService->email);

        }

    }

    fclose(warnings);
    fclose(errors);
}

int masFallos(ArrayList* logs, ArrayList* services) {

    int i, j;
    int auxId;
    int masFallos;
    int cantMasFallos;
    int cantidad = 0;
    int flag = 0;
    int lenL = al_len(logs);
    int lenS = al_len(services);
    S_LogEntry* auxLog;

    for (i = 0; i < lenS; i++) {

        auxId = ((S_Service*)services->pElements[i])->id;

        for (j = 0; j < lenL; j++) {

            auxLog = (S_LogEntry*)logs->pElements[j];

            if (auxLog->serviceId == auxId) {

                cantidad++;

            }

        }

        if (!flag) {

            masFallos = auxId;
            cantMasFallos = cantidad;
            flag = 1;

        } else {

            if (cantidad > cantMasFallos) {

                masFallos = auxId;
                cantMasFallos = cantidad;

            }

        }

        cantidad = 0;
    }

    return masFallos;
}

void cantidadFallos(ArrayList* logs, ArrayList* services) {

    int i;
    int tamL = al_len(logs);
    int idMasFallos = masFallos(logs, services);
    int index = getServiceById(services, idMasFallos);
    S_Service* auxService = (S_Service*)services->pElements[index];
    S_LogEntry* auxLog;
    int id = auxService->id;
    int menor3 = 0;
    int igual3 = 0;
    int entre4y7 = 0;
    int mayor7 = 0;

    printf("\nEl servicio con mas fallos ha sido %s", auxService->name);

    for (i = 0; i < tamL; i++) {

        auxLog = (S_LogEntry*)logs->pElements[i];

        if (auxLog->serviceId == id) {

            if (auxLog->gravedad < 3) {

                menor3++;

            } else if (auxLog->gravedad == 3) {

                igual3++;

            } else if (auxLog->gravedad >= 4 && auxLog->gravedad <= 7) {

                entre4y7++;

            } else {

                mayor7++;

            }

        }

    }

    printf("\nCantidad de fallos segun valor de gravedad:\n");

    printf("\nMenor a 3: %i", menor3);
    printf("\nIgual a 3: %i", igual3);
    printf("\nEntre 4 y 7 (inclusive): %i", entre4y7);
    printf("\nMayor a 7: %i\n", mayor7);

}

char* getString() {

    char cadena[250];

    printf("\nIngrese una string (solo letras y espacios): ");
    fflush(stdin);
    gets(cadena);

    int soloEsp = soloEspacios(cadena);
    int soloLet = soloLetras(cadena);

    while (soloEsp || !soloLet) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

        soloEsp = soloEspacios(cadena);
        soloLet = soloLetras(cadena);

    }

    return cadena;
}

char* getStringNum() {

    char cadena[250];

    printf("\nIngrese una string (solo letras, espacios o numeros): ");
    fflush(stdin);
    gets(cadena);

    int soloEsp = soloEspacios(cadena);
    int soloLetNum = soloLetrasONum(cadena);

    while (soloEsp || !soloLetNum) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

        soloEsp = soloEspacios(cadena);
        soloLetNum = soloLetrasONum(cadena);

    }

    return cadena;
}

int getIntRange(int min, int max) {

    char cadena[250];

    fflush(stdin);
    gets(cadena);

    int soloNum = soloNumeros(cadena);
    int valid = validarRangoInt(atoi(cadena), min, max);

    while (!soloNum || !valid) {

        printf("Entrada invalida. Reingrese (%i - %i): ", min, max);
        fflush(stdin);
        gets(cadena);

        soloNum = soloNumeros(cadena);
        valid = validarRangoInt(atoi(cadena), min, max);

    }

    return atoi(cadena);
}

int getInt() {

    char cadena[250];

    printf("\nIngrese un numero: ");
    fflush(stdin);
    gets(cadena);

    int soloNum = soloNumeros(cadena);

    while (!soloNum) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

        soloNum = soloNumeros(cadena);

    }

    return atoi(cadena);
}

int validarRangoInt(int num, int min, int max) {

    if (num >= min && num <= max) {

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

int soloLetrasONum(char nombre[]) {

    int i;
    int testLetra;
    int cantString = strlen(nombre);

    for (i = 0; i < cantString; i++) {

        testLetra = esLetraoNum(nombre[i]);

        if (testLetra == 1) {

            if (i == (cantString - 1)) {

                return 1;

            }

        } else {

            return 0;

        }

    }

}

int esLetraoNum(char a) {

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165) || (a == 32) || (a >= 48 && a <= 57)) {

        return 1;

    } else {

        return 0;

    }

}

int esLetra(char a) {

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165) || (a == 32)) {

        return 1;

    } else {

        return 0;

    }

}

int esNum(char a) {

    if (a >= 48 && a <= 57) {

        return 1;

    } else {

        return 0;

    }

}

sCliente* nuevoCliente() {

    sCliente* returnAux = NULL;
    sCliente* pCliente = (sCliente*)malloc(sizeof(sCliente));

    if (pCliente != NULL) {

        returnAux = pCliente;

    }

    return returnAux;
}

sCliente* nuevoClienteParam(int id, int dni, char nombre[], char apellido[]) {

    sCliente* returnAux = NULL;
    sCliente* pCliente = nuevoCliente();

    if(pCliente != NULL) {

        pCliente->id = id;
        pCliente->dni = dni;
        strcpy(pCliente->nombre, nombre);
        strcpy(pCliente->apellido, apellido);
        pCliente->estado = 1;
        returnAux = pCliente;

    }

    return returnAux;
}

void altaCliente(ArrayList* clientes) {

    int tam = al_len(clientes);
    int id;
    int dni;
    char nombre[31];
    char apellido[31];
    sCliente* auxCliente;

    id = tam+1;

    printf("\nIngrese el DNI del cliente (5.000.000 - 50.000.000): ");
    dni = getIntRange(5000000, 50000000);

    printf("\Ingrese el nombre del cliente: ");
    fflush(stdin);
    gets(nombre);

    printf("\nIngrese el apellido del cliente: ");
    fflush(stdin);
    gets(apellido);

    auxCliente = nuevoClienteParam(id, dni, nombre, apellido);

    if (auxCliente != NULL) {

        clientes->add(clientes, auxCliente);

    }
}

void modificarCliente(ArrayList* clientes) {

    int i;
    int tam = al_len(clientes);
    int eleccion;
    int index;
    char nombre[31];
    char apellido[31];
    sCliente* auxCliente;

    printf("\nLista de clientes:\n");
    printf("\nID\tNOMBRE\tAPELLIDO\n");

    for (i = 0; i < tam; i++) {

        auxCliente = (sCliente*)clientes->pElements[i];
        if (auxCliente->estado != 0) {

            printf("\n%i\t%s\t%s", auxCliente->id, auxCliente->nombre, auxCliente->apellido);

        }

    }

    printf("\nIngrese el ID del cliente a modificar: ");
    eleccion = getInt();
    if ((index = getIndexById(clientes, eleccion)) != -1) {

        printf("\nIngrese el nuevo nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("\nIngrese el nuevo apellido: ");
        fflush(stdin);
        gets(apellido);

        strcpy(((sCliente*)(clientes->pElements[index]))->nombre, nombre);
        strcpy(((sCliente*)(clientes->pElements[index]))->apellido, apellido);

        printf("\nDatos modificados con exito");

    } else {

        printf("\nNo se encontro un cliente con el ID especificada");

    }
}

void bajaCliente(ArrayList* clientes) {

    int i;
    int eleccion;
    int index;
    int tam = al_len(clientes);
    sCliente* auxCliente;

    printf("\nLista de clientes:\n");
    printf("\nID\tNOMBRE\tAPELLIDO\n");

    for (i = 0; i < tam; i++) {

        auxCliente = (sCliente*)clientes->pElements[i];
        if (auxCliente->estado != 0) {

            printf("\n%i\t%s\t%s", auxCliente->id, auxCliente->nombre, auxCliente->apellido);

        }

    }

    printf("\nIngrese el ID del cliente a dar de baja: ");
    eleccion = getInt();

    if ((index = getIndexById(clientes, eleccion)) != -1) {

        ((sCliente*)clientes->pElements[index])->estado = 0;

    } else {

        printf("\nNo se encontro un cliente con el ID especificado");

    }
}

int getIndexById(ArrayList* clientes, int id) {

    int i;
    int tam = al_len(clientes);
    sCliente* auxCliente;

    for (i = 0; i < tam; i++) {

        auxCliente = (sCliente*)clientes->pElements[i];

        if (auxCliente->id == id) {

            return i;

        }

    }

    return -1;
}

int getIndexByIdAlquiler(ArrayList* alquileres, int id) {

    int i;
    int tam = al_len(alquileres);
    sAlquiler* auxAlquiler;

    for (i = 0; i < tam; i++) {

        auxAlquiler = (sAlquiler*)alquileres->pElements[i];

        if (auxAlquiler->idCliente == id) {

            return i;

        }

    }

    return -1;
}

sAlquiler* newAlquiler() {

    sAlquiler* returnAux = NULL;
    sAlquiler* pAlquiler = (sAlquiler*)malloc(sizeof(sAlquiler));

    if (pAlquiler != NULL) {

        returnAux = pAlquiler;

    }

    return returnAux;
}

sAlquiler* newAlquilerParam(int idCliente, int equipo, int tiempoEst, char operador[]) {

    sAlquiler* returnAux = NULL;
    sAlquiler* pAlquiler = newAlquiler();

    if (pAlquiler != NULL) {

        pAlquiler->idCliente = idCliente;
        pAlquiler->equipo = equipo;
        pAlquiler->tiempoEstimado = tiempoEst;
        strcpy(pAlquiler->operador, operador);
        pAlquiler->estado = ALQUILADO;
        returnAux = pAlquiler;
    }

    return returnAux;
}

void nuevoAlquiler(ArrayList* clientes, ArrayList* alquileres) {

    int i;
    int eleccion;
    int existe;
    int equipo;
    int tiempoEst;
    char operador[31];
    int tamC = al_len(clientes);
    sCliente* auxCliente;
    sAlquiler* auxAlquiler;

    printf("\nLista de clientes:\n");

    printf("\nID\tNOMBRE\tAPELLIDO\n");

    for (i = 0; i < tamC; i++) {

        auxCliente = (sCliente*)clientes->pElements[i];

        if (auxCliente->estado != 0) {

            printf("\n%i\t%s\t%s", auxCliente->id, auxCliente->nombre, auxCliente->apellido);

        }

    }

    printf("\nElija el ID del cliente que realizara el alquiler: ");
    eleccion = getInt();
    existe = getIndexById(clientes, eleccion);

    if (existe != -1) {

        printf("\nIngrese el equipo a alquilar (1- AMOLADORA | 2- MEZCLADORA | 3- TALADRO): ");
        equipo = getIntRange(1, 3);

        printf("\nIngrese el tiempo de alquiler estimado (en dias): ");
        tiempoEst = getIntRange(1, 365);

        printf("\nIngrese el nombre del operador del alquiler: ");
        fflush(stdin);
        gets(operador);

        auxAlquiler = newAlquilerParam(eleccion, equipo, tiempoEst, operador);

        if (auxAlquiler != NULL) {

            alquileres->add(alquileres, auxAlquiler);

        }

    } else {

        printf("\nNo se ha encontrado un cliente con el ID especificado");

    }

}

void finAlquiler(ArrayList* alquileres) {

    int i;
    int eleccion;
    int index;
    int tiempo;
    int tam = al_len(alquileres);
    sAlquiler* auxAlquiler;

    printf("\nLista de alquileres activos: ");

    printf("\nID CLI\tOPERADOR\n");

    for (i = 0; i < tam; i++) {

        auxAlquiler = (sAlquiler*)alquileres->pElements[i];
        if (auxAlquiler->estado != FINALIZADO) {

            printf("\n%i\t%s", auxAlquiler->idCliente, auxAlquiler->operador);

        }

    }

    printf("\nIngrese el ID de cliente del alquiler a finalizar: ");
    eleccion = getInt();
    index = getIndexByIdAlquiler(alquileres, eleccion);

    if (index != -1) {

        printf("\nIngrese el tiempo real de alquiler: ");
        tiempo = getIntRange(1, 365);

        ((sAlquiler*)alquileres->pElements[index])->tiempoReal = tiempo;
        ((sAlquiler*)alquileres->pElements[index])->estado = FINALIZADO;

    } else {

        printf("\nNo se ha encontrado un alquiler con ese ID de cliente");

    }
}

// Esqueleto menu

//int main()
//{
//    int seguir = 1;
//    int opcion;
//
//    while (seguir == 1) {
//
//        printf("\n\t\t~ Bienvenido ~\n\n");
//
//        printf("1- Tramite urgente\n");
//        printf("2- Tramite regular\n");
//        printf("3- Proximo cliente\n");
//        printf("4- Listar\n");
//        printf("5- Informar\n");
//        printf("6- Salir\n");
//
//        printf("\nIngrese la opcion deseada: ");
//        opcion = getIntRange(1, 6);
//
//        switch (opcion)
//        {
//            case 1:
//
//                break;
//
//            case 2:
//
//                break;
//
//            case 3:
//
//                break;
//
//            case 4:
//
//                break;
//
//            case 5:
//
//                break;
//
//            case 6:
//
//                seguir = 0;
//                break;
//
//        }
//
//    printf("\n");
//    system("pause");
//    system("cls");
//
//    }
//
//    return 0;
//}


