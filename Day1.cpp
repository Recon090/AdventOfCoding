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
		int i = 0;
		int letterCounter=0;
		char line[100];
		std::string numberWord = "";
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
			else {
				numberWord += line[i];
				letterCounter++;
				if (checkIfWordNumber(numberWord) != -1) {
					int j = 0;
					while (line[j] != NULL && j < 100) {
						std::cout << line[j];
						j++;
					}
					std::cout << "\n";
				}
				switchAndAssignWord(numberWord, firstNumber, lastNumber, letterCounter);

			}

			i++;
		}


		if (lastNumber == NULL) {
			lastNumber = firstNumber;
		}
		combined = (firstNumber * 10) + lastNumber;
		std::cout << combined << "\n";
		numbers.push_back(combined);
		}
		 
	  for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

		std::cout<<"\n"<<sum;
	return 0;
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
void switchAndAssignWord(std::string & numberWord, int & firstNumber, int & lastNumber,	int & letterCounter) {
	switch (letterCounter) {
	case 3:
	case 4:
		if (checkIfWordNumber(numberWord) != -1) {
			std::cout << numberWord << "\n";
			if (firstNumber == NULL) {
				firstNumber = checkIfWordNumber(numberWord);
			}
			else {
				lastNumber = checkIfWordNumber(numberWord);
			}
			std::cout << checkIfWordNumber(numberWord) << "\n";
			letterCounter = 0;
			numberWord = "";
		}
		break;
	case 5:
		if (checkIfWordNumber(numberWord) != -1) {
			std::cout << numberWord << "\n";
			if (firstNumber == NULL) {
				firstNumber = checkIfWordNumber(numberWord);
				
			}
			else {
				lastNumber = checkIfWordNumber(numberWord);
			}
			std::cout << checkIfWordNumber(numberWord) << "\n";
			numberWord = "";
			letterCounter = 0;
		}
		else {
			numberWord = "";
			letterCounter = 0;
		}
	}
}
