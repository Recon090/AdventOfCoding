#include <iostream>
#include <ctype.h>
#include <fstream>
#include<string>
#include <vector>

int readAndCaliber(std::ifstream& inFile);
int checkIfWordNumber(std::string word);
void switchAndAssignWord(std::string &numberWord,int& firstNumber,int& lastNumber,int& letterCounter);

int main() {
	int calibrationVal;
	std::ifstream inFile("input.txt");
	if (!inFile.is_open()) {
		std::cout << "File could not open, exiting code";
		exit(0);
	}
	calibrationVal = readAndCaliber(inFile);
	std::cout << calibrationVal;

	return 0;
}

int readAndCaliber(std::ifstream& inFile) {
	int firstNumber, lastNumber, combined, sum=0;
	std::vector<int> numbers;

	while (!inFile.eof()) {
		firstNumber = NULL;
		lastNumber = NULL;
		int i = 0, j=0;
		int letterCounter=0;
		char line[100];
		std::string numberWord = "";
		inFile.getline(line,100);

		while (line[i]!=NULL && i<100) {
			numberWord="";
			if (isdigit(line[i])) {
				if (firstNumber == NULL) {
					firstNumber = int(line[i]) - 48;
				}
				else {
					lastNumber = int(line[i]) -48;
				}
			}





			else {
				j=i;
			while(line[j]!=NULL && j<(i+5)){
				numberWord+=line[j];
				if (checkIfWordNumber(numberWord) != -1) {
					std::cout << numberWord<<"\n";
					if (firstNumber == NULL) {
						firstNumber = checkIfWordNumber(numberWord);
					}
					else {
						lastNumber = checkIfWordNumber(numberWord);
					}
					i=j;
					break;
				}
				j++;	
			}

			}

			i++;
		}


		if (lastNumber == NULL) {
			lastNumber = firstNumber;
		}
				std::cout << firstNumber << "\n";
						std::cout << lastNumber << "\n";
		combined = (firstNumber * 10) + lastNumber;
		std::cout << combined << "\n";
		numbers.push_back(combined);
		}
		 
	  for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

	return sum;
}
int checkIfWordNumber(std::string word) {
	if (word == "one") {
		return 1;
	}
	else if (word == "two") {
		return 2;
	}
	else if (word == "three") {
		return 3;
	}
	else if (word == "four") {
		return 4;
	}
	else if (word == "five") {
		return 5;
	}
	else if (word == "six") {
		return 6;
	}
	else if (word == "seven") {
		return 7;
	}
	else if (word == "eight") {
		return 8;
	}
	else if (word == "nine") {
		return 9;
	}
	else if (word == "zero") {
		return 0;
	}
	else {
		return -1;
	}

}
