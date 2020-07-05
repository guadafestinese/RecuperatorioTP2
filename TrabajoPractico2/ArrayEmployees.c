#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "utn.h"

void initEmployees(eEmployee empleado[], int len)
{
        int i;
        for (i=0; i <len; i++)
        {
            empleado[i].isEmpty = 1;
        }
 }

//---------------------------------------------------


void addEmployee (eEmployee empleado[], int cantidad){

    int auxSector;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxSueldo[10];

    printf("*** ALTA EMPLEADOS *** \n\n");

    for(i=0;i<cantidad;i++){

        if(empleado[i].isEmpty==1)
        {

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxNombre);

        while(esSoloLetras(auxNombre)==0 || strlen(auxNombre)< 3 || strlen(auxNombre)>51)
        {
            printf("ERROR, ingrese un nombre correcto entre 3 y 51 letras: ");
            fflush(stdin);
            gets(auxNombre);
        }

        strcpy(empleado[i].name, auxNombre);
        strupr(empleado[i].name);


        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxApellido);

        while(esSoloLetras(auxApellido)==0 || strlen(auxApellido)< 3 || strlen(auxApellido)>51)
        {
            printf("ERROR, ingrese un apellido correcto entre 3 y 51 letras: ");
            fflush(stdin);
            gets(auxApellido);
        }

        strcpy(empleado[i].lastName, auxApellido);
        strupr(empleado[i].lastName);


        printf("Ingrese salario entre 10.000 y 80.000: ");
        fflush(stdin);
        gets(auxSueldo);
        while(esNumerico(auxSueldo)==0 || atof(auxSueldo)<10000 || atof(auxSueldo)>60000)
        {
            printf("ERROR, ingrese un salario correcto entre 10.000 y 80.000: ");
            fflush(stdin);
            gets(auxSueldo);
        }
        empleado[i].salary = atof(auxSueldo);



        auxSector= menuSector();
        empleado[i].sector = auxSector;

        while(empleado[i].sector<1||empleado[i].sector>4)
        {
            printf("ERROR. Ingrese un sector correcto\n");
            auxSector= menuSector();
            empleado[i].sector = auxSector;
        }


            empleado[i].isEmpty = 0;
            empleado[i].id = i+1;



        printf("Se dio de alta el emplado con exito!\n");
        system("pause");
        break;
    } //FIN FOR
 }

}

//-----------------------------------
int findEmployeeById(int id, eEmployee empleado[], int tam){

    int indice= -1;

    for(int i=0; i<tam; i++)
    {
        if(empleado[i].id == id)
        {
            indice= i;
            break;
        }
    }
    return indice;
}

//--------------------------

void mostrarEmpleado(eEmployee empleado){

    printf("ID   Sector           Apellido            Nombre      Salario\n\n");
    printf("%d   %d     %20s %20s    %10.2f\n",empleado.id, empleado.sector, empleado.lastName, empleado.name, empleado.salary);
}

//---------------------------------------------

int printEmployees (eEmployee empleado [], int cantidad){

    int hayEmpleados = 0;
    printf("ID   Sector           Apellido            Nombre      Salario\n\n");
    for (int i=0; i<cantidad; i++)
    {
        if(empleado[i].isEmpty==0)
        {
            printf("%d   %d     %20s %20s    %10.2f\n", empleado[i].id, empleado[i].sector, empleado[i].lastName, empleado[i].name, empleado[i].salary);
            hayEmpleados = 1;
        }
    }
    return hayEmpleados;

}

//--------------------------------------------------
void modificarEmpleado(eEmployee empleado[], int cantidad){

    char respuesta;
    int auxiliar;
    int flag = 0;
    char auxNombre[51];
    char auxApellido[51];
    char auxSueldo[10];

    if(hayEmpleados(empleado, cantidad)== 0){
        printf("No hay empleados cargados\n");
        system("pause");
    }else{
    printf("*** MODIFICAR EMPLEADOS ***\n\n");
    printEmployees(empleado, cantidad);
    printf("Ingrese el id a modificar: ");
    scanf("%d", &auxiliar);



    for(int i = 0; i < cantidad; i++){

        if(auxiliar == empleado[i].id){
            printf("Datos encontrados: \n");
            mostrarEmpleado(empleado[i]);

            do{

                flag = 1;

                switch(menuModificar())
                {
                    case 1:
                            printf("Ingrese nuevo nombre: ");
                            fflush(stdin);
                            gets(auxNombre);

                            while(esSoloLetras(auxNombre)==0 || strlen(auxNombre)< 3 || strlen(auxNombre)>51)
                            {
                                printf("ERROR, ingrese un nombre correcto entre 3 y 51 letras: ");
                                fflush(stdin);
                                gets(auxNombre);
                            }

                            strcpy(empleado[i].name, auxNombre);
                            strupr(empleado[i].name);
                            printf("Se modifico el nombre con exito!\n\n");
                            //system("pause");
                            break;

                     case 2:
                            printf("Ingrese nuevo apellido: ");
                            fflush(stdin);
                            gets(auxApellido);

                            while(esSoloLetras(auxApellido)==0 || strlen(auxApellido)< 3 || strlen(auxApellido)>51)
                            {
                                printf("ERROR, ingrese un apellido correcto entre 3 y 51 letras: ");
                                fflush(stdin);
                                gets(auxApellido);
                            }

                            strcpy(empleado[i].lastName, auxApellido);
                            strupr(empleado[i].lastName);
                            printf("Se modifico el apellido con exito!\n\n");
                            //system("pause");
                            break;


                     case 3:

                            printf("Ingrese nuevo salario entre 10.000 y 80.000: ");
                            fflush(stdin);
                            gets(auxSueldo);
                            while(esNumerico(auxSueldo)==0 || atof(auxSueldo)<10000 || atof(auxSueldo)>60000)
                            {
                                printf("ERROR, ingrese un salario correcto entre 10.000 y 80.000: ");
                                fflush(stdin);
                                gets(auxSueldo);
                            }
                            empleado[i].salary = atof(auxSueldo);
                            printf("Se modifico el salario con exito!\n\n");
                            //system("pause");
                            break;


                     case 4:
                            printf("Ingrese nuevo sector: \n");
                            empleado[i].sector = menuSector();

                            while(empleado[i].sector<0||empleado[i].sector>4)
                            {
                                printf("ERROR. Ingrese nuevo sector: \n");
                                empleado[i].sector = menuSector();
                            }
                            printf("Se modifico el sector con exito!\n\n");
                            //system("pause");
                            break;

                     case 5:
                            printf("No se modifico ningun dato\n\n");
                            //system("pause");
                            break;

                }
                printf("Quiere modificar algo mas? s o n \n");
                fflush(stdin);
                scanf("%c", &respuesta);
                respuesta = tolower(respuesta);


            }while(respuesta=='s');


        }
    }

    if(flag==0)
    {
        printf("No se encontro un empleado con ese ID\n");
        system("pause");
    }
    }
}

