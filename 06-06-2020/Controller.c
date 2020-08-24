#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funciones.h"
#include "Controller.h"
#include <string.h>
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
	int loadFromTextResult;
	FILE* data = fopen(path, "r");
	loadFromTextResult = parser_EmployeeFromText(data , pArrayListEmployee);
	if(loadFromTextResult == 1){
		printf("\nEmpleados cargados con exito\n");
		return 1;
	}
	else{
		printf("\nOcurrio un problema al cargar el archivo\n");
	}
	return 0;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
	int loadFromTextResult;
	FILE* data = fopen(path, "rb");
	loadFromTextResult = parser_EmployeeFromBinary(data, pArrayListEmployee);
	if(loadFromTextResult == 1){
		printf("\nEmpleados cargados con exito\n");
		return 1;
	}
	else{
		printf("\nOcurrio un problema al cargar el archivo\n");
	}
	return 0;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee){
	Employee* auxEmpleado;
	char nombre[20];
	char id[5];
	int horasTrabajadasInt;
	char horasTrabajadas[4];
	int sueldoInt;
	char sueldo[7];
	int validacionId;
	int idInt;
	int len;
	int addReturn;
	printf("\nIngrese el nombre: \n");
	fflush(stdin);
	fgets(nombre, sizeof(nombre), stdin);
	len = strlen(nombre);
	if( nombre[len-1] == '\n' ){
		nombre[len-1] = 0;
	}

	idInt = getInt("\nIngrese un Id:\n", 0, 9999, "\nIngrese un valor entre 0 y 9999.\n");
	validacionId = controller_validateId(pArrayListEmployee, &idInt);
	if(validacionId == 0){
		horasTrabajadasInt = getInt("\nIngrese las horas trabajadas\n", 0, 200, "\nIngrese un valor entre 0 y 200.\n");
		sueldoInt = getInt("\nIngrese el sueldo\n", 0, 120000, "\nIngrese un valor entre 0 y 120000.\n");

		itoa(horasTrabajadasInt, horasTrabajadas, 10);
		itoa(sueldoInt, sueldo, 10);
		itoa(idInt, id, 10);

		auxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
		addReturn = ll_add(pArrayListEmployee, auxEmpleado);
		if(addReturn == 0){
			printf("\nEmpleado cargado con exito.\n");
		    return 1;
		}
		else{
			printf("\nOcurrio un problema al cargar el empleado.\n");
		}
	}
	else{
		printf("\nEl id ya esta en uso.\n");
	}
	return 0;
}

/** \brief verifica que el id no este en uso
 * \param LinkedList* pArrayListEmployee
 * \param  int* id
 * \return int
 */
int controller_validateId(LinkedList* pArrayListEmployee, int* id){
	int llLength = ll_len(pArrayListEmployee);
	Employee* auxEmp;
	int idEmpleado;
	int idOcupado = 0;
	for(int i = 0 ; i < llLength ; i++){
		auxEmp = ll_get(pArrayListEmployee, i);
		employee_getId(auxEmp, &idEmpleado);

		if(idEmpleado == *id){
			idOcupado = 1;
		}
	}
	return idOcupado;
}

/** \brief busca en la linkedlist un empleado por id
 * \param LinkedList* pArrayListEmployee
 * \param  int* id
 * \return Employee*
 */
void* getEmployeeById(LinkedList* pArrayListEmployee, int* id){
	int llLength = ll_len(pArrayListEmployee);
	Employee* auxEmp;
	int idEmpleado;
	for(int i = 0 ; i < llLength ; i++){
		auxEmp = ll_get(pArrayListEmployee, i);
		employee_getId(auxEmp, &idEmpleado);
		if(idEmpleado == *id){
			return auxEmp;
		}
	}
	return NULL;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee){
	Employee* auxEmp;
	int opcionAModificar;
	int id;
	int validacionId;

	id = getInt("\nIngrese un Id:\n", 0, 9999, "\nIngrese un valor entre 0 y 9999.\n");
	validacionId = controller_validateId(pArrayListEmployee, &id);
	if(validacionId == 1){
		do{
			//IMPRIMIENDO EL EMPLEADO
			auxEmp = getEmployeeById(pArrayListEmployee, &id);
			mostrarEmpleado(auxEmp);
			opcionAModificar = showMenu("\n1. Nombre\n2. Horas trabajadas\n3. Sueldo.\n4. Salir\n",1 ,4, "\nIngrese una opcion valida.\n");
			switch(opcionAModificar){
				case 1:
					modificarNombre(auxEmp);
				break;
				case 2:
					modificarHoras(auxEmp);
				break;
				case 3:
					modificarSueldo(auxEmp);
				break;
			}
		} while(opcionAModificar != 4);

	}
	else{
		printf("No se encontro empleado con ese Id.\n");
	}
    return 1;
}

/** \brief busca el index de la linkedlist donde se encuentra el empleado
 * \param pArrayListEmployee LinkedList*
 * \param int* id
 * \return int
 */
