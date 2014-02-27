/***************************************************************************************************************
 * FILE: File.c
 *
 * DESCRIPTION
 * See comments in File.h.
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
#include <stdio.h>    /* For FILE, fopen(), fscanf(), fclose(), fprintf() */
#include <string.h>   /* For strlen() */
#include "File.h"     /* Good to always include the module header file. See comments in Globals.c. */
#include "Globals.h"  /* For TERM_ERR_FILE */
#include "Main.h"     /* For MainTerminate() */

/*==============================================================================================================
 * Function definitions.
 *============================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: FileReadStr
 * DESCR:    Reads a string from the file named by pFilename and returns the string in pString. Fails and termi-
 *           nates with an error message if the file could not be opened for reading.
 * RETURNS:  Nothing directly. pString is an array of chars where the string that is read will be stored. It
 *           had better be defined to be large enough to store the string that is read. It is an output param.
 *------------------------------------------------------------------------------------------------------------*/
void FileReadStr
    (
    char *pFilename,
    char *pString
    )
{
    FILE *in;

    /*
     * Open the file with name specified by pFilename. "rt" means "read text". To open a text file for writing
     * we use "wt". To open a binary file for reading we write "rb", and to open a binary file for writing we
     * write "wb".
     */
    in = fopen(pFilename, "rt");

    /*
     * fopen() returns NULL is the file cannot be opened. If the file cannot be opened, we cannot continue so
     * we call MainTerminate() to terminate the program.
     */
    if (!in) MainTerminate(TERM_ERR_FILE, "could not open '%s' for reading.\n", pFilename);

    /*
     * Read the string from the file. Note: the string does not contain embedded spaces, so we can use fscanf()
     * to read the string. If the string contained embedded spaces, we would have to read the string a different
     * way. We'll see that later on.
     */
	fscanf(in, "%s", pString);

    /*
     * You should always close a file after you are finished reading from it or writing to it.
     */
    fclose(in);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: FileWriteStr
 * DESCR:    Writes the string pString to the file named by pFilename. Fails and terminates with an error
 *           message if the file could not be opened for writing.
 * RETURNS:  Nothing.
 * NOTE:     This function is currently unused but is placed here for future use.
 *------------------------------------------------------------------------------------------------------------*/
void FileWriteStr
    (
    char *pFilename,
    char *pString
    )
{
    FILE *out;

    /*
     * See comments in FileReadStr().
     */
    out = fopen(pFilename, "wt");
    if (!out) MainTerminate(TERM_ERR_FILE, "could not open '%s' for writing.\n", pFilename);
	fprintf(out, "%s", pString);
    fclose(out);
}
