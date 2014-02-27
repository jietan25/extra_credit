/***************************************************************************************************************
 * FILE: String.h
 *
 * DESCRIPTION
 * Implements dynamically resizable string objects.
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
???  /* Preprocessor guard to prevent String.h from being included more than once */
???  /* See comments in Main.h. */

/*
 * A header file can always #include other header files, in particular, when that other header file contains
 * some piece of code that is ABSOLUTELY NECESSARY in the present header file. But you should not just #include
 * header files willy nilly, including them just for some rainy day when you may actually NEED the stuff
 * declared in the other header file. Why? Because it slows down the compilation of your code. Remember, header
 * files contain code. Code must be compiled. The more code that must be compiled, the longer it takes the
 * compiler to compile a source code file. How to reduce the amount of time it takes the compiler to compile
 * a source code file? Reduce the amount of code in the source code file. One way to reduce the amount of code
 * in a source code file. Don't #include header files that contain code that you DO NOT NEED.
 *
 * Header File Rule #4: Only #include a header file in a .h or .c file IFF that header file contains some
 * piece of code that is ABSOLUTELY NECESSARY in the .h or .c file in order for it to be compilable.
 *
 * Note that violating Header File Rule #4 will not banish you to the lowest depths of hell, but if you do it
 * enough, you *will* go blind.
 *
 * Now's probably the time for me to also mention the difference between,
 *
 * #include <afile.h>
 * #include "anotherfile.h"
 *
 * The former syntax <> is used for header files that are part of the C Standard Library, e.g., string.h,
 * stdio.h, stdlib.h, and math.h. The latter syntax is for header files that you create which are part of
 * your project.
 *
 * When the compiler sees a header file name in <> it will look in the system include directory(ies) for the
 * header file. Most of the header files for the C Standard Library are found in /usr/include. It won't look
 * in the current directory for these header files. On the other hand, when the compiler sees the header file
 * name inside "", it will NOT look in the system include directory for the file, but rather in your current
 * dir (or some other directory you specify to the compiler by throwing the -I option at the gcc compiler).
 */

#include <string.h>

/*==============================================================================================================
 * Global preprocessor macro definitions.
 *
 * In particular, this is a preprocessor macro function definition. See the comments in Types.h for more
 * information on these beasts.
 *
 * The strcmp() library function is used to compare two strings. It returns one of three integers: (1) 0 if
 * the two strings are equal; (2) a negative integer if s1 < s2; or (3) a positive integer if s1 > s2. To
 * compare two strings for equality, then, one could write something like,
 *
 * char *s1 = "Fred";
 * char *s2 = "Fred";
 * ...
 * if (strcmp(s1, s2) == 0) {
 *     -- the strings are equal
 * }
 *
 * or
 *
 * if (!strcmp(s1, s2)) {
 *     -- the strings are equal
 * }
 *
 * I think that both of those look kinda sleazy, so my streq macro permits me to write this as,
 *
 * if (streq(s1, s2)) {
 *     -- the strings are equal
 * }
 *
 * It's just a matter of personal preference, but that's my reason.
 *============================================================================================================*/
#define streq(s1,s2) (!strcmp((s1),(s2)))

/*==============================================================================================================
 * Global function declarations.
 *
 * See comments in Main.h concerning what global function declarations are for.
 *============================================================================================================*/
char *StrCatChar
    (
    char *pString,
    char  pChar
    );

char *StrCatInt
    (
    char *pString,
    int   pInt
    );

??? /* __STRING_H__ */
