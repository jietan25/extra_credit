/***************************************************************************************************************
 * FILE: Controller.c
 *
 * DESCRIPTION
 * See comments in Controller.h.
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
#include "Controller.h"  /* Good to always include the module header file. See comments in Globals.c. */
#include "File.h"        /* For FileReadStr() */
#include "Globals.h"     /* For MAX_MSG_LEN, TERM_ERR_CMD_LINE */
#include "Main.h"        /* For MainTerminate() */
#include "Model.h"       /* For ModelBegin(), ModelEnd(), ModelSetMode(), ModelSetKeyFilename(), ModelSetKey() */
#include "String.h"      /* For streq */
#include "Types.h"       /* For bool */
#include "View.h"        /* For ViewBegin(), ViewEnd(), ViewGetChar(), ViewHelp(), ViewVersion(), ViewPrintStr() */
#include "Vigenere.h"    /* For Vigenere() */
#include <stdio.h>

/*==============================================================================================================
 * Static function declarations.
 *
 * A "static" function is one that has scope of the source code file. You can think of the word "static" in
 * this context as meaning "private". A static function cannot be called from any function in any other source
 * code file. Static functions are intended to only be called by the functions in the source code file in which
 * the static function is defined. Functions should always be static unless they have to be nonstatic. When
 * does a function have to be nonstatic? When it is intended to be called by a function in some other source
 * code file.
 *
 * Note that C requires a function to either be DECLARED or DEFINED before it is called. Consider,
 *
 * Foo.c
 * -----
 * ... code here, it does not matter what it does.
 * static void SomeFunction()  -- This is the DEFINITION of SomeFunction.
 * {
 *     ...
 * }
 *
 * void SomeOtherFunction()
 * {
 *     ...
 *     SomeFunction();  -- Okay because SomeFunction is DEFINED before the call.
 * }
 *
 * The reason is that the compiler must know three things about the function being called in order to generate
 * the assembly language code to call the function. These three things are: (1) the name of the function; (2)
 * the number and data types of the function parameters; and (3) the data type of the return value. In the
 * example above, when the compiler encounters SomeFunction() it sees and remembers all three of those things.
 * Later when it sees the function call in SomeOtherFuncion() it has all the information it needs to be able
 * to generate the code to call SomeFunction().
 *
 * We would have a problem if these functions were reversed, e.g.,
 *
 * Foo.c
 * -----
 * ... code here, it does not matter what it does.
 *
 * void SomeOtherFunction()
 * {
 *     ...
 *     SomeFunction();  -- Not okay because SomeFunction has not been DEFINED or DECLARED before the call.
 * }
 *
 * static void SomeFunction()  -- This is the definition of SomeFunction.
 * {
 *     ...
 * }
 *
 * Since the compiler reads the source code from top to bottom, left to right, when it sees the call to
 * SomeFunction() inside SomeOtherFunction() it HAS NOT SEEN SomeFunction() yet, so it does not know: (1) the
 * name of the function being called; (2) the number and data types of the function parameters; and (3) the
 * data type of the return value. Therefore, it cannot generate the code to call SomeFunction() and you get
 * a syntax error (which will be something to the effect that SomeFunction() is undefined). One way to fix
 * this, as we have already seen, is to reverse the order of the functions. The second way is to write a
 * DECLARATION for SomeFunction() above the function call to it, e.g.,
 *
 * Foo.c
 * -----
 * ... code here, it does not matter what it does.
 *
 * static void SomeFunction();  -- This is A DECLARATION of SomeFunction.
 *
 * void SomeOtherFunction()
 * {
 *     ...
 *     SomeFunction();  -- Okay because SomeFunction is DECLARED before the call.
 * }
 *
 * static void SomeFunction()  -- This is the definition of SomeFunction.
 * {
 *     ...
 * }
 *
 * Burger's Rule For Ordering Functions in a Source Code File: I always write the functions in a source code
 * file in alphabetical order, without regard to letter case. This makes it easy to locate a particular funct-
 * ion because you just scan the functions from top to bottom in alphabetical order. Nonstatic functions are
 * functions that are intended to be called from other source code files, so they are already declared in the
 * corresponding header file (which *is* included) so the function definitions can be written in any order in
 * the source code file because the declarations will be seen first (because they are sucked in with the header
 * file). Static functions do not have declarations in the header file (why?) so I write declarations for the
 * static functions near the top of the source code file above all of the function definitions. Now I can call
 * any static function from any static/nonstatic function without the compiler bitching at me about the
 * function being undefined.
 *============================================================================================================*/
static void ControllerEncryptDecrypt(bool  pMode, char *pMsgOut);
static void ControllerParseCmdLine(int pArgc, char *pArgv[]);

/*==============================================================================================================
 * Function definitions. These are in alphabetical order.
 *============================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ControllerBegin
 * DESCR:    Initializes the Controller module. Initializes the Model and View modules, and parses the command
 *           line.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ControllerBegin(int pArgc,	char *pArgv[])
{
    /* Initialize the Model. */
    ModelBegin();

    /* Initialize the View. */
    ViewBegin();

    /* Parse the command line for the arguments and options. */
    ControllerParseCmdLine(pArgc, pArgv);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ControllerEncryptDecrypt
 * DESCR:    Encrypts the plaintext to produce the ciphertext or decrypts the ciphertext to produce the plain-
 *           text. The message is read from stdin by calling ViewGetStr().
 * RETURNS:  If pMode is VIGENERE_ENCRYPT, pMsgOut is the ciphertext. If pMode is VIGENERE_DECRYPT, pMstOut is
 *           the plaintext.
 *------------------------------------------------------------------------------------------------------------*/
