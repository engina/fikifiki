/*
 * ff_util.c
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#include <stdio.h>

#include "ff_utils.h"

#include "ff_board.h"
#include "ff_cell.h"

void ff_util_print_board( struct FF_Board* board )
{
	size_t sqr = board->Size * board->Size;

	int dLines = sqr + board->Size + 1;
	int k = 0;
	for( int i = 0; i < dLines; i++ )
	{
		for( int j = 0; j < dLines; j++ )
		{
			if( !( i % (board->Size + 1 ) ) )
			{
				if( !( j % (board->Size + 1) ) )
				{
					printf( "Ö" );
				}
				else
					printf("-");
			}
			else
			{
				if( !( j % (board->Size + 1) ) )
				{
					printf( "|" );
				}
				else
					printf("%d", board->Cells[k++]->Value);
			}
		}
		printf("\n");
	}
}


int ff_util_remove_possibility( FF_Cell** cells, size_t listSize, int p )
{
	if(!listSize) return 0;
	if( !p ) return 0;
	int modified = 0;
	p--;
	for(size_t i = 0; i < listSize; i++)
	{
		FF_Cell* cell = cells[i];
		if( cell->Possibilities[p] )
		{
			cell->Possibilities[p] = 0;
			modified++;
		}
	}

	return modified;
}

void ff_util_import_data( struct FF_Board* board, int* data )
{
	size_t sqr = board->Size * board->Size;
	size_t sqrsqr = sqr * sqr;
	for( size_t i = 0; i < sqrsqr; i++ )
		board->Cells[i]->Value = data[i];
}
