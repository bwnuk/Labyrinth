// labirynt.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include "solve.h"

using namespace std;

void error(solve k)
{

	if (k.searching() == 3)
	{
		system("cls");
		cout << "NOT FOUND EXIT" << endl;
		system("pause");
		exit(3);
	}

}

int main()
{
	solve lab;
	
	lab.reading();
	lab.size();
	
	lab.board();
	lab.filling();
	
	// lab.searchin();
	error(lab);
	
	lab.capabilities();
	lab.passage();

	lab.road();


	lab.painting();
	lab.checking();

	system("pause");
	
	return 0;
}