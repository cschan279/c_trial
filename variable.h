#ifndef VAR_H
#define VAR_H

#include "def_struct.h"

#ifdef DEFINE_VARIABLES
#define EXTERN/* nothing */
#else
#define EXTERN extern
#endif /* DEFINE_VARIABLES */


namespace var {
    EXTERN TestStruct ts1, ts2;
};


#endif //VAR_H