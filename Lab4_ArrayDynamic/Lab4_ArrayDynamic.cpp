#include <iostream>

using namespace std;

int sum(int number) {
	int multiply = 1, sum = 0, sumb = 0, temp_num, digit_counter = 0, last_digit;
	temp_num = number;
	while (multiply < number) {
		digit_counter++;
		last_digit = temp_num % 10;
		temp_num /= 10;
		multiply *= 10;
		if (digit_counter % 2 == 0) {
			sum += last_digit;
		}
		else {
			sumb += last_digit;
		}
	}
	if (digit_counter % 2 == 0) 
		return sumb;
	else 
		return sum;
}

void bubble_sort(int* arr, int size) {
	int smena = 0;
	for (unsigned int i = 0; i < (size); i++) {
		for (unsigned int j = 0; j < (size-1); j++) {
			if (arr[j] % 10 > arr[j + 1] % 10) {
				smena = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = smena;
			}
			else if (arr[j] % 10 == arr[j + 1] % 10) {
				if (arr[j] < arr[j + 1]) {
					smena = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = smena;
				}
			}
		}
	}
	cout << "Array sorted by sum: ";
	for (int k = 0; k < size - 1; k++)
		cout << arr[k] << ", ";
	cout << arr[size - 1] << ". \n" << "\n";
}

void Task1(int*& arr, int& size) {
	int a;
	if (arr != nullptr)
		delete[] arr;
	cout << "Input the size of array: ";
	cin >> size;
	arr = new int[size];
	cout << "Enter a number into an array: ";
	for (int i = 0; i < size; i++) {
		cin >> a;
		arr[i] = a;
	}
	cout << "Array entered." << "\n" << "\n";
}

void Task2(int* arr, int size) {
	cout << "Array: ";
	for (int i = 0; i < size-1; i++)
		cout << arr[i] << ", ";
	cout << arr[size - 1] << "." << "\n"<<"\n";
}

void Task3(int* arr, int size) {
	int* mas = new int[size];
	for (int g = 0; g < size; g++)
		mas[g] = arr[g];
	int changea = 0, changeb;
	int* b = new int[size];
	for (int k = 0; k < size; k++)
		b[k] = sum(mas[k]);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			if (b[j] > b[j + 1]) {
				changeb = b[j];
				b[j] = b[j + 1];
				b[j + 1] = changeb;
				changea = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = changea;
			}
		}
	}
	cout << "Array sorted by sum: ";
	for (int g = 0; g < size-1; g++)
		cout << mas[g] << ", ";
	cout<<mas[size-1]<<". \n" <<"\n";
}

void Task4(int*& arr, int size) {
	int* a = new int[size];
	for (int i = 0; i < size; i++)
		a[i] = arr[i];
	bubble_sort(a, size);
}

int main()
{
	int choice = 0; // variable to store the user's choice
	int* arr = nullptr;
	int size = 0;
	while (true) // endless cycle
	{
		std::cout << "Choice task" << "\n"
			<< "1. Task 1" << "\n"
			<< "2. Task 2" << "\n"
			<< "3. Task 3" << "\n"
			<< "4. Task 4" << "\n"
			<< "5. Exit" << "\n" << "\n";
		cout << "Select a task: ";
		std::cin >> choice;
		switch (choice) {
		case 1: {		//function call to solve task 1
			Task1(arr, size);
			break;	//if absent, the next function will start
		}
		case 2: {		//function call to solve task 2
			Task2(arr, size);
			break;
		}
		case 3: {		//function call to solve task 3
			Task3(arr, size);
			break;
		}
		case 4: {		//function call to solve task 3
			Task4(arr, size);
			break;
		}
		case 5: {		//function call to solve task 4
			return 0;
		}
		default: {		//if the switch is invalid
			return 0;
		}
		}
	}
}