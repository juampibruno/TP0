#ifndef FUNCIONES
#define FUNCIONES
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

enum token
{
    FDT, //Fin de texto
    SEP, //Separador
    CAD  //Cadena
};


void mostrarToken (int token);
void get_token(char buffer[]);

#endif