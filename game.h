#ifndef __Game_H
#define __Game_H
#include "player.h"
#include "board.h"


class Game {
private:
	Board board;
	Player players[2];
	enum statuses { win, draw, start };
	statuses status;
	char turn;
public:
	Game();
	Game(char*, char*);
	void play();
	bool winOrDraw();
	bool is_draw();
	void print(int);
	~Game();
};

#endif