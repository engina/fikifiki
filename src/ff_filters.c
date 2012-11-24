/*
 * ff_filters.c
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#include <stdlib.h>

#include "ff_filters.h"

FF_Filter g_FF_Filters[FF_MAX_FILTERS] = {0};

int ff_filter_add( FF_Filter filter )
{
	for( int i = 0; i < FF_MAX_FILTERS; i++ )
	{
		if( !g_FF_Filters[i] )
		{
			g_FF_Filters[i] = filter;
			return 0;
		}
	}
	return -1;
}

int ff_filter_rem( FF_Filter filter )
{
	for( int i = 0; i < FF_MAX_FILTERS; i++ )
		if( g_FF_Filters[i] == filter )
		{
			g_FF_Filters[i] = NULL;
			return 0;
		}
	return -1;
}
