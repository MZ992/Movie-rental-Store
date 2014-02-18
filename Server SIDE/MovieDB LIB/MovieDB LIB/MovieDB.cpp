#include "MovieDB.h"


MovieDB::MovieDB()
{
}

MovieDB::~MovieDB()
{
}

void MovieDB::writeMovie(Movie& movie)
{
	ofstream FILE;
	FILE.open("Movie_DataBase.dtb", ios::app | ios::binary);
	
	REQUIRE0(FILE.is_open());
	FILE.write((char*)&movie, sizeof(movie));
	FILE.close();
}

int MovieDB::searchMovie(double code)
{
	int j = 0;
	Movie movie;
	ifstream FILE;
	FILE.open("Movie_DataBase.dtb", ios::binary);
	
	REQUIRE0(FILE.is_open());
	while (!FILE.eof())
	{
		FILE.seekg(j*sizeof(Movie), ios::beg);
		FILE.read((char*)(&movie), sizeof(movie));
		if (code == movie.getCode())
		{
			FILE.close();
			return j;
		}
		j++;
	}
	FILE.close();
	return -1;
}

Movie MovieDB::readMovie(int j)
{
	REQUIRE0(j >= 0);
	Movie movie;
	ifstream FILE;
	FILE.open("Movie_DataBase.dtb", ios::binary);
	
	REQUIRE0(FILE.is_open());
	FILE.seekg(j*sizeof(Movie), ios::beg);
	FILE.read((char*)(&movie), sizeof(movie));
	FILE.close();
	return movie;
}

void MovieDB::updateMovie(Movie& movie, int j)
{
	REQUIRE0(j >= 0);
	ofstream FILE;
	FILE.open("Movie_DataBase.dtb", ios::out | ios::in | ios::binary);

	REQUIRE0(FILE.is_open());
	FILE.seekp(j*sizeof(Movie), ios::beg);
	FILE.write((char*)(&movie), sizeof(movie));
	FILE.close();
}

int MovieDB::numMovie()
{
	int j = 0;
	ifstream FILE;
	FILE.open("Movie_DataBase.dtb", ios::binary);

	REQUIRE0(FILE.is_open());
	while (!FILE.eof())
	{
		FILE.seekg(j*sizeof(Movie), ios::beg);
		j++;
	}
	FILE.close();
	return (j-1);
}