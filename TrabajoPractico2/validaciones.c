#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include <conio.h>
void myFgets (char nombre [], int cant)
{
    fflush (stdin);
    fgets(nombre, cant, stdin);
    nombre[strcspn(nombre, "\r\n")] = 0;
}

int menu(){
    int opcion;
    system("cls");
    printf("***MENU DE OPCIONES****\n\n");

    printf("1) Alta empleado\n");
    printf("2) Modificar empleado\n");
    printf("3) Baja empleado\n");
    printf("4) Informar\n");
    printf("5) Salir\n");

    printf("Seleccione opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes(){
    int opcion;
    printf("1) Listado de empleados ordenados alfabeticamente por apellido y sector\n");
    printf("2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n\n");
    printf("Seleccione opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuSector(){
    int opcion;

    printf("1)Atencion al cliente\n");
    printf("2) Ventas\n");
    printf("3) Compras\n");
    printf("4) Recursos humanos\n");
    printf("Seleccione opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuModificar(){

    int opcion;

    printf("Ingrese la opcion que quiera modificar: \n");
    printf("1) Nombre\n");
    printf("2) Apellido\n");
    printf("3) Salario\n");
    printf("4) Sector\n");
    printf("5) Salir\n");


    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    while(opcion<1 || opcion>5){
        printf("ERROR. Ingrese una opcion valida: ");
        scanf("%d", &opcion);
    }


 return opcion;
}