//-----------------------------------------------------------------

void removeEmployee (eEmployee empleado [], int cantidad){

    int id;
    char confirma;
    system("cls");
    int flag= 0;

    printf("*** BAJA EMPLEADO ***\n");

    if(hayEmpleados(empleado, cantidad)== 0){
        printf("No hay empleados cargados, debe dar de alta primero\n\n");
        system("pause");
    }else{

        printEmployees(empleado, cantidad);
        printf("Ingrese id: ");
        scanf("%d", &id);

        for(int i=0; i<cantidad; i++){

            if(empleado[i].id == id){
                mostrarEmpleado(empleado[i]);
                flag = 1;
                printf("Confima baja? s o n \n");
                fflush(stdin);
                scanf("%c", &confirma);


            if(confirma == 's'){
                empleado[i].isEmpty = 1;
                printf("Se ha realizado la baja con exito\n");
                system("pause");

            }else{
                printf("Se ha cancelado la operacion\n");
                system("pause");
            }
        }


    }
        if(flag == 0){
            printf("No se encontro un empleado con ese ID\n");
            system("pause");
        }

    }




}


//------------------------------------------

int sortEmployees (eEmployee empleado[], int cantidad, int order){

    eEmployee auxiliar;
    int todoOk = 0;
    int sortOrder = order;
    int flag = 0;


    if(hayEmpleados(empleado, cantidad)== 0){
        printf("No se encuentran empleados cargados para ordenar\n\n");
        system("pause");
    }else
    {
        flag = 1;

        if(sortOrder == 1){
            for(int i=0; i<cantidad-1; i++){
                for(int j=i+1; j<cantidad; j++)
                {
                    if (strcmp(empleado[j].lastName,empleado[i].lastName)<0)
                    {
                        auxiliar = empleado[i];
                        empleado[i] = empleado[j];
                        empleado[j] = auxiliar;
                    }else if(strcmp(empleado[j].lastName, empleado[i].lastName)== 0 && empleado[i].sector > empleado[j].sector)
                    {
                        auxiliar = empleado[i];
                        empleado[i] = empleado[j];
                        empleado[j] = auxiliar;
                    }

                }
            }// cierro else
      todoOk= 1;
     }// cierro sortOrder = 1

       if(sortOrder==0){
        for(int i=0; i<cantidad-1; i++){
            for(int j=i+1; j<cantidad; j++) {
                if(strcmp(empleado[j].lastName,empleado[i].lastName)>0){
                    auxiliar = empleado[i];
                    empleado[i] = empleado[j];
                    empleado[j] = auxiliar;
                }
                else if(strcmp(empleado[j].lastName, empleado[i].lastName) == 0 && empleado[i].sector < empleado[j].sector){
                    auxiliar= empleado[i];
                    empleado[i] = empleado[j];
                    empleado[j] = auxiliar;
                }
            }
        }
        todoOk = 1;
    }//cierro sort otder = 0

    }

    if(flag == 1){
        printEmployees(empleado, cantidad);
        system("pause");
    }

    return todoOk;
}
//------------------------------------------------------

void promedioEmpleados (eEmployee empleado[], int cantidad){

    int i;
    float acumulador=0;
    int contSalarios=0;
    float promedio;
    int contadorMayores=0;

    if(hayEmpleados(empleado, cantidad) == 0){
        printf("No hay empleados cargados para calcular el promedio de salarios\n\n");
        system("pause");
    }else{

    for (i=0; i<cantidad; i++)
    {
        if((empleado[i].salary>0)&&(empleado[i].isEmpty ==0))
            {
                acumulador = acumulador + empleado[i].salary;
                contSalarios++;
            }
    }

    promedio= (float) acumulador/contSalarios;

    for(int e=0; e<cantidad; e++){
        if(empleado[e].salary > promedio){
        contadorMayores++;
        }
    }


    printf("La cantidad de salarios es %d y suma %.2f \n", contSalarios, acumulador);
    printf("El promedio de salarios es %.2f\n", promedio);
    printf("La cantidad de salarios que superan el promedio es: %d\n", contadorMayores );
    system("pause");

    }




}

int hayEmpleados(eEmployee empleado[], int cantidad){
    int hayEmpleados = 0;

    for(int i=0; i<cantidad; i++)
    {
        if(empleado[i].isEmpty == 0)
        {
            hayEmpleados = 1;
        }
    }
    return hayEmpleados;

}
