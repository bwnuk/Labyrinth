#include "solve.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include "solve.h"
#include <string>

using namespace std;

solve::solve()
{
}

void solve::reading()
{
	ifstream file("lab.txt");
	if ((file.fail()))
	{
		cout << "ERROR 1:\n FILE isn't avaible";
		exit(1);
	}

	file.close();
}

void solve::size()
{
	ifstream file("lab.txt");

	string line;

	getline(file, line);
	
	//											COLUMN
	x = line.size() - 1;
	y = 0;
	
	//											LINE
	while (!file.eof())
	{
		getline(file, line);
		y++;
	}
	file.close();
}

void solve::board()
{
	tab = new int *[y];
	for (int i = 0; i <=y; i++ )
	{
		tab[i] = new int[x];
	}
	
}

void solve::typing()
{
	ifstream file("lab.txt");
	
	string temp;
	int templ;
	int k;

	for (int i = 0; i <= y; i++)
	{
		k = 0;
		getline(file, temp);
		templ = temp.size() - 1;

		for (int j = 0; j <= x; j++)
		{
			tab[i][j] = temp[k] - 48;
			k++;
		}
	}
	
	file.close();
}

int solve::searching()
{
	for (int i = 0; i <= y; i++)
	{
		if (tab[i][x] == 1)
		{
			tab[i][x] = 3;
			return 1;
		}
	}

	for (int i = 0; i <= x; i++)
	{
		if (tab[y][i] == 1)
		{
			tab[y][i] = 3;
			return 1;
			break;
		}
	}
	return 3;

}

void solve::painting()
{
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (tab[i][j] == 1)
				cout << "* ";
			else if (tab[i][j] == 0)
				cout << "  ";
			else if(tab[i][j] == 3 || tab[i][j] == 2)
				cout << "X ";
		}
		cout << endl;
	}
}

void solve::checking()
{
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	//cout << x << y;
}

solve::~solve()
{
}
