/*
 * ff_cell.h
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#ifndef FF_CELL_H_
#define FF_CELL_H_

/* Forward declarations */
struct FF_Board;

typedef struct FF_Cell
{
	int					ID;
	int 				Value;
	struct FF_Board* 	Board;
	/*
	FF_Block* 	Block;
	FF_Line*	Row;
	FF_Line*	Column;
	*/
	int* Possibilities;
} FF_Cell;

FF_Cell* ff_cell_init( struct FF_Board* board );
void ff_cell_free( FF_Cell* cell );

#endif /* FF_CELL_H_ */
