#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <vector>

using namespace std;

class solve
{
public:
	solve();
	~solve();

	//					POSSIBLE DIRECTIONS
	enum directions
	{
		right = 0,
		down = 1,
		up = 2,
		left = 3,
		default = 5
	};

	//					Structur of Crosse
	struct Crossing
	{
		int z; // X
		int w; // Y
		directions direct;
	};

	//							COLUMN
	int x;
	
	//							LINE
	int y;

	int iter;
	int **tab;
	int **tab_cap;

	//							FUNCTIONS ARE EXPLAINED IN SOLVE.CPP
	void reading();
	void size();
	void board();
	void filling();
	int searching();
	void capabilities();
	void passage();
	void going();
	void painting();
	void checking();

	//								ERROR WITH NOT FOUNDING A FILE
	friend void error(solve k);
};

