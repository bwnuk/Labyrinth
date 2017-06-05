#include "game.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include "solve.h"
#include <conio.h>

using namespace std;

game::game()
{
}

void game::menu()
{
	system("cls");
	cout << "Welcome to the labyrinth" << endl;
	cout << "You have to choice, what you want to do: \n";
	cout << "1 - play\n";
	cout << "2 - bot\n";
	cout << "3 - edit\n";
	cout << "4 - exit\n";
	cin >> choice;
	game::ch();
}

void game::ch()
{
	solve lab;

	lab.reading();
	lab.size();

	lab.board();
	lab.filling();
	error(lab);

	lab.capabilities();

	switch (choice)
	{
	case 1:
		play(lab);
		break;
	case 2:
		lab.passage();
		lab.road();
		cout << "View: " << endl;
		lab.painting();
		cout << endl;
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		cout << "WRONG NUMBER" << endl;
		system("pause");
		menu();
		break;
	}
}

void game::play(solve l)
{
	system("cls");

	//l.painting();
}


game::~game()
{
}