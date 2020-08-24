#include "funciones.h"
#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/** \brief guarda lugar en memoria para ingresar un empleado
 * \param void
 * \return Employee*
 */
Employee* employee_new(){
	Employee* auxEmpleado = NULL;
	auxEmpleado = (Employee*)malloc(sizeof(Employee));
	return auxEmpleado;
}

/** \brief crea un empleado con sus campos
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldo
 * \return Employee*
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo){
	int empleadoCargado = 0;
	Employee* employee = NULL;
	employee = employee_new();
	if(employee != NULL){
		if(employee_setNombre(employee, nombreStr) == 0 &&
				employee_setId(employee, atoi(idStr)) == 0 &&
				employee_setHorasTrabajadas(employee, atoi(horasTrabajadasStr)) == 0 &&
				employee_setSueldo(employee, atoi(sueldo)) == 0){
			empleadoCargado = 1;
		}
		else{
			printf("Empleado %s no cargado\n", nombreStr);
		}
	}
	if(empleadoCargado == 1){
		return employee;
	}
	return NULL;
}

/** \brief libera un empleado
 * \param Employee* this
 * \return void
 */
void employee_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

/** \brief setter de id de empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int employee_setId(Employee* this, int id){
	int ret = -1;
	if(this != NULL && id >= 0){
		ret = 0;
		this->id = id;
	}
	return ret;
}

/** \brief getter de id de empleado
 * \param Employee* this
 * \param int* id
 * \return int
 */
int employee_getId(Employee* this,int* id){
	int ret = -1;
	if(this != NULL && id != NULL){
		ret = 0;
		*id = this->id;
	}
	return ret;
}

/** \brief setter de nombre de empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int employee_setNombre(Employee* this, char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		//VERIFICO QUE NO HAYA VALORES NUMERICOS
		if(validateName(nombre, LONGNOMBRE)){
			ret = 0;
			strncpy(this->nombre, nombre, LONGNOMBRE);
		}
	}
	return ret;
}

/** \brief getter de nombre de empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int employee_getNombre(Employee* this,char* nombre){
	int ret = -1;
	if(this != NULL && nombre != NULL){
		ret = 0;
		strncpy(nombre, this->nombre, LONGNOMBRE);
	}
	return ret;
}

/** \brief setter de horas trabajadas de empleado
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 */
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
	int ret = -1;
	if(this != NULL && horasTrabajadas >= 0){
		ret = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return ret;
}

/** \brief getter de horas trabajadas de empleado
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 */
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
	int ret = -1;
	if(this != NULL && horasTrabajadas != NULL){
		ret = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return ret;
}

/** \brief setter de sueldo de empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int employee_setSueldo(Employee* this, int sueldo){
	int ret = -1;
	if(this != NULL && sueldo >= 0){
		ret = 0;
		this->sueldo = sueldo;
	}
	return ret;
}

/** \brief getter de sueldo de empleado
 * \param Employee* this
 * \param int* sueldo
 * \return int
 */
int employee_getSueldo(Employee* this,int* sueldo){
	int ret = -1;
	if(this != NULL && sueldo != NULL){
		ret = 0;
		*sueldo = this->sueldo;
	}
	return ret;
}

/** \brief modificador de nombre de empleado
 * \param Employee* auxEmp
 * \return void
 */
void modificarNombre(Employee* auxEmp){
	int len;
	char nuevoNombre[20];
	int setReturn;
	printf("\nIngrese el nombre\n");
	fflush(stdin);
	fgets(nuevoNombre, sizeof(nuevoNombre), stdin);
	len = strlen(nuevoNombre);
		if( nuevoNombre[len-1] == '\n' )
			nuevoNombre[len-1] = 0;
	setReturn = employee_setNombre(auxEmp, nuevoNombre);
	if(setReturn == 0){
		printf("\nNombre modificado con exito\n");
	}
	else{
		printf("\nOcurrio un problema al modificar el nombre\n");
	}
}

/** \brief modificador de horas de empleado
 * \param Employee* auxEmp
 * \return void
 */
void modificarHoras(Employee* auxEmp){
	int nuevasHorasTrabajadas;
	int setReturn;

	nuevasHorasTrabajadas = getInt("\nIngrese las horas trabajadas\n", 0, 200, "\nIngrese un valor entre 0 y 200.\n");
	setReturn = employee_setHorasTrabajadas(auxEmp, nuevasHorasTrabajadas);
	if(setReturn == 0){
		printf("\nHoras modificadas con exito\n");
	}
	else{
		printf("\nOcurrio un problema al modificar las horas\n");
	}
}

