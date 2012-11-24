/*
 * ff_block.c
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#include <stdlib.h>

#include "ff_block.h"

#include "ff_common.h"
#include "ff_board.h"

FF_Block* ff_block_init( struct FF_Board* board )
{
	FF_DEBUG("[ff_block_init]\n");
	FF_Block* block = malloc( sizeof(FF_Block) );
	if( !block ) return NULL;
	size_t sqr = board->Size * board->Size;
	block->Board = board;
	block->Cells = malloc( sizeof(struct FF_Cell*) * board->Size * board->Size );
	block->VProbabilities = malloc( sizeof(int*) * board->Size );
	block->HProbabilities = malloc( sizeof(int*) * board->Size );
	for( size_t i = 0; i < board->Size; i++ )
	{
		block->VProbabilities[i] = malloc( sizeof(int) * sqr );
		block->HProbabilities[i] = malloc( sizeof(int) * sqr );
		for( size_t j = 0; j < sqr; j++ )
		{
			block->VProbabilities[i][j] = 1;
			block->HProbabilities[i][j] = 1;
		}
	}
	return block;
}

void ff_block_free( FF_Block* block )
{
	FF_DEBUG("[ff_block_free] %p\n", (void*)block);
	free( block->Cells );
	for( size_t i = 0; i < block->Board->Size; i++ )
	{
		free(block->VProbabilities[i]);
		free(block->HProbabilities[i]);
	}
	free( block->VProbabilities );
	free( block->HProbabilities );
	free( block );
}
