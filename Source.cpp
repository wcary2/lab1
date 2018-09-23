#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileName;
	cout << "Enter File Name: ";
	cin >> fileName;
	ifstream file(fileName);
	if (file.is_open()) {
		int count = 0;
		int firstNumber, secondNumber, thirdNumber, lastNumber;
		while (!file.eof()) {
			if (file >> thirdNumber) {
				count++;
				if (count == 1) {
					firstNumber = thirdNumber;
					secondNumber = thirdNumber;
				}
			}
			else {
				file.clear();
				file.ignore();
			}
			if (file >> lastNumber) {
				count++;
				if (count == 2) {
					secondNumber = lastNumber;
				}
			}
			else {
				file.clear();
				file.ignore();
			}
		}
		if ((count % 2) == 1) {
			int temp = lastNumber;
			lastNumber = thirdNumber;
			thirdNumber = temp;
		}
		cout << "Count: " << count << endl;
		cout << "First Number: " << firstNumber << endl << "Second Number: " << secondNumber << endl;
		cout << "Second to Last Number: " << thirdNumber << endl << "Last Number: " << lastNumber << endl;
	}
	file.close();
	cin >> fileName;
	return 0;
}

/*void test(ifstream file) {
	if (file.is_open()) {
		int count = 0;
		int firstNumber, secondNumber, thirdNumber, lastNumber;
		while (!file.fail()) {
			if (file >> thirdNumber) {
				count++;
				if (count = 1) {
					firstNumber = thirdNumber;
					secondNumber = firstNumber;
				}
			}
			else {
				file.clear();
				file.ignore();
			}
			if (file >> lastNumber) {
				count++;
				if (count == 2) {
					secondNumber = lastNumber;
				}
			}
			else {
				file.clear();
				file.ignore();
			}
		}
	}
}*/