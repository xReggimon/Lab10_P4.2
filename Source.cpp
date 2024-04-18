#include <iostream>
#include <string>

using namespace std;

bool isCardValid(string s);
bool isNumeric(string s);
bool isCorrectLength(string s);

int main() {

	int digits[8];

	while (true) {
		string input;
		cout << "Enter 16-digit credit card # or Q to quit: ";
		getline(cin, input);

		if (input[0] == 'Q' || input[0] == 'q') {
			break;
		}

		if (!isNumeric(input)) {
			cout << "Error, only digits." << endl;
			continue;
		}

		if (!isCorrectLength(input)) {
			cout << "Error, 16 digits only." << endl;
			continue;
		}

		if (isCardValid(input)) {
			cout << "Card is valid. " << endl;
		}
		else {
			cout << "Card is not valid" << endl;
		}
	}
	return 0;
}

bool isCardValid(string s) {
	int sum1 = 0;
	int sum2 = 0;
	bool is_even = false;

	for (int i = s.length() - 1; i >= 0; i--) {
		int digit = s[i] - '0';

		if (is_even) {
			digit *= 2;
			if (digit >= 10) {
				digit = digit / 10 + digit % 10;
			}
			sum2 += digit;
		}
		else {
			sum1 += digit;
		}

		is_even = !is_even;
	}
	return(sum1 + sum2) % 10 == 0;
}

bool isNumeric(string s) {
	for (char c : s) {
		if (c < '0' || c > '9') {
			return false;
		}
	}
	return true;
}
bool isCorrectLength(string s) {
	return s.length() == 16;
}
