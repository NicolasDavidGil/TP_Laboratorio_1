/*
 * Menus.h
 *
 *  Created on: 25 abr. 2022
 *      Author: Gil Nicolás David
 */

#ifndef MENUS_H_
#define MENUS_H_

#include "ArrayPassenger.h"


/// @fn 		void MainMenu(ePassenger*, eCargaForzada*, int)
/// @brief 	es la unica llamada del main, aca se ejecuta el menu de opcion y se hacen las llamadas a todos los procesos del programa.
///
/// @param pasajero array de ePassenger con 2000 lugares.
/// @param cargaForzada array de ePassenger hardcodeado con 6 datos.
/// @param len Largo permitido para carga de pasajeros, es un define de 2000.
void MainMenu(void);

/// @fn 		int InteractiveMenu(void)
/// @brief	Es el menu de opciones que se invocara en el main siempre que se realice una iteracion, hasta que se elija la opcion
///					de salir del programa.
/// @return Devuelve la opcion que el usuario elija.
int InteractiveMenu(void);

/// @fn int MenuRequestID(char[])
/// @brief
///
/// @param mensaje
/// @return
int MenuRequestID(char mensaje[]);

/// @fn void MenuCase4(ePassenger*, int, int)
/// @brief
///
/// @param pasajero
/// @param len
/// @param contador
void MenuCase4(ePassenger* pasajero,  int len,  int contador);

/// @fn int SubMenuCase4(void)
/// @brief
///
/// @return
int SubMenuCase4(void);

/// @fn int MenuCase6(void)
/// @brief
///
/// @return
int MenuCase6 (void);



#endif /* MENUS_H_ */
