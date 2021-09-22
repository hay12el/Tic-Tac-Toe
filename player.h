#ifndef __Player_h
#define __Player_h
#define _CRT_SECURE_NO_WARNINGS

class Player {
private:
	char* name;
	char symbol;
	Player(const Player&);
public:
	Player();
	Player(char*, char);
	~Player();
	int make_move();
	void print_player();
	void set_name(char*);
	void set_symbol(char);
	char* get_name();
	char get_symbol();
};

#endif