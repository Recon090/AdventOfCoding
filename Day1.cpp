#include <iostream>
#include <ctype.h>
#include <fstream>
#include<string>
#include <vector>
#include "checkWord.cpp"
//The right calibration values for string "eighthree" is 83 and for "sevenine" is 79.

int readAndCaliber(std::ifstream& inFile);

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
	int firstNumber;
	int lastNumber;
	int combined;
	int sum=0;
	int z = 0, j=0;
	std::string numberWord,temp;
	std::vector<char> line;
	std::vector<int> numbers;

	while (std::getline(inFile, temp)) {
		firstNumber = -1;
		lastNumber = -1;
		line = getVector(temp);

		
			for(int i=0;i<line.size();i++){
			numberWord="";
			if (isdigit(line[i])) {
					firstNumber = int(line[i]) - 48;
					break;
			}
			else {
				j=i;
			while(j<line.size() && j<(i+5)){
				numberWord+=line[j];
				if (checkIfWordNumber(numberWord) != -1) {
						firstNumber = checkIfWordNumber(numberWord);
						break;
				}
					j++;	
					}
			}
			z=i;
			if(firstNumber !=-1){
				break;
			}

			}
			for(int i=line.size()-1;i>=z;--i){
			numberWord="";
			if (isdigit(line[i])) {	
					lastNumber = int(line[i]) - 48;
					break;
			}
			else {
				j=i;
			while(j>z && j>(i-5)){
				numberWord+=line[j];
				temp = reverseWord(numberWord);
				//std::cout<<temp<<std::endl;
				if (checkIfWordNumber(temp) != -1) {
					lastNumber = checkIfWordNumber(temp);
					break;
				}
				j--;	
			}

			}
				if(lastNumber!=-1){
					break;
				}
			}



		if (lastNumber == -1) {
			lastNumber = firstNumber;
		}
			//std::cout << firstNumber << "\n";
			//std::cout << lastNumber << "\n";
		combined = (firstNumber * 10) + lastNumber;
			std::cout << combined << "\n";
		numbers.push_back(combined);
		}
		 
	  for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }

	return sum;
}

