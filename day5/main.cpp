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

struct t_moves{
    int num;
    int from;
    int to;
};

struct t_data
{
	std::vector<std::stack<char>> stacks;
	std::vector<t_moves> moves;
	int num_stacks;
};

static t_data load_input(void);
static void make_moves_1(t_data data);
static void make_moves_2(t_data data);

int main(void)
{
	t_data input = load_input();
	make_moves_1(input);
	std::cout << std::endl;
	make_moves_2(input);
	std::cout << std::endl;
}

static t_data load_input(void)
{
	t_data input;
	int num_stacks = 0;
	std::string line;
	std::vector<std::string> lines;
	std::vector<std::vector<char>> create_lists;

	std::ifstream myfile ("input.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
		{
			if(num_stacks == 0){
            num_stacks = (int)ceil(line.size() / 4.0f);
			input.num_stacks = num_stacks;
            create_lists.resize(num_stacks);
        	}
			if (line.empty())
				break;
            for(int i=0; i<num_stacks; ++i){
                char crate = line[1+(i*4)];
                if(crate != ' '){
                    create_lists[i].push_back(crate);
                }
            }
		}
		while ( getline (myfile,line) )
		{
			t_moves move;
			sscanf(line.c_str(), "move %d from %d to %d\n", &move.num, &move.from, &move.to);
			input.moves.push_back(move);
		}	
    	myfile.close();
        for(int i=0; i<num_stacks; ++i){
				create_lists[i].pop_back();
        }
		input.stacks.resize(num_stacks);
    	for(int i=0; i<num_stacks; ++i)
		{
        	for(int j=(int)create_lists[i].size()-1; j>=0; --j)
            	input.stacks[i].push(create_lists[i][j]);
        }
		  	}
  	else std::cout << "Unable to open file"; 
	return input;
}

static void make_moves_1(t_data data)
{
	for(t_moves move : data.moves)
	{
		for (int i = 0; i < move.num; i++)
		{
			data.stacks[move.to - 1].push(data.stacks[move.from - 1].top());
			data.stacks[move.from - 1].pop();
		}
	}
	for(int i=0; i<data.num_stacks; ++i)
		std::cout << data.stacks[i].top();
}

static void make_moves_2(t_data data)
{
	std::vector<char> tmp;
	for(t_moves move : data.moves)
	{
		for (int i = 0; i < move.num; i++)
		{
			tmp.push_back(data.stacks[move.from - 1].top());
			data.stacks[move.from - 1].pop();
		}
		while (!tmp.empty())
		{
			data.stacks[move.to-1].push(tmp.back());
			tmp.pop_back();
		}
	}
	for(int i=0; i<data.num_stacks; ++i)
		std::cout << data.stacks[i].top();
}
