#include <iostream>
#include "cell.h"

using namespace std;

Cell::Cell(){
	cell = ' ';
	free = true;
}

void Cell::print()
{
	cout << cell << endl;
}

void Cell::setter(char a)
{
	cell = a;
	free = true ? false : false;
}

char Cell::getter()
{
	return cell;
}

bool Cell::Is_free()
{
	if (free)
		return true;
	else
		return false;
}

Cell::~Cell(){}