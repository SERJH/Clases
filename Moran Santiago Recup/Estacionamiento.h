

typedef struct {

    char patente[30];
    char modelo[30];
    int marca;
    int profesor;
    int estado;

} sAuto;

typedef struct {

    int profesor;
    int estado;

} sEstacionamiento;

typedef struct {

    int profesor;
    int estado;

} sEspera;

typedef struct {

    int profesor;
    int estado;

} sEstacionado;

/** \brief Muestra el menu principal
  *
  *  \param No lleva parametros
  *
  *  \return No devuelve nada
  */

void mostrarMenu();

/** \brief Inicializa los vectores
  *
  * \param Vector autos
  * \param Vector lugares en estacionamiento
  * \param Vector espera
  * \param Vector estacionado
  * \param Vector profesores
  * \param tamaño 1
  * \param tamaño 2
  *
  * \return No devuelve nada
  */

  void startupVector(sAuto autos[], sEstacionamiento lugaresEst[], sEspera enEspera[], sEstacionado estacionado[], int profesoresE[], int tam1, int tam2);

/** \brief Valida un entero para que solo pueda estar entre un determinado rango ingresado
  *
  * \param Minimo
  * \param Maximo
  *
  *\return Devuelve el entero validado
  */

int validarRangoInt(int num, int min, int max);

/** \brief Checkea si una string esta repetida
 *
 * \param String
 * \param Vector auto
 * \param Tamaño
 *
 * \return Devuelve 1 si esta repetida, 0 de lo contrario
 */

int stringRepetida(char string[], sAuto autos[], int tam);

/** \brief Comprueba si la cadena ingresada contiene solo espacios
  *
  * \param Cadena a checkear
  *
  * \return
  */

int soloEspacios(char nombre[]);

/** \brief Comprueba si la cadena ingresada contiene solo letras (y espacios)
  *
  * \param Cadena a checkear
  *
  * \return Devuelve 1 si son todas letras (y espacios) y 0 de lo contrario
  */

int soloLetras(char nombre[]);

/** \brief Comprueba si un caracter ingresado es una letra (o espacio)
  *
  * \param Caracter a checkear
  *
  * \return Devuelve 1 si es una letra (o espacio) y 0 de lo contrario
  */

int esLetra(char a);

/** \brief Comprueba si un caracter ingresado es una letra
 *
 * \param Caracter a checkear
 *
 * \return
 */

int esLetraStrict(char a);

/** \brief Comprueba si la cadena ingresada contiene solo numeros
  *
  * \param Cadena a checkear
  *
  * \return Devuelve 1 si son todos numeros y 0 de lo contrario
  */

int soloNumeros(char num[]);

/** \brief Comprueba si un caracter ingresado es un numero
  *
  * \param Caracter a checkear
  *
  * \return Devuelve 1 si es un numero y 0 de lo contrario
  */

int esNum(char a);

/** \brief Valida un caracter ingresado para que solo pueda ser una de las dos opciones dadas
  *
  * \param Caracter a validar
  * \param Posible caracter opcion 1
  * \param Posible caracter opcion 2
  *
  * \return Devuelve el caracter validado
  */

/** \brief Egresa un auto del estacionamiento
 *
 * \param Vector lugares en estacionamiento
 * \param Vector autos
 * \param Vector espera
 * \param Vector estacionado
 *
 * \return No devuelve nada
 */

void egresoAutomovil(sEstacionamiento lugaresEst[], sAuto autos[], sEspera espera[], sEstacionado estacionado[]);

/** \brief Confirma un borrado
 *
 * \return Devuelve la opcion elegida (Si o no)
 */

char confirmarBorrado();

/** \brief Da de baja un profesor
 *
 * \param Profesor
 * \param Vector autos
 * \param Tamaño
 *
 * \return
 */

void borrarProfesor(int profesor, sAuto autos[], int tam);

/** \brief Ingresa un auto al estacionamiento
 *
 * \param Vector lugares en estacionamiento
 * \param Vector autos
 * \param Vector espera
 * \param Vector estacionado
 *
 * \return No devuelve nada
 */

void ingresoAutomovil(sEstacionamiento lugaresEst[], sAuto autos[], sEspera espera[], sEstacionado estacionado[]);

/** \brief Valida un caracter ingresado para que sea una de dos opciones
 *
 * \param Caracter ingresado
 * \param Opcion 1
 * \param Opcion 2
 *
 * \return Caracter validado
 */

char validarChar(char caracter, char opcion1, char opcion2);

/** \brief Comprueba si el numero ingresado es un profesor
 *
 * \param Vector profesores
 * \param Tamaño
 * \param Numero
 *
 * \return 1 si es profesor, 0 de lo contrario
 */

int esProfesor(int profesores[], int tam, int num);

/** \brief Comprueba si en una string hay 2 espacios consecutivos
 *
 * \param String a checkear
 *
 * \return 1 si hay 2 espacios consecutivos, 0 de lo contrario
 */

int espaciosConsecutivos(char string[]);

/** \brief Comprueba si una patente ingresada es valida
 *
 * \param Patente
 *
 * \return 1 si es valida, 0 de lo contrario
 */

int patenteValida(char patente[]);

/** \brief Da de baja un auto
 *
 * \param vector autos
 *
 * \return No devuelve nada
 */

