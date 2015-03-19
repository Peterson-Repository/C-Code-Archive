/*
 * Program Prog1.cpp
 * Author: Marco Peterson
 * Date: 4-20-2011
 * Course: CSCI250
 *
 * Program Description
 * 
 * Enter a number and the program will display the number in word form
 * 
 */

#include <iostream>
#include <string>
using namespace std;

class Numbers {

private:
	int numberToConvert;

public:
	Numbers(int i);
	string convert();
};

Numbers::Numbers(int i) {
	numberToConvert = i;
}

string Numbers::convert() {
	string lessThan20[] = {"zero", "one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine", "ten", "eleven", "twelve",
		"thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
		"eighteen", "nineteen"};

	string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty",
		"seventy", "eighty", "ninety"};

	string result;

	//1-20
	if(numberToConvert < 20){
		result = lessThan20[numberToConvert];
	}

	//20-100
	if (numberToConvert >= 20 && numberToConvert < 100) {
		result = tens[(numberToConvert/10)-2] + " ";
		numberToConvert = numberToConvert%10;
	
		if (numberToConvert != 0) {
			result = result + lessThan20[numberToConvert];
		}
	}
	
	string hundreds[] = {"one hundred", "two hundred", "three hundred", "four hundred", "five hundred"
		, "six hundred", "seven hundred", "eight hundred", "nine hundred"};

	//100-999
	if (numberToConvert >= 100 && numberToConvert <= 999){
		result = hundreds[(numberToConvert/100)-1] + " ";
		numberToConvert = numberToConvert%100;

		if(numberToConvert%100 < 20){
			result = result + lessThan20[numberToConvert];
		}

			else if(numberToConvert != 0){
			result = result + tens[(numberToConvert/10)-2] + " ";
			numberToConvert = numberToConvert%10;
	
				if (numberToConvert != 0) {
				result = result + lessThan20[numberToConvert];
			}
		}
	}

	string thousands[] = {"one thousand", "two thousand", "three thousand", "four thousand",
		"five thousand", "six thousand", "seven thousand", "eight thousand", "nine thousand"};


	//1,000-9,999
	if (numberToConvert >= 1000 && numberToConvert <= 9999){
		result = thousands[(numberToConvert/1000)-1] + " ";
		numberToConvert = numberToConvert%1000;

		if(numberToConvert%1000 < 20){
			result = result + lessThan20[numberToConvert];
		}


			else if(numberToConvert != 0){
			result = result + hundreds[(numberToConvert/100)-1] + " ";
			numberToConvert = numberToConvert%100;


				if(numberToConvert != 0){
				result = result + tens[(numberToConvert/10)-2] + " ";
				numberToConvert = numberToConvert%10;
	
					if (numberToConvert != 0) {
					result = result + lessThan20[numberToConvert];
				}
			}
		}
	}

	return result;
}


int main() {

	int number;

	//Prompt
	cout << "Enter a number between 0 and 9999: ";
	cin >> number;

	//input Validation
	while(number < 0 || number > 9999){
		cout <<"Negative Numbers and numbers greater that 9,999 are invalid, try again" <<endl;
		cin >> number;
	}

	Numbers A1(number);
	cout << A1.convert() << endl;

	system("pause");
	return 0;
}