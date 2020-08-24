/*
 * funciones.c
 *
 *  Created on: 10 abr. 2020
 *      Author: Francisco
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pedirPrimerOperando(int a){
	printf("Ingrese el primer operando:\n");
	fflush(stdout);
	scanf("%d", &a);
	return a;
}
int pedirSegundoOperando(int b){
	printf("Ingrese el segundo operando:\n");
	fflush(stdout);
	scanf("%d", &b);
	return b;
}

int sumar(int a, int b){
	return a + b;
}
int restar(int a, int b){
	return a - b;
}
double multiplicar(int a, int b){
	return a * b;
}
float dividir(int a, int b){
	return (float)a / (float)b;
}

double devolverFactorial(int x){
	double resultado = x;
	for(int i = 1 ; i < x ; i++){
		resultado *= i;
	}
	return resultado;
}

void mostrarResultados(int a, int b, int suma, int resta, float division, double multiplicacion, double factorialA, double factorialB, bool bValeCero){
	printf("-------------------------------------------------------------\n");
	printf("El resultado de %d+%d es: %d\n", a, b, suma);
	printf("El resultado de %d-%d es: %d\n", a, b, resta);
	if(bValeCero){
		printf("No es posible dividir por cero\n");
	}
	else{
		printf("El resultado de %d/%d es: %.2f\n", a, b, division);
	}
	printf("El resultado de %d*%d es: %.0lf\n", a, b, multiplicacion);
	printf("El factorial de %d es: %.0lf. El factorial de %d es: %.0lf.\n", a, factorialA, b, factorialB);
	printf("-------------------------------------------------------------\n");
}

int mostrarMenu(int a, int b){
	int opcion;
	system("cls");
	printf("1- Ingresar 1er operando (A=%d)\n", a);
	printf("2- Ingresar 2do operando: (B=%d)\n", b);
	printf("3- Calcular todas las operaciones.\n");
	printf("4- Informar resultados.\n");
	printf("5- Salir.\n");
	printf("Ingrese una opcion.\n");
	fflush(stdout);
	scanf("%d", &opcion);
	return opcion;
}
