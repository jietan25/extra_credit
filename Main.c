/***************************************************************************************************************
 * FILE: Main.c
 *--------------------------------------------------------------------------------------------------------------
 * VIGENERE                                       MAN PAGE                                              VIGENERE
 *
 * NAME
 *     vigenere - performs Vigenere encryption and decryption.
 *
 * SYNOPSIS
 *     vigenere mode [-h] -k keyfile [-v]
 *
 * DESCRIPTION
 *     Perform Vigenere encryption or decryption. Modes are:
 *
 *     e  Encrypt the plaintext to produce the ciphertext.
 *     d  Decrypt the ciphertext to produce the plaintext.
 *
 *     When encrypting (mode is 'e'), reads the plaintext from stdin and writes the ciphertext to stdout. When
 *     performing decryption (mode is 'd'), reads the ciphertext from stdin and writes the plaintext to stdout.
 *
 *     -h  Displays a help message and terminates without further processing.
 *     -k  Reads the key from 'keyfile'.
 *     -v  Displays version info and teminates without further processing.
 *
 * AUTHOR
 *     Written by Kevin R. Burger.
 *
 *     Mailing Address:
 *     Computer Science & Engineering
 *     School of Computing, Informatics, and Decision Systems Engineering
 *     Arizona State University
 *     Tempe, AZ 85287-8809
 *
 *     Email: burgerk@asu
 *     Web:   http://kevin.floorsoup.com
 *
 * REPORTING  BUGS
 *     Report bugs to burgerk@asu.edu.
 *
 * COPYRIGHT
 *     Copyright (c) 2012 Kevin R. Burger.
 *
 * MODIFICATION HISTORY
 *     24 Jan 2012 [KRB] Version 1.0.
 *
 * VIGENERE                                        24 Jan 2012                                         VIGENERE
***************************************************************************************************************/
#include <stdarg.h>      /* For va_list, va_start, va_arg, and va_end */
#include <stdio.h>       /* For sprintf() */
#include <stdlib.h>      /* For exit() */
#include "Controller.h"  /* For ControllerBegin(), ControllerRun(), ControllerEnd() */
#include "Globals.h"     /* For BINARY */
#include "Main.h"        /* Good to always include the module header file. See comments in Globals.c. */
#include "String.h"      /* For StrCatChar(), StrCatInt() */
#include "View.h"        /* For ViewPrintStr() */

/*
 * Note that the declaration for strcat() is imported by virtue of <string.h> being included in "String.h". That
 * is, when "String.h" is included, so is <string.h>. This is considered acceptable.
 */

/*==============================================================================================================
 * Function definitions.
 *============================================================================================================*/

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: main
 * DESCR:    Starting point. All of the processing is done in the Controller module, so we initialize it by
 *           calling ControllerBegin() then ControllerRun() and shut things down by calling ControllerEnd().
 * RETURNS:  Zero on success. On failure, MainTerminate() is called with a nonzero return code to terminate the
 *           program.
 *------------------------------------------------------------------------------------------------------------*/
int main(int pArgc, char *pArgv[])
{
    /* Call ControllerBegin() */
    ControllerBegin(Argc, pArgv);

    /* Call ControllerRun() */
    ControllerRun();

    /* Call ControllerEnd() */
    ControllerEnd();

    /* What should main return? */
    return 0;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: MainTerminate
 * DESCR:    Terminates the program. If pTermCode is 0, then the program terminated normally without error. If
 *           pTermCode is nonzero, then the program terminated abnormally because of some sort of error. In the
 *           latter case, a formatted error message should be displayed.
 * RETURNS:  Nothing
 * NOTE:     This is a variadic function because the ... following the required pFmt parameter states that
 *           there may be 0, 1, 2, ... optional parameters. Variadic arguments are handled by preprocessor
 *           macros defined in stdarg.h, in particular: va_list, va_start, va_arg, and va_end.
 * NOTE:     This function works similarly to printf(). A typical call would be something like,
 *
 *           MainTerminate(-1, "An error code %d occurred in %s", err_code, some_string_var);
 *
 *           pTermCode would be initialized to -1 when the function is called. pFmt would be initialized to
 *           "An error code %d occurred in %s", and there would be two variadic arguments: err_code which
 *           had better be an int variable, and some_string_var which had better be of the data type char *.
 *           If you located the source code for the printf() function in the C Standard Library, you will see
 *           that it looks very similar to this, only without the pTermCode parameters, and it will handle
 *           more format specifiers than just %c, %d, and %s.
 *------------------------------------------------------------------------------------------------------------*/
void MainTerminate(int pTermCode, char *pFmt,...)
{
    if (pTermCode != 0) {
        char *fp, msg[4096];
        sprintf(msg, "%s: ", BINARY);
        va_list argp; va_start(argp, pFmt);
        for (fp = pFmt; fp && *fp; fp++) {
            if (*fp != '%') {
                StrCatChar(msg, *fp);
            } else {
                switch (*++fp) {
                case 'c': StrCatChar(msg, (char)va_arg(argp, int)); break;
                case 'd': StrCatInt(msg, va_arg(argp, int)); break;
                case 's': strcat(msg, va_arg(argp, char *)); break;
                }
            }
        }
        va_end(argp);
        ViewPrintStr(msg);
    }
    ControllerEnd();
	exit(pTermCode);
}
