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

void startupVector(sAbonado abonados[], int tam);

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

char validarChar(char caracter, char opcion1, char opcion2);

/** \brief Comprueba si un num ingresado esta repetido en un vector dado
  *
  * \param Numero a comparar
  * \param Vector a revisar
  * \param Tamaño del vector
  *
  * \return Devuelve 1 si el num ya se encuentra en el vector y 0 de lo contrario
  */

int numRepetido(int num, sAbonado abonados[], int tam);

/**
  * \brief Obtiene el primer indice libre del array
  *
  * \param Vector en el que se quiere buscar lugar
  * \param Tamaño del vector dado
  *
  * \return El primer indice disponible
  */

int obtenerEspacioLibre(sAbonado abonados[], int tam);

/** \brief Se pide un numero para saber donde guardar los datos a cargar
  *
  * \param Vector donde se busca cargar datos
  *
  * \return Devuelve el indice donde deben ser cargados los datos
  */

int cargarID(sAbonado abonados[]);

/** \brief  Obtiene el indice que coincide con el num pasado por parametro
  *
  * \param Vector en el que se quiere buscar el num
  * \param Tamaño del vector dado
  *
  * \return El indice en donde se encuentra el elemento que coincide con el parametro num
  */

int buscarPorNumero(sAbonado abonados[], int tam);

/** \brief Pide confirmacion antes de borrar la persona que se pidio
  *
  * \param Vector de personas
  * \param Index en el que se encuentra la persona que se busca borrar
  *
  * \return Devuelve S si se decidio continuar y N de lo contrario
  */

char confirmarBorrado(sAbonado abonados[], int index);

/** \brief Borra a una persona cambiando su estado a 0
 *
 * \param Vector de personas
 * \param Index en el que se encuentra la persona que se busca borrar
 *
 * \return No devuelve nada
 */

void borrarPersona(sAbonado abonados[], int index);

/** \brief Modifica un vector
 *
 * \param Vector a modificar
 * \param Index a modificar
 *
 * \return No devuelve nada
 */

void modificarAbonado(sAbonado abonados[], int index);

/**
  * Carga una persona al sistema
  *
  * @param Lista de personas
  * @param Indice donde hay espacio libre
  *
  * @return No devuelve nada
  */

void altaAbonado(sAbonado abonados[]);

/**
  * Carga una persona al sistema
  *
  * @param Lista de personas
  * @param Indice donde hay espacio libre
  *
  * @return No devuelve nada
  */

void cargarPersona(sPersona persona[], int libre);

/** \brief Inicializa una nueva llamada
  *
  * \param Vector abonados
  * \param Vector llamadas
  * \param Tamaño vector abonados
  * \param Tamaño vector llamadas
  *
  * \return No devuelve nada
  */

void nuevaLlamada(sAbonado abonados[], sLlamada llamadas[], int tam1, int tam2);

/** \brief Muestra quien dio mas reclamos
  *
  * \param Vector abonados
  * \param Vector llamadas
  * \param Tamaño vector 1
  * \param Tamaño vector 2
  * \return
  *
  */

int masReclamos(sAbonado abonados[], sLlamada llamadas[], int tam1, int tam2);

/** \brief Finaliza una llamada
  *
  * \param Vector llamadas
  * \param Tamaño del vector
  *
  * \return No devuelve nada
  */

void finLlamada(sLlamada llamadas[], int tam);

/** \brief Muestra la lista ordenada de personas (Nombre -- Edad -- DNI)
  *
  * \param Vector de personas
  * \param Tamaño del vector
  *
  * \return No devuelve nada
  */

void mostrarLista(sPersona personas[], int tam);

/** \brief Dice si hay datos ingresados en un vector o si aun falta ingresar el primero
  *
  * \param Vector a revisar
  * \param Tamaño del vector
  *
  * \return Devuelve 1
  */

int hayPersonas(sPersona personas[], int tam);

/** \brief Imprime un grafico de barras que indica la cantidad de personas en cada grupo de edad
  *
  * \param Vector de personas
  * \param Tamaño del vector
  *
  * \return No devuelve nada
  */

void imprimirGrafico(sPersona personas[], int tam);
