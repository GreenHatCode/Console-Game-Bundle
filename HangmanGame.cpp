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
	std::string word;
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



	while (true) // game loop.
	{
		// setting the level difficulty.
		std::cout << " Choose the game difficulty: Easy(1), Mediun(2), Hard(3)" << std::endl;
		std::cout << " Your difficulty > ";
		std::cin >> uInput;
		
		if (uInput == "exit")return;
		else if (uInput.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << " This is not a number." << std::endl;
			continue;
		}

		// validating the level difficulty and selecting the word .
		difficulty = std::stoi(uInput);
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

		// game.
		std::string uWord(word.size(), '_');
		bool fg = false;
		for (int trials = 6; trials > 0; trials--)
		{
			// output current user word and draw the man.
			std::cout << " Word: " << uWord << std::endl;
			std::cout << " Trials left: " << trials << std::endl;

			// getting user input.
			std::cout << " Enter a letter > ";
			std::cin >> uInput;

			// input validation.
			if (uInput == "exit")return;
			else if (uInput.size() != 1)
			{
				std::cout << "You can enter only an exit command or a single char. Try again!" << std::endl;
				trials++;
			}
			else uInput = std::toupper(uInput[0]);

			//checking, if the word contains the uLetter.
			std::size_t found = word.find_first_of(uInput);
			while (found!=std::string::npos)
			{
				uWord[found] = uInput[0];
				found = word.find_first_of(uInput, found + 1);
				fg = true;
			}

			// checking if the word is guessed.
			// checking starts if this is the 4 or later trial.
			if (trials <= 3 && uWord.find_first_of("_") == std::string::npos)
			{
				break;
			}

			if (fg == true)std::cout << " Congratulations, you guessed the letter!\n" << std::endl;
			else std::cout << " There is no such letter in the word. Try again!\n" << std::endl;

			fg = false;
		}

		if (fg == true)std::cout << " Congratulations, you guessed the word!\n" << std::endl;
		else std::cout << " You didn't guess the word. Try again!" << " The word was " << word << std::endl;
	}



}