void bajaAutomovil(sAuto autos[]);

/** \brief Busca un espacio libre en el estacionamiento
 *
 * \param Vector estacionamiento
 *
 * \return Devuelve el indice si se encontro lugar y -1 de lo contrario
 */

int libreEst(sEstacionamiento lugaresEst[]);

/** \brief Busca un espacio libre en los autos estacionados
 *
 * \param Vector estacionados
 *
 * \return Devuelve el indice si se encontro lugar y -1 de lo contrario
 */

int libreEst2(sEstacionado estacionado[]);

/** \brief Comprueba si el numero ingresado esta proximo en la espera
 *
 * \param Vector espera
 * \param Numero
 *
 * \return 1 si es asi, 0 de lo contrario
 */

int esperando(sEspera espera[], int num);

/** \brief Comprueba si el estacionamiento esta lleno
 *
 * \param Vector lugares en estacionamiento
 *
 * \return 1 si esta lleno, 0 de lo contrario
 */

int estacionamientoLleno(sEstacionamiento lugaresEst[]);

/** \brief Acomoda el vector espera una vez que se ingresa el que esperaba desde hace mas tiempo al sistema
 *
 * \param Vector espera
 *
 * \return No devuelve nada
 */

void acomodarEspera(sEspera espera[]);

/** \brief Ingresa un profesor a la espera
 *
 * \param Vector espera
 * \param Profesor
 *
 * \return No devuelve nada
 */

void ingresarAEspera(sEspera espera[], int profesor);

/** \brief Muestra el menu de listados permitidos
 *
 * \param Vector autos
 * \param Vector estacionamiento
 * \param Tamaño
 *
 * \return No devuelve nada
 */

void mostrarListas(sAuto autos[], sEstacionado lugaresEst[], int tam);

/** \brief Muestra la lista 1
 *
 * \param Vector autos
 * \param Tamaño
 *
 * \return No devuelve nada
 */

void mostrarLista1(sAuto autos[], int tam);

/** \brief Muestra la lista 2
 *
 * \param Vector estacionamiento
 * \param Vector autos
 * \param Tamaño
 *
 * \return No devuelve nada
 */

void mostrarLista2(sEstacionado lugaresEst[], sAuto autos[], int tam);

/** \brief Muestra la lista 3
 *
 * \param Vector estacionamiento
 * \param Vector autos
 * \param Tamaño
 *
 * \return No devuelve nada
 */

void mostrarLista3(sEstacionado lugaresEst[], sAuto autos[], int tam);

/** \brief Muestra la lista 4
 *
 * \param Vector estacionamiento
 * \param Vector autos
 * \param Tamaño
 *
 * \return No devuelve nada
 */

void mostrarLista4(sEstacionado estacionado[], sAuto autos[], int tam);

/** \brief Busca espacio libre en estacionamiento
 *
 * \param Vector estacionamiento
 *
 * \return El indice si encontro, -1 de lo contrario
 */

int buscarEspacioLibreE(sEstacionamiento lugarEst[]);

/** \brief Busca por numero en el estacionamiento y que no este ingresado
 *
 * \param Vector estacionamiento
 * \param Numero
 * \param Tamaño
 *
 * \return El indice si lo encontro, -1 si no lo encontro y -2 si lo encontro pero ya estaba ingresado
 */

int buscarPorNumeroE(sEstacionamiento lugarEst[], int num, int tam);

/** \brief Busca por numero en el estacionamiento y que este ingresado
 *
 * \param Vector estacionamiento
 * \param Numero
 * \param Tamaño
 *
 * \return El indice si lo encontro, -1 de lo contrario
 */

int buscarPorNumeroE2(sEstacionamiento lugarEst[], int num, int tam);

/** \brief Busca por numero en el vector de estacionados
 *
 * \param Vector estacionados
 * \param Numero
 * \param Tamaño
 *
 * \return El indice si lo encontro, -1 de lo contrario
 */

int buscarPorNumeroE3(sEstacionado estacionado[], int num, int tam);

/** \brief Busca un numero en los autos y que este ingresado
 *
 * \param Vector autos
 * \param Numero
 * \param Tamaño
 *
 * \return El indice si lo encontro, -1 de lo contrario
 */

int buscarPorNumero(sAuto autos[], int num, int tam);

/** \brief Obtiene un espacio libre para poder cargar
 *
 * \param Vector auto
 * \param Tamaño
 *
 * \return El indice si encontro, -1 de lo contrario
 */

int obtenerEspacioLibre(sAuto autos[], int tam);

/** \brief Checkea si un numero esta repetido
 *
 * \param Numero
 * \param Vector auto
 * \param Tamaño
 *
 * \return 1 si esta repetido, 0 de lo contrario
 */

int numRepetido(int num, sAuto autos[], int tam);

/** \brief Checkea si un numero esta repetido
 *
 * \param Numero
 * \param Vector espera
 * \param Tamaño
 *
 * \return 1 si esta repetido, 0 de lo contrario
 */

int numRepetidoEspera(int num, sEspera espera[], int tam);

/** \brief Da de alta un automovil
 *
 * \param Vector autos
 * \param Indice en donde cargar
 *
 * \return No devuelve nada
 */

void altaAutomovil(sAuto autos[], int libre);
