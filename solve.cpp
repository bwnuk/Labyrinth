#include "solve.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include "solve.h"
#include <string>
#include <vector>

using namespace std;

solve::solve()
{
}

//											READING FILE
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

//									SIZE STUDY
void solve::size()
{
	ifstream file("lab.txt");

	string line;

	getline(file, line);
	
	//											COLUMN
	x = line.size() + 1;
	y = 0;
	
	//											LINE
	while (!file.eof())
	{
		getline(file, line);
		y++;
	}
	y += 2;
	file.close();
}

//										CREATING TABLE
void solve::board()
{
	tab = new int *[y];
	for (int i = 0; i <=y; i++ )
	{
		tab[i] = new int[x];
	}

	tab_cap = new int *[y];
	for (int i = 0; i <= y; i++)
	{
		tab_cap[i] = new int[x];
	}
	
}

//										FILLING TABLE FROM FILE
void solve::filling()
{
	ifstream file("lab.txt");
	
	string temp;
	int templ;
	int k;

	for (int i = 0; i <= y; i++)
	{
		tab[i][0] = 0;
		tab[i][x] = 0;
	}
	for (int j = 0; j < x; j++)
	{
		tab[0][j] = 0;
		tab[y][j] = 0;
	}

	for (int i = 1; i < y; i++)
	{
		k = 0;
		getline(file, temp);
		templ = temp.size() - 1;

		for (int j = 1; j < x; j++)
		{
			tab[i][j] = temp[k] - 48;
			k++;
		}
	}
	tab[1][1] = 2;
	
	file.close();
}

//											SEARCHING OF FINISH
int solve::searching()
{
	for (int i = 1; i < y; i++)
	{
		if (tab[i][x-1] == 1)
		{
			tab[i][x - 1] = 3;
			return 1;
		}
	}

	for (int i = 1; i < x; i++)
	{
		if (tab[y - 1][i] == 1)
		{
			tab[y - 1][i] = 3;
			return 1;
			break;
		}
	}
	return 3;

}

//									FILLING TABLE WITH CAPABILITIES OF MOVES
void solve::capabilities()
{
	int temp_x = x;
	int temp_y = y;
	int i = 1;
	int j = 1;

	for (i = 0; i <= temp_y; i++)
	{
		for (j = 0; j <= temp_x; j++)
		{
			tab_cap[i][j] = 0;

			if (tab[i][j] != 0)
			{
				if (j != temp_x)
					if (tab[i][j + 1] == 1)
						tab_cap[i][j] += 1;

				if (j != 0)
					if (tab[i][j - 1] == 1 || tab[i][j - 1] == 2)
						tab_cap[i][j] += 1;
				if (i != temp_y)
					if (tab[i + 1][j] == 1)
						tab_cap[i][j] += 1;

				if (i != 0)
					if (tab[i - 1][j] == 1 || tab[i - 1][j] == 2)
						tab_cap[i][j] += 1;
			}

		}
	}
}

