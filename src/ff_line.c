/*
 * ff_line.c
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#include <stdlib.h>

#include "ff_line.h"
#include "ff_board.h"
#include "ff_common.h"

struct FF_Cell;

FF_Line* ff_line_init( struct FF_Board* board )
{
	FF_Line* line = malloc( sizeof(FF_Line) );
	if( !line )
	{
		FF_DEBUG("[ff_line_init] No more memory.\n");
		return NULL;
	}

	line->Board = board;
	size_t sqr = board->Size * board->Size;
	line->Cells = malloc( sizeof(struct FF_Cell*) * sqr );
	if( !line->Cells )
	{
		FF_DEBUG("[ff_line_init] No more memory.\n");
		free( line );
		return NULL;
	}

	FF_DEBUG("[ff_line_init] Allocated: %p\n", (void*)line);
	return line;
}

void ff_line_free( FF_Line* line )
{
	FF_DEBUG("[ff_line_free] %p\n", (void*)line);
	free( line->Cells );
	free( line );
}
