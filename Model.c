/***************************************************************************************************************
 * FILE: Model.c
 *
 * DESCRIPTION
 * See comments in Model.h
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
#include "Model.h"  /* Good to always include the module header file. See comments in Globals.c. */

/*==============================================================================================================
 * Static global variables.
 *
 * Global variables are inherently evil, but occasionally useful. EVERY global variable should always be
 * defined static because this limits the scope of the global variable to the point at which it is defined to
 * the end of the source code file. I like to wrap my static global variables into a structure, so technically
 * now, I only have one static global variable in this source code file: gModelDbase. The fact that it contains
 * multiple variables limits the opportunities for me to muck things up by having four, rather than one, global
 * variable, in this case. Then, to limit those opportunities even more, I provide accessor/mutator functions
 * which permit to read and write the global variable. All accesses to global variables are made through the
 * appropriate accessor/mutator function.
 *
 * Burger's Rule Concerning Global Variables: Don't, unless you have to. If you have to, do it they way I am
 * doing it here. You will make far fewer mistakes and introduce far fewer bugs into the code if you do it my
 * way. This is about as OO as you can get in a C program.
 *============================================================================================================*/
struct {
    char *mKey;          /* The encryption/decryption key */
    char *mKeyFilename;  /* The name of the file containing the key */
    bool  mMode;         /* mMode is VIGENERE_ENCRYPT or VIGENERE_DECRYPT */
} gModelDbase;

/*==============================================================================================================
 * Function definitions.
 *============================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelBegin
 * DESCR:    Called to initialize the Model data base. Sets the alphabet, the key file name to "", and the
 *           mode to -1.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ModelBegin
	(
	)
{
    ModelSetKeyFilename("");
    ModelSetMode(-1);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelEnd
 * DESCR:    Called to deallocate the Model data base.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ModelEnd
	(
	)
{
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelGetKey
 * DESCR:    Returns the key string. Note: this is an accessor function for the mKey global variable.
 * RETURNS:  A C-string which is the key.
 *------------------------------------------------------------------------------------------------------------*/
char *ModelGetKey
    (
    )
{
    ???
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelGetKeyFilename
 * DESCR:    Returns the key file name string. Note: this is an accessor function for the mKeyFilename global.
 * RETURNS:  A C-string which is the file name of the key file.
 *------------------------------------------------------------------------------------------------------------*/
char *ModelGetKeyFilename
    (
    )
{
    ???
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelGetMode
 * DESCR:    Returns the mode. Note: this is an accessor function for the mMode global variable.
 * RETURNS:  A bool which is either VIGENERE_ENCRYPT or VIGENERE_DECRYPT.
 *------------------------------------------------------------------------------------------------------------*/
bool ModelGetMode
    (
    )
{
    ???
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelSetKey
 * DESCR:    Sets the key string. Note: this is a mutator function for mKey.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ModelSetKey
    (
    char *pKey
    )
{
    ???
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelSetKeyFilename
 * DESCR:    Sets the key file name string. Note: this is a mutator function for mKeyFilename.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ModelSetKeyFilename
    (
    char *pKeyFilename
    )
{
    ???
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ModelSetMode
 * DESCR:    Sets the mode integer. Note: this is a mutator function for mMode.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ModelSetMode
    (
    bool pMode
    )
{
    ???
}
