#ifndef PARSER_H_
#define PARSER_H_

#include "Passenger.h"

/// @fn 		int parser_PassengerFromText(FILE*, LinkedList*)
/// @brief	Recibe el archivo ya abierto y el puntero de la linkedlist, hace una primera lectura en falso para saltear la primer linea
///					del archivoy luego entra a un do while hasta que se llegue al final del archivo(con la funcion feof) y en cada iteracion guarda
/// 					los datos en un auxiliar y si este es distinto de nulo lo añade a la linkedlist.
/// @param pFile puntero al archivo ya abierto
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return	TRUE si pudo realizar lectura de algun dato, FALSE si no.
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/// @fn 		int parser_PassengerFromBinary(FILE*, LinkedList*)
/// @brief	Si el archivo y el puntero al array son distintos de null, lee linea por linea obtiendo un pasajero a la vez
///					y si el id esta libre lo agrega a la linkedlist, en cambio si el id esta ocupado busca el primer id libre y lo
/// 					guarda ahi.
/// @param pFile puntero al archivo ya abierto
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return TRUE si pudo realizar lectura de algun dato, FALSE si no.
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */
