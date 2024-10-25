#pragma once
#include <string>
#include <vector>

void PrintTextInFrame(const std::string& file_name, unsigned frame_width);
std::vector<std::string> LoadWords(const std::string& file_name); // loads words from a .txt file. If it cannot open the file, throws an exception.