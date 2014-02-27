/***************************************************************************************************************
 * FILE: String.h
 *
 * DESCRIPTION
 * See comments in String.h.
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
#include <stdio.h>   /* For sprintf() */
#include "String.h"  /* Good to always include the module header file. See comments in Globals.c. */

/*==============================================================================================================
 * Function definitions.
 *============================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: StrCatChar
 * DESCR:    Concatenates pChar onto the end of pString.
 * RETURNS:  A pointer to the string with the new character concatenated onto the end.
 * NOTE:     pString had better be large enough to store the concatenated char.
 *------------------------------------------------------------------------------------------------------------*/
char *StrCatChar
    (
    char *pString,
    char  pChar
    )
{
    char charBuf[2] = { pChar, '\0' };

    strcat(pString, charBuf);
    return pString;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: StrCatInt
 * DESCR:    Returns the alphabet string.
 * RETURNS:  A pointer to the string with the integer concatenated onto the end.
 * NOTE:     pString had better be large enough to store the concatenated integer.
 *------------------------------------------------------------------------------------------------------------*/
char *StrCatInt
    (
    char *pString,
    int   pInt
    )
{
    char intBuf[32];

    sprintf(intBuf, "%d", pInt);
    strcat(pString, intBuf);
    return pString;
}
