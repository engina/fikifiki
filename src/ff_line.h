/*
 * ff_line.h
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#ifndef FF_LINE_H_
#define FF_LINE_H_

struct FF_Board;
struct FF_Cell;

typedef struct FF_Line
{
	struct FF_Board*	Board;
	struct FF_Cell**	Cells;
} FF_Line;

FF_Line* ff_line_init( struct FF_Board* board );
void ff_line_free( FF_Line* );

#endif /* FF_LINE_H_ */
