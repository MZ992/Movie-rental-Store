#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include "Movie.h"
using namespace std;

enum{ MAX1 = 20, MAX2 = 256, MAX0 = 20 };
class Client
{
 private:
	char fName[20];
	char lName[20];
	char userName[20];
	char Pass[20];
	double cardNum;
	char Messages[MAX1][MAX2];
 public:
	 Movie Movies[MAX0];
	 Client();
	~Client();
	char* getUser();
	char* getPass();
	void showDetails();
	void showMessages();
	void showMovies();
	void Register();
	void Login();
	void setMessage(char* M);
	void deleteMessages();
	friend ostream& operator<< (ostream& out, Client& client);
	friend istream& operator>> (istream& in, Client& client);
	friend class TCP;
};

