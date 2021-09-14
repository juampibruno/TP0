#include "scanner.h"

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

void get_token(char buffer[])
{
    char caracter;
    int i = 0;
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
                buffer[i] = caracter;
                i++;
                caracter = getchar();
            }
            else
            {
                mostrarToken(CAD);
                while (caracter != EOF && caracter != ',' && isspace(caracter) == 0)
                {
                    buffer[i] = caracter;
                    putchar(caracter);
                    i++;
                    caracter = getchar();
                }
                buffer[i] = '\0'; // lo pongo para indicar que termina cadena de texto
                i++;
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