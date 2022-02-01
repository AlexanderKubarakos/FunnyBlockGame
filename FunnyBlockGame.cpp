#include "FunnyBlockGame.h"
#include "funnyblockgame/client/Client.h"
#include <cstring>

// One big block list, just normal array that maps block id to that blocks info
// Blocks are defined in their own file, and then they call a function on load to cache them in the list

int main(int argc, char* argv[])
{
	if (argc < 1)
	{
		std::cout << "You must supply a command line argument.\n";
		system("pause");
		return 1;
	}

	if (strcmp(argv[0], "client") == 0 || true)
	{
		std::cout << "Starting Client...\n";
		client::Client client;
		client.initialization();
		client.run();
		return 0;
	}

	if (strcmp(argv[0], "server") == 0)
	{
		std::cout << "Starting Server...\n";
		return 0;
	}

	std::cout << "No correct command line argument found.\n";
	system("pause");
	return 2;
}
