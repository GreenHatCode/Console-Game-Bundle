#include <iostream>
#include <fstream>
#include <string>

void PrintTextInFrame(const std::string& file_name, unsigned frame_width)
{
	std::ifstream inf(file_name);
	if (inf.is_open())
	{
		std::string line;
		std::string text;
		while (std::getline(inf, line))
		{
			text.append(line);
		}

		// todo: try to use only 1 counter i
		unsigned length = 0;
		for (size_t i = 0; i < text.size(); i++, length++)
		{
			if (length >= frame_width && text[i] == ' ')
			{
				std::cout << " " << std::endl;
				length = 0;
			}
			else std::cout << text[i];
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	else std::cout << "Can't open file \'" << file_name << "\'" << std::endl;
}