static void ControllerEncryptDecrypt(bool  pMode,  char *pMsgOut)
{
    /* Define a character array named msgIn which has room for MAX_MSG_LEN+1 characters. */
    char msgin[MAX_MSG_LEN+1];

    /* Call ViewGetStr() to get the message string to be encrypted or decrypted. */
    ViewGetStr(msgin);

    /* Call Vigenere() to encrypt or decrypt the message. */
    Vigenere(pMode, ModelGetKey(), msgin, pMsgOut);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ControllerEnd
 * DESCR:    Called when the Controller module is about to die. Ends the View and Model modules.
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
void ControllerEnd()
{
    ViewEnd();
	ModelEnd();
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ControllerParseCmdLine()
 * DESCR:    Examines the command line for arguments and options. Information parsed on the command line is
 *           stored in variables in the Model. Suppose the command line that was typed is:
 *
 *           ./vigenere e -k key.txt < plain.txt > cipher.txt
 *
 *           Then pArgc will be 4, and pArgv[] will be,
 *
 *           pArgv[0] = "vigenere"
 *           pArgv[1] = "e"
 *           pArgv[2] = "-k"
 *           pArgv[3] = "key.txt"
 *
 *           Note that the "< plain.txt > cipher.txt" part is not passed to the program in the pArgv[] array.
 *
 * RETURNS:  Nothing.
 *------------------------------------------------------------------------------------------------------------*/
static void ControllerParseCmdLine(int pArgc,   char *pArgv[])
{
    bool bKeyfile = false, bMode = false;
    int i;

    for (i = 1; i < pArgc; i++) {
        if (streq(pArgv[i], "e")) {
            /* Call ModelSetMode() to set the mode to VIGENERE_ENCRYPT */
            ModelSetMode(VIGENERE_ENCRYPT);

            /* Set bMode to true to indicate that a mode argument was found on the command line. */
            bMode = true;

        } else if (streq(pArgv[i], "d")) {
            /* Call ModelSetMode() to set the mode to VIGENERE_DECRYPT */
            ModelSetMode(VIGENERE_DECRYPT);

            /* Set bMode to true to indicate that a mode argument was found on the command line. */
            bMode = true;

        } else if (streq(pArgv[i], "-h")) {
            /* Call ViewHelp() to display the help information. */
            ViewHelp();

            /* Call MainTerminate() with an error code of 0 and "" as the format string. */
            MainTerminate(0, "");

        } else if (streq(pArgv[i], "-k")) {
            if (++i >= pArgc) MainTerminate(TERM_ERR_KEYFILE, "-k option, missing key file name.\n");
            ModelSetKeyFilename(pArgv[i]);
            bKeyfile = true;
        } else if (streq(pArgv[i], "-v")) {
            /* Call a certain View module function to display the version information. */
            ViewVersion();

            /* Call MainTerminate() like you did for the -h option to terminate the program. */
            MainTerminate(0, "");

        } else {
            MainTerminate(TERM_ERR_CMDLINE, "invalid command line option: %s\n", pArgv[i]);
        }
    }
    if (!bMode) {
        MainTerminate(TERM_ERR_CMDLINE, "missing mode (should be 'e' to encrypt or 'd' to decrypt\n");
    }
    if (!bKeyfile) {
        MainTerminate(TERM_ERR_CMDLINE, "missing -k 'keyfile' option. Use -h option for help.\n", pArgv[i]);
    }
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ControllerRun
 * DESCR:    Called after the Controller is initialized in ControllerBegin and after the command line has been
 *           parsed. Reads the key from the specified key file name. Calls ControllerEncryptDecrypt to encrypt
 *           or decrypt a message. Finally calls ViewPrintStr to print the encrypted or decrypted message.
 * RETURNS:  Nothing.
 * PSEUDOCODE:
 * Define a char array named key which is of length MAX_MSG_LEN+1.
 * Define a char array named msgOut which is of length MAX_MSG_LEN+1.
 * Call ModelGetKeyFilename() to get the key file name that was parsed from the command line.
 * Call FileReadStr() and pass the key file name and the key array as parameters. This will read the key
 *     from the file.
 * Call ModelSetKey() to store the key that was read from the file.
 * Call ModelGetMode() to get the mode from the Model (the mode was parsed from the command line).
 * Call ControllerEncryptDecrypt() and pass the mode and msgOut as parameters.
 * Call ViewPrintStr() and pass msgOut as the parameter.
 *------------------------------------------------------------------------------------------------------------*/
void ControllerRun()
{
    char key[MAX_MSG_LEN+1];
    char msgout[MAX_MSG_LEN+1];

    strcpy(key, ModelGetKeyFilename());
    /*printf("1.\t%s", *key);*/

    FileReadStr(key, key);
    /*printf("2.\t%s", &key);*/

    ModelSetKey(key);
    /*ModelGetMode();*/
    ControllerEncryptDecrypt(ModelGetMode(), msgout);
    ViewPrintStr(msgout);
}