int getEmployeeIndex(LinkedList* pArrayListEmployee, int* id){
	int llLength = ll_len(pArrayListEmployee);
	Employee* auxEmp;
	int idEmpleado;
	for(int i = 0 ; i < llLength ; i++){
		auxEmp = ll_get(pArrayListEmployee, i);
		employee_getId(auxEmp, &idEmpleado);
		if(idEmpleado == *id){
			return i;
		}
	}
	return -1;
}

/** \brief Baja de empleado
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee){
	Employee* auxEmp;
	int id;
	int validacionId;
	int index;
	int removeResult;
	char dobleValidacion;
	id = getInt("\nIngrese un Id:\n", 0, 9999, "\nIngrese un valor entre 0 y 9999.\n");
	validacionId = controller_validateId(pArrayListEmployee, &id);
	if(validacionId == 1){
		auxEmp = getEmployeeById(pArrayListEmployee, &id);
		index = getEmployeeIndex(pArrayListEmployee, &id);
		mostrarEmpleado(auxEmp);
        dobleValidacion = getChar("Esta seguro que desea eliminar al empleado? (s / n).\n", 's', 'n', "\nIngrese una respuesta valida\n");
        if(dobleValidacion == 's'){
    		removeResult = ll_remove(pArrayListEmployee, index);
    		if(removeResult == 0){
        		printf("Empleado eliminado con exito\n");
    			return 1;
    		}
		}
        else{
        	printf("\nSe ha cancelado la operacion\n");
        }
	}
	else{
		printf("No se encontro empleado con ese Id.\n");
	}
	return 0;
}

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee){
	int llLength = ll_len(pArrayListEmployee);
	Employee* auxEmp;
	printf("    ID -             NOMBRE -        HS -     SUELDO\n");
	for(int i = 0 ; i < llLength ; i++){
		auxEmp = ll_get(pArrayListEmployee, i);
		mostrarEmpleado(auxEmp);
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *  param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
	int llLength = ll_len(pArrayListEmployee);
	Employee* auxEmp;
	char auxNombre[64];
	int idEmpleado;
	int horasEmpleado;
	int sueldoEmpleado;
	FILE* data;
    int i;
    char headers[34] = "id,nombre,horasTrabajadas,sueldo\n";
    data = fopen(path, "w");
	if(data!=NULL){
		fprintf(data, headers);
		for(i = 0 ; i < llLength ; i++){
			auxEmp = ll_get(pArrayListEmployee, i);
			employee_getNombre(auxEmp, auxNombre);
			employee_getId(auxEmp, &idEmpleado);
			employee_getHorasTrabajadas(auxEmp, &horasEmpleado);
			employee_getSueldo(auxEmp, &sueldoEmpleado);
			fprintf(data,"%d,%s,%d,%d\n", idEmpleado, auxNombre, horasEmpleado, sueldoEmpleado);
		}
		fclose(data);
		printf("Archivo guardado con exito\n");
	}
	else{
		printf("No se pudo guardar el archivo\n");
	}
	return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
	int llLength = ll_len(pArrayListEmployee);
	Employee* auxEmp;
	FILE* data;
    int i;
    data = fopen(path, "wb");
	if(data !=NULL){
		for(i = 0 ; i < llLength ; i++){
			auxEmp = ll_get(pArrayListEmployee, i);
			fwrite(auxEmp, sizeof(Employee), 1, data);
		}
		fclose(data);
		printf("Archivo guardado con exito\n");
	}
	else{
		printf("No se pudo guardar el archivo\n");
	}
	return 0;
}

/** \brief Ordenar empleados
 * \param pArrayListEmployee LinkedList*
 * \return int
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee){
	int opcion;
	int orden;
	int sortResult;
	opcion = showMenu("Seleccione un campo de ordenamiento:\n1. Ordenar por ID\n2. Ordenar por nombre\n3. Ordenar por horas trabajadas\n4. Ordenar por sueldo\n5. Salir\n", 1, 5, "Ingrese un valor entre 1 y 5\n");
	orden = showMenu("Seleccione un orden:\n1. Ascendente\n2. Descendente\n3. Salir\n", 1, 3, "Ingrese un valor entre 1 y 3\n");
	switch(orden){
		case 2:
			orden = 0;
		break;
	}
	if(orden != 3){
		switch (opcion){
		case 1:
			printf("Ordenado empleados...\n");
			sortResult = ll_sort(pArrayListEmployee, sortEmployeeById, orden);
			if(sortResult == 0){
				printf("\nEmpleados ordenados por id con exito.\n");
			}
		break;
		case 2:
			printf("Ordenado empleados...\n");
			sortResult = ll_sort(pArrayListEmployee, sortEmployeeByName, orden);
			if(sortResult == 0){
				printf("\nEmpleados ordenados por nombre con exito.\n");
			}
		break;
		case 3:
			printf("Ordenado empleados...\n");
			sortResult = ll_sort(pArrayListEmployee, sortEmployeeByHours, orden);
			if(sortResult == 0){
				printf("\nEmpleados ordenados por horas trabajadas con exito.\n");
			}
		break;
		case 4:
			printf("Ordenado empleados...\n");
			sortResult = ll_sort(pArrayListEmployee, sortEmployeeBySalary, orden);
			if(sortResult == 0){
				printf("\nEmpleados ordenados por sueldo con exito.\n");
			}
		break;
		}

	}
    return 1;
}

