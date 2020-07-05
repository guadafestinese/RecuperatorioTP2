/** \brief Pide un numero y lo devuelve
 *
 * \param mensaje, es el mensaje que se muestra
 * \return el numero entero ingresado
 */
int getInt (char mensaje[]);

//-------------------------------------------------------------------------------------------

/** \brief Pide un numero y lo devuelve
 *
 * \param mensaje, es el mensaje que se muestra
 * \return el numero flotante ingresado
 */
float getFloat (char mensaje[]);

//-------------------------------------------------------------------------------------------
/** \brief Pide un caracter y lo devuelve
 *
 * \param mensaje, es el mensaje que se muestra
 * \return el caracter ingresado
 */
char getChar(char mensaje[]);



//-------------------------------------------------------------------------------------------

/** \brief Verifica si es numerico
 *
 * \param str, cadena de caracteres a chequear si es numerico
 * \return 1 si es un numero y 0 si no es un numero
 */
int esNumerico (char str[]);

//-------------------------------------------------------------------------------------------
/** \brief Verifica si solo tiene letras
 *
 * \param str, cadena de caracteres a chequear si es solo letras
 * \return 1 si contiene solo letras y 0 si tiene numeros o caracteres incorrectos
 */
int esSoloLetras (char str[]);



//-------------------------------------------------------------------------------------------
/** \brief Pide una cadena de caracteres
 *
 * \param mensaje, es el mensaje que se muestra
 * \param input, es el array donde se carga el mensaje ingresado
 * \return -
 */
void getString(char mensaje[], char input[]);

//-------------------------------------------------------------------------------------------


