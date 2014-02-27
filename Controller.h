/***************************************************************************************************************
 * FILE: Controller.h
 *
 * DESCRIPTION
 * The Controller module reads and parses the command line, and calls functions in other modules to encrypt/
 * decrypt the message. In the MVC architecture pattern, the Controller acts as an intermediary between the
 * View and the Model, and generally contains code that calls the View and Model modules.
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
???  /* Preprocessor guard to prevent Controller.h from being included more than once */
???  /* See comments in Main.h. */

/*==============================================================================================================
 * Global function declarations.
 *
 * See comments in Main.h concerning what global function declarations are for.
 *============================================================================================================*/
extern void ControllerBegin
    (
    int   pArgc,              /* Obviously, pArgc is an int. */
    char *pArgv[]             /* Obviously, pArgv is an array of char pointers, i.e., an array of C-strings.  */
    );

extern void ControllerEnd
    (
    );

extern void ControllerRun
    (
    );

??? /* __CONTROLLER_H__ */
