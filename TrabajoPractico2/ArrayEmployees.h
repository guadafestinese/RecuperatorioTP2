#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}eEmployee;
#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief Se utiliza esta funcion para inicializar el empleado
 * Se pone en 1 si esta ocupada la posicion
 * \param eEmployee empleado [] es el array de empleados de la estructura
 * \param int len es la cantidad del array
 * \return no devuelve nada
 */
void initEmployees(eEmployee empleado[], int len);

/** \brief Busca un empleado por el ID
 *
 * \param  int id
 * \param eEmployee empleado[]
 * \param int tam
 * \return devuelve -1 si no lo encontro y el ID si lo encontro
 *
 */

int findEmployeeById(int id, eEmployee empleado[], int tam);
//--------------------------------------------------------------------------

/** \brief Se utiliza para agregar un empleado
 *
 * \param eEmployee empleado []
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void addEmployee (eEmployee empleado[], int cantidad);
//--------------------------------------------------------------------------


/** \brief Muestra un solo empleado
 *
 * \param eEmployee empleado
 * \param -
 * \return no devuelve nada
 *
 */

void mostrarEmpleado(eEmployee empleado);
//--------------------------------------------------------------------------


/** \brief Muestra todos los empleados cargados
 *
 * \param eEmployee empleado []
 * \param int cantidad
 * \return no devuelve nada
 *
 */

int printEmployees (eEmployee empleado [], int cantidad);
//--------------------------------------------------------------------------

/** \brief Modifica un empleado
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no deuelve nada
 *
 */

void modificarEmpleado (eEmployee empleado[], int cantidad);
//--------------------------------------------------------------------------

/** \brief Elimina un empleado
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void removeEmployee (eEmployee empleado [], int cantidad);
//--------------------------------------------------------------------------

/** \brief Ordena los empleados por apellido y nombre
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no devuelve nada
 *
 */

int sortEmployees (eEmployee empleado[], int cantidad, int order);
//--------------------------------------------------------------------------
/** \brief Calcula el total de sueldos de los empleados, el promedio de ellos y la cantidad
 *
 * \param eEmployee empleado[]
 * \param int cantidad
 * \return no devuelve nada
 *
 */

void promedioEmpleados (eEmployee empleado[], int cantidad);


/** \brief Recibe el array de empleados y chequea que haya empleados cargados
 *
 * \param eEmployee empleado[], array de empleados
 * \param int cantidad, tamaño del array
 * \return devuelve 0 si no hay empleados y 1 si hay empleados
 *
 */

int hayEmpleados(eEmployee empleado[], int cantidad);
