#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
# include <iomanip>
#include <deque>

static int get_first_diff(std::string line);
static int get_second_diff(std::string line);
static bool unique_char_only_4(std::deque<char> letters);
static bool unique_char_only_14(std::deque<char> letters);
int main(void)
{
	std::string line;
	int count;
	//std::string test = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg";
	std::ifstream myfile ("input.txt");
  	if (myfile.is_open())
  	{
		getline (myfile,line);
		myfile.close();
		count = get_first_diff(line);
		std::cout << "First: " << count << std::endl;
		count = get_second_diff(line);
		std::cout << "Second: " << count << std::endl;
	}
	else std::cout << "Unable to open file"; 
}

static int get_first_diff(std::string line)
{
	std::deque<char> letters;
	for (int i = 0; i < 3;i++)
		letters.push_back(line.at(i));
	for (long unsigned int i = 3; i < line.length(); i++)
	{
		letters.push_back(line.at(i));
		if(unique_char_only_4(letters))
			return(i + 1);
		letters.pop_front();
	}
	return 1;
}

static bool unique_char_only_4(std::deque<char> letters)
{
	sort(letters.begin(), letters.end());
	for( int i = 0; i < 3; i++)
	{
		if(letters.at(i) == letters.at(i + 1))
			return (false);
	}
	return (true);
}

static int get_second_diff(std::string line)
{
	std::deque<char> letters;
	for (int i = 0; i < 13;i++)
		letters.push_back(line.at(i));
	for (long unsigned int i = 13; i < line.length(); i++)
	{
		letters.push_back(line.at(i));
		if(unique_char_only_14(letters))
			return(i + 1);
		letters.pop_front();
	}
	return 1;
}

static bool unique_char_only_14(std::deque<char> letters)
{
	sort(letters.begin(), letters.end());
	for( int i = 0; i < 13; i++)
	{
		if(letters.at(i) == letters.at(i + 1))
			return (false);
	}
	return (true);
}
