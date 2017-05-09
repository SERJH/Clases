

typedef struct {

    char patente[30];
    char modelo[30];
    char marca[15];
    int profesor;
    int estado;

} sAuto;

/** \brief Muestra el menu principal
  *
  *  \param No lleva parametros
  *
  *  \return No devuelve nada
  */

void mostrarMenu();

/** \brief Inicializa el vector de personas para que todas tengan 0 como estado inicial
  *
  * \param Vector de personas
  * \param Tamaño del vector
  *
  * \return No devuelve nada
  */

  void startupVector(sAuto autos[], int tam);
//void startupVector(sAbonado abonados[], int tam);

/** \brief Invierte una string dada
  *
  * \param String que se quiera invertir
  *
  * \return No devuelve nada
  */

void invertirString(char string[]);

/** \brief Valida un entero para que solo pueda estar entre un determinado rango ingresado
  *
  * \param Minimo
  * \param Maximo
  *
  *\return Devuelve el entero validado
  */

int validarRangoInt(int num, int min, int max);

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
//
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

char confirmarBorrado();

void borrarProfesor(int profesor, sAuto autos[], int tam);

char validarChar(char caracter, char opcion1, char opcion2);

int obtenerEspacioLibre(sAuto autos[], int tam);

int numRepetido(int num, sAuto autos[], int tam);

int stringRepetida(char string[], sAuto autos[], int tam);

void altaAutomovil(sAuto autos[], int libre);
