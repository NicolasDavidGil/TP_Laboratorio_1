/*
 * 	Passenger.c
 *
 *  	Created on: 19 may. 2022
 *     Author: Gil Nicolas David
 */

#include "Passenger.h"


int InteractiveMenu(void)
{
	int choice;

	choice = RequestIntInRange("\nMenu Principal\n"
								"1 - Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
								"2 - Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
								"3 - Alta de pasajero.\n"
								"4 - Modificar datos de pasajero.\n"
								"5 - Baja de pasajero.\n"
								"6 - Listar pasajeros.\n"
								"7 - Ordenar pasajeros.\n"
								"8 - Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
								"9 - Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
								"10 - Salir del programa.\n"
								"Ingrese una opcion: ", "Opcion no valida", 1, 10);
	return choice;
}


Passenger* Passenger_new()
{
	Passenger* newPassenger;

	newPassenger = (Passenger*)malloc(sizeof(Passenger));

	return newPassenger;
}

Passenger* Passenger_newParameters(char* idStr, char* nameStr, char* lastNameStr, char* priceStr, char* flyCodeStr, char* typePassengerStr, char* statusFlightStr)
{
	Passenger* newPassenger;
	int confirmID;
	int confirmPrice;

	newPassenger = (Passenger*) malloc(sizeof(Passenger));

	confirmID = ValidateInt(idStr);
	confirmPrice = ValidateFloatBiggerZero(priceStr);
	PolishFlyCode(flyCodeStr);

	if(newPassenger != NULL && confirmID != FALSE && confirmPrice != FALSE)
	{
		Passenger_setId(newPassenger, atoi(idStr));
		Passenger_setName(newPassenger, nameStr);
		Passenger_setLastName(newPassenger, lastNameStr);
		Passenger_setPrice(newPassenger, atof(priceStr));
		Passenger_setFlyCode(newPassenger, flyCodeStr);
		Passenger_setTypePassenger(newPassenger, typePassengerStr);
		Passenger_setStatusFlight(newPassenger, statusFlightStr);
	}
	return newPassenger;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this, int id)
{
	int retorno;

	if(this != NULL &&  id > 0)
	{
		retorno = TRUE;
		this->id = id;
	}else
	{
		retorno = FALSE;
	}

	return retorno;
}

int Passenger_getId(Passenger* this, int* id)
{
	int retorno= FALSE;

	if(this != NULL && id != NULL)
	{
		retorno = TRUE;
		*id = this->id;
	}

	return retorno;

}

int Passenger_setName(Passenger* this, char* name)
{
	int retorno;

	if(this != NULL && ValidateString(name) == TRUE)
	{
		PolishString(name);
		strcpy(this->name, name);
		retorno = TRUE;
	}else
	{
		retorno = FALSE;
	}
	return retorno;
}

int Passenger_getName(Passenger* this,char* name)
{
	int retorno = FALSE;

	if(this != NULL)
	{
		retorno = TRUE;
		strcpy(name, this->name);
	}

	return retorno;
}

int Passenger_setLastName(Passenger* this,char* lastName)
{
	int check;
	int validate;

	validate = ValidateString(lastName);
	if(this != NULL && validate == TRUE)
	{
		PolishString(lastName);
		strcpy(this->lastName, lastName);
		check = TRUE;
	}else
	{
		check = FALSE;
	}


	return check;
}

int Passenger_getLastName(Passenger* this,char* lastName)
{
	int retorno = FALSE;

	if(this != NULL)
	{
		retorno = TRUE;
		strcpy(lastName, this->lastName);
	}

	return retorno;
}

int Passenger_setFlyCode(Passenger* this,char* flyCode)
{
	int retorno;
	int validate;

	validate = ValidateString(flyCode);
	PolishFlyCode(flyCode);

	if(this != NULL && validate == TRUE)
	{
		retorno = TRUE;
		strcpy(this->flyCode, flyCode);
	}else
	{
		retorno = FALSE;
	}
	return retorno;
}

int Passenger_getFlyCode(Passenger* this,char* flyCode)
{
	int retorno = FALSE;

	if(this != NULL)
	{
		retorno = TRUE;
		strcpy(flyCode, this->flyCode);
	}
	return retorno;
}

