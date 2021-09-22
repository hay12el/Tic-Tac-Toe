#ifndef __Cell_H
#define __Cell_H

class Cell{
private:
	char cell;
	bool free;
public:
	Cell();
	void print();
	void setter(char);
	char getter();
	bool Is_free();
	~Cell();
};

#endif