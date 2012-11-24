/*
 * ff_board.h
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#ifndef FF_BOARD_H_
#define FF_BOARD_H_

#include <stdlib.h>

struct FF_Cell;

typedef struct FF_Board
{
	size_t 				Size;
	struct FF_Cell**	Cells;
	struct FF_Line**	Rows;
	struct FF_Line**	Columns;
	struct FF_Block**	Blocks;
} FF_Board;

FF_Board* ff_board_init( size_t size );
void ff_board_free( FF_Board* board );

#endif /* FF_BOARD_H_ */
