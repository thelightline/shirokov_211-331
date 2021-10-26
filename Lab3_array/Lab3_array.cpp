#include <iostream>

using namespace std;

void print_mas(int* temp_mas)
{
	for (unsigned int i = 0; i < 1000; i++) {
		if (temp_mas[i] == 0) {
			continue;
		}
		else {
			std::cout << temp_mas[i] << " ";
		}
	}
	std::cout << std::endl;
}

void print_mas_symbols(int* temp_mas)
{
	for (unsigned int i = 0; i < 1000; i++) {
		if (temp_mas[i] == 0 || (i == 48 && temp_mas[48] > 0)) {
			continue;
		}
		else {
			while (temp_mas[i] != 0) {
				std::cout << char(i) << " ";
				temp_mas[i]--;
			}
		}
	}
	std::cout << std::endl;
}

void merge(int* tmp_arr, int first, int last, int* b)
{
	int middle, left, right;
	middle = (first + last) / 2;
	left = first;
	right = middle + 1;
	for (int i = first; i <= last; i++)
		if ((left <= middle) && ((right > last) || (tmp_arr[left] < tmp_arr[right])))
		{
			b[i] = tmp_arr[left];
			left++;
		}
		else
		{
			b[i] = tmp_arr[right];
			right++;
		}
	for (int i = first; i <= last; i++) 
		tmp_arr[i] = b[i];
};

void merge_sort(int* tmp_arr, int first, int last, int* b)
{
	{
		if (first < last)
		{
			merge_sort(tmp_arr, first, (first + last) / 2, b); //sort left side
			merge_sort(tmp_arr, (first + last) / 2 + 1, last, b); //sort right side
			merge(tmp_arr, first, last, b); //merge all 
		}
	}
};

int bubble(int* arr) {
	int smena = 0;
	for (unsigned int i = 0; i < 1000; i++) {
		for (unsigned int j = 0; j < 999; j++) {
			if (arr[j] >= arr[j + 1]) {
				smena = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = smena;
			}
		}
	}
	return *arr;
}

void Task1() {
	int count = 0, a[1000]{}, n=3;
	cout <<"\n" << "To stop dialing enter 0" << "\n";
	cout << "Enter the array numbers: ";
	while (n != 0) {
		cin >> n;
		a[count] = n;
		count++;  // counter of numbers
	}
	bubble(a);
	cout << "Sorted Array: ";
	print_mas(a);
	cout << "\n";
}

void Task2() {
	int count = 0, b[1000]{};
	char n=' ';
	cout << "\n" << "To stop dialing enter 0" << "\n";
	cout << "Enter the letters of the array: ";
	while (n != '0') {
		std::cin >> n;
		b[((int)(n))]++;
		count++;  // counter of numbers
	}	
	cout << "Sorted Array: ";
	print_mas_symbols(b);
	cout << "\n";
}

void Task3() {
	int count = 0, a[1000]{}, n = 3, b[1000]{};
	cout << "\n" << "To stop dialing enter 0" << "\n";
	cout << "Enter the array numbers: ";
	while (n != 0) {
		cin >> n;
		a[count] = n;	
		count++;  // counter of numbers
	}
	count--; //without 0
	merge_sort(a, 0, count, b);
	cout << "Sorted Array: ";
	print_mas(a);
	cout << "\n";
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
			<< "4. Exit" << "\n"<< "\n";
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