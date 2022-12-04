#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

static int get_common(std::string first, std::string second);
static int get_common_2(std::string first,std::string second, std::string third);
int main(void)
{
	int score = 0;
	std::string line;
	std::string first;
	std::string second;
	std::vector<std::string> lines;
	std::ifstream myfile ("input.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
			lines.push_back(line);
    	myfile.close();
		for (std::string word : lines)
			score += get_common(word.substr(0, word.length()/2), word.substr(word.length()/2));
		std::cout << "score part 1: " << score << std::endl;
		score = 0;
		for (std::string::size_type i = 0; i < lines.size(); i+=3)
		{
			score += get_common_2(lines[i],lines[i +1], lines[i+ 2]);
		}
		std::cout << "score part 2: " << score << std::endl;
  	}
  	else std::cout << "Unable to open file"; 
}

static int get_common(std::string first, std::string second)
{

	for (char c : first)
	{
		if(second.find(c) != std::string::npos)
		{
			if (islower(c))
			{
				//std::cout << "char: " << c << " value: " << (c-96) << std::endl;
				return (c - 96);
			}
			else
			{
				//std::cout << "char: " << c << " value: " << (c-38) << std::endl;
				return (c - 38);
			}
		}
			
	}
	return 0;
}

static int get_common_2(std::string first,std::string second, std::string third)
{
	for (char c : first)
	{
		if(second.find(c) != std::string::npos)
		{
			if(third.find(c) != std::string::npos)
			{
			if (islower(c))
			{
				//std::cout << "char: " << c << " value: " << (c-96) << std::endl;
				return (c - 96);
			}
			else
			{
				//std::cout << "char: " << c << " value: " << (c-38) << std::endl;
				return (c - 38);
			}
			}
		}
	}
	return (0);
}