#include <iostream>

void task1(){	
	int n;
	std::cout << "Task 1" << "\n"			
	<< "Enter number: ";
	std::cin >> n;
	for (int i = 0; i <= n; i++) {  // cycle for strings
		for (int j = 0; j <= i; j++) {  // cycle for numbers
			std::cout << j;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void task3()
{
	std::cout << "Task 3"<< "\n"
	<< "To stop dialing enter 0" << "\n" 
	<< "Enter numbers: "<< "\n";
	int count = -1, sum = 0, n=3;
	while (n != 0) {
		std::cin >> n;
		count++;  // counter of numbers
		sum += n; //sum of numbers
	}
	std::cout << "Average number is " << double(sum) / double(count) << "\n"<<"\n";
}

void task2() {
	int st;
	double numb = 1;
	std::cout << "Enter a number: ";
	std::cin >> st;
	std::cout << numb << " ";
	
	for (int i = 1; i <= st; i++) {
		numb = numb * (st - (i - 1)) / i;
		std::cout << numb << " ";
	}
	std::cout << "\n";
}

int main()
{
	int choice = 0; // variable to store the user's choice
	while (true) // endless cycle
	{
		std::cout << "Choice task"<< "\n"
			<< "1. Task 1" << "\n"
			<< "2. Task 2" << "\n"
			<< "3. Task 3" << "\n"
			<< "4. Exit" << "\n";
		std::cin >> choice;
		switch (choice){
			case 1:{		//function call to solve task 1
				task1();
				break;	//if absent, the next function will start
			}
			case 2:{		//function call to solve task 2
				task2();
				break;
			}
			case 3:{		//function call to solve task 3
				task3();
					break;
			}
			case 4:{		//function call to solve task 4
				return 0;
			}
			default:{		//if the switch is invalid
				return 0;
			}
		}
	}
}