#pragma once
#include <iostream>
#include <fstream>
#include "Client.h"

class ClientDB
{
 public:
	 ClientDB();
	 ~ClientDB();
	void writeClient(Client& client);
	int searchClient(char* username);
	int checkClient(Client& client);
	Client readClient(int j);
	void updateClient(Client& client, int j);
	int numClient();
};

