#include <iostream>
#include <string>
using namespace std;

bool Palindrom(char* str, int count) {
	for (int j = 0; j < (count / 2); j++)
		if (str[j] != str[count - j - 1]) 
			return false;
	return true;
}

int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
	int flag = 0, len, len_subs, i, j, k;
	len = strlen(str_for_search_in);
	len_subs = strlen(substring);
	for (i = start_position; i < len - len_subs + 1; i++) {
		for (j = 0, k = i; j < len_subs; j++, k++) {
			if (str_for_search_in[k] != substring[j]) {
				flag = 0;
				break;
			}
			flag = 1;
		}
		if (flag == 1) {
			return i;
		}
	}
	return -1;
}

int* find_substring2(const char* str_for_search_in, const char* substring) {    
	int  len, len_subs, array_lenght, start_index = 0, result, index = 0, flag = -1;
	len = strlen(str_for_search_in);
	len_subs = strlen(substring);
	result = find_substring1(str_for_search_in, substring, start_index);
	while (result != -1) {
		if (flag != result) {
			std::cout << result << " ";
		}
		flag = result;
		start_index++;
		result = find_substring1(str_for_search_in, substring, start_index);
	}

	return   0;
}

void encrypt(char* str_for_encrypt, int key) {
	for (int i = 0; i < strlen(str_for_encrypt); i++) {
		if (str_for_encrypt[i] >= 65 && str_for_encrypt[i] <= 90) {
			if (str_for_encrypt[i] + key > 90) 
				str_for_encrypt[i] = char(str_for_encrypt[i] + key - 26);
			else 
				str_for_encrypt[i] = char(str_for_encrypt[i] + key);
		}
		else if (str_for_encrypt[i] >= 97 && str_for_encrypt[i] <= 122) {
			if (str_for_encrypt[i] + key > 122)
				str_for_encrypt[i] = char(str_for_encrypt[i] + key - 26);
			else
				str_for_encrypt[i] = char(str_for_encrypt[i] + key);
		}
	}
}

void Task1() {
	char text[255], a=']';
	int i = 0;
	cout << "To stop typing, enter \".\" "<< "\n";
	cout << "Enter text: ";
	while (int(a) != 46){
		cin >> a;
		if ((int(a)>64 && int(a)<91)||(int(a) > 96 && int(a) < 123)) {
			if (int(a) > 96)
				text[i] = char(int(a) - 32);
			else
				text[i] = a;
			i++;
		}
	}
	if (Palindrom(text,i))
		cout << "The entered text is a palindrome." << "\n" << "\n";
	else
		cout << "The entered text is NOT a palindrome." << "\n" << "\n";
}

void Task2() {
	cout << "Enter a main text: ";
	char main_str[255], str[255];
	cin.ignore(32767, '\n'); 
	cin.getline(main_str, 256, '\n');
	cout << "Enter a substring: ";
	cin.getline(str, 256, '\n');
	cout << "All occurrences of a given substring: ";
	find_substring2(main_str, str);

	cout << "\n" << "\n";
}

void Task3() {
	cout << "Enter the cipher text: ";
	cin.ignore(32767, '\n');
	char str[255];
	cin.getline(str, 256, '\n');
	int num;
	cout << "Enter the shift value: ";
	cin >> num;
	cout << "Decrypted text: ";
	encrypt(str, num);
	cout << str;
	cout << "\n \n";
}

void Task4() {
	cout << "Enter text: ";
	cin.ignore(32767, '\n');
	char str[255];
	cin.getline(str, 256, '\n');
	int count = 0, num1, num2;
	cout << "Quote text: ";
	for (int i = 0; i < strlen(str); i++) {
		if ((char(str[i]) == 34) || (char(str[i]) == 39)||(char(str[i])==96)) {
			count++;
			if (count % 2 == 0) {
				num2 = i;
				if (count > 2)
					cout << " | ";
				for (int j = (num1+1); j < num2; j++) cout << str[j];
			}
			else
				num1 = i;
		}
	}
	cout << "\n \n";
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
			<< "4. Task 4" << "\n"
			<< "5. Exit" << "\n" << "\n";
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
		case 4: {		//function call to solve task 3
			Task4();
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