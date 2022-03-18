#include "tools/hint.h"

static const char* WELCOME = "*** Welcome Library System! ***";
static const char* SUCCESS = "*** Operation Successful! ***";
static const char* FAILURE = "*** Operation Failed! ***";
static const char* ILLEGAL = "*** Illegal Input! ***";
static const char* LOADING = "*** Loading ... ***";
static const char* EXITING = "*** Exiting ... ***";
static const char* INVALID = "*** Your operation is Invalid! ***";

void welcomeMessage(){ printf("%s\n", WELCOME); }
void successMessage(){ printf("%s\n", SUCCESS); }
void failureMessage(){ printf("%s\n", FAILURE); }
void illegalMessage(){ printf("%s\n", ILLEGAL); }
void loadingMessage(){ printf("%s\n", LOADING); }
void exitingMessage(){ printf("%s\n", EXITING); }
void invalidMessage(){ printf("%s\n", INVALID); }
