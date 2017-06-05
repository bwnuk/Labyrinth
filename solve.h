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
private:

	//					POSSIBLE DIRECTIONS
	enum directions
	{
		right = 1,
		down = 2,
		up = 3,
		left = 4,
		default = -1
	};

	//					Structur of Crosse
	struct Crossing
	{
		int z; // X
		int w; // Y
		directions last_cross;
		directions f;
	};

	int **tab_cap;
	vector <Crossing> cross;
	int iter;

protected:

	//							COLUMN
	int x;
	
	//							LINE
	int y;

	
	int **tab;
	
public:

	solve();
	~solve();

	//							FUNCTIONS ARE EXPLAINED IN SOLVE.CPP
	void reading();
	void size();
	void board();
	void filling();
	int searching();
	void capabilities();
	void passage();
	void road();
	void painting();
	void checking();
	void checking1();

	//								ERROR WITH NOT FOUNDING A FILE
	friend void error(solve k);
};