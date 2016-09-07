//James Robertson, CS 1337.503
//Started on 8/29/2016


//am I allowed to import this much stuff?
#include <iostream>;
#include <string>;
#include <iomanip>;

using namespace std;

bool DefineInputIntegrity(string);
string checkInputIntegrity();
float checkINTputIntegrity();

//I seriously didn't know how classes in C++ work until I started this
//Why wouldn't I just create a class to hold all my stuff in?
class Company {
	string month;
	int year;
	float income;
	float taxArray[3];

public:
	Company(string, int, float);
	void CalculateTaxes();
	void Output();
};

Company::Company(string s, int y, float in){
	month = s;
	year = y;
	income = in;
}

void Company::CalculateTaxes() {
	taxArray[0] = income * 0.065;
	taxArray[1] = income * 0.0275;
	taxArray[2] = taxArray[0] + taxArray[1];
}

void Company::Output() {
	cout << "\n\n\t" << month << " " << year << endl;
	cout << "---------------------------" << endl;
	cout << "Sales for this month:  " << setprecision(2) << fixed << income << endl;
	cout << "Total:                 " << setprecision(2) << fixed << taxArray[2] + income << endl << endl;
	cout << "County Sales Tax:      " << setprecision(2) << fixed << taxArray[1] << endl;
	cout << "State Sales Tax:       " << setprecision(2) << fixed << taxArray[0] << endl;
	cout << "Total of Tax:          " << setprecision(2) << fixed << taxArray[2] << endl;
}



int main() {
	//Yeah I know, while(true) is scary but I don't care
	while (true) {
		//Input is re-declared every loop to prevent any type of carry over from the past iteration
		string validationInput;
		string s;
		int y;
		float in;

		cout << "\nPlease enter a month (string)" << endl;
		s = checkInputIntegrity();
		cout << "\nPlease enter the year (integer)" << endl;
		y = checkINTputIntegrity();
		cout << "\nPlease enter the income for the month (float)" << endl;
		in = checkINTputIntegrity();

		//We even start a new company every iteration
		Company foo(s, y, in);
		
		foo.CalculateTaxes();
		foo.Output();
		
		// --> Foo the entrepreneur
		cout << "\n\nWould you care to calculate another month? [y/n]" << endl;
		validationInput = checkInputIntegrity();

		DefineInputIntegrity(validationInput);

		//While(true) is not too scary :^)
		if (validationInput.compare("n") == 0) {
			break;
		}
	}

	system("pause");
    return 0;
}

//I never thought I would willingly use recursion after I left APCS, oh what have I become
bool DefineInputIntegrity(string inputIntegrity) {
	if (inputIntegrity.compare("y") == 0 || inputIntegrity.compare("n") == 0) {
		return true;
	}
	else {
		cout << "Please input y or n" << endl;
		cin >> inputIntegrity;

		DefineInputIntegrity(inputIntegrity);
	}
}

//Only works on C++11 and higher - lets hope it works :^)
string checkInputIntegrity() {
	string s;
	
	while (true) {
		cin >> s;

		try {
			int i = stoi(s);
		}
		catch (invalid_argument) {
			return s;
		}

		cout << "Please input a string without a number" << endl;
	}
}

float checkINTputIntegrity() {
	float s;

	while (true) {
		cin >> s;

		if (cin.fail() || s <= 0) {
			cin.clear();
			cin.ignore(256,'\n');

			cout << "Please reenter the correct data" << endl;
		}
		else {
			break;
			}
		}

	return s;
}
