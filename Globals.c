/***************************************************************************************************************
 * FILE: Globals.c
 *
 * DESCRIPTION
 * See comments in Globals.h
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

/*
 * Notice that Globals.c does not really need to #include Globals.h, but it is a good idea to do so. It permits
 * the compiler to check that the things declared in Globals.h match up with the things defined in Globals.c.
 * For example,
 *
 * Globals.c
 * ---------
 * #include "Globals.h"
 *
 * void SomeFunction(int someParameter) { ... }
 *
 * Globals.h
 * ---------
 * int SomeFunction (void) { ... }                -- Notice that this does not match what is in Globals.c
 *
 * Well, this is obviously wrong, so by including Globals.h in Globals.c, the compiler will catch these errors
 * and flag them for you. Saves you a bunch o' time.
 *
 * When I write C code, I always create a .h file for every .c file. Declarations and global stuff goes in the
 * .h file, and definitions and local stuff goes in the .c file. The .c file always #includes the .h file. Do it
 * this way and you will have fewer problems in life.
 */

#include "Globals.h"

/*=============================================================================================================
 * Global constant definitions.
 *
 * These are constants which are intended to be used in other .c files. There is a difference between the word
 * "declaration" and "definition" in C that not a lot of C programmers understand. Oh, they may say they under
 * stand it, but really, they don't. I know this for a fact, because I used to work with a lot of them. And I
 * would quiz them on it, me being the arrogant type I am concerning grammar and definitions. And it was
 * obvious to me that, although they could write the code correctly, they DID NOT UNDERSTAND why they had to
 * write the code that way to make it work. Somewhere, along the line, someone had told them or taught them
 * that you just do it "this way" without explaining why. I refuse to noneducate you. You're education is far
 * too important to me to permit me to do that, so bear with me. (BTW, if you don't give a *** about your
 * education then ignore what I am going to tell you--I don't care about your education more than you do, or
 * should :)
 *
 * Let's talk about declarations and definitions concerning global variables, but the same rules are applic-
 * able to global constants and functions, and some other things as well. Suppose in Foo.c I wish to define
 * (see, I said "define") a global variable named g_global. I intend to use g_global in Foo.c but I also
 * intend to use g_global in Bar.c. Why is it defined in Foo.c (Because that's where it belongs! It's some-
 * how related to all the other stuff that is in Foo.c. If you don't like *that* answer, then just accept it
 * and move on. I've learned in life, that acceptance is a good approach to many things that trouble you.)
 *
 * Foo.c
 * -----
 * ... some code is here, doesn't matter what it is.
 * int g_global = 100;  -- Defines (there's that word again) g_global to be a global variable of the int data
 *                      -- type and initializes it to 100. It's global because it is not defined inside a
 *                      -- function (if it were, it would be a local variable).
 *
 * Now, the "scope" of a global variable is from the point at which it is defined to the end of the source
 * code file in which it is defined. "scope" essentially means the places in the code where I can access and
 * use that global variable. Therefore, I can access and use g_global anywhere from the line on which it is
 * defined to the end of Foo.c.
 *
 * Now, suppose I want to use g_global in Bar.c, e.g.,
 *
 * Bar.c
 * -----
 * ... some code is here, doesn't matter what it is.
 * void SomeFunction()
 * {
 *     g_global++;
 * }
 *
 * Now, in order for the compiler to compile this code, it must know two things: (1) the name of the global
 * variable; and (2) the data type of the global variable. It needs to know the name because it needs to
 * check to see that we spelled/typed the name correctly here (we might have spelled it G_Global, e.g.).
 * It needs to know the data type of g_global, because if that thing ain't an int (or some integeral data)
 * type) then we're in a heap o' trouble because ++ is not defined on floats and doubles.
 *
 * Now, you and I can see that g_global is an int and that we spelled it correctly because you can see the
 * definition in Foo.c (Good gosh, just look up half a screen in your editor window if you don't believe me).
 * But, that's you and me. The compiler can't do that, because it can't see my editor window; in fact, the
 * compiler does not even--last time I checked--have eyes! How it compiles the code without being able
 * to see it is an existential question that is beyond the scope of this class, but it's something that
 * should seriously be troubling your right now.
 *
 * No, the compiler only knows about the code that's in the source code file it is currently compiling. It
 * does not know about anything that exists in other source code files, because source code files are compiled
 * ONE AT A TIME, individually and separately from all other source code files. Clearly, if we want to make the
 * compiler happy (and we do, oh yes, we do), then we need to tell it somewhere in Bar.c above the g_global++
 * line that, drumroll please: (1) g_global is the correct name of the global variable; and (2) g_global is
 * an int. If the compiler knew that, when it gets to the g_global++ line, well, then it would be just about
 * as happy as a compiler can be (and it will spit out object code all day long when it is happy).
 *
 * The question now, is, how do we tell the compiler that? There are two ways. First, the wrong way. Modify
 * Bar.c thusly,
 *
 * Bar.c
 * -----
 * ... some code is here, doesn't matter what it is.
 *
 * int g_global;  -- Defines g_global to be a global variable of the int data type.
 *
 * void SomeFunction()
 * {
 *     g_global++;
 * }
 *
 * Our happy compiler will spit out Bar.o just as quickly as you can say, "Wait a minute, I'm not so sure
 * about what you just did, Burger."
 *
 * Oh yes, Bar.c will compile to Bar.o. With no syntax errors. And similarly, Foo.c will compile to Foo.o
 * with no syntax errors. But what happens when the linker attempts to link these two .o files together with
 * .o code from the C Standard Library to form the binary? It will see there is a global variable named g_
 * global defined in Foo.o and it will see there is another variable named (the same) g_global defined in
 * Bar.o. This *IS* a problem. Why? Because a global variable can only be DEFINED ONCE! Why? jeez, I don't
 * know, email Dennis Ritchie, I didn't create the C language!
 *
 * So, this leads to a linker error. The linker will blow up, and in fact, the message you will see will look
 * something like this,
 *
 * $ gcc -fno-common Main.c Foo.c Bar.c
 * /tmp/ccgC71eN.o:Bar.c:(.bss+0x0): multiple definition of '_g_global'
 * /tmp/ccpZ7075.o:Foo.c:(.data+0x0): first defined here
 * collect2: ld returned 1 exit status
 *
 * To be honest, if you do not compile with the -fno-common option, gcc will not complain about this. But
 * that's because gcc does some weird stuff from time to time that I don't understand. Anytime you see an
 * error message containing "collect2: ld returned 1 exit status" that is a linker error message, not a gcc
 * compiler error message. This means that Foo.c and Bar.c compiled just fine, but the linker barfed.
 *
 * Defining Global Variables Rule #1: Don't. Global variable are inherently evil and are supported by the
 * C language only because Dennis Ritchie was doing a lot of acid at the time he created the language (this
 * *was* 1969 after all. Heck, I was only 5 in 1969, and I was doing a lot of acid as well. EVERY ONE in
 * 1969 was doing acid. Your grandparents were doing acid, they just have never told you about it).
 *
 * Defining Global Variables Rule #2: If you must violate Rule #1, then don't define the darn thing more than
 * once. Think of it this way: there's only one of you in the whole wild world. Do you really think the world
 * would be better off if there were two of you? I didn't think so.
 *
 * No, the way to fix this problem is to not REDEFINE g_global in Bar.c, but rather to DECLARE g_global in
 * Bar.c, viz.,
 *
  * Bar.c
 * -----
 * ... some code is here, doesn't matter what it is.
 *
 * extern int g_global;  -- The extern keyword makes this a DECLARATION. It tells the compiler that g_global
 *                       -- is defined somewhere else, but we are declaring it here. Note that the declaration
 *                       -- tells the compiler all it needs to know about g_global, namely: (1) the name of
 *                       -- global variable; and (2) it's data type. And, a variable can be DECLARED as many
 *                       -- times as you wish to declare it, hundreds, thousands of times. But, did I mention
 *                       -- that it can only be DEFINED once?
 *
 * void SomeFunction()
 * {
 *     g_global++;       -- A perfectly hunky-dory access to a global variable that was properly declared.
 * }
 *
 * The major problem with this approach is that it forces Bar.c to contain information about a global variable
 * that was defined in a different source code file. To see this, suppose the data type of g_global needs to
 * be changed to be a signed char. We edit Foo.c, make the change, recompile, and things work just fine until
 * g_global reaches the value 127 and SomeFunction() in Bar.c is called. At that point, the compiler will
 * generate code which happily increments g_global to 128 (remember, because of the declaration of g_global
 * in Bar.c, the compiler thinks it is still an int). But 128 is actually -128 if g_global happens to be a
 * signed char (which it is, because we changed it's type in Foo.c). Now you have a bug in your code and you're
 * banging your head against the wall at 3 o'clock in the morning because you cannot figure out how 127 + 1
 * equals -128.
 *
 * I like to watch students banging their heads against walls. It's an interesting and quite humorous sight, but
 * it's generally bad for the walls. So let me show you a better way to handle this. The fix involves two steps:
 * (1) Create (if you have not done so already) a header file named Foo.h and write the declaration for g_global
 * there; and (2) #include Foo.h in Bar.c.
 *
 * Foo.h
 * -----
 * #ifndef __FOO_H__     -- Why is this code here? See Main.h.
 * #define __FOO_H__
 * ...
 * extern int g_global;  -- A proper declaration of a global variable which is defined in Foo.c.
 * ...
 * #endif
 *
 * Bar.c
 * -----
 * #include "Foo.h"      -- sucks "extern int g_global" into Bar.c.
 * ... some code is here, doesn't matter what it is.
 *
 * void SomeFunction()
 * {
 *     g_global++;       -- A perfectly hunky-dory access to a global variable that was properly declared.
 * }
 *
 * The beauty in this approach is that should the data type of g_global need to be changed, Bar.c DOES NOT
 * NEED TO BE TOUCHED. Edit Foo.c and Foo.h and make the changes there, and simply make sure that Bar.c is
 * recompiled (which it will be if you set up your make file correctly).
 *
 * This is the ONE and ONLY PROPER way to do this. Learn it. Master it. And on your way to being, you will be,
 * a master Jedi programmer.
 *===========================================================================================================*/

/*
 * Note that global variables can be initialized when they are DEFINED. Look in Globals.h and you will see
 * where they are DECLARED. Note that declarations DO NOT contain initialization values.
 */

const char *AUTHOR          = "Kevin R. Burger";
const char *BINARY          = "vigenere";
const char *COPY            = "2012";
const char *VERSION         = "1.0";

const int MAX_MSG_LEN       = 4096;
const int TERM_ERR_ALPHA    =   -1;
const int TERM_ERR_BUG      =   -2;
const int TERM_ERR_CMDLINE  =   -3;
const int TERM_ERR_FILE     =   -4;
const int TERM_ERR_KEYFILE  =   -5;
const int TERM_ERR_MODE     =   -6;
