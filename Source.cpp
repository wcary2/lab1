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
		double firstNumber, secondNumber, thirdNumber, lastNumber;
		double temp;
		while (file >> temp) {
			if (!file.fail()) {
				if (count == 0) { //if there is only one number in the file, all stored values will be equivalent to that number
					firstNumber = temp;
					secondNumber = temp;
					thirdNumber = temp;
					lastNumber = temp;
				}
				if (count == 1) {
					secondNumber = temp;
					thirdNumber = temp;
					lastNumber = temp;
				}
				thirdNumber = lastNumber;
				lastNumber = temp;
				count++;
			}
		}
		cout << "Count: " << count << endl;
		cout << "First Number: " << firstNumber << endl << "Second Number: " << secondNumber << endl;
		cout << "Second to Last Number: " << thirdNumber << endl << "Last Number: " << lastNumber << endl;
	}
	file.close();
	cin >> fileName;
	return 0;
}
