#include <iostream>
#include <fstream>

#include "CMedian.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
	    std::cout << "Usage: " << argv[0] <<
	    		" file path to data(numbers)" << std::endl;
	    return 1;
	}

	CMedian<double> median;

	std::ifstream myfile (argv[1], std::ios::in);

	if(!myfile.good())
	{
		std::cout << "Cannot open file: " << argv[1] << std::endl;
		return 1;
	}

	double number = 0.0;

	while(!myfile.eof())
	{
		myfile >> number;
		if(!myfile.eof()) median.Add(number);
	}

	myfile.close();

	std::cout << median.GetMedian();

	return 0;
}


