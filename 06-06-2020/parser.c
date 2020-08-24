#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
	char prim[64];
	char seg[64];
	char terc[64];
	char cuart[64];
	Employee* auxEmpleado;
		int i = 0;
		if(pFile != NULL){
			//REMOVIENDO HEADERS
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", prim, seg, terc, cuart);
			//LEYENDO EL ARCHIVO
			do{
				if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", prim, seg, terc, cuart) == 4){
					auxEmpleado = employee_newParametros(prim, seg, terc, cuart);
					if(auxEmpleado != NULL){
						ll_add(pArrayListEmployee, auxEmpleado);
						i++;
					}
				}
				else{
					break;
				}
			} while(feof(pFile)==0);
		 fclose(pFile);

		}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param FILE* pFile
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
	Employee* auxEmpleado;
	int i = 0;
	int readResult;
	if(pFile != NULL){
		//LEYENDO EL ARCHIVO
		do{
			auxEmpleado = employee_new();
			readResult = fread(auxEmpleado, sizeof(Employee), 1, pFile);
			if(auxEmpleado != NULL && readResult != 0){
				i++;
				ll_add(pArrayListEmployee, auxEmpleado);
			}
		} while(feof(pFile)==0);
		fclose(pFile);
	}
    return 1;
}
