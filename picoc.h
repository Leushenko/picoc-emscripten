/* picoc external interface. This should be the only header you need to use if
 * you're using picoc as a library. Internal details are in interpreter.h */
#ifndef PICOC_H
#define PICOC_H

/* picoc version number */
#define PICOC_VERSION "v2.2-emscripten"

/* handy definitions */
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#include "interpreter.h"


#include <setjmp.h>

/* this has to be a macro, otherwise errors will occur due to the stack being corrupt */
#define PicocPlatformSetExitPoint(pc) setjmp((pc)->PicocExitBuf)


/* parse.c */
void PicocParse(Picoc *pc, const char *FileName, const char *Source, int SourceLen, int RunIt, int CleanupNow, int CleanupSource, int EnableDebugger);
void PicocParseInteractive(Picoc *pc);

/* platform.c */
void PicocCallMain(Picoc *pc, int argc, char **argv);
void PicocInitialise(Picoc *pc, int StackSize);
void PicocCleanup(Picoc *pc);
void PicocPlatformScanFile(Picoc *pc, const char *FileName);

/* include.c */
void PicocIncludeAllSystemHeaders(Picoc *pc);

#endif /* PICOC_H */
