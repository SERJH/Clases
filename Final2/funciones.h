#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define AMOLADORA 1
#define MEZCLADORA 2
#define TALADRO 3

#define ALQUILADO 1
#define FINALIZADO 0

#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"

typedef struct {

    int dni;
    int turno;

} sTramite;

typedef struct {

    int id;
    int dni;
    char nombre[31];
    char apellido[31];
    int estado;

} sCliente;

typedef struct {

    int idCliente;
    int equipo;
    int tiempoEstimado;
    int tiempoReal;
    char operador[31];
    int estado;

} sAlquiler;

typedef struct {

 char date[11];
 char time[6];
 int serviceId;
 int gravedad;
 char msg[65];

} S_LogEntry;

typedef struct {

 int id;
 char name[33];
 char email[65];

} S_Service;

typedef struct{

    char nombre[50];
    char apellido[50];
    float sueldo;
    int sector;
    int vacio;

} sEmpleado;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int compararTramitePorDNI(void* pTramiteA, void* pTramiteB);
 void printTramiteArray(ArrayList* arrList);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void printEmpleado(sEmpleado* empleado);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void printArrayListEmpleados(ArrayList* arrList);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int compararEmpleadoPorSueldo(void* pEmpleadoA,void* pEmpleadoB);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int nombreRepetido(ArrayList* arrList, char cad[]);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int setSueldo(ArrayList* arrList, float sueldo);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

float getSueldo(ArrayList* arrList);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

sEmpleado* nuevoEmpleado();

sTramite* nuevoTramite(int dni, int turno);

/** \brief Checkea si un caracter es letra o numero
  *
  * \param Caracter a checkear
  *
  * \return 1 si lo es, 0 de lo contrario
  */

void parseoServices(ArrayList* services);
S_Service* nuevoService();
S_Service* nuevoServiceParam(int id, char nombre[], char mail[]);

int esLetraoNum(char a);

/** \brief Checkea si un caracter es letra
 *
 * \param Caracter a checkear
 *
 * \return 1 si lo es, 0 de lo contrario
 *
 */

int esLetra(char a);

/** \brief Checkea si un caracter es numero
 *
 * \param Caracter a checkear
 *
 * \return 1 si lo es, 0 de lo contrario
 */

int esNum(char a);

/** \brief Valida entrada de string
 *
 * \return Cadena validada
 */

char* getString();

/** \brief Valida entrada de string con numeros
 *
 * \return Cadena validada
 */

char* getStringNum();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int getInt();

/** \brief Valida entrada de un entero con rango
 *
 * \param Rango minimo
 * \param Rango maximo
 *
 * \return Entero validado
 */

int getIntRange(int min, int max);

/** \brief Comprueba si en una cadena solo hay espacios
 *
 * \return 1 si hay solo espacios, 0 de lo contrario
 */

int soloEspacios();

/** \brief Comprueba si en una cadena solo hay letras (o espacios)
 *
 * \return 1 si hay solo hay letras (o espacios), 0 de lo contrario
 */

int soloLetras();

/** \brief Comprueba si en una cadena solo hay letras o numeros (o espacios)
 *
 * \return 1 si hay solo hay letras o numeros (o espacios), 0 de lo contrario
 */

int soloLetrasONum();

/** \brief Comprueba si en una cadena solo hay numeros
 *
 * \return 1 si hay solo hay numeros, 0 de lo contrario
 */

int soloNumeros();

/** \brief Muestra el menu principal
 *
 * \return No devuelve nada
 */

void mostrarMenu();

/** \brief Comprueba si un numero en un rango especificado
 *
 * \param Numero a validar
 * \param Rango minimo
 * \param Rango maximo
 *
 * \return 1 si esta dentro del rango, 0 de lo contrario
 */

int validarRangoInt(int num, int min, int max);

/** \brief Comprueba si un titulo esta repetido
 *
 * \param Puntero de peliculas
 * \param Cantidad de peliculas
 * \param Cadena a checkear
 *
 * \return 1 si se repite, 0 de lo contrario
 */

int nombreRepetido(ArrayList* arrList, char cad[]);

#endif // FUNCIONES_H_INCLUDED



