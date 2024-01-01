#include <iostream>
#include <ctype.h>
#include <fstream>
#include<string>
#include <vector>

int readAndCaliber(std::ifstream& inFile);

int main() {
	int calibrationVal;
	std::ifstream inFile("input.txt");
	if (!inFile.is_open()) {
		std::cout << "File could not open, exiting code";
		exit(0);
	}
	calibrationVal = readAndCaliber(inFile);
	//std::cout << calibrationVal;

	return 0;
}

int readAndCaliber(std::ifstream& inFile) {
	int firstNumber, lastNumber, combined, sum=0;
	std::vector<int> numbers;

	while (!inFile.eof()) {
		firstNumber = NULL;
		lastNumber = NULL;
		int i = 0;
		char line[100];
		inFile.getline(line,100);

		while (line[i]!=NULL && i<100) {

			if (isdigit(line[i])) {
				if (firstNumber == NULL) {
					firstNumber = int(line[i]) - 48;
				}
				else {
					lastNumber = int(line[i]) -48;
				}
			}
			i++;
		}
		if (lastNumber == NULL) {
			lastNumber = firstNumber;
		}

		combined = (firstNumber * 10) + lastNumber;
		numbers.push_back(combined);
		}
		 
	  for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

		std::cout<<"\n"<<sum;
	return 0;
}
