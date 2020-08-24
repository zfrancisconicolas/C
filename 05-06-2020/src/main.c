/*
 * main.c
 *	Author: Francisco Zanotti
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funciones.h"


int main(){
	int opcion;
	int a = 0;
	int b = 0;
	int suma;
	int resta;
	float division;
	double multiplicacion;
	double factorialA;
	double factorialB;
	bool seCalcularonLasOperaciones = false;
	bool bValeCero = false;
	do{
		opcion = mostrarMenu(a, b);
		switch(opcion){
			case 1:
				a = pedirPrimerOperando(a);
			break;
			case 2:
				b = pedirSegundoOperando(b);
			break;
			case 3:
				suma = sumar(a, b);
				resta = restar(a, b);
				multiplicacion = multiplicar (a, b);
				factorialA = devolverFactorial(a);
				factorialB = devolverFactorial(b);
				if(b == 0){
					bValeCero = true;
				}
				else{
					division = dividir(a, b);
				}
				seCalcularonLasOperaciones = true;
			break;
			case 4:
				if(seCalcularonLasOperaciones){
					mostrarResultados(a, b, suma, resta, division, multiplicacion, factorialA, factorialB, bValeCero);
				}
				else{
					printf("\n\nDebe seleccionar la opcion 3 antes de informar los resultados.\n\n");
				}
				system("pause");
			break;
		}
	}
	while(opcion != 5);
	return 0;
}
