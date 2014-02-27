/***************************************************************************************************************
 * FILE: Main.h
 *
 * DESCRIPTION
 * See comments in main.c.
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
 * The monstrosity below is called a "preprocessor guard" and should always be placed at the beginning of a
 * header file because it can prevent a header file from being included more than once. For example, consider
 * these simple source code files,
 *
 * Foo.h
 * -----
 * typedef int MyInt;               -- defines a new type named MyInt which is equiv to int. Don't ask me why.
 * extern MyInt g_foo_global_var;   -- declares a global variable of data type MyInt.
 * extern void Foo_SomeFunction();  -- exports a declaration of a function from the Foo module.
 * ... rest of Foo.h
 *
 * Foo.c
 * -----
 * #include "Bar.h"
 * #include "Foo.h"
 * ... rest of Foo.c
 *
 * Bar.h
 * -----
 * #include "Foo.h"                  -- Bar.h includes Foo.h because Bar.h is using the MyInt type.
 * extern MyInt g_bar_global_var;    -- declares a global variable.
 * ... rest of Bar.h
 *
 * Bar.c
 * -----
 * #include "Bar.h"                  -- A .c file should always include it's corresponding .h file.
 * #include "Foo.h"                  -- We are going to use the MyInt type from Foo.h
 * ... rest of Bar.c
 * ... (suppose MyInt is used here)
 *
 * Now, consider when Foo.c gets compiled, the preprocessor will suck in the contents of Bar.h first,
 *
 * Foo.i
 * -----
 * #include "Foo.h"                  -- Line 1 of Bar.h is sucked in.
 *
 * which will immediately tell the preprocessor to suck in the contents of Foo.h,
 *
 * Foo.i
 * -----
 * typedef int MyInt;                <--+  This code comes from Foo.h
 * extern MyInt g_foo_global_var;       |
 * extern void Foo_SomeFunction();      |
 * ... rest of Foo.h                 <--+
 *
 * then the remainder of Bar.h will be included,
 *
 * Foo.i
 * -----
 * typedef int MyInt;                <--+  This code comes from Foo.h
 * extern MyInt g_foo_global_var;       |
 * extern void Foo_SomeFunction();      |
 * ... rest of Foo.h                 <--+
 * extern MyInt g_bar_global_var;    <--+  This code comes from Bar.h
 * ... rest of Bar.h                 <--+
 *
 * At this point, the preprocessor has preprocessed line 1 of Foo.c, so it moves on to line 2 and sucks
 * in "Foo.h",
 *
 * Foo.i
 * -----
 * typedef int MyInt;                <--+  This code comes from Foo.h
 * extern MyInt g_foo_global_var;       |
 * extern void Foo_SomeFunction();      |
 * ... rest of Foo.h                 <--+
 * extern MyInt g_bar_global_var;    <--+  This code comes from Bar.h
 * ... rest of Bar.h                 <--+
 * typedef int MyInt;                <--+  Note that at this point, Foo.h is being included TWICE.
 * extern MyInt g_foo_global_var;       |  This is BAD. BAD BAD BAD!!!
 * extern void Foo_SomeFunction();      |  Oh, the horror, the agony of it all. I cannot take it!
 * ... rest of Foo.h                 <--+  It's horrible!!! Did I mention that you don't want to do this???
 *
 * At this point we have a problem, because eventually the compiler will see the same typedef statement twice
 * and it will complain that MyInt is multiply defined. Other sorts of problems can occur, but this is the basic
 * gist of the problem: header files should NEVER be included more than once in a .c file. This can be handled
 * in two ways: (1) always write the .h and .c files to make sure that never happens; or (2) write preprocessor
 * guards at the top of header files. The first way is difficult to do and the second way is easy. To fix the
 * problem, we will take the easy route and rewrite Foo.h and Bar.h with preprocessor guards (we programmers
 * are some of the laziest people on Earth; we did, after all, invent computers in the first place because we
 * were too lazy to multiply and divide numbers by hand),
 *
 * Foo.h
 * -----
 * #ifndef __FOO_H__                -- the "name" for the guard can be anything as long as it is unique.
 * #define __FOO_H__                -- usually, some mangling of the file name is sufficient.
 *
 * typedef int MyInt;               -- defines a new type named MyInt which is equiv to int.
 * extern MyInt g_foo_global_var;   -- declares a global variable
 * extern void Foo_SomeFunction();  -- exports a declaration of a function from the Foo module.
 * ... rest of Foo.h
 * #endif                           -- this #endif matches the #ifndef __FOO_H__
 *
 *
 * Bar.h
 * -----
 * #ifndef __BAR_H__                -- the "name" for the guard is usually some mangling of the file name.
 * #define __BAR_H__
 *
 * #include "Foo.h"
 * extern MyInt g_bar_global_var;
 * ... rest of Bar.h
 * #endif                           -- this #endif matches the #ifndef __BAR_H__
 *
 * Now consider what happens when Foo.c is compiled. The preprocess will suck in the contents of Bar.h first,
 *
 * Foo.i
 * -----
 * #include "Foo.h"
 *
 * which will immediately tell the preprocessor to suck in the contents of Foo.h,
 *
 * Foo.i
 * -----
 * -- this stuff gets sucked in because __FOO_H__ is not defined. But after seeing that it is not defined,
 * -- it *becomes* defined (and entered into the preprocessor macro table). Remember that.
 * typedef int MyInt;
 * extern MyInt g_foo_global_var;
 * extern void Foo_SomeFunction();
 * ... rest of Foo.h
 *
 * then the remainder of Bar.h will be included,
 *
 * Foo.i
 * -----
 * typedef int MyInt;
 * extern MyInt g_foo_global_var;
 * extern void Foo_SomeFunction();
 * ... rest of Foo.h
 * -- this stuff gets sucked in because __BAR_H__ is not defined. But after seeing that it is not defined,
 * -- it *becomes* defined (and entered into the preprocessor macro table). Remember that.
 * extern MyInt g_bar_global_var;
 * ... rest of Bar.h
 *
 * At this point, the preprocessor has preprocessed line 1 of Foo.c, so it moves on to line 2 and attempts to
 * suck in "Foo.h". It opens Foo.h and sees the #ifndef __FOO_H__ line and checks the internal macro table
 * that the preprocessor maintains, and it sees that __FOO_H__ *is* defined. Therefore, since it is defined,
 * none of the code between the #ifndef and the #endif directives is sucked in, so essentially what happens
 * is that Foo.h is not included (twice). This is a good thing, and exactly what we want to happen.
 *
 * So now the preprocessor moves on to line 3 of Foo.c, where it sees now more preprocessor directives, and
 * the final output file from the preprocessor is,
 *
 * Foo.i
 * -----
 * typedef int MyInt;                 <--+  This code came from Foo.h
 * extern MyInt g_foo_global_var;        |
 * extern void Foo_SomeFunction();       |
 * ... rest of Foo.h                  <--+
 * extern MyInt g_bar_global_var;     <--+  This code came from Bar.h
 * ... rest of Bar.h                  <--+
 * ... rest of Foo.c                  <---  This code code from Foo.c
 *
 * And this is the file that is sent to the C compiler for compiling into assembly language code.
 *
 * I call this a preprocessor "kludge" because it is sleazy and kludgy as hell, but it does work and
 * no one has ever accused C of being a beautiful language. Fast, small, efficient, powerful, yes, those
 * are adjectives you will hear applied to C, but beautiful is not in the C vocabulary. So now you know.
 *
 * Header File Rule #1: NEVER, EVER, omit the preprocessor guard (kludge) from a header file.
 */

