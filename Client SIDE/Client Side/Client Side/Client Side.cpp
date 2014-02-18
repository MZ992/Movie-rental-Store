// CLIENT SIDE

#include "stdafx.h"
#include "Client Side.h"

// MFC NETWORKING LIBRARIES
#include <afx.h>
#include <afxext.h> 
#include <afxsock.h>

// PROJECT LIBRARIES
#include "TCP.h"
#include "Movie.h"
#include "Movies.h"
#include "Client.h"

// OTHER LIBRARIES
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


int main()
{
	const int buff_size = 0;
	CSocket clientSocket;
	if (!(AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0)))
		cout << "XModule ERROR" << endl;
	if (!(AfxSocketInit()))
		cout << "XInitialize ERROR" << endl;
	if (!(clientSocket.Create()))
		cout << "XCreate 1 ERROR" << endl;
	if (!clientSocket.SetSockOpt(SO_SNDBUF, &buff_size, (int)sizeof(buff_size), SOL_SOCKET))
		cout << "FAILED TO SET SEND BUFFER" << endl;
	
	char IP_ADDR[15];
	cout << "Enter The SERVER Address To Connect> ";
	cin >> IP_ADDR;
	
	cout << "Connecting To Server ..." << endl << endl;
	if (!clientSocket.Connect(IP_ADDR, 3333))
	{
		cout << endl << "SERVER DOWN." << endl << endl;
		return 0;
	}
	cout << endl << "Connected." << endl << endl;

	
	



	return 0;
}