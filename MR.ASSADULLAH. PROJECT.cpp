#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void Login();
void Register();
void Forgot();



main()
{
	int choice;
	cout << "****************************************" << endl;
	cout << "*******************Welcome**************" << endl;
	cout << "Menu; " << endl;
	cout << "1. Login" << endl;
	cout << "2. Register" << endl;
	cout << "3. Forgot username or password" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice" << endl;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		Login();
		break;
	case 2:
		Register();
		break;
	case 3:
		Forgot();
		break;
	case 4:
		system("cls");
		cout << "You have made a mistake, pls try again.";
		main();

	}
}


void Login()
{
	int count;
	string user, pass, u, p;
	system("cls");
	cout << "Please Enter the following details:" << endl;
	cout << "Username: ";
	cin >> user;
	cout << "password: ";
	cin >> pass;

	ifstream input("database.txt");
	while (input >> u >> p)
	{
		if (u == user && p == pass)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "Hello" << user << "/ n <LOGIN SUCSESSFUL>";
		cin.get();
		main();
	}
	else
	{
		cout<<"/nLOGIN ERROR!!!!/n Please check your username and password" <<endl;
		main();
	}
}

//lets register first
void Register()
{
	string reguser, regpass, ru, pu;
	system("cls");
	cout << "Enter username: ";
	cin >> reguser;
	cout << "Enter the password: ";
	cin >> regpass;

	ofstream reg("database.txt", ios::app);
	reg << reguser << " " << regpass << endl;
	system("cls");
	cout << "Registratiion Successful. " << endl;
	main();
}

void Forgot()
{
	int ch;
	system("cls");
	cout << "Forgotten? we're here to help." << endl;
	cout << "1. search your id by username" << endl;
	cout << "2. Main Menu" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
		int count = 0;
		string searchuser, su, sp;
		cout << "/n Enter your remembered username:";
		cin >> searchuser;

		ifstream searchu("database.txt");
		while (searchu >> su >> sp)
		{
			if (su == searchuser)
			{
				count = 1;
			}
		}
		searchu.close();
		if (count == 1)
		{
			cout << "/nAccount found" << endl;
			cout << "/nYour password is:" << sp;
			cin.get();
			system("cls");
			main();
		}
		else
		{
			cout << "/nSorry userID is not found in our database./n";
			cin.get();
			main();
		}
		break;

	}
}






