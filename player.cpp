#include <iostream>
#include <cstring> 
#include "player.h"
#include "board.h"
#include "game.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Player::Player()
{
	name = nullptr;
	symbol = ' ';
}

Player::Player(char* shem, char sym)
{
	int i = 0, counter = 0;
	while (shem[i] != '\0')
		counter++;
	name = new char[counter];

	for (i = 0; i < counter; i++)
		name[i] == shem[i];

	symbol = sym;
}

Player:: ~Player(){}


int Player::make_move() {
	int choose = 0;
	cin >> choose;
	return choose - 1;
}

void Player::print_player()
{
	cout << name << " with symbol: " << symbol<< " ";
}

char* Player::get_name(){
	return name;
}

char Player::get_symbol() {
	return symbol;
}

void Player::set_name(char* NtoIn)
{
	int i = 0, counter = 0;
	while (NtoIn[i] != '\0')
	{
		counter++;
		i++;
	}
	name = new char[counter+1];
	
	strcpy(name, NtoIn);

	//for (i = 0; i < counter; i++)
	//	name[i] == NtoIn[i];
	
}

void Player::set_symbol(char newC)
{
	symbol = newC;
}