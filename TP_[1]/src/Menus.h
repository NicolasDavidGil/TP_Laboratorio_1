/*
 * Menus.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Gil Nicolás David
 */

#ifndef MENUS_H_
#define MENUS_H_

#include "Calculos.h"

/// @fn 	void MenuPrincipal(void)
/// @brief 	Es la unico función invocada en el main, desde esta se invocaran a todas las demas para que el programa funcione.
/// 		No retorna nada ya que el programa termina dentro de ella.
void MenuPrincipal(void);

/// @fn 	void MenuInteractivo(double, double, double)
/// @brief 	Funcion que contiene el despliegue del menu interactivo. Se invoca varias veces con distintos
/// 		parametros dependiendo los ingresos del usuario.
/// @param 	kilometros tiene un flag, al estar en 0 se pasa 0 y al estar en 1 el valor que ha ingresado el usuario,
/// @param 	AeroArg tiene un flag, al estar en 0 se pasa 0 y al estar en 1 el valor que ha ingresado el usuario,
/// @param 	Latam tiene un flag, al estar en 0 se pasa 0 y al estar en 1 el valor que ha ingresado el usuario,
int MenuInteractivo(double kilometros, double AeroArg, double Latam);

#endif /* MENUS_H_ */
