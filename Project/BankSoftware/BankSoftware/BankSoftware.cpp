#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct User
{
	char username[30];
	char password[20];
	double balance;

};
char MainMenu();
void Processing();
int main()
{
	

}
void Processing()
{
	char username[30];
	char password[20];
	char option = MainMenu();
	if (option == 'L')
	{
		cout << "Enter Name:  "; cin >> username;
		cout << endl;
		cout << "Enter Password:  "; cin >> password;
	}
	else if (option == 'R')
	{
		cout << "Enter Name:  "; cin >> username;
		cout << endl;
		cout << "Enter Password:  "; cin >> password;
	}
	else 
	{
		exit(0);
	}
}

char MainMenu()
{
	char input;
	cout << endl;
	cout << "     Choose one of the options:   " << endl;
	cout << endl;
	cout << endl;
	cout << "L for login" << "    " << "R for register" << "    ." << "Q for quit";
	cout << endl;
	cin >> input;

	return input;
}



