#include "Movies.h"


Movies::Movies()
{

}
Movies::~Movies()
{

}

ostream& operator<< (ostream& sout, Movies& movies)
{
	for (int i = 0; i < MAX; i++)
		sout << movies.allMovies[i] << ' ';
	return sout;
}

istream& operator>> (istream& sin, Movies& movies)
{
	for (int i = 0; i < MAX; i++)
		sin >> movies.allMovies[i];
	return sin;
}