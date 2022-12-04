#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


static int find_overlapping(std::string first, std::string second);
static int find_overlapping_2(std::string first, std::string second);

int main(void)
{
	int score = 0;
	std::string line;
	// std::string first;
	// std::string second;
	std::vector<std::string> lines;
	size_t pos = 0;

	std::ifstream myfile ("input.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
			lines.push_back(line);
    	myfile.close();
		for (std::string word : lines)
		{
			pos = word.find(',');
			score += find_overlapping(word.substr(0, pos), word.substr(pos + 1));
		}
		std::cout << "First riddle: " << score << std::endl;
		score = 0;
		for (std::string word : lines)
		{
			pos = word.find(',');
			score += find_overlapping_2(word.substr(0, pos), word.substr(pos + 1));
		}
		std::cout << "Second riddle: " << score << std::endl;
  	}
  	else std::cout << "Unable to open file"; 
}

static int find_overlapping(std::string first, std::string second)
{
	int first_start;
	int first_end;
	int second_start;
	int second_end;
	size_t pos;

	pos = first.find('-');
	first_start = stoi(first.substr(0, pos));
	first_end = stoi(first.substr(pos + 1));
	pos = second.find('-');
	second_start = stoi(second.substr(0, pos));
	second_end = stoi(second.substr(pos + 1));
	if (first_start <= second_start && first_end >= second_end)
		return (1);
	else if (first_start >= second_start && first_end <= second_end)
		return (1);
	return 0;
}

static int find_overlapping_2(std::string first, std::string second)
{
	int first_start;
	int first_end;
	int second_start;
	int second_end;
	size_t pos;

	pos = first.find('-');
	first_start = stoi(first.substr(0, pos));
	first_end = stoi(first.substr(pos + 1));
	pos = second.find('-');
	second_start = stoi(second.substr(0, pos));
	second_end = stoi(second.substr(pos + 1));
	if (first_start >= second_start && first_start <= second_end)
		return (1);
	else if (first_end >= second_start && first_end <= second_end)
		return (1);
	else if (first_start <= second_start && first_end >= second_start)
		return (1);
	else if (first_start <= second_end && first_end >= second_end)
		return (1);
	return 0;
}
