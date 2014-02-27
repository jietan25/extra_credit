/***************************************************************************************************************
 * FILE: Globals.h
 *
 * DESCRIPTION
 * Handy global constant declarations.
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
???  /* Preprocessor guard to prevent Globals.h from being included more than once */
???  /* See comments in Main.h. */

/*==============================================================================================================
 * Global constant declarations.
 *
 * These are declaration for various constants that are going to be used by the various .c files. Remember
 * our Header File Rules from Main.h. Header File Rule #2: Header files only contain declarations. These are
 * declarations because of the "extern" keyword. If extern was missing, then these would be definitions, and
 * Header File Rule #3 says you never ever write a definition of an identifier in a header file. So by omitting
 * the extern keyword you would be violating not just one Header File Rule, but actually two, and doing so
 * in the same source code file would banish you to an even lower ring of hell than if you violated only one of
 * these. I hear hell is unpleasant, so please, for the sake of your eternal soul, don't omit the extern key
 * word.
 *
 * By the way, these constants are "defined" in Globals.c.
 *============================================================================================================*/
extern const char *AUTHOR;
extern const char *BINARY;
extern const char *COPY;
extern const char *VERSION;

extern const int MAX_MSG_LEN;
extern const int TERM_ERR_ALPHA;
extern const int TERM_ERR_BUG;
extern const int TERM_ERR_CMDLINE;
extern const int TERM_ERR_FILE;
extern const int TERM_ERR_KEYFILE;
extern const int TERM_ERR_MODE;

??? /* __GLOBALS_H__ */
