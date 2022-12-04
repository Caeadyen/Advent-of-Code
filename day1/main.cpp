#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main(void)
{
	std::vector<int> v;
	int num = 0;
	std::string line;
	std::ifstream myfile ("input.txt");
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
			if (!line.empty())
				num += std::stoi(line);
			else
			{
				v.push_back(num);
				num = 0;
			}
    	}
    	myfile.close();
		std::cout << *max_element(v.begin(), v.end()) << '\n';
		std::sort(v.rbegin(), v.rend());
		std::cout << "top 3: " << v[0] + v[1] + v[2] << std::endl;
  	}
  	else std::cout << "Unable to open file"; 
}