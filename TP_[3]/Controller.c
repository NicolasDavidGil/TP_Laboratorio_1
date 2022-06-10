#include "Controller.h"
/*
 * "1 - Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
	"2 - Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
	"3 - Alta de pasajero.\n"
	"4 - Modificar datos de pasajero.\n"
	"5 - Baja de pasajero.\n"
	"6 - Listar pasajeros.\n"
	"7 - Ordenar pasajeros.\n"
	"8 - Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
	"9 - Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
	"10 - Salir del programa.\n"
 */

void controller_MainMenu(void)
{
	int option;
	int exitOption;
	int flagBin;
	int flagTxt;

	LinkedList* passengerList = ll_newLinkedList();

	flagTxt = TRUE;
	flagBin = TRUE;

	do{
		option = InteractiveMenu();
		switch(option)
		{
			case 1:
				if(flagTxt == TRUE && flagBin == TRUE)
				{
					if(controller_loadFromText("data.csv", passengerList) == TRUE)
					{
						flagTxt = FALSE;
					}
				}else
				{
					printf("\n=======================================================================================================================\n"
								"Ya se ha realizado la carga de un archivo.\n"
								"========================================================================================================================\n");
				}
				break;
			case 2:
				if(flagTxt == TRUE && flagBin == TRUE)
				{
					if(controller_loadFromBinary("dataBin.bin", passengerList) == TRUE)
					{
						printf("\n=======================================================================================================================\n"
									"Archivo cargado correctamente.\n"
									"=======================================================================================================================\n");
						flagBin = FALSE;
					}else
					{
						printf("\n=======================================================================================================================\n"
									"No se ha podido cargar el archivo.\n"
									"=======================================================================================================================\n");
					}
				}else
				{
					printf("\n=======================================================================================================================\n"
								"Ya se realizo la carga de un archivo.\n"
								"=======================================================================================================================\n");
				}
				break;
			case 3:
				if(controller_addPassenger(passengerList) == TRUE)
				{
					printf("\n========================================================================================================================\n"
								"Pasajero agregado correctamente.\n"
								"==========================================================================================================================\n");
				}else
				{
					printf("\n========================================================================================================================\n"
								"Error en la carga del pasajero.\n"
								"=========================================================================================================================\n");
				}
				break;
			case 4:
				if(ll_isEmpty(passengerList) != 1)
				{
					if(controller_editPassenger(passengerList) != FALSE)
					{
						printf("\n========================================================================================================================\n"
									"Pasajero modificado exitosamente.\n"
									"=========================================================================================================================\n");
					}else
					{
						printf("\n=======================================================================================================================\n"
									"Modificacion de pasajero cancelada.\n"
									"=======================================================================================================================\n");
					}
				}else
				{
					printf("\n=======================================================================================================================\n"
								"No hay pasajeros cargados para modificar.\n"
								"=======================================================================================================================\n");
				}
				break;
			case 5:
				if(ll_isEmpty(passengerList) != 1)
				{
					if(controller_removePassenger(passengerList) == TRUE)
					{
						printf("\n=======================================================================================================================\n"
									"Pasajero eliminado.\n"
									"========================================================================================================================\n");
					}else
					{
						printf("\n=======================================================================================================================\n"
									"Eliminacion cancelada.\n"
									"========================================================================================================================\n");
					}
				}else
				{
					printf("\n=======================================================================================================================\n"
								"No hay pasajeros cargados para eliminar.\n"
								"========================================================================================================================\n");
				}
				break;
			case 6:
				if(ll_isEmpty(passengerList) != 1)
				{
					if(controller_ListPassenger(passengerList) == FALSE)
					{
						printf("\n===================================================================================================================================\n"
									"Error en el listado de pasajeros..\n"
									"===================================================================================================================================\n");
					}
				}else
				{
					printf("\n===================================================================================================================================\n"
								"No hay datos para imprimir.\n"
								"===================================================================================================================================\n");
				}
				break;
			case 7:
				if(ll_isEmpty(passengerList) != 1)
				{
					if(controller_sortPassenger(passengerList) == TRUE)
					{
						printf("\n========================================================================================================================\n"
									"Ordenamiento realizado, tiene a su disposicion la opcion 6 para listarlos.\n"
									"==========================================================================================================================\n");
					}else
					{
						printf("\n========================================================================================================================\n"
									"Se ha cancelado el ordenamiento.\n"
									"==========================================================================================================================\n");
					}
				}else
				{
					printf("\n========================================================================================================================\n"
								"No hay pasajeros cargados para ordenar.\n"
								"==========================================================================================================================\n");
				}
				break;
			case 8:
				if(ll_isEmpty(passengerList) != 1)
				{
					if(flagTxt == FALSE || flagBin == FALSE)//uso un salvado dual en csv y bin en ambos casos para evitar un desfasage en los datos de los archivos
					{
						if( controller_saveAsBinary("dataBin.bin", passengerList) == TRUE &&  controller_saveAsText("data.csv", passengerList) == TRUE)
						{
							printf("\n=======================================================================================================================\n"
										"Archivo guardado exitosamente.\n"
										"=======================================================================================================================\n");
						}else
						{
							printf("\n=======================================================================================================================\n"
										"Error en el salvado del archivo.\n"
										"=======================================================================================================================\n");
						}
					}else
					{
						printf("\n=======================================================================================================================\n"
									"Aun no ha cargado el archivo, ingrese a la opcion 1 antes de salvar para evitar sobreescrituras.\n"
									"=======================================================================================================================\n");
					}
				}else
				{
					printf("\n=======================================================================================================================\n"
								"No hay datos cargados para guardar en el archivo.\n"
								"=======================================================================================================================\n");
				}
				break;
			case 9:
				if(ll_isEmpty(passengerList) != 1)
				{
					if(flagBin == FALSE || flagTxt == FALSE)//uso un salvado dual en csv y bin en ambos casos para evitar un desfasage en los datos de los archivos
					{
						if( controller_saveAsBinary("dataBin.bin", passengerList) == TRUE &&  controller_saveAsText("data.csv", passengerList) == TRUE)
						{
							printf("\n=======================================================================================================================\n"
										"Archivo guardado correctamente.\n"
										"=======================================================================================================================\n");
						}
					}else
					{
						printf("\n=======================================================================================================================\n"
									"No hay ningun archivo cargado en el cual guardar. Puede cargar en la opcion 1 o 2.\n"
									"=======================================================================================================================\n");
					}
				}else
				{
					printf("\n=======================================================================================================================\n"
								"No hay datos cargados para guardar en el archivo.\n"
								"=======================================================================================================================\n");
				}
				break;
			case 10:
				exitOption = controller_ExitMenu();
				if(exitOption == 1)
				{
					printf("\n=======================================================================================================================\n"
								"Gracias por usar nuestro programa.\n"
								"=======================================================================================================================\n");
				}else
				{
					printf("\n=======================================================================================================================\n"
								"Gracias por quedarte, volviendo al menu principal.\n"
								"=======================================================================================================================\n");
				}
				break;
		}
	}while(exitOption != 1);
}

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retorno = parser_PassengerFromText(pFile, pArrayListPassenger);
		if(retorno == TRUE)
		{
			printf("\n=======================================================================================================================\n"
						"Archivo cargado correctamente.\n"
						"=========================================================================================================================\n");
		}else
		{
			printf("\n=========================================================================================================================\n"
						"Error en la carga del archivo.\n"
						"===========================================================================================================================\n");
		}
	}

	fclose(pFile);

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pFile;

	if(pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "rb");

		if(pFile != NULL)
		{
			retorno = parser_PassengerFromBinary(pFile, pArrayListPassenger);
		}
		fclose(pFile);
	}
    return retorno;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* newPassenger;
	int id;
	char idAux[SIZE];
	char name[SIZE];
	char lastName[SIZE];
	float price;
	char auxPrice[SIZE];
	char type[SIZE];
	char flycode[SIZE];
	char status[SIZE];

	if(pArrayListPassenger != NULL)
	{
		id = passenger_getLastId("IdMax.txt");
		do
		{
			RequestString("\nIngrese nombre del pasajero: ", name, SIZE);
		}while(CheckOnlyLetters(name) == FALSE);

		do
		{
			RequestString("\nIngrese apellido del pasajero: ", lastName, SIZE);
		}while(CheckOnlyLetters(lastName)== FALSE);

		price = RequestFloatInRange("\nIngrese el precio del vuelo: ", "Precio no valido", 1, MAX_PRICE);

		RequestString("\nIngrese el codigo de vuelo: ", flycode, SIZE);
		PolishFlyCode(flycode);

		passenger_TypeMenu(type);

		passenger_StatusMenu(status);

		sprintf(idAux, "%d", id);
		sprintf(auxPrice, "%f", price);

		newPassenger = Passenger_newParameters(idAux, name, lastName, auxPrice, flycode, type, status);

		if(newPassenger != NULL)
		{
			id++;
			retorno = TRUE;
			ll_add(pArrayListPassenger, newPassenger);
			passenger_setLastID("IdMax.txt", id);
		}else
		{
			retorno= FALSE;
		}
	}
    return retorno;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = FALSE;
	int searchID;
	int index;
	int option;
	Passenger* auxPassenger;
	char newName[SIZE];
	char newLastName[SIZE];
	float newPrice;
	char newFlyCode[SIZE];
	char newType[SIZE];
	char newStatus[SIZE];

	searchID = FALSE;

	if(pArrayListPassenger != NULL)
	{
		searchID = RequestIntInRange("\nIngrese el ID del pasajero a modificar: ", "\nId invalido.\n", 1, INT_MAX);

		index = passenger_findPassengerById(pArrayListPassenger, searchID);

		if(index != FALSE)
		{
			auxPassenger = ll_get(pArrayListPassenger, index);
			if(auxPassenger != NULL)
			{
				passenger_printOnePassenger(pArrayListPassenger, index);

				do
				{
					option = controller_ModificationMenu();
					switch(option)
					{
					case 1:
						retorno =TRUE;
						RequestString("\nIngrese el nuevo nombre: ", newName, SIZE);
						Passenger_setName(auxPassenger, newName);
						break;
					case 2:
						retorno =TRUE;
						RequestString("\nIngrese el nuevo apellido: ", newLastName, SIZE);
						Passenger_setLastName(auxPassenger, newLastName);
						break;
					case 3:
						retorno =TRUE;
						newPrice = RequestFloatInRange("\nIngrese nuevo precio: ", "\nPrecio invalido\n", 1, MAX_PRICE);
						Passenger_setPrice(auxPassenger, newPrice);
						break;
					case 4:
						retorno =TRUE;
						RequestString("\nIngrese nuevo codigo de vuelo: ", newFlyCode, SIZE);
						PolishFlyCode(newFlyCode);
						Passenger_setFlyCode(auxPassenger, newFlyCode);
						break;
					case 5:
						retorno =TRUE;
						passenger_TypeMenu(newType);
						Passenger_setTypePassenger(auxPassenger, newType);
						break;
					case 6:
						retorno =TRUE;
						passenger_StatusMenu(newStatus);
						Passenger_setStatusFlight(auxPassenger, newStatus);
						break;
					case 7:
						printf("\n==============================================================================================================\n"
									"Volviendo al menu principal.\n"
									"==============================================================================================================\n");
						break;
					}
				}while(option != 7);
			}else
			{
				printf("\n==============================================================================================================\n"
							"No se encontro pasajero para ese ID.\n"
							"==============================================================================================================\n");
			}
		}
	}
    return retorno;
}

