//Boost
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inFile;
	string content;
	string buffer;

	inFile.open("assets/test-1.csst");
	if(!inFile)
	{
		cerr << "Unable to open file";
		exit(1);
	}

	while(inFile >> buffer)
	{
		content += buffer;
	}

	inFile.close();

	vector<string> splitVector;
	boost::split(splitVector, content, boost::is_any_of("{}"));
	
	vector<string>::iterator it = splitVector.begin();
	while(it != splitVector.end())
	{
		cout << "Token: " << boost::trim_copy(*it) << endl;
		++it;
	}

	return 0;
}