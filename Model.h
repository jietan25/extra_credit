/***************************************************************************************************************
 * FILE: Model.h
 *
 * DESCRIPTION
 * Stores data.
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
#ifndef _MODEL_H_ /* Preprocessor guard to prevent Model.h from being included more than once */
#define _MODEL_H_ /* See comments in Main.h. */

#include "Types.h" /* For bool */

/*==============================================================================================================
 * Global function declarations.
 *
 * See comments in Main.h concerning what global function declarations are for.
 *============================================================================================================*/
extern void ModelBegin
    (
    );

extern void ModelEnd
    (
    );

extern char *ModelGetKey
    (
    );

extern char *ModelGetKeyFilename
    (
    );

extern bool ModelGetMode
    (
    );

extern void ModelSetKey
    (
    char *pKey
    );

extern void ModelSetKeyFilename
    (
    char *pKeyfilename
    );

extern void ModelSetMode
    (
    bool pMode
    );

#endif /* __MODEL_H__ */