int controller_ModificationMenu(void)
{
	int option;

	option = RequestIntInRange("\n===========================================================================================\n"
														"Que desea modificar:\n"
														"1 - Para modificar nombre.\n"
														"2 - Para modificar apellido.\n"
														"3 - Para modificar precio.\n"
														"4 - Para modificar codigo de vuelo.\n"
														"5 - Para modificar tipo de pasajero.\n"
														"6 - Para modificar estado de vuelo: \n"
														"7 - Para cancelar y volver al menu principal.\n"
														"Ingrese una opcion: ", "\nOpcion invalida\n", 1, 7);

	return option;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int idDelete;
	int len;
	int index;
	int confirm;
	Passenger* passengerToDelete;

	len = ll_len(pArrayListPassenger);

	if(len > 0)
	{
		idDelete = RequestIntInRange("\nIngrese el id del pasajero a eliminar: ", "Id invalido",1, INT_MAX);
	}

	index = passenger_findPassengerById(pArrayListPassenger, idDelete);

	if(index != FALSE)
	{
		printf("==============================================================================================================\n");
		passenger_printOnePassenger(pArrayListPassenger, index);

		confirm = RequestIntInRange("\nEste pasajero sera eliminado.\n"
																"1 - Confirmar eliminacion.\n"
																"2 - Cancelar eliminacion.\n"
																"Eleccion: ", "Opcion no valida",1, 2);
		if(confirm == 1)
		{
			retorno = TRUE;
			passengerToDelete = (Passenger*) ll_get(pArrayListPassenger, index);
			Passenger_delete(passengerToDelete);
			ll_remove(pArrayListPassenger, index);
		}else
		{
			retorno = FALSE;
		}
	}else
	{
		retorno = FALSE;
		printf("==============================================================================================================\n"
					"\nNo existe un pasajero con ese id.\n"
				"===============================================================================================================\n");
	}

    return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = FALSE;
	int len;

	len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL)
	{
		PrintTitle();
		for(int i = 0; i < len; i++)
		{
			retorno = TRUE;
			passenger_printOnePassenger(pArrayListPassenger, i);
		}
	}
    return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int option;
	int option1;
	int option2;
	int option3;
	int option4;
	int option5;
	int option6;
	int option7;
	int retorno;

	retorno = FALSE;

	option = controller_SortMenu();

	switch(option)
	{
	case 1:
		option1 = controller_OrderMenu();
		ll_sort(pArrayListPassenger, passenger_SortByName, option1);
		retorno = TRUE;
		break;
	case 2:
		option2 = controller_OrderMenu();
		ll_sort(pArrayListPassenger, passenger_SortByLastName, option2);
		retorno = TRUE;
		break;
	case 3:
		option3 = controller_OrderMenu();
		ll_sort(pArrayListPassenger, passenger_SortByFlyCode, option3);
		retorno = TRUE;
		break;
	case 4:
		option4 = controller_OrderMenu();
		ll_sort(pArrayListPassenger, passenger_SortByPrice, option4);
		retorno = TRUE;
		break;
	case 5:
		option5 = controller_OrderMenu();
		ll_sort(pArrayListPassenger, passenger_SortByTypePassenger, option5);
		retorno = TRUE;
		break;
	case 6:
		option6 = controller_OrderMenu();
		ll_sort(pArrayListPassenger, passenger_SortByStatus, option6);
		retorno = TRUE;
		break;
	case 7:
		option7 = controller_OrderMenu();
		ll_sort(pArrayListPassenger, passenger_SortById, option7);
		retorno = TRUE;
		break;
	case 8:
		break;
	}

    return retorno;
}

