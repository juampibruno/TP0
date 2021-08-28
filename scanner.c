#include "scanner.h"

enum token
{
    FDT, //Fin de texto
    SEP, //Separador
    CAD  //Cadena
};

void mostrarToken(int token)
{
    switch (token)
    {
    case FDT:
        printf("Fin de texto: ");
        break;
    case SEP:
        printf("Separador: ");
        break;
    case CAD:
        printf("Cadena: ");
        break;
    }
}

void get_token()
{
    char caracter;
    caracter = getchar();

    do
    {
        if (isspace(caracter) == 0) // Si es espacio me devuelve != 0
        {
            if (caracter == ',')
            {
                mostrarToken(SEP);
                putchar(caracter);
                printf("\n");
                caracter = getchar();
            }
            else
            {
                mostrarToken(CAD);
                while (caracter != EOF && caracter != ',' && isspace(caracter) == 0)
                {
                    putchar(caracter);
                    caracter = getchar();
                }
                printf("\n");
            }
        }
        else
        {
            caracter = getchar();
        }

    } while (caracter != EOF);

    if (caracter == EOF)
    {
        mostrarToken(FDT);
        printf("\n");
    }
}
