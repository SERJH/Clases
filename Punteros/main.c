#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int* puntero;
//    int num = 7;
//    int* otro;
//
//    puntero = &num;
//
//    printf("%p", &num);
//    printf("\n%p", puntero);
//    printf("\n%i", num);
//    printf("\n%i", *puntero);
//    *puntero = 27;
//    printf("\n%i\n", num);
//    scanf("%i", puntero);
//    printf("%i\n", num);
//    printf("%p", &puntero);
//
//    otro = puntero;

    int vec[5] = {5,4,3,2,1};
    int* pvec;
    int i;

    pvec = vec;

    for (i = 0; i < 5; i++) {

        printf("\Ingrese el valor %i: ", i+1);
        scanf("%i", pvec+i);

    }

    for (i = 0; i < 5; i++) {

        printf("\n%i: %i", i+1, *pvec+i);

    }

    return 0;

}
