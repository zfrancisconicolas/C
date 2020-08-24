#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

}

int employee_setNombre(Employee* this,char* nombre)
{

}

int employee_getNombre(Employee* this,char* nombre)
{

}



int employee_setSueldo(Employee* this,int sueldo)
{

}
int employee_getSueldo(Employee* this,int* sueldo)
{


}

int employee_setId(Employee* this,int id)
{

}
int employee_getId(Employee* this,int* id)
{

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{


}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    //verificar nulidad

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }



    return strcmp(e1->nombre, e2->nombre);
}



