#include "YAPOG/Game/Chat/OPTChat.hpp"
#include "YAPOG/Game/Chat/Chat.hpp"
#include "YAPOG/Game/Chat/ChatDisplayer.hpp"

int main()
{
	yap::ChatDisplayer displayer;
	std::string line;
	while (true)
	{
		std::getline(std::cin, line);
		if (line.compare("exit") == 0)
			break;
		yap::Chat mychat (line);
		displayer.display(mychat.getbuf(), mychat.parse());
	}

	return EXIT_SUCCESS;
}