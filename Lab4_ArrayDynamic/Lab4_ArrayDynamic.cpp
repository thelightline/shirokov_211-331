#include <iostream>

using namespace std;

void Task1() {
	cout << "1";
}

void Task2() {
	cout << "2";
}

void Task3() {
	cout << "3";
}

int main()
{
	int choice = 0; // variable to store the user's choice
	while (true) // endless cycle
	{
		std::cout << "Choice task" << "\n"
			<< "1. Task 1" << "\n"
			<< "2. Task 2" << "\n"
			<< "3. Task 3" << "\n"
			<< "4. Exit" << "\n" << "\n";
		cout << "Select a task: ";
		std::cin >> choice;
		switch (choice) {
		case 1: {		//function call to solve task 1
			Task1();
			break;	//if absent, the next function will start
		}
		case 2: {		//function call to solve task 2
			Task2();
			break;
		}
		case 3: {		//function call to solve task 3
			Task3();
			break;
		}
		case 4: {		//function call to solve task 4
			return 0;
		}
		default: {		//if the switch is invalid
			return 0;
		}
		}
	}
}