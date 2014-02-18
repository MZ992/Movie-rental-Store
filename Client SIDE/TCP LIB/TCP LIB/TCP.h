#pragma once
#define _WIN32_WINNT _WIN32_WINNT_WIN8

#include <afx.h> 
#include <afxext.h> 
#include <afxsock.h>
#include "Client.h"
#include "Movies.h"

class TCP
{
 public:
	TCP();
	~TCP();
	int sendClient(CSocket& socket, Client& client);
	int receiveClient(CSocket& socket, Client& client);
	int sendMovies(CSocket& socket, Movies& movies);
	int receiveMovies(CSocket& socket, Movies& movies);
};

