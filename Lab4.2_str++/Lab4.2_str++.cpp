#include <iostream> // E:\project\shirokov_331\file.txt
#include <string>
#include <fstream>
using namespace std;

// TASK 1
string file_format(const string file_path_full) {
	int pos = file_path_full.rfind('.');
	string extension;
	for (int i = pos + 1; i < file_path_full.size(); i++)
		extension = extension + file_path_full[i];
	return extension;
} 

// TASK 2
string file_name(const string file_path_full) {
	int pos1 = file_path_full.rfind('\\');
	int pos2 = file_path_full.rfind('.');
	string name;
	for (int i = pos1 + 1; i < pos2; i++)
		name = name + file_path_full[i];
	return name; 
}

// TASK 3
string file_path(const string file_path_full) {
	int pos = file_path_full.rfind('\\');
	string path;
	for (int i = 0; i < pos; i++)
		path = path + file_path_full[i];
	return path;
} 

// TASK 4
char file_disk(const string file_path_full) {
	return file_path_full[0];
}

// TASK 5
bool file_rename(string& file_path_full) {
	string format, new_name, path, new_file_path;
	format = file_format(*&file_path_full);
	cout << "Enter new filename: ";
	cin >> new_name;
	path = file_path(*&file_path_full);
	new_file_path = file_path(*&file_path_full)+ '\\' + new_name + "." + format;
	file_path_full = new_file_path;
	return true;
}

// TASK 6
bool file_copy(const string file_path_full) {
	string name, path, format, new_path_full;
	name = file_name(file_path_full);
	name.append("_copy");
	path = file_path(file_path_full);
	format = file_format(file_path_full);
	new_path_full.append(path);
	new_path_full.append("\\");
	new_path_full.append(name);
	new_path_full.append(".");
	new_path_full.append(format);
	ifstream infile(file_path_full, ios::binary);
	if (infile.is_open()) {
		infile.seekg(0, ios_base::end);
		long size = infile.tellg();
		infile.seekg(0);
		char* buffer = new char[size];
		infile.read(buffer, size);
		ofstream outfile(new_path_full, ios::binary);
		if (outfile.is_open()) {
			outfile.write(buffer, size);
			delete[] buffer;
			infile.close();
			outfile.close();
			return true;
		}
		else {
			infile.close();
			return false;
		}
	}
	else {
		return false;
	}

	return true;
}

int main()
{
	int choice = 0; // variable to store the user's choice
	string file_path_full;
	cout << "Enter file location: "; 
	cin >> file_path_full;
	while (true) // endless cycle
	{
		std::cout << "Choice task" << "\n"
			<< "1. Task 1" << "\n"
			<< "2. Task 2" << "\n"
			<< "3. Task 3" << "\n"
			<< "4. Task 4" << "\n"
			<< "5. Task 5" << "\n"
			<< "6. Task 6" << "\n"
			<< "7. Exit" << "\n" << "\n";
		std::cout << "Select a task: ";
		std::cin >> choice;
		switch (choice) {
		case 1: {		//function call to solve task 1
			cout << "File format: " << file_format(file_path_full) << "\n \n";
			break;	//if absent, the next function will start
		}
		case 2: {		//function call to solve task 2
			cout << "File name: " << file_name(file_path_full) << "\n \n";
			break;
		}
		case 3: {		//function call to solve task 3
			cout << "File path: " << file_path(file_path_full) << "\n \n";
			break;
		}
		case 4: {		//function call to solve task 4
			cout << "File disk: " << file_disk(file_path_full) << "\n \n";
			break;
		}
		case 5: {		//function call to solve task 5
			if (file_rename(*&file_path_full))
				cout << "File renamed successfully" << "\n \n";
			else
				cout << "File was not renamed" << "\n \n";
			break;
		}
		case 6: {		//function call to solve task 6
			if (file_copy(file_path_full)) {
				cout << "File copied successfully" << "\n\n";
			}
			else {
				cout << "File copied unsuccessfully" << "\n\n";
			}
			break;
		}
		case 7: {		//function call to solve task 7
			return 0;
		}
		default: {		//if the switch is invalid
			return 0;
		}
		}
	}
}