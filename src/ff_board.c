/*
 * ff_board.c
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#include "ff_board.h"

#include "ff_common.h"
#include "ff_cell.h"
#include "ff_block.h"
#include "ff_cell.h"
#include "ff_line.h"

FF_Board* ff_board_init( size_t size )
{
	FF_DEBUG( "[ff_board_ini] size: %zu\n", size );
	FF_Board* board = malloc( sizeof(FF_Board) );
	size_t sqr = size * size;
	size_t sqrsqr = sqr * sqr;
	board->Size = size;
	board->Cells = malloc( sizeof(FF_Cell*) * sqrsqr );
	board->Blocks = malloc( sizeof(FF_Block*) * sqr );
	board->Rows = malloc( sizeof(FF_Line*) * sqr );
	board->Columns = malloc( sizeof(FF_Line*) * sqr );

	for( size_t i = 0; i < sqrsqr; i++ )
	{
		FF_Cell* cell = ff_cell_init( board );
		board->Cells[i] = cell;
		cell->ID = i;
	}

	for( size_t i = 0; i < sqr; i++ )
	{
		FF_Line* row = ff_line_init( board );
		for( size_t x = 0; x < sqr; x++ )
		{
			FF_DEBUG("Cell %d to Row %d\n", board->Cells[x + i * sqr]->ID, i);
			row->Cells[x] = board->Cells[x + i * sqr];
		}
		board->Rows[i] = row;

		FF_Line* column = ff_line_init( board );
		for( size_t y = 0; y < sqr; y++ )
		{
			FF_DEBUG("Cell %d to Col %d\n", board->Cells[y * sqr + i]->ID, i);
			column->Cells[y] = board->Cells[y * sqr + i];
		}
		board->Columns[i] = column;

		FF_Block* block = ff_block_init( board );
		int x = i % size;
		int y = i / size;
		int src = y * sqr * size + x * size;
		for( size_t j = 0; j < sqr; j++ )
		{
			int x2 = j % size;
			int y2 = j / size;
			FF_DEBUG("Cell %d to Block %d (x: %d y: %d x2: %d y2: %d)\n",
					board->Cells[src + y2 * sqr + x2]->ID, i, x, y, x2, y2 );
			block->Cells[j] = board->Cells[ src + y2 * sqr + x2 ];
		}
		board->Blocks[i] = block;
	}
	return board;
}

void ff_board_free( FF_Board* board )
{
	FF_DEBUG("[ff_board_free] %p\n", (void*)board);
	size_t sqr = board->Size * board->Size;
	size_t sqrsqr = sqr * sqr;
	for( size_t i = 0; i < sqrsqr; i++ )
		free( board->Cells[i] );
	free( board->Cells );

	for( size_t i = 0; i < sqr; i++ )
		ff_block_free(board->Blocks[i]);
	free( board->Blocks );

	for( size_t i = 0; i < sqr; i++ )
		ff_line_free( board->Rows[i] );
	free( board->Rows );

	for( size_t i = 0; i < sqr; i++ )
		ff_line_free( board->Columns[i] );
	free( board->Columns );
	free( board );
}
