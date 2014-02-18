#pragma once
#include <iostream>
#include <fstream>
#include "Movie.h"

class MovieDB
{
 public:
	MovieDB();
	~MovieDB();
	void writeMovie(Movie& movie);
	int searchMovie(double code);
	Movie readMovie(int j);
	void updateMovie(Movie& movie, int j);
	int numMovie();
};