int controller_SortMenu(void)
{
	int option;

	option = RequestIntInRange("\nBienvenido al sort.\n"
														"1 - Para ordenar por nombre.\n"
														"2 - Para ordenar por apellido\n"
														"3 - Para ordenar por codigo de vuelo.\n"
														"4 - Para ordenar por precio.\n"
														"5 - Para ordenar por tipo de pasajero.\n"
														"6 - Para ordenar por estado de vuelo.\n"
														"7 - Para ordenar por id.\n"
														"8 - Para volver al menu.\n"
														"Ingrese una opcion: ", "Opcion no valida", 1, 8);

	return option;
}

int controller_OrderMenu(void)
{
	int option;

	option = RequestIntInRange("\nElija el modo de ordenamiento.\n"
														"1 - Para ascendente.\n"
														"0 - Para descendente\n"
														"Como ordenamos: ", "Opcion no valida", 0, 1);

	return option;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = FALSE;
    FILE* pFile = fopen(path,"w");
    Passenger* auxSave;

    int auxId;
    char auxNombre[SIZE];
    char auxLastName[SIZE];
    float auxPrice;
    char auxFlyCode[SIZE];
    char auxType[SIZE];
    char auxStatus[SIZE];

    if(pFile != NULL)
    {
        fprintf(pFile, "id, name, lastname, price, flycode, typePassenger, statusFlight\n");
        for(int i = 0; i < ll_len(pArrayListPassenger); i++)
        {
        	auxSave = ll_get(pArrayListPassenger, i);

        	Passenger_getId(auxSave, &auxId);
        	Passenger_getName(auxSave, auxNombre);
        	Passenger_getLastName(auxSave, auxLastName);
        	Passenger_getPrice(auxSave, &auxPrice);
        	Passenger_getFlyCode(auxSave, auxFlyCode);
        	Passenger_getTypePassenger(auxSave, auxType);
        	Passenger_getStatusFlight(auxSave, auxStatus);


            fprintf(pFile, "%d, %s, %s, %f, %s, %s, %s\n", auxId, auxNombre, auxLastName, auxPrice, auxFlyCode, auxType, auxStatus);
        }
        retorno = TRUE;
        fclose(pFile);
    }

    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pFile;
	Passenger* passengerToSave;
	int len;

	len = ll_len(pArrayListPassenger);
	if(path != NULL)
	{
		pFile = fopen(path, "wb");

		if(pFile != NULL && pArrayListPassenger != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				passengerToSave = (Passenger*) ll_get(pArrayListPassenger, i);
				if(passengerToSave != NULL)
				{
					fwrite(passengerToSave, sizeof(Passenger), 1, pFile);
				}
				retorno = TRUE;
			}
			fclose(pFile);
		}
	}else
	{
		retorno = FALSE;
	}

    return retorno;
}

int controller_ExitMenu(void)
{
	int option;

	option = RequestIntInRange("\nEsta a punto de abandonar el programa.\n"
														"Los datos que no esten guardados se perderan.\n"
														"1 - Para confirmar salir.\n"
														"Cualquier otra numero para quedarse.\n"
														"Que desea hacer: ", "Opcion no valida.", 1, INT_MAX);
	return option;
}


