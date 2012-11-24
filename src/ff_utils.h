/*
 * ff_utils.h
 *
 *  Created on: Aug 27, 2009
 *      Author: engin
 */

#ifndef FF_UTILS_H_
#define FF_UTILS_H_

struct FF_Board;
struct FF_Cell;

void ff_util_print_board( struct FF_Board* board );
int ff_util_remove_possibility( struct FF_Cell** cells, size_t listSize, int p );
void ff_util_import_data( struct FF_Board* board, int* data );

#endif /* FF_UTILS_H_ */
