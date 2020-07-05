#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include <conio.h>
#include "utn.h"

#define CANTIDAD 1000

/*
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
*/



int main()
{
    eEmployee empleado[CANTIDAD]; /*= {    {1, "CLAUDIA", "ARIS", 30000, 2, 0},
                                        {2, "FRANCO", "FESTINESE", 40000, 3, 0},
                                        {3, "GUADALUPE", "FESTINESE", 35000, 1, 0},
                                        {4, "CAMILA", "DAVO", 45000, 2, 0},
                                        {5, "NORBERTO", "DAVO", 30000, 1, 0}
                                        };
                                        */
    initEmployees(empleado, CANTIDAD);
    char opcion=0;



    do{

        switch(menu()){



        case 1:
            addEmployee(empleado,CANTIDAD);
            break;

        case 2:
            system("cls");
            modificarEmpleado(empleado,CANTIDAD);
            break;

        case 3:
            system("cls");
            removeEmployee(empleado, CANTIDAD);
            break;

        case 4:

                switch(menuInformes())
                {
                    case 1:
                        sortEmployees(empleado, CANTIDAD, 1);
                        break;

                    case 2:
                        promedioEmpleados(empleado,CANTIDAD);
                        break;
                }
            break;

                    case 5:
                        printf("El programa ha terminado\n");
                        opcion = 5;
                        system("pause");
                        break;

                default:
                    printf("Opcion invalida\n");
                    system("pause");
                    break;

            system("cls");
        }


        }while(opcion != 5);
    return 0;
}
