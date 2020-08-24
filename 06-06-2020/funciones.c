#include "funciones.h"
#include <stdio.h>
#include <ctype.h>

/** \brief muestra un menu y si la opcion no esta entre las posibles muestra un mensaje de error
 * \param char message[]
 * \param int min
 * \param int max
 * \param char errorMessage[]
 * \return int
 */
int showMenu(char message[], int min, int max, char errorMessage[]){
	printf(message);
	int option;
	scanf("%d", &option);
	while(option < min || option > max){
		printf(errorMessage);
		scanf("%d", &option);
	}
	return option;
}

/** \brief valida el nombre ingresado. se aceptan nombres con espacios y guiones
 * \param char* name
 * \param int len
 * \return int
 */
int validateName(char* name, int len){
	int i = 0;
	int ret = 1;
	if(name != NULL && len > 0){
		for(i = 0 ; name[i] != '\0' && i < len; i++){
			if((name[i] < 'A' || name[i] > 'Z' ) && (name[i] < 'a' || name[i] > 'z' ) && name[i] != ' ' && name[i] != '-'){
				ret = 0;
				break;
			}
		}
	}
	return ret;
}

/** \brief permite el ingreso de valores enteros entre limites
 * \param char message[]
 * \param int min
 * \param int max
 * \param char errorMessage[]
 * \return int
 */
int getInt(char message[], int min, int max, char errorMessage[]){
	int number;
	printf(message);
	scanf("%d", &number);
	while(number < min || number > max){
		printf(errorMessage);
		scanf("%d", &number);
	}
	return number;
}


/** \brief permite el ingreso de un char entre dos valores
 * \param char message[]
 * \param char opcionUno
 * \param char opcionDos
 * \param char errorMessage[]
 * \return char
 */
char getChar(char message[], char opcionUno, char opcionDos, char errorMessage[]){
	char response;
	printf("\n%s\n", message);
	fflush(stdin);
	scanf("%c", &response);
	while (tolower(response) != opcionUno && tolower(response) != opcionDos){
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%c", &response);
	}
	return tolower(response);
}











