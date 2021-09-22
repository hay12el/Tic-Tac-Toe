#include <iostream>
#include "board.h"
#include "cell.h"

using namespace std;

Board::Board()
{
	board = nullptr;
	size = 0;
}

Board::Board(int s)
{
	size = s;
	board = new Cell[size];
}

Board::Board(const Board& obj)
{
	board = new Cell[size];
	for (int i = 0; i < size; i++)
		board[i] = obj.board[i];
}

Board::~Board() {delete[] board;}

void Board::print() {
	int symbol_place = 0;
	bool theplace;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 17 ; j++)
		{
			theplace = is_char(i, j);
			if (theplace == false)
			{
				if (board[symbol_place].Is_free() == true)
					cout << " ";
				else
					cout << board[symbol_place].getter();
				symbol_place++;
			}
			else if (j == 5 || j == 11)
				cout << "|";
			else if ((j != 5 || j != 11) && (i == 2 || i == 5))
				cout << "_";
			else
			{
				if (theplace == true)
					cout << " ";
			}
		}
		cout << endl;
	}
}

bool Board::set_symbol(int position, char X_O) {
	if (position > 8 || position < 0)
		return false;
	else if (board[position].Is_free() == false)
		return false;
	else if (X_O != 'X' && X_O != 'O')
		return false;
	else 
	{
		board[position].setter(X_O);
		return true;
	}
}

int Board::count_board() {
	int counter = 0;
	for (int i = 0; i < 9; i++)
	{
		if (board[i].Is_free())
			counter++;
	}
	return counter;
}

char Board::get_symbol(int a) {
	return board[a].getter();
}

bool Board::is_char(int i, int j) {
	if (i == 1 || i == 4 || i == 7)
	{
		if (j == 2 || j == 8 || j == 14)
		{
			return false;
		}
	}
	return true;
}