// labirynt.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include "solve.h"

using namespace std;

int main()
{
	solve lab;
	lab.reading();
	lab.size();
	lab.board();
	//lab.checking();
	lab.typing();
	lab.checking();
	system("pause");
	return 0;
}