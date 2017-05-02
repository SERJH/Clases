#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesSM.h"

int main()
{
    char string[20];

    printf("Ingrese una string: ");
    gets(string);

    invertirString(string);

    printf("\nString invertida: %s\n", string);

    return 0;
}


