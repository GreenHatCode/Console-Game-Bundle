#include <iostream>
#include "RockPaperScissor.h"
#include "Text.h"

int main() 
{

	std::cout << "\tCONSOLE GAME BUNDLE" << std::endl;
	//PrintTextInFrame("README.md", 45);

	while (true)
	{
		std::cout << " In which game do you want to play: \n   - Rock-Paper-Scissors (r)\n   - Casino Guessing Number (c)\n   - Hangman Game (h)" << std::endl;
		std::cout << " To quit game write \'exit\' in console" << std::endl;
		std::cout << " enter one symbol > ";
		std::string answer;
		std::cin >> answer;

		if (answer == "exit")
		{
			std::cout << "\n\tGood Bye!\n" << std::endl;
			break;
		}
		else if (answer == "r") RockPaperScissor(); // runs  Rock-Paper-Scissors game.
		else if (answer == "c")std::cout << " Chosen Casino Guessing Number" << std::endl;
		else if (answer == "h")std::cout << " Chosen Hangman Game" << std::endl;
		else 
		{
			std::cout << " There is no such command, watch the \"GameCommand.md\" and try again." << std::endl;
		}


		std::cout << std::endl;
	}

	


	return 0;
}