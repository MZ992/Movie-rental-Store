#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <ctime>
#include "dbc.h"
using namespace std;

class Movie
{
 private:
	 char movieName[50];
	 double movieCode;
	 double movieYear;
	 char Duration[15];
	 int NumberOfCopies;
	 char rentTime[50];
	 char returnTime[50];
	 char Status[10];
 public:
	Movie();
	~Movie();
	double getCode();
	char* getName();
	void setOver();
	void setUnder();
	void setRent(time_t T); 
	void setReturn();
	void setReserve();
	void addMovie();
	void addMovieR(Movie& M);
	void showMovie();
	void showMovieR();
	friend ostream& operator<< (ostream& Out, Movie& movie);
	friend istream& operator>> (istream& In, Movie& movie);
};