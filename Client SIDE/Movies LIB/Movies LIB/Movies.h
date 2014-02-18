#pragma
#ifndef MOVIES_H  
#define MOVIES_H  

#include <iostream>
#include "Movie.h"

enum{MAX = 50};
class Movies
{
private:
public:
	Movies();
	~Movies();
	Movie allMovies[MAX];
	friend ostream& operator<< (ostream& sout, Movies& movies);
	friend istream& operator>> (istream& sin, Movies& movies);
	friend class TCP;
};
#endif