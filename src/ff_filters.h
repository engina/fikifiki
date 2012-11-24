/*
 * ff_filter.h
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#ifndef FF_FILTER_H_
#define FF_FILTER_H_

struct FF_Board;

#define FF_MAX_FILTERS	(512)

typedef int (*FF_Filter)(struct FF_Board* board);

int ff_filter_add( FF_Filter filter );
int ff_filter_remove( FF_Filter filter );

extern FF_Filter g_FF_Filters[];

#endif /* FF_FILTER_H_ */
