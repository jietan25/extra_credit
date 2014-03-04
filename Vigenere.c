/***************************************************************************************************************
 * FILE: Vigenere.c
 *
 * DESCRIPTION
 * See comments in Vigenere.h.
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
#include <string.h>    /* For strlen() */
#include "Vigenere.h"  /* Good to always include the module header file. See comments in Globals.c. */
#include<stdio.h>

/*==============================================================================================================
 * Global constant definitions. See comments in Globals.c concerning global constants. These particular
 * constants are declared in Vigenere.h.
 *============================================================================================================*/

/* Define a bool constant named VIGENERE_ENCRYPT and initialize it to false. */
bool const VIGENERE_ENCRYPT = false;

/* Declare a bool constant named VIGENERE_DECRYPT and initialize it to true. */
bool const VIGENERE_DECRYPT = true;

/*==============================================================================================================
 * Static function declarations.
 *============================================================================================================*/
char DecryptChar
    (
    char *pCiphertext,
    char  pKeyChar,
    int   pIndex
    );

char EncryptChar
    (
    char *pPlaintext,
    char  pKeyChar,
    int   pIndex
    );

/*==============================================================================================================
 * Function definitions.
 *============================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: DecryptChar
 *
 * DESCR:    Given pIndex which is the index of the characters in the ciphertext and the key that are being
 *           decrypted, this function returns the corresponding plaintext character. The formula for determi-
 *           ning the plaintext character is,
 *
 *           row <- key[k] - 'A'
 *           col <- ciphertext[i] - 'A'
 *           plaintext[i] <- 'A' + (col - row + 26) % 26
 *
 * RETURNS:  The plaintext character at index pIndex.
 *
 * PSEUDOCODE:
 * int row <- pKeyChar - 'A'
 * int col <- pCiphertext[pIndex] - 'A'
 * return 'A' + (col - row +26) % 26
 *------------------------------------------------------------------------------------------------------------*/
char DecryptChar
    (
    char *pCiphertext,
    char  pKeyChar,
    int   pIndex
    )
{
    int row = pKeyChar - 'A';
    int col = pCiphertext[pIndex] - 'A';
    return 'A' + (col - row +26) % 26;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: EncryptChar
 *
 * DESCR:    Given pIndex which is the index of the characters in the plaintext and the key that are being
 *           decrypted, this function returns the corresponding ciphertext character. The formula for determi-
 *           ning the ciphertext character is,
 *
 *           row <- key[k] - 'A'
 *           col <- plaintext[i] - 'A'
 *           ciphertext[i] <- 'A' + (row + col) % 26
 *
 * RETURNS:  The ciphertext character at index pIndex.
 *
 * PSEUDOCODE:
 * int row <- pKeyChar - 'A'
 * int col <- pPlaintext[pIndex] - 'A'
 * return 'A' + (row + col) % 26
 *------------------------------------------------------------------------------------------------------------*/
char EncryptChar
    (
    char *pPlaintext,
    char  pKeyChar,
    int   pIndex
    )
{
    int row = pKeyChar - 'A';
    int col = pPlaintext[pIndex] - 'A';
    return 'A' + (row + col) % 26;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: Vigenere
 *
 * DESCR:    This function either encrypts or decrypts a message. If pMode is VIGENERE_ENCRYPT, then pIn is the
 *           plaintext message and pOut will be the ciphertext. If pMode is VIGENERE_DECRYPT, then pIn is the
 *           ciphertext message and pOut will be the plaintext. pKey is the key.
 *
 * RETURNS:  pOut is either the plaintext (if pMode is VIGENERE_DECRYPT) or ciphertext (if pMode is VIGENERE_
 *           ENCRYPT).
 *
 * PSEUDOCODE:
 * Define k as an int variable and initialize it to 0.
 * Define i as an int variable.
 * Set the first char of pOut to the null character '\0'.
 * For i <- 0 to strlen(pIn) - 1 Do (increment i by one each time thru the loop)
 *     If pMode is VIGENERE_ENCRYPT Then
 *         Set pOut[i] to EncryptChar(pIn, pKey[k], i)
 *     Else
 *         Set pOut[i] to DecryptChar(pIn, pKey[k], i)
 *     End If
 *     printf("%d\t%s\t%s\t%s\n", i, &pOut[i], &pKey[k], &pIn[i]);
 *     Set k to (k + 1) % strlen(pKey)
 * End For
 * Set pOut[i] to the null character '\0'
 *------------------------------------------------------------------------------------------------------------*/
void Vigenere
    (
    bool  pMode,
    char *pKey,
    char *pIn,
    char *pOut
    )
{
    int k = 0;
    int i;
    pOut[0]='\0';


    for (i = 0; i < strlen(pIn); ++i)
    {

        if (pMode)
        {
        pOut[i]=EncryptChar(pIn, pKey[k], i);
        }
        else
        {
        pOut[i]=EncryptChar(pIn, pKey[k], i);
        }
        k = (k+1)% strlen(pKey);
    }
    pOut[i]='\0';
}