int Passenger_setTypePassenger(Passenger* this, char* typePassenger)
{
	int retorno;

	if(this != NULL && typePassenger != NULL)
	{
		retorno = TRUE;
		strcpy(this->typePassenger, typePassenger);
	}else
	{
		retorno = FALSE;
	}
	return retorno;
}

int Passenger_getTypePassenger(Passenger* this, char* typePassenger)
{
	int retorno = FALSE;

	if(this != NULL)
	{
		retorno = TRUE;
		strcpy(typePassenger, this->typePassenger);
	}

	return retorno;
}

int Passenger_setPrice(Passenger* this, float price)
{
	int retorno;

	if(this != NULL && price > 0)
	{
		retorno = TRUE;
		this->price = price;
	}else
	{
		retorno = FALSE;
	}
	return retorno;
}

int Passenger_getPrice(Passenger* this, float* price)
{
	int retorno = FALSE;

	if(this != NULL)
	{
		retorno = TRUE;
		*price = this->price;
	}
	return retorno;
}

int Passenger_setStatusFlight(Passenger* this, char* statusFlight)
{
	int retorno;
	int validate;

	validate = ValidateString(statusFlight);

	if(this != NULL && validate == TRUE)
	{
		retorno = TRUE;
		strcpy(this->statusFlight, statusFlight);
	}else
	{
		retorno = FALSE;
	}
	return retorno;
}

int Passenger_getStatusFlight(Passenger* this,  char* statusFlight)
{
	int retorno = FALSE;

	if(this != NULL)
	{
		retorno = TRUE;
		strcpy(statusFlight, this->statusFlight);
	}

	return retorno;
}

