#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

struct User
{
	char username[30];
	char password[20];
	double balance;

};
char MainMenu();
int FindAccount(vector<User> users, char username[30], char password[20]);
void Processing(vector<User> users);

int main()
{
	vector<User> users;


}
void SecondMenu(User user, vector<User> users)
{
	/*You have X BGN.Choose one of the following options :
	C - cancel account
		D - deposit
		L - logout
		T - transfer
		W - withdraw*/

	cout << "You have" << user.balance << " BGN.Choose one of the following options :";
	cout << "C - cancel account" << endl;
	cout << "     D - deposit" << endl;
	cout << "     L - logout" << endl;
	cout << "     T - transfer" << endl;
	cout << "     W - withdraw" << endl;
	char option;
	cin >> option;
	if (option == 'C')
	{
		char password[20];
		cout << "Password: "; cin >> password;
		if (user.password == password && user.balance == 0)
		{
			remove(users.begin(), users.end(), user);

		}
	}


}
void Processing(vector<User> users)
{
	char username[30];
	char password[20];
	char option = MainMenu();
	if (option == 'L')
	{
		cout << "Enter Name:  "; cin >> username;
		cout << endl;
		cout << "Enter Password:  "; cin >> password;
		int index = FindAccount(users, username, password);
		SecondMenu(users[index]);


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
int FindAccount(vector<User> users, char username[30], char password[20])
{
	for (int i = 0; i < size(users); i++)
	{
		if (users[i].username == username && users[i].password == password)
		{
			return i;
		}
	}
	return -1;

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
	cout << endl;
	cout << endl;

	return input;
}



