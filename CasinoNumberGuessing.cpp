#include <iostream>
#include <fstream>
#include "CasinoNumberGuessing.h"
#include "Text.h"

enum class DifficultyLevel
{
	Easy = 1,
	Medium,
	Hard
};


void CasinoNumberGuessing()
{
	// executes game Casino-Number-Guessing 
	std::cout << "\n\tCASINO-NUMBER-GUESSING" << std::endl;

	// load game description and rules from rock-paper-scissors.txt
	PrintTextInFrame("CasinoGuessingNumber.txt", 45);

	// game set up
	int coins = 500;
	DifficultyLevel difficultyLevel = DifficultyLevel::Easy;   // available 1 2 3
	int number = 0;
	int uNumber = 0;
	std::string uInput;

	while (true) // main loop
	{
		int min = -50 + rand() % 100;
		int max = min + static_cast<int>(difficultyLevel) * 4;
		number = min + rand() % (max + 1);// min + rand()%(max+1)

		std::cout << " Your coins: " << coins << std::endl;
		std::cout << " The computer has chosen the number in a range [" << min << "; " << max << "]" << std::endl;
		std::cout << " Your number > ";
		std::cin >> uInput;

		if (uInput == "exit")return;

	}



}





