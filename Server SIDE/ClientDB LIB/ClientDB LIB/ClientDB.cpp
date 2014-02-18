#include "ClientDB.h"

ClientDB::ClientDB()
{
}

ClientDB::~ClientDB()
{
}

void ClientDB::writeClient(Client& client)
{
	ofstream FILE;
	FILE.open("Client_DataBase.dtb", ios::app | ios::binary);
	
	REQUIRE0(FILE.is_open());
	FILE.write((char*)&client, sizeof(client));
	FILE.close();
}

int ClientDB::searchClient(char* username)
{
	int j = 0;
	Client client;
	ifstream FILE;
	FILE.open("Client_DataBase.dtb", ios::binary);
	
	REQUIRE0(FILE.is_open());
	while (!FILE.eof())
	{
		FILE.seekg(j*sizeof(Client), ios::beg);
		FILE.read((char*)(&client), sizeof(client));
		if (!strcmp(username, client.getUser()))
		{
			FILE.close();
			return j;
		}
		j++;
	}
	FILE.close();
	return -1;
}

int ClientDB::checkClient(Client& client)
{
	int j = 0;
	Client clientdb;
	ifstream FILE;
	FILE.open("Client_DataBase.dtb", ios::binary);
	
	REQUIRE0(FILE.is_open());
	while (!FILE.eof())
	{
		FILE.seekg(j*sizeof(Client), ios::beg);
		FILE.read((char*)(&clientdb), sizeof(clientdb));
		if (!strcmp(client.getUser(), clientdb.getUser()))
		{
			if (!strcmp(client.getPass(), clientdb.getPass()))
			{
				FILE.close();
				return j;
			}
		}
		j++;
	}
	FILE.close();
	return -1;
}

Client ClientDB::readClient(int j)
{
	REQUIRE0(j >= 0);
	Client client;
	ifstream FILE;
	FILE.open("Client_DataBase.dtb", ios::binary);
	
	REQUIRE0(FILE.is_open());
	FILE.seekg(j*sizeof(Client), ios::beg);
	FILE.read((char*)(&client), sizeof(client));
	FILE.close();
	return client;
}

void ClientDB::updateClient(Client& client, int j)
{
	REQUIRE0(j >= 0);
	ofstream FILE;
	FILE.open("Client_DataBase.dtb", ios::out | ios::in | ios::binary);
	
	REQUIRE0(FILE.is_open());
	FILE.seekp(j*sizeof(Client), ios::beg);
	FILE.write((char*)(&client), sizeof(client));
	FILE.close();
}

int ClientDB::numClient()
{
	int j = 0;
	ifstream FILE;
	FILE.open("Client_DataBase.dtb", ios::binary);
	
	REQUIRE0(FILE.is_open());
	while (!FILE.eof())
	{
		FILE.seekg(j*sizeof(Client), ios::beg);
		j++;
	}
	FILE.close();
	return (j-1);
}
