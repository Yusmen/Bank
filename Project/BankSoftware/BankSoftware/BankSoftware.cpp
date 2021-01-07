#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct User
{
	char username[30] = "";
	char password[20] = "";
	double balance;

};
char MainMenu();
bool AreEqualCharArrays(char firstArr[30], char secondArr[30]);
void Copy(char firstArr[30], char secondArr[30]);
int FindAccount(vector<User>& users, char username[30], char password[20]);
void SecondMenu(int numberOfUser, vector<User>& users);
void Processing(vector<User>& users);
vector<User> ReadFromFile();
void RecordInFile(vector<User> users);
int main()
{
	vector<User> users = ReadFromFile();

	Processing(users);
	RecordInFile(users);

	//string number = "25";
	//char arr[20] = "poiee";
	//string name = "Ikpow";
	//name = arr;
	//cout << name;
	////cout << name[0];

}
void RecordInFile(vector<User> users)
{
	char filename[150] = "C:/Users/Yusmen/Desktop/users.txt";

	ofstream File(filename);
	for (int i = 0; i < users.size(); i++)
	{
		File << users[i].username << ':' << users[i].password << ':' << users[i].balance << endl;
	}
	File.close();
}
vector<User> ReadFromFile()
{
	vector<User> users;

	char filename[150] = "C:/Users/Yusmen/Desktop/users.txt";

	ifstream File(filename);
	char userLine[30];

	while (!File.eof())
	{
		char username[30] = "";
		char password[20] = "";
		char balance[20] = "";

		File >> userLine;
		int i = 0;
		while (userLine[i] != ':')
		{
			username[i] = userLine[i];
			i++;
		}
		int k = 0;
		while (userLine[i + 1] != ':')
		{
			password[k++] = userLine[i + 1];
			i++;
		}
		k = 0;
		while (userLine[i + 2] != '\0')
		{
			balance[k++] = userLine[i + 2];
			i++;
		}
		string stringBalance = balance;

		User user;
		Copy(username, user.username);
		Copy(password, user.password);
		double numberBalance = atof(stringBalance.c_str());
		user.balance = numberBalance;
		//cout << username << endl;
		//cout << password<<endl;
		//cout << numberBalance<<endl;
		//cout << userLine << endl;
		//cout << endl;
		users.push_back(user);

	}

	File.close();
	return users;


}

void SecondMenu(int numberOfUser, vector<User>& users)
{
	cout << "You have " << users[numberOfUser].balance << " BGN. Choose one of the following options:  " << endl;
	cout << "C - cancel account" << endl;
	cout << "D - deposit" << endl;
	cout << "L - logout" << endl;
	cout << "T - transfer" << endl;
	cout << "W - withdraw" << endl;
	char option;
	cin >> option;
	if (option == 'C')
	{
		char password[20];
		cout << "Password: "; cin >> password;
		cout << endl;
		int index = 0;

		if (AreEqualCharArrays(users[numberOfUser].password, password) && users[numberOfUser].balance == 0)
		{
			users.erase(users.begin() + numberOfUser);
		}
	}
	else if (option == 'D')
	{
		double depositSum;
		cout << "Amount for deposit: ";  cin >> depositSum;
		users[numberOfUser].balance += depositSum;
	}
	else if (option == 'L')
	{
		MainMenu();
	}
	else if (option == 'T')
	{
		char username[30];
		char password[30];
		double amount;
		cout << "Enter username for transfer: ";
		cout << "Password: "; cin >> password;
		cout << "Amount to transfer: "; cin >> amount;
		int accountNumber = FindAccount(users, username, password);
		users[accountNumber].balance += amount;
		users[numberOfUser].balance -= amount;

	}
	else if (option == 'W')
	{
		double amount;
		cout << "Amount for decreasing: ";  cin >> amount;
		users[numberOfUser].balance -= amount;
	}



}
bool AreEqualCharArrays(char firstArr[30], char secondArr[30])
{
	if (strlen(firstArr) != strlen(secondArr))
	{
		return false;
	}

	for (size_t i = 0; i < strlen(firstArr); i++)
	{
		if (firstArr[i] != secondArr[i])
		{
			return false;
		}
	}
	return true;
}
void Processing(vector<User>& users)
{

	char option = MainMenu();

	if (option == 'L')
	{
		char username[30];
		char password[20];
		cout << "Enter Name:  "; cin >> username;
		cout << endl;
		cout << "Enter Password:  "; cin >> password;
		cout << endl;
		int index = FindAccount(users, username, password);
		SecondMenu(index, users);


	}
	else if (option == 'R')
	{
		char username[30];
		char password[20];
		cout << "Enter Name:  "; cin >> username;
		cout << endl;
		cout << "Enter Password:  "; cin >> password;
		cout << endl;
		User user;
		user.balance = 0;
		Copy(username, user.username);
		Copy(password, user.password);
		users.push_back(user);
		int index = FindAccount(users, username, password);
		SecondMenu(index, users);
	}
	else if (option == 'Q')
	{
		exit(0);
	}
}
void Copy(char firstArr[30], char secondArr[30])
{
	for (size_t i = 0; i < strlen(firstArr); i++)
	{
		secondArr[i] = firstArr[i];
	}
}
int FindAccount(vector<User>& users, char username[30], char password[20])
{
	for (int i = 0; i < size(users); i++)
	{
		if (AreEqualCharArrays(users[i].username, username)
			&& AreEqualCharArrays(users[i].password, password))
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



