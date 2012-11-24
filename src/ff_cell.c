/*
 * ff_cell.c
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#include "ff_cell.h"
#include "ff_common.h"
#include "ff_board.h"

FF_Cell* ff_cell_init(struct FF_Board* board )
{
	FF_Cell* cell = malloc( sizeof( FF_Cell ) );
	if(!cell)
	{
		FF_DEBUG("[ff_cell_init] No more memory.\n");
		return NULL;
	}
	cell->Board = board;
	cell->Value = 0;
	size_t sqr = board->Size * board->Size;
	cell->Possibilities = malloc( sizeof(int) * sqr );

	if(!cell->Possibilities)
	{
		FF_DEBUG("[ff_cell_init] No more memory.\n");
		free(cell);
		return NULL;
	}
	for( size_t i = 0; i < sqr; i++ )
	{
		cell->Possibilities[i] = 1;
	}
	FF_DEBUG("[ff_cell_init] Allocated: %p\n", (void*)cell);
	return cell;
}

void ff_cell_free( FF_Cell* cell )
{
	free( cell->Possibilities );
	free( cell );
}
