/*
 * Calculos.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Gil Nicolás David
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @fn 	void IniciarCargaForzada(void)
/// @brief 	Utilizada solo en el case 5, esta funcion realiza todos los calculos y muestra los resultados por la pantalla a partir de parametros
/// 		pasados en cosigna y hardcodeados.
void IniciarCargaForzada(void);

/// @fn 	double CuentaDebCreBit(double, int)
/// @brief	Esta creada para por hacer los 3 calculos solicitados, 10% de descuento, 25% de interes y precio en bitcoin, el parametro "aux" es el que determina
///			que funcion de llevara a cabo. Se pasa por hardcodeo.
/// @param 	precio: de la aerolinea con la que estamos esperando.
/// @param 	aux, determina que cuenta se hace: 1 - Descuento 10%; 2 - Interes 25%; 3 - Precio en bitcoin.
/// @return	El resultado de la operacion solicitada.
double CuentaDebCreBit(double precio, int aux);

/// @fn 	float CalcularDiferenciaPrecioKilometro(float, float, int)
/// @brief 	Recibe dos valores por parametro y una auxiliar, si aux es 1 divide el parametro 1 por el 2 y si aux es 2, los compara y al
/// 		mayor le resta el menor.
/// @param 	precio1 precio de una aerolinea
/// @param 	precio2 si aux es 1 sera los km ingresados, para aux 2 el otro precio de la otra aerolinea.
/// @param 	aux determina que operacion realizar: 1 division para precio por km. 2 resta para dif de costo de vuelos.
/// @return	el resultado de la operacion solicitada.
float CalcularDiferenciaPrecioKilometro(float precio1, float precio2, int aux);

#endif /* CALCULOS_H_ */
