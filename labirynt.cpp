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
#include "game.h"

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

	cout << "tab_cap" << endl;
	lab.checking();
	cout << endl;

	lab.passage();
	cout << "tab" << endl;
	lab.checking1();
	lab.road();
	cout << endl; 

	cout << "View" << endl;
	lab.painting();
	cout << endl;
	
	cout << "tab_cap" << endl;
	lab.checking();
	cout << endl;
	
	cout << "tab" << endl;
	lab.checking1();

	system("pause");
	
	return 0;
}