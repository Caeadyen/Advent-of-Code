#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

static int getscore1(char op, char me);
static int getscore2(char op, char me);
int main(void)
{
	int score1 = 0;
	int score2 = 0;
	std::string line;
	std::ifstream myfile ("input.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
			score1 += getscore1(line[0], line[2]);
			score2 += getscore2(line[0], line[2]);
    	}
    	myfile.close();
		std::cout << "score: " << score1 << std::endl;
		std::cout << "score: " << score2 << std::endl;
  	}
  	else std::cout << "Unable to open file"; 
}

static int getscore1(char op, char me)
{
	int result;
	if (op == 'A')
	{
		if(me == 'X')
			result = 4;
		else if(me == 'Y')
			result = 8;
		else if(me == 'Z')
			result = 3;
	}
	else if (op == 'B')
	{
		if(me == 'X')
			result = 1;
		else if(me == 'Y')
			result = 5;
		else if(me == 'Z')
			result = 9;
	}
	else if (op == 'C')
	{
		if(me == 'X')
			result = 7;
		else if(me == 'Y')
			result = 2;
		else if(me == 'Z')
			result = 6;
	}
	return result;
}

static int getscore2(char op, char me)
{
	int result;
	if (op == 'A')
	{
		if(me == 'X')
			result = 3;
		else if(me == 'Y')
			result = 4;
		else if(me == 'Z')
			result = 8;
	}
	else if (op == 'B')
	{
		if(me == 'X')
			result = 1;
		else if(me == 'Y')
			result = 5;
		else if(me == 'Z')
			result = 9;
	}
	else if (op == 'C')
	{
		if(me == 'X')
			result = 2;
		else if(me == 'Y')
			result = 6;
		else if(me == 'Z')
			result = 7;
	}
	return result;
}