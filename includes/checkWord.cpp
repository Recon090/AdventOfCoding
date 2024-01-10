#include <iostream>
#include <fstream>
#include <vector>

std::string reverseWord(const std::string &str){
  std::string reversed;
  for (int i = str.length() - 1; i >= 0; --i) {
      reversed += str[i];
  }
  std::cout<<"This runs"<<std::endl;
  return reversed;
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
	else {
		return -1;
	}

}


std::vector<char> getVector(std::string line){
  std::vector<char> charVector;
        for (char ch : line) {
            if (ch == '\n') {
                break;
            }
            charVector.push_back(ch);
        }
    return charVector;
}