#include "parser.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = TRUE;
	int validacion;
	Passenger* auxPassenger;
	char id[SIZE];
	char name[SIZE];
	char lastName[SIZE];
	char typePassenger[SIZE];
	char price[SIZE];
	char flyCode[SIZE];
	char statusFlight[SIZE];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, name, lastName, price, flyCode, typePassenger, statusFlight);//salteo primer linea desde aca para no modificar el archivo "data.csv" recibido.

		do
		{
			validacion = fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, name, lastName, price, flyCode, typePassenger , statusFlight);
			if(validacion == 7)//id,name,lastname,price,flycode,typePassenger,statusFlight
			{
				auxPassenger = Passenger_newParameters(id, name, lastName, price, flyCode, typePassenger, statusFlight);
				if(auxPassenger != NULL)
				{
					ll_add(pArrayListPassenger, auxPassenger);
				}else
				{
					retorno = FALSE;
					break;
				}
			}else
			{
				printf("\nError en la carga del archivo.\n"); //para control interno de funcionamiento, verifica no haber cometido algun error en las lineas de fscanf.
			}
		}while(feof(pFile)== 0);
	}

	return retorno;

}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = FALSE;
	Passenger* newPassenger;
	int read;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(feof(pFile) == 0)
		{
			newPassenger = Passenger_new();
			if(newPassenger != NULL)
			{
				read = fread(newPassenger, sizeof(Passenger), 1, pFile);
				if(read == 1)
				{
					retorno = TRUE;
					ll_add(pArrayListPassenger, newPassenger);
				}
			}
		}
	}
    return retorno;
}










