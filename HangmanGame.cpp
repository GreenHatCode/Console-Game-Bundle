#include <iostream>
#include "Text.h"

enum class LevelDifficulty
{
	Easy = 1,
	Normal,
	Hard
};

void HangmanGame()
{
	// executes game Casino-Number-Guessing 
	std::cout << "\n\tHANGMAN-GAME" << std::endl;

	// load game description and rules from rock-paper-scissors.txt
	PrintTextInFrame("HangmanGameAbout.txt", 45);

	// game set up
	LevelDifficulty difficulty = LevelDifficulty::Easy;
	std::string uInput;

	while (true) // game loop
	{
		std::cout << " \nChoose the game difficulty: Easy(1), Mediun(2), Hard(3)" << std::endl;
		std::cout << " Your difficulty > ";
		std::cin >> uInput;

		if (uInput == "exit")return;
		
		if (uInput == "exit")return;
		else if (uInput.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << " This is not a number." << std::endl;
			continue;
		}

		int num = std::stoi(uInput);
		if (num != 1 && num != 2 && num != 3)
		{
			std::cout << " There is no such level difficulty." << std::endl;
			continue;
		}
		difficulty = (LevelDifficulty)num;

		std::cout << "chosen > " << num << std::endl;





	}



}