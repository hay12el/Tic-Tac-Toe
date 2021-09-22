#include <iostream>
#include <string>
#include "player.h"
#include "board.h"
#include "game.h"
#include <random>
#include <random>

using namespace std;

Game::Game(){
	turn = ' ';
	status = start;
}

Game::Game(char* name1, char* name2) : board(9) {
	srand(time(nullptr));
	players[0].set_name(name1);
	players[0].set_symbol('X');	
	players[1].set_name(name2);
	players[1].set_symbol('O');
	turn = players[rand() % 2].get_symbol();
	status = start;
}

void Game::play(){
	int nowTurn;
	if (turn == players[0].get_symbol())
		nowTurn = 0;
	else
		nowTurn = 1;
	do
	{
		system("cls"); //clean screen.
		board.print(); //print board
		cout << endl;
		cout << "Choose your move"<<endl<<"Player name: ";
		
		players[nowTurn].print_player(); //print the details of current player.

		int choose = players[nowTurn].make_move();
		while (board.set_symbol(choose, players[nowTurn].get_symbol()) == false) //check if the choosen number is legal and inialize the cell
		{
			cout << "ilegal number, try again!: ";
			choose = players[nowTurn].make_move();
			cout << endl;	
		}

		if (winOrDraw())
		{
			status = win;
		}
		else if (is_draw())
		{
			status = draw;
		}
		nowTurn = (nowTurn + 1) % 2;

	} while (status == start);

	if (status == win)
	{
		system("cls");
		board.print();
		cout << endl<<endl<<endl;           
		cout << "We have a winner: ";
		players[(nowTurn + 1) % 2].print_player();
		cout << endl<<endl<<endl;
	}
	else if (status == draw)
	{
		system("cls");
		board.print();
		cout << endl<<endl<<endl;
		cout << "It is a Draw!";
		cout << endl<<endl<<endl;
	}
	exit(1);
}

bool Game::winOrDraw()
{
	int i;
	for (i = 0; i < 9; i+=3)//check for rows
	{
		if (board.get_symbol(i) != ' ' && (board.get_symbol(i) == board.get_symbol(i + 1) && board.get_symbol(i + 1) == board.get_symbol(i + 2)))
			return true;
	}
	for (i = 0; i < 3; i++) //check for columns
	{
		if (board.get_symbol(i) == board.get_symbol(i + 3) && board.get_symbol(i + 3) == board.get_symbol(i + 6) && board.get_symbol(i) != ' ')
			return true;
	}
	if (board.get_symbol(0) == board.get_symbol(4) && board.get_symbol(4) == board.get_symbol(8) && board.get_symbol(0) != ' ')
		return true;
	if (board.get_symbol(2) == board.get_symbol(4) && board.get_symbol(4) == board.get_symbol(6) && board.get_symbol(2) != ' ')
		return true;
	return false;
}

bool Game::is_draw()
{
	if (board.count_board() == 0)
		return true;
	else
		return false;
}

void Game::print(int n)
{
	cout << players[n].get_name() << endl;
}

Game::~Game(){}