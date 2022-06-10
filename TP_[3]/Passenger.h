/*
 * 	Passenger.h
 * 	Created on: 19 may. 2022
 *		Author: Gil Nicolas David
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Inputs.h"

#define SIZE 50
#define MAX_PRICE 5000000 //se busco el precio mas caro pagado por un vuelo y se obtuvo este valor


typedef struct
{
	int id;
	char name[SIZE];
	char lastName[SIZE];
	float price;
	char typePassenger[SIZE]; // se trata como char desde un inicio para facilitar su manejo
	char flyCode[SIZE];
	char statusFlight[SIZE]; // se trata como char desde un inicio para facilitar su manejo
}Passenger;

/// @fn 		int InteractiveMenu(void)
/// @brief	Menu de opciones que se mostrar en la iteracion principal del programa.
///
/// @return la opcion ingresada por el usuario en formato int
int InteractiveMenu(void);

/// @fn 		Passenger Passenger_new*()
/// @brief	Crea espacio en memoria dinamica con la funcion malloc para una estructura del tipo pasajero
///					y devuelve el puntero a la misma.
/// @return	puntero al espacio en memoria dinamica creado. No verifica que sea null se debe hacer por fuera.
Passenger* Passenger_new();

/// @fn 		Passenger Passenger_newParameters*(char*, char*, char*, char*, char*, char*, char*)
/// @brief	Crea un espacio en memoria dinamica para un nuevo pasajero y le setea todos los datos recibidos
///					por parametros.
/// @param idStr id a setear en el nuevo pasajero.
/// @param nameStr nombre a setear en el nuevo pasajero.
/// @param lastName apellido a setear en el nuevo pasajero.
/// @param price precio a setear en el nuevo pasajero.
/// @param typePassengerStr tipo de pasajero a setear en el nuevo pasajero.
/// @param flyCode codigo de vuelo a setear en el nuevo pasajero.
/// @param statusFlight estado de vuelo a setear en el nuevo pasajero.
/// @return	puntero al espacio en memoria dinamica creado. No verifica que sea null se debe hacer por fuera.
Passenger* Passenger_newParameters(char* idStr, char* nameStr, char* lastName, char* price, char* typePassengerStr, char* flyCode, char* statusFlight);

/// @fn 		void Passenger_delete(LinkedList*, int)
/// @brief	Recibe un puntero a un nodo de pasajero, comprueba que sea distinto de nulo y si lo es le
///					realiza un free al nodo, la funcion de borrar pasajero se ocupa del remove.
/// @param this puntero al pasajero.
void Passenger_delete(Passenger* this);

/// @fn 		int Passenger_setId(Passenger*, int)
/// @brief	Si los parametros recibidos son distintos de null, setea el id recibido al pasajero.
///
/// @param this puntero al nodo del pasajero.
/// @param id entero que se ingresara como id del pasajero.
/// @return	TRUE si realizo el seteo FALSE si no.
int Passenger_setId(Passenger* this, int id);

/// @fn 		int Passenger_getId(Passenger*, int*)
/// @brief	Si los punteros que recibe por parametros son distintos de nulo, Copia el id que haya en el pasajero
///					en la direccion de memoria del puntero Id.
/// @param this	puntero al nodo del pasajero,
/// @param id	puntero a la variable que almacenara el id.
/// @return	TRUE si logro copiar el valor FALSE si no.
int Passenger_getId(Passenger* this, int* id);

/// @fn 		int Passenger_setName(Passenger*, char*)
/// @brief	Si los parametros recibidos son distintos de null, setea el nombre recibido al pasajero.
///
/// @param this puntero al nodo del pasajero.
/// @param name: array que se ingresara como nombre del pasajero.
/// @return TRUE si realizo el seteo FALSE si no.
int Passenger_setName(Passenger* this, char* name);

/// @fn 		int Passenger_getName(Passenger*, char*)
/// @brief	Si los punteros que recibe por parametros son distintos de nulo, Copia el nombre que haya
/// 					en el pasajero en la direccion de memoria del puntero Name.
///
/// @param this	puntero al nodo del pasajero.
/// @param name puntero a la variable que almacenara el nombre.
/// @return	TRUE si logro copiar el valor FALSE si no.
int Passenger_getName(Passenger* this, char* name);

/// @fn 		int Passenger_setLastName(Passenger*, char*)
/// @brief	Si los parametros recibidos son distintos de null, setea el apellido recibido al pasajero.
///
/// @param this puntero al nodo del pasajero.
/// @param lastName: array que se ingresara como apellido del pasajero.
/// @return	TRUE si realizo el seteo FALSE si no.
int Passenger_setLastName(Passenger* this, char* lastName);

/// @fn 		int Passenger_getLastName(Passenger*, char*)
/// @brief	Si los punteros que recibe por parametros son distintos de nulo, Copia el apellido que haya
///					en el pasajero en la direccion de memoria del puntero lastName.
/// @param this puntero al nodo del pasajero.
/// @param lastName: puntero a la variable que almacenara el apellido.
/// @return	TRUE si logro copiar el valor FALSE si no.
int Passenger_getLastName(Passenger* this, char* lastName);

/// @fn 		int Passenger_setFlyCode(Passenger*, char*)
/// @brief	Si los parametros recibidos son distintos de null, setea el codigo de vuelo
/// 					recibido al pasajero.
///
/// @param this puntero al nodo del pasajero.
/// @param flyCode array que se ingresara como codigo de vuelo del pasajero.
/// @return TRUE si realizo el seteo FALSE si no.
int Passenger_setFlyCode(Passenger* this, char* flyCode);

/// @fn 		int Passenger_getFlyCode(Passenger*, char*)
/// @brief	Si los punteros que recibe por parametros son distintos de nulo, Copia el codigo de vuelo
///					 que haya en el pasajero en la direccion de memoria del puntero flyCode.
/// @param this puntero al nodo del pasajero.
/// @param flyCode puntero a la variable que almacenara el codigo de vuelo.
/// @return	TRUE si logro copiar el valor FALSE si no.
int Passenger_getFlyCode(Passenger* this, char* flyCode);

/// @fn 		int Passenger_setTypePassenger(Passenger*, char*)
/// @brief	Si los parametros recibidos son distintos de null, setea el tipo de pasajero
///					recibido al pasajero.
/// @param this puntero al nodo del pasajero.
/// @param typePassenger array que se ingresara como tipo de pasajero, del pasajero.
/// @return TRUE si realizo el seteo FALSE si no.
int Passenger_setTypePassenger(Passenger* this, char* typePassenger);

/// @fn 		int Passenger_getTypePassenger(Passenger*, char*)
/// @brief	Si los punteros que recibe por parametros son distintos de nulo, Copia el tipo de pasajero
/// 					que haya en el pasajero en la direccion de memoria del puntero typePassenger.
///
/// @param this puntero al nodo del pasajero.
/// @param typePassenger puntero a la variable que almacenara el tipo de pasajero.
/// @return	TRUE si logro copiar el valor FALSE si no.
int Passenger_getTypePassenger(Passenger* this, char* typePassenger);

/// @fn 		int Passenger_setPrice(Passenger*, float)
/// @brief	Si los parametros recibidos son distintos de null, setea el precio recibido al pasajero.
///
/// @param this puntero al nodo del pasajero.
/// @param price flaot que se ingresara como precio de vuelo del pasajero.
/// @return	TRUE si logra hacer el seteo, FALSE si no.
int Passenger_setPrice(Passenger* this, float price);

/// @fn 		int Passenger_getPrice(Passenger*, float*)
/// @brief	Si los punteros que recibe por parametros son distintos de nulo, Copia el precio
///					que haya en el pasajero en la direccion de memoria del puntero price.
/// @param this puntero al nodo del pasajero.
/// @param price puntero a la variable que almacenara el precio del vuelo.
/// @return	TRUE si logro copiar el valor FALSE si no.
int Passenger_getPrice(Passenger* this, float* price);

/// @fn 		int Passenger_setStatusFlight(Passenger*, char*)
/// @brief	Si los parametros recibidos son distintos de null, setea el estado de vuelo
///					recibido al pasajero.
/// @param this puntero al nodo del pasajero.
/// @param statusFlight array que se ingresara como estado de vuelo del pasajero.
/// @return	TRUE si logra hacer el seteo, FALSE si no.
int Passenger_setStatusFlight(Passenger* this, char* statusFlight);

/// @fn 		int Passenger_getStatusFlight(Passenger*, char*)
/// @brief	Si los punteros que recibe por parametros son distintos de nulo, Copia el estado de
///					vuelo que haya en el pasajero en la direccion de memoria del puntero statusFlight.
///
/// @param this puntero al nodo del pasajero.
/// @param statusFlight puntero a la variable que almacenara el estado de vuelo.
/// @return	TRUE si logro copiar el valor FALSE si no.
int Passenger_getStatusFlight(Passenger* this, char* statusFlight);

/// @fn 			int passenger_findPassengerById(LinkedList*, int)
/// @brief		Si los parametros recibidos son correcto, itenarara a lo largo de la linkedlist, en cada iteracion
/// 					guardara el pasajero en un auxiliar y obtendra el id del mismo, para luego compararlo con el id que se
/// 					recibio por parametro, si encuentra la igualda retorna el indice y rompe la iteracion.
///
/// @param pArrayPassenger puntero a la linkedlist.
/// @param id	valor para buscar el pasajero.
/// @return	El indice o variable de iteracion si encontro el pasajero, FALSE si no.
int passenger_findPassengerById(LinkedList* pArrayPassenger, int id);

/// @fn 			void passenger_printOnePassenger(LinkedList*, int)
/// @brief		Obtiene al pasajero correspondienter al indice recibido por parametro en un auxiliar,
/// 					y si es distinto de nulo lo imprime por pantalla.
///
/// @param pArrayPassenger puntero a la linkedlist.
/// @param index	indice correspondiente al pasajero.
void passenger_printOnePassenger(LinkedList* pArrayPassenger, int index);

/// @fn 			void PrintTitle(void)
/// @brief		Imprime por pantalla una cabecera para la impresion de los pasajeros.
///
void PrintTitle(void);

/// @fn 			int passenger_SortByName(void*, void*)
/// @brief		Establece criterio de comparacion entre dos pasajeros por nombre para
///						usar en la funcion ll_sort.
/// @param 	pOne	puntero generico
/// @param 	pTwo puntero generico
/// @return 	el resultado de la comparacion.
int passenger_SortByName(void* pOne, void* pTwo);

/// @fn 			int passenger_SortByLastName(void*, void*)
/// @brief 		Establece criterio de comparacion entre dos pasajeros por apellido para
///						usar en la funcion ll_sort.
/// @param 	pOne puntero generico
/// @param 	pTwo puntero generico
/// @return 	el resultado de la comparacion.
int passenger_SortByLastName(void* pOne, void* pTwo);

/// @fn 			int passenger_SortByFlyCode(void*, void*)
/// @brief		Establece criterio de comparacion entre dos pasajeros por codigo de vuelo
/// 					 para usar en la funcion ll_sort.
/// @param 	pOne puntero generico.
/// @param 	pTwo puntero generico
/// @return 	el resultado de la comparacion.
int passenger_SortByFlyCode(void* pOne, void* pTwo);

/// @fn 			int passenger_SortByTypePassenger(void*, void*)
/// @brief 		Establece criterio de comparacion entre dos pasajeros por tipo de pasajero
///						para usar en la funcion ll_sort.
/// @param 	pOne puntero generico.
/// @param 	pTwo puntero generico.
/// @return	el resultado de la comparacion.
int passenger_SortByTypePassenger(void* pOne, void* pTwo);

/// @fn			int passenger_SortByStatus(void*, void*)
/// @brief		Establece criterio de comparacion entre dos pasajeros por estado de vuelo
///						para usar en la funcion ll_sort.
/// @param 	pOne puntero generico.
/// @param 	pTwo puntero generico.
/// @return	el resultado de la comparacion.
int passenger_SortByStatus(void* pOne, void* pTwo);

/// @fn 			int passenger_SortByPrice(void*, void*)
/// @brief		Establece criterio de comparacion entre dos pasajeros por precio
///						para usar en la funcion ll_sort.
/// @param 	pOne puntero generico.
/// @param 	pTwo puntero generico.
/// @return	el resultado de la comparacion.
int passenger_SortByPrice(void* pOne, void* pTwo);

/// @fn 		int passenger_SortById(void*, void*)
/// @brief 	Establece criterio de comparacion entre dos pasajeros por id
/// 					para usar en la funcion ll_sort.
/// @param 	pOne puntero generico.
/// @param	pTwo puntero generico.
/// @return	el resultado de la comparacion.
int passenger_SortById(void* pOne, void* pTwo);

/// @fn 			void passenger_setLastID(char*, int)
/// @brief		Abre el archivo desde la ruta recibida como parametro y le escribe el id
///						recibido como parametro, qeu sera el mayor.
/// @param 	path ruta de acceso al archivo.
/// @param 	id	valor a escribir en el archivo.
void passenger_setLastID(char* path, int id);

/// @fn 			int passenger_getMaxId(char*)
/// @brief		Abre el archivo desde la ruta recibida como parametro y lee el valor que contiene
/// 					el mismo, lo convierte a entero y lo guarda en una variable para retornarlo.
///
/// @param 	path ruta de acceso al archivo.
/// @return	valor que haya leido en el archivo o FALSE si no logro leer nada.
int passenger_getLastId(char* path);

/// @fn 			void TypeMenu(char*)
/// @brief		Menu de opciones para elegir el tipo de pasajero.
///						La opcion elegida se guarda en el puntero recibido por parametro.
/// @param 	retorno direccion de memoria que almacenara la opcion elegida.
void passenger_TypeMenu(char* retorno);

/// @fn 			void StatusMenu(char*)
/// @brief	 	Menu de opciones para elegir el estado de vuelo.
///						La opcion elegida se guarda en el puntero recibido por parametro.
/// @param 	retorno direccion de memoria que almacenara la opcion elegida.
void passenger_StatusMenu(char* retorno);

#endif /* PASSENGER_H_ */
