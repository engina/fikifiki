/*
 * ff_common.h
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#ifndef FF_COMMON_H_
#define FF_COMMON_H_

#if 1 //FF_DEBUG_ENABLE == 1

#include <stdio.h>

#define FF_DEBUG(...) fprintf( stderr, __VA_ARGS__ )

#else

#define FF_DEBUG(...)

#endif

#endif /* FF_COMMON_H_ */
