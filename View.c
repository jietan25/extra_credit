/***************************************************************************************************************
 * FILE: View.c
 *
 * DESCRIPTION
 * See comments in View.h
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
#include <stdio.h>    /* For printf(), scanf() */
#include "Globals.h"  /* For BINARY */
#include "View.h"     /* Good to always include the module header file. See comments in Globals.c. */

/*==============================================================================================================
 * Function definitions.
 *============================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ViewBegin
 * DESCR:    Initializes the View module. Currently does nothing, but is here as a placeholder for future
 *           functionality.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ViewBegin
	(
	)
{
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ViewEnd
 * DESCR:    Uninitializes the View module. Currently does nothing, but is here as a placeholder for future
 *           functionality.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ViewEnd
	(
	)
{
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ViewGetChar
 * DESCR:    Reads a character from stdin.
 * RETURNS:  The character that was read.
 * NOTE:     Not currently used, but is placed her for future use.
 *------------------------------------------------------------------------------------------------------------*/
char ViewGetChar
	(
	)
{
	return fgetc(stdin);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ViewGetStr
 * DESCR:    Reads a string (not containing whitespace) from stdin.
 * RETURNS:  Nothing directly. The string is returned through the pStr parameter which has better be an array
 *           of chars large enough to store the string that was entered.
 *------------------------------------------------------------------------------------------------------------*/
void ViewGetStr
	(
	char *pStr
	)
{
	scanf("%s", pStr);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ViewHelp
 * DESCR:    Displays the help message.
 * RETURNS:  Nothing
 *------------------------------------------------------------------------------------------------------------*/
void ViewHelp() {
    /* Call ViewVersion() to display the version information. */
    ???

    /*
     * Write printf() statements to print the help information. See the project document in Section 4 where I
     * describe the -h option for what you should display here.
     */
    ???
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ViewPrintStr
 * DESCR:    Prints a string to stdout.
 * RETURNS:  Nothing
 *------------------------------------------------------------------------------------------------------------*/
void ViewPrintStr
    (
    char *pString
    )
{
    printf("%s", pString);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ViewVersion
 * DESCR:    Prints the version of the Vigenere cipher program.
 * RETURNS:  Nothing
 *------------------------------------------------------------------------------------------------------------*/
void ViewVersion
    (
    )
{
    printf("Vigenere Cipher Version %s -- (c) %s %s\n", VERSION, COPY, AUTHOR);
}
