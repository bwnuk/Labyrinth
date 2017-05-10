#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class solve
{
public:
	solve();
	~solve();

	int x , y;
	int **tab;

	void reading();
	void size();
	void board();
	void filling();
	int searching();
	void painting();
	void checking();
	friend void error(solve k);
};

