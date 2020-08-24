#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

int main(){
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	option = showMenu("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n",1 ,10, "\nIngrese una opcion valida.\n");
        switch(option){
            case 1:
            	if(ll_isEmpty(listaEmpleados)  == 1){
            		// ../ sirve para abrir el archivo csv desde el ejecutable dentro de debug
            		controller_loadFromText("../data.csv", listaEmpleados);
            	}
            	else{
            		printf("Ya hay empleados cargados\n");
            	}
			break;
            case 2:
            	if(ll_isEmpty(listaEmpleados)  == 1){
            		// ../ sirve para abrir el archivo csv desde el ejecutable dentro de debug
            		controller_loadFromBinary("../data.csv", listaEmpleados);
            	}
            	else{
            		printf("Ya hay empleados cargados\n");
            	}
			break;
            case 3:
            	controller_addEmployee(listaEmpleados);
			break;
            case 4:
            	if(ll_isEmpty(listaEmpleados)  == 1){
            		printf("No hay empleados cargados\n");
            	}
            	else{
            		controller_editEmployee(listaEmpleados);
            	}
			break;
            case 5:
            	if(ll_isEmpty(listaEmpleados)  == 1){
					printf("No hay empleados cargados\n");
				}
				else{
					controller_removeEmployee(listaEmpleados);
				}
			break;
            case 6:
            	if(ll_isEmpty(listaEmpleados)  == 1){
					printf("No hay empleados cargados\n");
				}
				else{
					controller_ListEmployee(listaEmpleados);
				}
			break;
            case 7:
            	if(ll_isEmpty(listaEmpleados)  == 1){
    				printf("No hay empleados cargados\n");
            	}
            	else{
            		controller_sortEmployee(listaEmpleados);
            	}
			break;
            case 8:
            	if(ll_isEmpty(listaEmpleados)  == 1){
					printf("No hay empleados cargados\n");
				}
				else{
            		// ../ sirve para abrir el archivo csv desde el ejecutable dentro de debug
                	controller_saveAsText("../data.csv", listaEmpleados);
				}
            break;
            case 9:
            	if(ll_isEmpty(listaEmpleados)  == 1){
					printf("No hay empleados cargados\n");
				}
				else{
            		// ../ sirve para abrir el archivo csv desde el ejecutable dentro de debug
                	controller_saveAsBinary("../data.csv", listaEmpleados);
				}
			break;

        }
    } while(option != 10);
    return 0;
}

