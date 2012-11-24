/*
 * ff_block.h
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#ifndef FF_BLOCK_H_
#define FF_BLOCK_H_

struct FF_Board;
struct FF_Cell;

typedef struct FF_Block
{
	struct FF_Board* Board;
	struct FF_Cell** Cells;
	int**	VProbabilities;
	int**	HProbabilities;
} FF_Block;

FF_Block* ff_block_init( struct FF_Board* board );
void ff_block_free( FF_Block* );
#endif /* FF_BLOCK_H_ */
