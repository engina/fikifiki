/*
 ============================================================================
 Name        : fikifiki.c
 Author      : Engin AYDOGAN
 Version     :
 Copyright   :
 Description : Sudoku solvers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ff_common.h"
#include "ff_board.h"
#include "ff_utils.h"
#include "ff_cell.h"
#include "ff_line.h"
#include "ff_block.h"

int ff_filter_simple( FF_Board* board )
{
	size_t sqr = board->Size * board->Size;
	int modified = 0;
	for( size_t i = 0; i < sqr; i++ )
	{
		FF_Line* hline = board->Rows[i];
		FF_Line* vline = board->Columns[i];
		FF_Block* block = board->Blocks[i];
		for( size_t j = 0; j < sqr; j++ )
		{
			FF_Cell* cell = hline->Cells[j];
			modified += ff_util_remove_possibility(board->Rows[i]->Cells, sqr, cell->Value);
			cell = vline->Cells[j];
			modified += ff_util_remove_possibility(board->Columns[i]->Cells, sqr, cell->Value);
			cell = block->Cells[j];
			modified += ff_util_remove_possibility(board->Blocks[i]->Cells, sqr, cell->Value);
		}
	}
	return modified;
}

int ff_filter_lines( FF_Board* board )
{
	(void) board;
	return 0;
}

int ff_fill( FF_Board* board )
{
	size_t sqr = board->Size * board->Size;
	size_t sqrsqr = sqr * sqr;
	int filled = 0;
	for( size_t i = 0; i < sqrsqr; i++ )
	{
		FF_Cell* cell = board->Cells[i];
		if(cell->Value) continue;
		int c = 0;
		for( size_t j = 0; j < sqr; j++ )
		{
			if(cell->Possibilities[j])
				c++;
		}
		FF_DEBUG("%d - %d possibilities\n", cell->ID, c );
		if( c == 1 )
		{
			for( size_t j = 0; j < sqr; j++ )
			{
				if(cell->Possibilities[j])
				{
					cell->Value = j + 1;
					filled += 1;
					FF_DEBUG("Found value!\n");
					break;
				}
			}
		}
	}
	return filled;
}

int main(void) {
	/* very hard */
	int data_very_hard[] =
				 { 1, 0, 0, 0, 8, 0, 0, 0, 9,
				   0, 0, 0, 5, 0, 9, 0, 0, 0,
				   0, 0, 7, 4, 1, 3, 8, 0, 0,
				   0, 0, 1, 0, 0, 0, 4, 0, 0,
				   7, 6, 0, 0, 0, 0, 0, 8, 2,
				   0, 0, 5, 0, 0, 0, 3, 0, 0,
				   0, 0, 2, 9, 5, 4, 7, 0, 0,
				   0, 0, 0, 8, 0, 2, 0, 0, 0,
				   8, 0, 0, 0, 3, 0, 0, 0, 4 };

	/* very easy */
	int data_very_easy1[] =
				 { 0, 0, 6, 0, 2, 0, 9, 0, 0,
				   7, 3, 0, 0, 0, 0, 0, 8, 5,
				   0, 0, 0, 5, 0, 6, 0, 0, 0,
				   0, 0, 1, 7, 8, 4, 3, 0, 0,
				   0, 0, 0, 0, 0, 0, 0, 0, 0,
				   0, 0, 5, 9, 6, 1, 2, 0, 0,
				   0, 0, 0, 2, 0, 3, 0, 0, 0,
				   5, 2, 0, 0, 0, 0, 0, 9, 6,
				   0, 0, 8, 0, 4, 0, 1, 0, 0 };

	int data_very_easy2[] =
				{ 0, 0, 0, 0, 3, 0, 0, 0, 0,
				  0, 5, 0, 0, 0, 0, 0, 1, 0,
				  0, 4, 7, 1, 0, 9, 6, 3, 0,
				  4, 0, 0, 6, 0, 1, 0, 0, 3,
				  9, 0, 0, 0, 0, 0, 0, 0, 1,
				  7, 0, 0, 4, 0, 8, 0, 0, 2,
				  0, 2, 6, 7, 0, 4, 9, 5, 0,
				  0, 9, 0, 0, 0, 0, 0, 2, 0,
				  0, 0, 0, 0, 5, 0, 0, 0, 0
				};
	int data_easy[] = { 0, 0, 6, 0, 9, 0, 2, 0, 0,
					    0, 5, 0, 0, 0, 0, 0, 7, 0,
					    9, 0, 0, 3, 0, 2, 0, 0, 1,
					    0, 9, 0, 1, 0, 7, 0, 2, 0,
					    0, 0, 3, 0, 0, 0, 1, 0, 0,
					    0, 2, 0, 5, 0, 4, 0, 6, 0,
					    7, 0, 0, 8, 0, 5, 0, 0, 2,
					    0, 1, 0, 0, 0, 0, 0, 9, 0,
					    0, 0, 8, 0, 4, 0, 3, 0, 0 };
	(void) data_very_hard;
	(void) data_very_easy1;
	(void) data_very_easy2;
	(void) data_easy;
	
	FF_Board* board = ff_board_init( 3 );
	ff_util_import_data( board, data_very_easy2 );
	ff_util_print_board( board );
	int run = 1;
	while(1)
	{
		int m1 = ff_filter_simple(board);
		int m2 = ff_filter_lines(board);
		int filled = ff_fill(board);
		printf("Run: %d M1: %d M2: %d Filled: %d\n", run++, m1, m2, filled );
		if(!filled)
			break;
	}
	ff_util_print_board( board );

	ff_board_free( board );
	FF_DEBUG("Bye!\n");
	return EXIT_SUCCESS;
}