int passenger_findPassengerById(LinkedList* pArrayPassenger, int id)
{
	int retorno;
	int len;
	Passenger* Auxiliar;

	retorno = FALSE;

	if(pArrayPassenger != NULL && id >= 0)
	{
		len = ll_len(pArrayPassenger);

		for(int i = 0; i < len; i++)
		{
			Auxiliar = (Passenger*) ll_get(pArrayPassenger, i);
			if(Auxiliar != NULL)
			{
				if(Auxiliar->id == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

void passenger_printOnePassenger(LinkedList* pArrayPassenger, int index)
{
	Passenger* passengerPrint;

	if(pArrayPassenger != NULL && index >=  0)
	{
		passengerPrint = (Passenger*) ll_get(pArrayPassenger, index);

		if(passengerPrint != NULL)
		{
			printf(	"%10d | %15s | %18s | %3s%.2f | %13s | %14s | %14s |\n"	,passengerPrint->id
																																,passengerPrint->name
																																,passengerPrint->lastName
																																," "
																																,passengerPrint->price
																																,passengerPrint->flyCode
																																,passengerPrint->typePassenger
																																,passengerPrint->statusFlight);
		}
	}
}

void PrintTitle(void)
{
    printf("\n========================================================================================================================================\n"
    			"%10s %10s %10s %10s %10s %13s %12s" ,"ID PASAJERO |"
																					,"NOMBRE PASAJERO |"
																					,"APELLIDO PASAJERO |"
																					,"PRECIO VUELO |"
																					,"CODIGO VUELO |"
																					,"TIPO PASAJERO |"
																					,"ESTADO DE VUELO |\n"
	      "========================================================================================================================================\n");
}

int passenger_SortByName(void* pOne, void* pTwo)
{
	int status = 0;
	char NameOne[SIZE];
	char NameTwo[SIZE];

	Passenger* one = (Passenger*) pOne;
	Passenger* two = (Passenger*) pTwo;

	if(Passenger_getName(one, NameOne) != FALSE && Passenger_getName(two, NameTwo) != FALSE)
	{
		status = strcmp(NameOne, NameTwo);
	}

	return status;
}

int passenger_SortByLastName(void* pOne, void* pTwo)
{
	int status = 0;
	char lastNameOne[SIZE];
	char lastNameTwo[SIZE];

	Passenger* one = (Passenger*) pOne;
	Passenger* two = (Passenger*) pTwo;

	if(Passenger_getLastName(one, lastNameOne) != FALSE && Passenger_getLastName(two, lastNameTwo) != FALSE)
	{
		status = strcmp(lastNameOne, lastNameTwo);
	}

	return status;
}

int passenger_SortByFlyCode(void* pOne, void* pTwo)
{
	int status = 0;
	char flyCodeOne[SIZE];
	char flyCodeTwo[SIZE];

	Passenger* one = (Passenger*) pOne;
	Passenger* two = (Passenger*) pTwo;

	if(Passenger_getFlyCode(one, flyCodeOne) != FALSE && Passenger_getFlyCode(two, flyCodeTwo)!= FALSE)
	{
		status = strcmp(flyCodeOne, flyCodeTwo);
	}

	return status;
}

int passenger_SortByTypePassenger(void* pOne, void* pTwo)
{
	int status = 0;
	char TypeOne[SIZE];
	char TypeTwo[SIZE];

	Passenger* one = (Passenger*) pOne;
	Passenger* two = (Passenger*) pTwo;

	if(Passenger_getTypePassenger(one, TypeOne) != FALSE && Passenger_getTypePassenger(two, TypeTwo) != FALSE)
	{
		status = strcmp(TypeOne, TypeTwo);
	}

	return status;
}

int passenger_SortByStatus(void* pOne, void* pTwo)
{
	int status = 0;
	char statusOne[SIZE];
	char statusTwo[SIZE];

	Passenger* one = (Passenger*) pOne;
	Passenger* two = (Passenger*) pTwo;

	if(Passenger_getStatusFlight(one, statusOne) != FALSE && Passenger_getStatusFlight(two, statusTwo) != FALSE)
	{
		status = strcmp(statusOne, statusTwo);
	}

	return status;
}

int passenger_SortByPrice(void* pOne, void* pTwo)
{
	int retorno;
	float priceOne;
	float priceTwo;

	Passenger* one = (Passenger*) pOne;
	Passenger* two = (Passenger*) pTwo;

	retorno = 0;

	if(Passenger_getPrice(one, &priceOne) != FALSE && Passenger_getPrice(two, &priceTwo) != FALSE)
	{
		if (priceOne > priceTwo)
		{
			retorno = 1;
		} else if (priceOne < priceTwo)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int passenger_SortById(void* pOne, void* pTwo)
{
	int retorno;
	int idOne;
	int idTwo;

	Passenger* one = (Passenger*) pOne;
	Passenger* two = (Passenger*) pTwo;

	retorno = 0;

	if(Passenger_getId(one, &idOne) != FALSE && Passenger_getId(two, &idTwo) != FALSE)
	{
		if(idOne > idTwo)
		{
			retorno = 1;
		}else if(idTwo > idOne)
		{
			retorno = -1;
		}
	}
	return retorno;
}

void passenger_setLastID(char* path, int id)
{
	FILE* pFile;

	pFile = fopen(path, "w");
	if(pFile != NULL)
	{
		fprintf(pFile, "%d", id);

		fclose(pFile);
	}

}

int passenger_getLastId(char* path)
{
	char maxID[SIZE];
	int retorno = FALSE;
	FILE* pFile;


	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", maxID);
		retorno = atoi(maxID);

		fclose(pFile);
	}

	return retorno;
}

void passenger_StatusMenu(char* retorno)
{
	int option;

	option = RequestIntInRange("\nElija el estado del vuelo.\n"
														"1 - Aterrizado.\n"
														"2 - En horario.\n"
														"3 - En vuelo. \n"
														"4 - Demorado. \n"
														"Elija una opcion: ", "Opcion no valida", 1, 4);
	switch(option)
	{
	case 1:
		strcpy(retorno,"Aterrizado");
		break;
	case 2:
		strcpy(retorno, "En Horario");
		break;
	case 3:
		strcpy(retorno, "En Vuelo");
		break;
	case 4:
		strcpy(retorno,"Demorado");
		break;
	}
}

void passenger_TypeMenu(char* retorno)
{
	int option;

	option = RequestIntInRange("\nElija el tipo de pasajero.\n"
																"1 - First class.\n"
																"2 - Executive class.\n"
																"3 - Economy class. \n"
																"Elija una opcion: ", "Opcion no valida", 1, 3);
	switch(option)
	{
	case 1:
		strcpy(retorno,"First Class");
		break;
	case 2:
		strcpy(retorno,"Executive Class");
		break;
	case 3:
		strcpy(retorno,"Economy Class");
		break;
	}
}



