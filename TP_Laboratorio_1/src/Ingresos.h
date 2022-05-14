/*
 * Ingresos.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Gil Nicol�s David
 */

#ifndef INGRESOS_H_
#define INGRESOS_H_

/// @fn 	double PedirIngresoNumero(char[])
/// @brief 	Pide al usuario el ingreso de una cadena. Correspondera al costo del vuelo o a los kilometros del mismo.
///			Invoca a la funci�n ValidarIngresoNumeros() y luego de ser validada la convierte a flotante.
/// @param 	mensajeKilometros o mensajeVuelos, cadena definidas al principio, usadas segun el caso.
/// @return	N�mero v�lidado tanto para kilometros como para coste de vuelo en formato double.
double PedirIngresoNumero(char mensaje[]);

/// @fn 	int ValidarIngresoNumeros(char[])
/// @brief	Recibe una cadena de la funci�n PedirIngresoNumero() y v�lida que solo contenga numeros..
///			Solo se invoca al usarse la funcion de pedir numero.
/// @param 	Recibe la cadena que se pidio en funcion PedirIngresoNumero().
/// @return	1 si el numero es correcto y 0 si no.
int ValidarIngresoNumeros(char numero[]);

#endif /* INGRESOS_H_ */
