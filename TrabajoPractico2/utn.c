
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int getInt(char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;
}
//-------------------------------------------------------------------------------------------

char getChar(char mensaje[])
{
    char auxiliarChar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", &auxiliarChar);
    return auxiliarChar;
}
//-------------------------------------------------------------------------------------------

float getFloat(char mensaje[])
{
    float auxiliarFloat;
    printf("%s", mensaje);
    scanf("%f", &auxiliarFloat);
    return auxiliarFloat;
}
//-------------------------------------------------------------------------------------------


int esNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;
}

//-------------------------------------------------------------------------------------------


int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

//-------------------------------------------------------------------------------------------

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", mensaje);
    gets(input);
}


