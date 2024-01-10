#include <iostream>
#include <ctype.h>
#include <fstream>
#include<string>
#include <vector>
#include "includes/checkWord.cpp"

int readAndCaliber(std::ifstream& inFile);

int main() {
	int calibrationVal;
	std::ifstream inFile("inputTest.txt");
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

	while (!inFile.eof()) {
		firstNumber = 0;
		lastNumber = 0;
		std::getline(inFile, temp);
		line = getVector(temp);

		
		if(firstNumber==0){
			for(int i=0;i<line.size();i++){
			numberWord="";
			if (isdigit(line[i])) {
					firstNumber = int(line[i]) - 48;
					break;
			}
			else {
				j=i;
			while(line[j]!=NULL && j<(i+5)){
				numberWord+=line[j];
				if (checkIfWordNumber(numberWord) != -1) {
						std::cout << numberWord<<"\n";
						firstNumber = checkIfWordNumber(numberWord);
						break;
				}
					j++;	
					}
			}
			z=i;
			if(firstNumber!=0){
					break;
			}
			}
		}else{
			for(int i=line.size();i>z;--i){
			numberWord="";
			if (isdigit(line[i])) {	
					lastNumber = int(line[i]) - 48;
			}
			else {
				j=i;
			while(line[j]!=NULL && j<(i+5)){
				numberWord+=line[j];
				temp = reverseWord(numberWord);
				if (checkIfWordNumber(temp) != -1) {
					lastNumber = checkIfWordNumber(temp);
					break;
				}
				j++;	
			}

			}
				if(firstNumber!=0){
					break;
				}
			}
		}



		if (lastNumber == 0) {
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

