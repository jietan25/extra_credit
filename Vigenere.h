/***************************************************************************************************************
 * FILE: Vigenere.h
 *
 * DESCRIPTION
 * Encrypts or decrypts a message with a specified key using the Vigenere cipher.
 *
 * AUTHOR INFORMATION
 * Kevin R. Burger [KRB]
 *
 * Mailing Address:
 * Computer Science & Engineering
 * School of Computing, Informatics, and Decision Systems Engineering
 * Arizona State University
 * Tempe, AZ 85287-8809
 *
 * Email: burgerk@asu
 * Web:   http://kevin.floorsoup.com
 *
 * MODIFICATION HISTORY:
 * -------------------------------------------------------------------------------------------------------------
 * 24 Jan 2012 [KRB] Initial revision.
 **************************************************************************************************************/
#ifndef _VIGENERE_H_ /* Preprocessor guard to prevent Vigenere.h from being included more than once */
#define _VIGENERE_H_

/*
 * See comments in String.h concerning one header file including another header file. I am including Types.h
 * here, because I am going to use the "bool" type that was defined in Types.h. Look at lines 36 and 37 below.
 */

#include "Types.h"

/*==============================================================================================================
 * Global constant declarations. These constants are defined in Vigenere.c.
 *============================================================================================================*/

/* Declare a bool constant named VIGENERE_ENCRYPT. */
bool const VIGENERE_ENCRYPT;

/* Declare a bool constant named VIGENERE_DECRYPT. */
bool const VIGENERE_DECRYPT;

/*==============================================================================================================
 * Global function declarations.
 *
 * See comments in Main.h concerning what global function declarations are for.
 *============================================================================================================*/
extern void Vigenere
    (
    bool  pMode,
    char *pKey,
    char *pIn,
    char *pOut
    );

#endif /* __VIGENERE_H__ */