/** \brief modificador de sueldo de empleado
 * \param Employee* auxEmp
 * \return void
 */
void modificarSueldo(Employee* auxEmp){
	int nuevoSueldo;
	int setReturn;
	nuevoSueldo = getInt("\nIngrese el sueldo\n", 0, 100000, "\nIngrese un valor entre 0 y 100000.\n");
	setReturn = employee_setSueldo(auxEmp, nuevoSueldo);
	if(setReturn == 0){
		printf("\nSueldo modificado con exito\n");
	}
	else{
		printf("\nOcurrio un problema al modificar el sueldo\n");
	}

}

/** \brief hace un print del empleado
 * \param Employee* auxEmp
 * \return void
 */
void mostrarEmpleado(Employee* auxEmp){
	printf("%6d - %18s - %9d - %10d\n", auxEmp->id, auxEmp->nombre, auxEmp->horasTrabajadas, auxEmp->sueldo);
}

/** \brief ordenador de empleados por id
 * \param void* empleado1
 * \param void* empleado2
 * \return int
 */

int sortEmployeeById(void* empleado1, void* empleado2){
	 int retorno;
	 int idEmpleado1;
	 int idEmpleado2;
	 if(empleado1 != NULL && empleado2 != NULL){
		 Employee* auxEmp1 = (Employee*) empleado1;
		 Employee* auxEmp2 = (Employee*) empleado2;
		 employee_getId(auxEmp1, &idEmpleado1);
		 employee_getId(auxEmp2, &idEmpleado2);
		 if(idEmpleado1 > idEmpleado2){
			 retorno = 1;
		 }
		 else if (idEmpleado1 < idEmpleado2){
			 retorno = -1;
		 }
		 else{
			 retorno = 0;
		 }
	 }
	 return retorno;
}

/** \brief ordenador de empleados por nombre
 * \param void* empleado1
 * \param void* empleado2
 * \return int
 */

int sortEmployeeByName(void* empleado1, void* empleado2){
	 int retorno;
	 char nombreEmpleado1[64];
	 char nombreEmpleado2[64];
	 if(empleado1 != NULL && empleado2 != NULL){
		 Employee* auxEmp1 = (Employee*) empleado1;
		 Employee* auxEmp2 = (Employee*) empleado2;
		 employee_getNombre(auxEmp1, nombreEmpleado1);
		 employee_getNombre(auxEmp2, nombreEmpleado2);
		 retorno = strcmp(nombreEmpleado1, nombreEmpleado2);
	 }
	 return retorno;
}

/** \brief ordenador de empleados por horas trabajadas
 * \param void* empleado1
 * \param void* empleado2
 * \return int
 */

int sortEmployeeByHours(void* empleado1, void* empleado2){
	 int retorno;
	 int horasEmpleado1;
	 int horasEmpleado2;
	 if(empleado1 != NULL && empleado2 != NULL){
		 Employee* auxEmp1 = (Employee*) empleado1;
		 Employee* auxEmp2 = (Employee*) empleado2;
		 employee_getHorasTrabajadas(auxEmp1, &horasEmpleado1);
		 employee_getHorasTrabajadas(auxEmp2, &horasEmpleado2);
		 if(horasEmpleado1 > horasEmpleado2){
			 retorno = 1;
		 }
		 else if (horasEmpleado1 < horasEmpleado2){
			 retorno = -1;
		 }
		 else{
			 retorno = 0;
		 }
	 }
	 return retorno;
}

/** \brief ordenador de empleados por sueldo
 * \param void* empleado1
 * \param void* empleado2
 * \return int
 */

int sortEmployeeBySalary(void* empleado1, void* empleado2){
	 int retorno;
	 int sueldoEmpleado1;
	 int sueldoEmpleado2;
	 if(empleado1 != NULL && empleado2 != NULL){
		 Employee* auxEmp1 = (Employee*) empleado1;
		 Employee* auxEmp2 = (Employee*) empleado2;
		 employee_getSueldo(auxEmp1, &sueldoEmpleado1);
		 employee_getSueldo(auxEmp2, &sueldoEmpleado2);
		 if(sueldoEmpleado1 > sueldoEmpleado2){
			 retorno = 1;
		 }
		 else if (sueldoEmpleado1 < sueldoEmpleado2){
			 retorno = -1;
		 }
		 else{
			 retorno = 0;
		 }
	 }
	 return retorno;
}














