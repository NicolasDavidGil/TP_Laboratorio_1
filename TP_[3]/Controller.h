#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "parser.h"


/// @fn 		void controller_MainMenu(void)
/// @brief 	Primera y unica funcion que se carga desde el main, consulta al menu interctativo para obtener la opcion introducida e invoca
/// 					a los controller correspondientes a cada caso.
///
void controller_MainMenu(void);

/// @fn 			int controller_loadFromText(char*, LinkedList*)
/// @brief		abre el archivo, comprueba que ninguno de los parametros sean nulos y llama a la funcion de parser texto pasandole el archivo ya abierto.
/// 						Si el parser lo leyo y cargo de manera correcta o no, el controller lo cerrara de igual manera.
///
/// @param 		path: ruta del archivo que se debe abrir
/// @param 		pArrayListPassenger: puntero a la primera posicion de la linkedlist
/// @return		TRUE si no se produjo error alguno, FALSE si algo fallo.
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/// @fn 		int controller_loadFromBinary(char*, LinkedList*)
/// @brief	abre el archivo, comprueba que ninguno de los parametros sean nulos y llama a la funcion de parser binario pasandole el archivo ya abierto
///					Si el parser lo leyo y cargo de manera correcta o no, el controller lo cerrara de igual manera.
/// @param 	path: ruta del archivo que se debe abrir
/// @param 	pArrayListPassenger: puntero a la primera posicion de la linkedlist
/// @return	TRUE si no se produjo error alguno, FALSE si algo fallo.
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// @fn 		int controller_addPassenger(LinkedList*)
/// @brief	Obtiene el primer id libre a traves del archivo IdMax y pide al usuario los datos para completar los demas campos
///					de la estructura. Luego pasa dichos datos a Passenger_newParameters, si se pudo generar el pasajero lo añade a la
/// 					linkedlist y escribira el nuevo id maximo en el archivo IdMax.txt.
/// @param 	pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return	TRUE si no hubo errores, FALSE si los hubo.
int controller_addPassenger(LinkedList* pArrayListPassenger);

/// @fn 		int controller_editPassenger(LinkedList*)
/// @brief	Solicita al usuario el ingreso del id a modificar, realiza una busqueda para ver si ese id existe, es caso afirmativo lo
/// 					imprime e invoca un menu para elegir que campo de la estructura modificar. Si el ingreso es valido setea la modificacion
///					en el pasajero. En caso de no encontrar el id, lo notifica y regresa al menu principal.
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return	TRUE si se realizo alguno modificacion y FALSE si no,
int controller_editPassenger(LinkedList* pArrayListPassenger);

/// @fn 		int controller_removePassenger(LinkedList*)
/// @brief	Solicita al usuario el ingreso del id que se desea eliminar, realiza una busqueda para ver si el id ingresado pertenece a un
/// 					pasajero, si lo encuentra imprime dicho pasajero y pide confimacion al usuario para su eliminacion. Si el usuario lo confirma
/// 					procede a eliminar el pasajero al que pertenece el id ingresado y a eliminar el nodo en el que se encontraba.
///					Si no existe el id o el pasajero cancela la eliminacion, el programa lo informa y regresara al menu principal.
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return TRUE si se realizo la eliminacion de algun pasajero, FALSE si no se elimino.
int controller_removePassenger(LinkedList* pArrayListPassenger);

/// @fn 		int controller_ListPassenger(LinkedList*)
/// @brief	Obtiene la longitud de la linkedlist, si no es nulo imprime una vez el titulo por medio de la funcion print_Title y entra
/// 					a un ciclo for invocando en cada iteracion a la funcion passenger_printOnePassenger pasandole a la misma la variable de
///					iteracion.
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return	TRUE si se realizo algun impresion FALSE si no.
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/// @fn 		int controller_sortPassenger(LinkedList*)
/// @brief	Inicia llamando a controller_SortMenu y luego pide si se debe hacer de manera ascendente o descendiente,
/// 					segun las opciones que devuelvan ordena a los pasajeros por esos criterios.
///
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return	TRUE si realizo algun ordenamiento y FALSE si no.
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// @fn 		int controller_SortMenu(void)
/// @brief	Simple menu para pedir al usuario una opcion. En este caso esa opcion dependera de con que criterio quiera
/// 					el usuario ordenar a los pasajeros. Nombre, apellido, etc.
/// @return	La opcion ingresada por el usuario en formato int.
int controller_SortMenu(void);

/// @fn 		int controller_OrderMenu(void)
/// @brief	Simple menu para pedir al usuario una opcion. En este caso sera segun el modo en que el usuario
///					quiera ordenar, se manera descendente o ascendente.
/// @return	La opcion ingresada por el usuario en formato int.
int controller_OrderMenu(void);

/// @fn 		int controller_saveAsText(char*, LinkedList*)
/// @brief	Abre el archivo y empieza a recorrer la linkedlist, en cada iteracion obtendra el pasajero y todos los campos de
///					la estructura en variables auxiliares y por ultimo hara una escritura en el archivo de texto.
/// 					Al final de la iteracion se produce el cierre del archivo.
/// @param path ruta al archivo en el que se desea salvar los datos.
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return TRUE si pudo realizar el salvado, FALSE si fallo.
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/// @fn 		int controller_saveAsBinary(char*, LinkedList*)
/// @brief	Abre el archivo y empieza a recorrer la linkedlist, en cada iteracion obtendra el pasajero
///					en una variable auxiliar y por ultimo hara una escritura en el archivo de texto.
///					Al final de la iteracion se produce el cierre del archivo.
/// @param path ruta al archivo en el que se desea salvar los datos.
/// @param pArrayListPassenger puntero a la primera posicion de la linkedlist
/// @return	TRUE si pudo realizar el salvado, FALSE si fallo.
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/// @fn 		int controller_ModificationMenu(void)
/// @brief	Simple menu de opciones para cuando se quiere modificar un pasajero, pide una opcion al usuario
/// 					y la devuelve a la funcion controller_editPassenger.
///
/// @return	la opcion ingresada por el usuario en formato int.
int controller_ModificationMenu(void);

/// @fn int controller_ExitMenu(void)
/// @brief
///
/// @return
int controller_ExitMenu(void);

#endif /* CONTROLLER_H_ */
