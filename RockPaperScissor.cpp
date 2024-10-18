#include "RockPaperScissor.h"
#include "Text.h"
#include <iostream>
#include <fstream>

void RockPaperScissor()
{
	// executes game Rock-Paper-Scissor
	std::cout << "\n\tROCK-PAPER-SCISSORS" << std::endl;

	// load game description and rules from rock-paper-scissors.txt

	// game setup
	std::string words[3] = { "ROCK", "PAPER", "SCISSOR" };
	unsigned compWordIndex = rand() % 4;
	unsigned userWordIndex = 0;
	std::string userWord;

	while (true) // main loop
	{
		compWordIndex = rand() % 3;

		std::cout << " The computer has chosen a word, now it's your turn." << std::endl;
		std::cout << " Your word> ";
		std::cin >> userWord;
		if (userWord == "exit")return;

		to_upper(userWord);

		// user input validation
		if (userWord == words[0])userWordIndex = 0;
		else if (userWord == words[1])userWordIndex = 1;
		else if (userWord == words[2])userWordIndex = 2;
		else
		{
			// error input from user
			std::cout << " Wow, you made a mistake, your word is incorrect. Let's try again!" << std::endl;
			std::cout << " There is no such command, watch the \"GameCommand.md\" and try again." << std::endl;
			continue;
		}

		// choosing the winner
		if (userWordIndex == compWordIndex)std::cout << " DRAW" << std::endl;
		else if (compWordIndex == 0 && userWordIndex == 1)std::cout << " Rock vs Paper -> Paper wins" << std::endl;
		else if (compWordIndex == 0 && userWordIndex == 2)std::cout << " Rock vs Scissor -> Rock wins" << std::endl;
		else if (compWordIndex == 1 && userWordIndex == 0)std::cout << " Paper vs Rock -> Paper wins" << std::endl;
		else if (compWordIndex == 1 && userWordIndex == 2)std::cout << " Paper vs Scissor -> Scissor wins" << std::endl;
		else if (compWordIndex == 2 && userWordIndex == 0)std::cout << " Scissor vs Rock -> Rock wins" << std::endl;
		else if (compWordIndex == 2 && userWordIndex == 1)std::cout << " Scissor vs Paper -> Scissor wins" << std::endl;

		std::cout << std::endl;
		userWord.clear();
	}

}

void to_upper(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}


