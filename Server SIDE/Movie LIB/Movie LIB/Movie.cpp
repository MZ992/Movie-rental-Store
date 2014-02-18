#include "Movie.h"


Movie::Movie()
{
}

Movie::~Movie()
{
}

double Movie::getCode()
{
	return movieCode;
}

char* Movie::getName()
{
	return movieName;
}

void Movie::setOver()
{
	REQUIRE0(NumberOfCopies > 0);  
	    NumberOfCopies++;
}

void Movie::setUnder()
{
	REQUIRE0(NumberOfCopies > 0);
		NumberOfCopies--;
}

void Movie::setRent(time_t T)
{
	struct tm* Time;

	time_t current = time(0);
	Time = localtime(&current);
	strcpy(rentTime, ctime(&current));
	
	time_t next = time(0) + T;
	Time = localtime(&next);
	strcpy(returnTime, ctime(&next));

	 strcpy(Status, "Rented");
}

void Movie::setReturn()
{
	strcpy(rentTime, "Not Specified");
	strcpy(returnTime, "Not Specified");
	strcpy(Status, "Returned");
}

void Movie::setReserve()
{
	strcpy(rentTime, "Not Specified");
	strcpy(returnTime, "Not Specified");
	strcpy(Status, "Reserved");
}

void Movie::addMovie()
{
	char Name[49];
	cout << "<< Please Enter Details For New Movie >>" << endl;
	cout << "\n  Movie Name> ";
	cin.ignore();
	cin.get(Name, sizeof(Name));
	strcpy(movieName, "# ");
	strcat(movieName, Name);
	cout << "\n  Movie Code> ";
	while (!(cin >> movieCode))
	{
		cout << "\tInvalid Value";
		cout << "\n  Movie Code> ";
		cin.clear();
		cin.ignore();
	}
	cout << "\n  Movie Year> ";
	while (!(cin >> movieYear))
	{
		cout << "\tInvalid Value";
		cout << "\n  Movie Year> ";
		cin.clear();
		cin.ignore();
	}
	cout << "\n    Duration> ";
	cin >> Duration;
	cout << "\nNo.Of Copies> ";
	while (!(cin >> NumberOfCopies))
	{
		cout << "\tInvalid Value";
		cout << "\nNo.Of Copies> ";
		cin.clear();
		cin.ignore();
	}
	strcpy(rentTime, "Not-Specified");
	strcpy(returnTime, "Not-Specified");
	strcpy(Status, "Off");
	cout << endl;
}

void Movie::addMovieR(Movie& M)
{
	REQUIRE0(M.NumberOfCopies >= 0);
	strcpy(movieName, M.movieName);
    movieCode = M.movieCode;
	movieYear = M.movieYear;
    strcpy(Duration, M.Duration);
	NumberOfCopies = M.NumberOfCopies;
    strcpy(rentTime, M.rentTime);
    strcpy(returnTime, M.returnTime);
	strcpy(Status, M.Status);
}

void Movie::showMovie()
{
	cout << "    Movie Name> " << movieName << endl;
	cout << "    Movie Code> " << movieCode << endl;
	cout << "    Movie Year> " << movieYear << endl;
	cout << "      Duration> " << Duration << endl;
	cout << "NumberOfCopies> " << NumberOfCopies << endl;
}

void Movie::showMovieR()
{
	cout << " Movie Name> " << movieName << endl;
	cout << "    Movie Code> " << movieCode << endl;
	cout << "     Rent Time> " << rentTime << endl;
	cout << "   Return Time> " << returnTime << endl;
	cout << "        Status> " << Status << endl;
}