#ifndef __MAIN_H__
#define __MAIN_H__

/*==============================================================================================================
 * Global function declarations.
 *
 * A global function is one that is intended to be called by some function from some other source code file.
 * The extern keyword is what makes this line of code a "declaration". It says, in English, that MainTerminate
 * is "defined" somewhere else, but it is "declared" here. In general, an identifier (such as a variable, a
 * named constant, a function, a type, a struct, and all other kinds of things) can be "defined" only once, but
 * may be "declared" multiple times.
 *
 * The reason for this declaration is seen if we consider some other .c file which needs to call this function,
 * e.g.,
 *
 * Foo.c
 * -----
 * ... code is here
 * void SomeFunction()
 * {
 *     ... code is here
 *     MainTerminate(...);  -- oh shoot, something bad happened. call MainTerminate().
 * }
 *
 * When the compiler sees a function call, it needs to know three things about the function being called to
 * be able to generate the assembly language code to call the function. These three things are: (1) the name
 * of the function (to verify that we spelled/typed it correctly in both places); (2) the number, order, and
 * data types of the function's parameters (so it can generate the code to push this data onto the runtime
 * stack so the called function can retrieve the data); and (3) the data type of the return value (so the
 * compiler can generate the code to do something with the return value; e.g., by assigning it to a variable).
 *
 * Without knowing all three of those things, the compiler cannot generate the code to call the function. Now,
 * where does it get that information? Why, naturally, from a FUNCTION DECLARATION. And where is the function
 * declaration for MainTerminate(). I'll give you a hint: it is is Main.h. And how do we suck the code that
 * is in a header file into a .c file. I'll give you another hint: with an #include directive. Therefore, the
 * code for Foo.c should #include "Main.h", viz.,
 *
 * Foo.c
 * -----
 * #include "Main.h"        -- sucks contents of Main.h into Foo.c. Now the compiler will see the function
 * ... code is here         -- declaration of MainTerminate() before it sees the function call.
 * void SomeFunction()
 * {
 *     ... code is here
 *     MainTerminate(...);  -- compiler knows enough about MainTerminate() to be able to generate the
 * }                        -- assembly language code to call it and do something with the return value.
 *
 * Header File Rule #2: Any identifier defined in a .c file that needs to be shared with code in other .c files
 * should have a declaration of the identifier in a .h file. The .c file that needs to use the identifier must
 * include the .h file.
 *
 * Header File Rule #3: Unless you have a very good reason to do so (and you don't, so don't) a header file
 * should never contain a definition of an identifier. Declarations, yes, by all means do so. But definitions,
 * no, don't, ever. Or you will be visited at midnight on three consecutive nights by three ghosts, each
 * showing you the eternal agony that awaits you in three successive lower rings of hell for violating
 * Header File Rule #3.
 *
 * Final note, ... is how you indicate in C that MainTerminate is a "variadic function". A variadic function
 * is one that can have a variable number of arguments following the pFmt argument. The number of variadic
 * arguments can be 0, 1, 2, 3, ... (up to some presumably compiler dependent number [Note 1]). I don't really
 * plain to teach you how to write code to handle variadic arguments, but it's not all that difficult. If you
 * want to know how, study the code for MainTerminate() in Main.c. It's actually quite easy to do, and it's
 * useful as hell to know how.
 *
 * Notes:
 * 1. There's an old saying--attributable to someone, but I don't remember who now--that if a function has
 *    more than five parameters, then you're probably missing some. See Note 2.
 *
 * 2. For those of you who don't get it, see, it's funny. If you have more than five parameters (which is
 *    A LOT), and you're missing some, then presumably your function should really have 6, 7, 100, or 10000
 *    parameters. And that's A LOT more than A LOT. It's like A LOT SQUARED. See, I told you it was funny.
 *============================================================================================================*/
extern void MainTerminate
	(
	int   pTermCode,
	char *pFmt,
	...
	);

#endif /* __MAIN_H__ */
