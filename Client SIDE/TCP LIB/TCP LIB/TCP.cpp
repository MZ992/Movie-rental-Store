#include "TCP.h"

TCP::TCP()
{
}

TCP::~TCP()
{
}

int TCP::sendClient(CSocket& socket, Client& client)
{
	int x0, x1, x2, x3, x4;
	int x5 = 0; int x6 = 0; int temp1 = 0; int temp2 = 0;
	x0 = socket.Send((char*)&client.fName, sizeof(client.fName));
	x1 = socket.Send((char*)&client.lName, sizeof(client.lName));
	x2 = socket.Send((char*)&client.userName, sizeof(client.userName));
	x3 = socket.Send((char*)&client.Pass, sizeof(client.Pass));
	x4 = socket.Send((char*)&client.cardNum, sizeof(client.cardNum));
	for (int i = 0; i < MAX1; i++)
	{
		temp1 = socket.Send((char*)&client.Messages[i], sizeof(client.Messages[i]));
		x5 += temp1;
	}
	for (int j = 0; j < MAX0; j++)
	{
		temp2 = socket.Send((char*)&client.Movies[j], sizeof(client.Movies[j]));
		x6 += temp2;
	}
	return (x0 + x1 + x2 + x3 + x4 + x5 + x6);
}

int TCP::receiveClient(CSocket& socket, Client& client)
{
	int x0, x1, x2, x3, x4;
	int x5 = 0; int x6 = 0; int temp1 = 0; int temp2 = 0;
	x0 = socket.Receive((char*)&client.fName, sizeof(client.fName));
	x1 = socket.Receive((char*)&client.lName, sizeof(client.lName));
	x2 = socket.Receive((char*)&client.userName, sizeof(client.userName));
	x3 = socket.Receive((char*)&client.Pass, sizeof(client.Pass));
	x4 = socket.Receive((char*)&client.cardNum, sizeof(client.cardNum));
	for (int i = 0; i < MAX1; i++)
	{
		temp1 = socket.Receive((char*)&client.Messages[i], sizeof(client.Messages[i]));
		x5 += temp1;
	}
	for (int j = 0; j < MAX0; j++)
	{
		temp2 = socket.Receive((char*)&client.Movies[j], sizeof(client.Movies[j]));
		x6 += temp2;
	}
	return (x0 + x1 + x2 + x3 + x4 + x5 + x6);
}

int TCP::sendMovies(CSocket& socket, Movies& movies)
{
	int x = 0;
	int temp = 0;
	for (int i = 0; i < MAX; i++)
	{
		temp = socket.Send((char*)&movies.allMovies[i], sizeof(movies.allMovies[i]));
		x += temp;
	}
	return x;
}
int TCP::receiveMovies(CSocket& socket, Movies& movies)
{
	int x = 0;
	int temp = 0;
	for (int i = 0; i < MAX; i++)
	{
		temp = socket.Receive((char*)&movies.allMovies[i], sizeof(movies.allMovies[i]));
		x += temp;
	}
	return x;
}