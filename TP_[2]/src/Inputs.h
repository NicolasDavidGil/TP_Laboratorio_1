/*
 * Inputs.h
 *
 *  Created on: 9 may. 2022
 *      Author: Gil Nicolás David
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define NUM "0123456789"

/// @fn int RequestInt(char[])
/// @brief
///
/// @param mensaje
/// @return
int RequestInt(char mensaje[]);

/// @fn int RequestIntInRange(char[], int, int)
/// @brief
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return
int RequestIntInRange(char mensaje[], int minimo, int maximo);

/// @fn float RequestFloat(char[])
/// @brief
///
/// @param mensaje
/// @return
float RequestFloat(char mensaje[]);

/// @fn float RequestFloatInRange(char[], float, float)
/// @brief
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return
float RequestFloatInRange(char mensaje[], float minimo, float maximo);

/// @fn int ValidateNumber(char[])
/// @brief
///
/// @param numero
/// @return
int ValidateNumber(char numero[]);

/// @fn void RequestString(char[], char[], int)
/// @brief
///
/// @param mensaje
/// @param string
/// @param len
void RequestString(char mensaje[], char string[], int len);

/// @fn int CorrectString(char[], int)
/// @brief
///
/// @param string
/// @param len
/// @return
int CorrectString(char string[], int len);

/// @fn int ValidateString(char[])
/// @brief
///
/// @param string
/// @return
int ValidateString(char string[]);

/// @fn void PolishString(char[])
/// @brief
///
/// @param cadena
void PolishString(char cadena[]);


void RequestAlphaDigit(char mensaje[], char cadena[], int len);


#endif /* INPUTS_H_ */
