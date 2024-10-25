#include <iostream>
#include "Text.h"
#include "HangmanGame.h"

void HangmanGame()
{
	// executes game Casino-Number-Guessing 
	std::cout << "\n\tHANGMAN-GAME" << std::endl;

	// load game description and rules from HangmanGameAbout.txt
	PrintTextInFrame("HangmanGameAbout.txt", 45);

	// game set up
	unsigned difficulty = 1; // easy(1) mediun(2) hard(3).
	std::vector<std::string> words;
	std::string uInput;

	try
	{
		words = LoadWords("words.txt");
	}
	catch (const std::string& er)
	{
		std::cout << er << std::endl;
		return;
	}



	while (true) // game loop
	{
		// setting the level difficulty.
		std::cout << " \n Choose the game difficulty: Easy(1), Mediun(2), Hard(3)" << std::endl;
		std::cout << " Your difficulty > ";
		std::cin >> uInput;
		
		if (uInput == "exit")return;
		else if (uInput.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << " This is not a number." << std::endl;
			continue;
		}

		// validating the level difficulty and selecting the word 
		difficulty = std::stoi(uInput);
		std::string word;
		if (difficulty == 1)
		{
			unsigned word_index = 0 + rand() % (29 - 0 + 1);
			word = words.at(word_index);
		}
		else if (difficulty == 2)
		{
			unsigned word_index = 30 + rand() % (59 - 30 + 1);
			word = words.at(word_index);
		}
		else if (difficulty == 3)
		{
			unsigned word_index = 60 + rand() % (89 - 60 + 1);
			word = words.at(word_index);
		}
		else
		{
			std::cout << " There is no such level difficulty." << std::endl;
			continue;
		}

		std::cout << "selected word is  " << word << std::endl;



	}



}
