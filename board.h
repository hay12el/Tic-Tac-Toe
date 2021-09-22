#ifndef __Board_H
#define __Board_H

#include <iostream>
#include "cell.h"

class Board {
private:
	Cell* board;
	int size;
public:
	Board();
	Board(int);
	Board(const Board&);
	~Board();
	void print();
	bool set_symbol(int, char);
	int count_board();
	char get_symbol(int);
	bool is_char(int, int);
};

#endif