#include "RockPaperScissor.h"
#include <iostream>

void RockPaperScissor()
{
	// executes game Rock-Paper-Scissor
	std::cout << "\n\tROCK-PAPER-SCISSORS" << std::endl;
	// load game description and rules from rock-paper-scissors.txt


	// game setup
	std::string words[3] = { "ROCK", "PAPER", "SCISSORS" };
	unsigned compWordIndex = rand() % 4;
	unsigned userWordIndex = 0;
	std::string userWord;

	while (true)
	{
		compWordIndex = rand() % 4;

		std::cout << " \nThe computer has chosen a word, now it's your turn." << std::endl;
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



		userWord.clear();
	}

	while (true) // main game loop
	{

	}


}

void to_upper(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}


