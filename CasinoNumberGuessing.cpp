#include <iostream>
#include <fstream>
#include "CasinoNumberGuessing.h"
#include "Text.h"

void CasinoNumberGuessing()
{
	// executes game Casino-Number-Guessing 
	std::cout << "\n\tCASINO-NUMBER-GUESSING" << std::endl;

	// load game description and rules from rock-paper-scissors.txt
	PrintTextInFrame("CasinoGuessingNumber.txt", 45);

	// game set up
	int coins = 500;
	int number = 0;
	int uNumber = 0;
	std::string uInput;

	while (true) // main loop
	{
		int difficulty = 0;
		std::cout << " Choose the game difficulty: Easy(1), Mediun(2), Hard(3)" << std::endl;
		std::cout << " Your difficulty > ";
		std::cin >> uInput;

		if (uInput == "exit")return;
		else if (uInput.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << " This is not a number." << std::endl;
			continue;
		}

		difficulty = std::stoi(uInput);
		if (difficulty != 1 && difficulty != 2 && difficulty != 3)
		{
			std::cout << " There is no such level difficulty." << std::endl;
			continue;
		}

		int trials = 3;
		int min = -50 + rand() % 100;
		int max = min + static_cast<int>(difficulty) * 4;
		number = min + rand() % (max + 1);// min + rand()%(max+1)

		for (; trials > 0 && coins; trials--)
		{
			std::cout << " Your coins: " << coins << std::endl;
			std::cout << " The computer has chosen the number in a range [" << min << "; " << max << "]" << std::endl;
			std::cout << " Your number > ";
			std::cin >> uInput;

			if (uInput == "exit")return;
			else if (uInput.find_first_not_of("0123456789") != std::string::npos)
			{
				std::cout << " This is not a number." << std::endl;
				trials++;
				continue;
			}

			uNumber = std::stoi(uInput);
			if (uNumber == number)
			{
				coins += 100;
				std::cout << " You have guessed the number. You won 100 coins." << std::endl;;
			}
			else if (uNumber < number)
			{
				coins -= 100;
				std::cout << " You didn't guess the number, your number is lower. You lost 100 coins." << std::endl;
			}
			else
			{
				coins -= 100;
				std::cout << " You didn't guess the number, your number is higher. You lost 100 coins." << std::endl;
			}

			std::cout << std::endl;
			uInput.clear();
		}


		if (coins == 1000)std::cout << " You win the casino." << std::endl;
		else if (coins == 0 || trials == 0)std::cout << " You lost the casino." << std::endl;



	}



}





