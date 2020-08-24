/*
 * funciones.h
 * Author: Francisco
 */
#include "stdbool.h"
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/*
 * Recibe: Los nuemros con los que se esta trabajando y muestra un menu de opciones.
 * Devuelve: int opcion elegida
 * Params: int a, int b
 */
int mostrarMenu(int a, int b);

/*
 * Recibe: Los numeros con los que se esta trabajando y se devuelve el nuevo ingresado por el usuario
 * Devuelve: int a elegido por el usuario
 * Params: int a
*/
int pedirPrimerOperando(int a);

/*
 * Recibe: Los numeros con los que se esta trabajando y se devuelve el nuevo ingresado por el usuario
 * Devuelve: int b elegido por el usuario
 * Params: int b
*/
int pedirSegundoOperando(int b);

/*
 * Recibe: Los numeros con los que se esta trabajando y los suma
 * Devuelve: int suma
 * Params: int a, int b
 */
int sumar(int a, int b);

/*
 * Recibe: Los numeros con los que se esta trabajando y los resta.
 * Devuelve: int resta
 * Params: int a, int b
 */
int restar(int a, int b);

/*
 * Recibe: Los numeros con los que se esta trabajando y los multiplica
 * Devuelve: double multiplicacion (se utiliza double por si el usuario ingresa numeros muy altos)
 * Params: int a, int b
 */
double multiplicar(int a, int b);

/*
 * Recibe: Los numeros con los que se esta trabajando y los divide
 * Devuelve: float division
 * Params: int a, int b
 */
float dividir(int a, int b);

/*
 * Recibe: El numero al que se le quiere calcular el factorial
 * Devuelve: double factorial ((se utiliza double por si el usuario ingresa numeros muy altos)
 * Params: int x
 */
double devolverFactorial(int x);

/*
 * Recibe: Todos las operaciones matematicas que se realizaron y booleanos de validaciones
 * void
 * Params: int a, int b, int suma, int resta, float division, double multiplicacion, double factorialA, double factorialB, bool bValeCero
 */
void mostrarResultados(int a, int b, int suma, int resta, float division, double multiplicacion, double factorialA, double factorialB, bool bValeCero);


#endif /* FUNCIONES_H_ */
