// SERVER SIDE

#include "stdafx.h"
#include "Server Side 1.h"

// MFC NETWORKING LIBRARIES
#include <afx.h> 
#include <afxext.h> 
#include <afxsock.h>

// PROJECT LIBRARIES
#include "TCP.h"
#include "Movie.h"
#include "Movies.h"
#include "Client.h"
#include "MovieDB.h"
#include "ClientDB.h"

// OTHER LIBRARIES
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CSocket serverSocket;
CSocket clientSocket;
void Maintenance();
int main()
{
	system("title SERVER SIDE");
	system("cls");
	cout << "# MAIN SERVER #" << endl;
	cout << "---------------" << endl << endl;
	cout << "<M> Server Maintenance" << endl << endl;
	cout << "<A> Server Available" << endl << endl;
	cout << "----------------------";
	char x;
	cin >> x;

	switch (x)
	{
	case'm': Maintenance();
		break;
	
	case'a': 
		break;

	default: main();
		break;
	}

	system("cls");
	const int buff_size = 1048576;
	const int buff_size0 = 0;
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
		cout << "XModule ERROR" << endl;
	if (!AfxSocketInit())
		cout << "XInitialize ERROR" << endl;
	if (!serverSocket.Create(3333))
		cout << "XCreate ERROR" << endl;
	if (!serverSocket.SetSockOpt(SO_RCVBUF, &buff_size, (int)sizeof(buff_size), SOL_SOCKET))
		cout << "FAILED TO SET RECEIVE BUFFER" << endl;
	if (!serverSocket.SetSockOpt(SO_SNDBUF, &buff_size0, (int)sizeof(buff_size0), SOL_SOCKET))
		cout << "FAILED TO SET SEND BUFFER" << endl;
	if (!serverSocket.Listen())
		cout << "XListen ERROR" << endl;
	cout << "Server Is Waiting ..." << endl << endl;
	
	char msg[128];
	char S = '0';
	while (serverSocket.Accept(clientSocket))
	{
		cout << "Client Connected." << endl << endl;

		while (S != 'L')
		{
			clientSocket.Receive(msg, 128);
			S = msg[0];
			switch (S)
			{
			case'L':
				break;

            
			}
		}

		clientSocket.Close();
		break;
	}
	serverSocket.Close();
	return 0;
}
void Maintenance()
{

}