#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char nombre[50];
    int estado;
} ePersona;

int main()
{
    ePersona listaPersonas[4] = {{1,"Juan",1},{2,"Maria",1},{3,"Jose",1},{4,"Ana",1}};
    FILE* pArchivo;
    int i;

    pArchivo = fopen("datos.csv","w");

    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"Id,Nombre,Estado\n");

        for(i=0; i<4; i++)
        {
            fprintf(pArchivo,"%d,%s,%d\n", listaPersonas[i].id, listaPersonas[i].nombre,listaPersonas[i].estado);
        }

        fclose(pArchivo);
        printf("Guardado!");
    }
    else
    {
        printf("Imposible guardar");
    }
    return 0;
}