//													Passing labyrinth
void solve::passage()
{

	int i = 1;
	int j = 1;
	iter = 0;

	directions last = default;
	directions last_crs = default;
	Crossing temp = { i, j, last, last_crs };
	cross.push_back(temp);
	iter++;

	while (tab[i][j] != 3)
	{
		if (tab_cap[i][j] > 2 )
		{
			if (tab[i][j + 1] > 0 && last_crs != right)
			{
				if (last != left )
				{
					last = right;
					last_crs = right;
					iter--;
					if (i == cross[iter].z && j == cross[iter].w)
					{
						cross[iter].direct = last;
						cross[iter].last_cross = last_crs;
					}
					else
					{
						iter++;
						Crossing temp = { i, j, last, last_crs };
						cross.push_back(temp);
					}

					last_crs = default;
					j++;
				}
				else
				{
					iter--;
					i = cross[iter - 1].z;
					j = cross[iter - 1].w;
					last = cross[iter - 1].direct;
					last_crs = cross[iter - 1].last_cross;
				}
			}
			else if (tab[i + 1][j] > 0 && last_crs != down )
			{
				if (last != up )
				{
					last_crs = down;
					last = down;
					iter--;

					if (i == cross[iter].z && j == cross[iter].w)
					{
						cross[iter].direct = last;
						cross[iter].last_cross = last_crs;
					}
					else
					{
						iter++;
						Crossing temp = { i, j, last, last_crs };
						cross.push_back(temp);
					}

					last_crs = default;
					i++;
				}
				else
				{
					iter--;
					i = cross[iter].z;
					j = cross[iter].w;
					last = cross[iter].direct;
					last_crs = cross[iter].last_cross;
				}
			}
			else if (tab[i - 1][j] > 0 && last_crs != up)
			{
				if (last != down )
				{
					last_crs = down;
					last = up;
					iter--;
					if (i == cross[iter].z && j == cross[iter].w)
					{
						cross[iter].direct = last;
						cross[iter].last_cross = last_crs;
					}
					else
					{
						iter++;
						Crossing temp = { i, j, last, last_crs };
						cross.push_back(temp);
					}

					last_crs = default;
					i--;
				}
				else
				{
					iter--;
					i = cross[iter].z;
					j = cross[iter].w;
					last = cross[iter].direct;
					last_crs = cross[iter].last_cross;
				}
			}
			else if (tab[i][j - 1] > 0 && last_crs != left)
			{
				if (last != right )
				{
					last_crs = left;
					last = left;
					iter--;
					if (i == cross[iter].z && j == cross[iter].w)
					{
						cross[iter].direct = last;
						cross[iter].last_cross = last_crs;
					}
					else
					{
						iter++;
						Crossing temp = { i, j, last, last_crs };
						cross.push_back(temp);
					}

					last_crs = default;
					j--;
				}
				else
				{
					iter--;
					i = cross[iter].z;
					j = cross[iter].w;
					last = cross[iter].direct;
					last_crs = cross[iter].last_cross;
				}
			}
			else
			{
				iter--;
				i = cross[iter].z;
				j = cross[iter].w;
				last = cross[iter].direct;
				last_crs = cross[iter].last_cross;
			}
		}
		else //							When is 1 possible way
		{
			if (tab[i][j + 1] > 0 && last != left)
			{
				j++;
				last = right;
			}
			else if (tab[i + 1][j] > 0 && last != up)
			{
				i++;
				last = down;
			}
			else if (tab[i - 1][j] > 0 && last != down)
			{
				i--;
				last = up;
			}
			else if (tab[i][j - 1] > 0 && last != right)
			{
				j--;
				last = left;
			}
			else
			{
				i = cross[iter].z;
				j = cross[iter].w;
				last = cross[iter].direct;
				last_crs = cross[iter].last_cross;
				iter++;
			}
		}
	}
}


//										LEAVING ROAD

void solve::road()
{
	int j = 1;
	int i = 1;
	int iterr = 1;
	
	directions last = default;

	while (tab[i][j] != 3)
	{
		if (tab_cap[i][j] > 2)
		{
			last = cross[iterr].last_cross;
			iterr++;
			
			switch (last)
			{
			case 0:
				tab[i][j] = 4;
				j++;
				last = right;
				break;
			case 1:
				tab[i][j] = 4;
				i++;
				last = up;
				break;
			case 2:
				tab[i][j] = 4;
				i--;
				last = down;
				break;
			case 3:
				tab[i][j] = 4;
				j--;
				last = left;
				break;
			case 5:
				exit(5);
				break;
			}
			
		}
		else
		{
			if (tab[i][j + 1] > 0)
			{
					tab[i][j] = 4;
					j++;
					last = right;
			}
			else if (tab[i + 1][j] > 0)
			{
				tab[i][j] = 4;
				i++;
				last = down;
			}
			else if (tab[i - 1][j] > 0)
			{
				tab[i][j] = 4;
				i--;
				last = up;
			}
			else if (tab[i][j - 1] > 0)
			{
				tab[i][j] = 4;
				j--;
				last = left;
			}
			else
			{
				exit(4);
			}
		}
	}
}

//												CONSOLE PAINTING
void solve::painting()
{
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (tab[i][j] == 1)
				cout << "  ";
			else if (tab[i][j] == 0)
				cout << "* ";
			else if (tab[i][j] == 3 || tab[i][j] == 2)
				cout << "X ";
			else if (tab[i][j] == 4)
				cout << "o ";
		}
		cout << endl;
	}
}

void solve::checking1()
{
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

//									FOR ME - CHECKING TABLES
void solve::checking()
{
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			cout << tab_cap[i][j] << " ";
		}
		cout << endl;
	}
	//cout << x << y;
}

solve::~solve()
{
}
