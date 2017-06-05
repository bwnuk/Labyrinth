#pragma once
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

class game:public solve
{
public:
	int choice;
	game();
	~game();
	void menu();
	void ch();
	void play(solve l);

	//									FUNCTION IN LABIRYNT.CPP
	friend void move(int xx, int yy);
};
