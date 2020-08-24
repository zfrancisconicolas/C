#include <stdio.h>
#include <stdlib.h>

#include "Dato.h"


int main()
{
    eDato dato;
    eDato* d;

    d=&dato;




    if(eDato_set_a(d,500)==1 && eDato_set_b(d,"hola")==1)
    {
         printf("%d--%s", eDato_get_a(d),eDato_get_b(d));
    }
    else
    {
        printf("Verifique los datos");
    }



    return 0;
}

