#include "Client.h"


Client::Client()
{
}

Client::~Client()
{
}

char* Client::getUser()
{
	return userName;
}

char* Client::getPass()
{
	return Pass;
}

void Client::showDetails()
{
	cout << "<< Your Details >>" << endl << endl;
	cout << "Full Name> " << fName << " " << lName << endl;
	cout << "User Name> " << userName << endl;
	cout << " PassWord> " << Pass << endl;
	cout << " Card Num> " << cardNum << endl;
	cout << endl;
}

void Client::showMessages()
{
	cout << "<< Your Messages >>" << endl << endl;
	for (int i = 0; i < MAX1; i++)
	{
		if (Messages[i][0] == '#')
		{
			cout << i + 1 << "> ";
			for (unsigned int j = 1; j < strlen(Messages[i]); j++)
				cout << Messages[i][j];
			cout << endl;
		}
	}
	cout << endl;
}
void Client::showMovies()
{
	cout << "<< Your Processed Movies >>" << endl << endl;
	for (int i = 0; i < MAX0; i++)
	{
		if (Movies[i].getName()[0] == '#')
		{
			cout << i + 1 << "> ";
			Movies[i].showMovieR();
			cout << endl;
		}
	}
	cout << endl;
}

void Client::Register()
{
	string fName1, lName1, userName1, Pass1;
	double cardNum1;
	cout << "<< Please Enter Your Details Below >>" << endl;
	cout << "\nFirst Name> ";
	cin >> fName1;
	cout << "\n Last Name> ";
	cin >> lName1;
	cout << "\n User Name> ";
	cin >> userName1;
	cout << "\n  PassWord> ";
	cin >> Pass1;
	cout << "\n  Card Num> ";
	while (!(cin >> cardNum1))
    {
		cout << "\tInvalid Value";
		cout << "\n  Card Num> ";
	    cin.clear();
	    cin.ignore();
    }
	REQUIRE0(fName1.length() < 20 && lName1.length() < 20 && userName1.length() < 20 && Pass1.length() < 20);
	strcpy(fName, fName1.c_str());
	strcpy(lName, lName1.c_str());
	strcpy(userName, userName1.c_str());
	strcpy(Pass, Pass1.c_str());
	cardNum = cardNum1;
	cout << endl;
}

void Client::Login()
{
	string userName1, Pass1;
	cout << "<< Please Enter Yours Below >>" << endl;
	cout << "\nUser Name> ";
	cin >> userName1;
	cout << "\n PassWord> ";
	cin >> Pass1;
	REQUIRE0(userName1.length() < 20 && Pass1.length() < 20);
	strcpy(userName, userName1.c_str());
	strcpy(Pass, Pass1.c_str());
	cout << endl;
}

void Client::setMessage(char* M)
{
	REQUIRE0(strlen(M) < (MAX2 - 1));
	for (int i = 0; i < MAX1; i++)
	{
		if (Messages[i][0] != '#')
		{
			strcpy(Messages[i], "#");
			strcat(Messages[i], M);
			ENSURE0(strlen(Messages[i]) < MAX2);
			return;
		}
	}
	this->deleteMessages();
	this->setMessage(M);
}

void Client::deleteMessages()
{
	for (int i = 0; i < MAX1; i++)
		strcpy(Messages[i], "\0");
}



