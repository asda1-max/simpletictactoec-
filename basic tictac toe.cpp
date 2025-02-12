#include <iostream>

using namespace std;

struct placed{
bool isx = false;
bool iso = false;
}placedObj[9];

char symbol[2] = {'x', 'o'};

void checks();
void gamefinish(int index);
void clearObj();
void gamestart();
void drawpanel();
void drawfield();
int giliran =1;
int turnleft = 9;

int main()
{
	int pilihan;
	cout << "------------------------\n";
	cout << "|      TIC TAC TOE     |\n";		
	cout << "------------------------\n";
	cout << "1. Play Game\n2. Exit\n=>";
	cin >> pilihan;
	if (pilihan == 1)
	{
		gamestart();
	}
	else if (pilihan == 2)
	{
		return 0;
	}
	else
	{
		cout << "Option Not Avaiable";
	}
	
}

void gamestart()
{
	system("cls");
	if (turnleft != 0)
	{
		drawfield();
	if (giliran == 1)
	{
		cout << "Player 1 Turn (x)!\n";
		int angka;
		cout << "Plot Number : "; cin >> angka;
		if (placedObj[angka-1].iso == true or placedObj[angka-1].isx ==true)
			{
				cout << "duplicate number detected\n"; system("pause");
				gamestart();
			}
		placedObj[angka-1].isx = true;
		giliran++;
	}
	else if (giliran ==2)
	{
		cout << "Player 2 turn (o)!\n";
		int angka;
		cout << "Plot : "; cin >> angka;
		if (placedObj[angka-1].iso == true or placedObj[angka-1].isx ==true)
			{
				cout << "duplicate number detected\n"; system("pause");
				gamestart();
			}
		placedObj[angka-1].iso = true;
		giliran--;
	}
		turnleft--;
	checks();
	gamestart();
	}
	else
	{
		drawpanel();
	}
	
}

void checks()
{
for (int a = 0; a < 3; a++)
{
	if (placedObj[a].iso == true and placedObj[a+1].iso == true and placedObj[a+2].iso == true)
	{
		gamefinish(1);
		break;
	}
	if (placedObj[a].iso == true and placedObj[a+3].iso == true and placedObj[a+6].iso == true)
	{
		gamefinish(1);
		break;
	}
	if (placedObj[a].isx == true and placedObj[a+1].isx == true and placedObj[a+2].isx == true)
	{
		gamefinish(0);
		break;
	}
	if (placedObj[a].isx == true and placedObj[a+3].isx == true and placedObj[a+6].isx == true)
	{
		gamefinish(0);
		break;
	}
}
if (placedObj[6].isx == true and placedObj[4].isx == true and placedObj[2].isx == true)
	{
		gamefinish(0);
	}
if (placedObj[0].isx == true and placedObj[4].isx == true and placedObj[8].isx == true)
	{
		gamefinish(0);
	}
if (placedObj[6].iso == true and placedObj[4].iso == true and placedObj[2].iso == true)
	{
		gamefinish(1);
	}
if (placedObj[0].iso == true and placedObj[4].iso == true and placedObj[8].iso == true)
	{
		gamefinish(1);
	}
}

void gamefinish(int index)
{
	system("cls");
	drawfield();
	int pil;
	cout << "Congratulations player " << index + 1 << " (" << symbol[index] << ")\n";
	cout << "-----------------";
	clearObj();
	giliran =1;
	cout << "\nMenu\n1. Play Again\n2. Menu\n=>"; cin>> pil;
	system("cls");
	if (pil == 1)
	{
		gamestart();
	}
	else if (pil == 2)
	{
		main();
	}
	else
	{
		cout << "Option Not Avaiable";
	}
}

void clearObj()
{
	for (int i = 0; i < 9; i++)
	{
		placedObj[i].iso = false;
		placedObj[i].isx = false;
	}
	turnleft = 9;
}

void drawpanel()
{
	drawfield();
	int pil;
	cout << "DRAW\n";
	cout << "-----------------";
	clearObj();
	giliran =1;
	cout << "\nMenu\n1. Play Again\n2. Menu\n=>"; cin>> pil;
	system("cls");
	if (pil == 1)
	{
		gamestart();
	}
	else if (pil == 2)
	{
		main();
	}
	else
	{
		cout << "Option Not Avaiable";
	}
}

void drawfield()
{
	cout << "------------- \n";
	for (int i = 1; i <= 9; i++)
	{
		if (i%3 == 1)
		{
			cout << "|";
		}
		
		if (placedObj[i-1].iso == false and placedObj[i-1].isx == false)
		{
			cout << " " <<"\033[0m" << i << " " << "|";
		}
		else if (placedObj[i-1].iso == true)
		{
			cout << " " << "\033[31m" << "o" << "\033[0m"<< " " << "|";
		}
		else if (placedObj[i-1].isx == true)
		{
			cout << " "  <<  "\033[34m" << "x" << "\033[0m" << " " << "|";
		}
		if ( i%3 == 0)
		{
			cout << "\n------------- \n";
		}
	}
}
