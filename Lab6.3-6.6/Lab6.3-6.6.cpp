#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <fstream>
 
using namespace std;

void task_queue()
{	
	deque<int> q2 = { 2 }, q3 = { 3 }, q5 = { 5 };
	int n, res;
	cout << "Enter n: ";
	cin >> n;
	cout << "\n" << "Answer: ";
	for (int i = 0; i < n; i++)
	{

		res = min(q2.front(), min(q3.front(), q5.front()));

		cout << res << " ";

		q2.push_back(2 * res);
		q3.push_back(3 * res);
		q5.push_back(5 * res);

		if (res == q2.front())
			q2.pop_front();
		if (res == q3.front())
			q3.pop_front();
		if (res == q5.front())
			q5.pop_front();
	}
	cout << "\n\n";
}

void task_set()
{
	//Вход: ФИ + балл
	
	set<pair<string, int>> res;
	int n, score;
	bool flag = true;
	string name;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter result: \n";
	for (int i = 0; i < n; i++)
	{
		flag = true;
		cin >> name >> score;
		for (auto it = res.begin(); it != res.end(); it++)
			if (it->first == name)
				flag = false;
		if (flag)
			res.insert(pair<string, int>(name, score));
	}
	cout << "\nAnswer: \n";
	for (auto it = res.begin(); it != res.end(); it++)
		cout << it->first << " " << it->second << "\n";
	cout << "\n";
}

void task_list()
{
	list<pair<int, string>> ex;
	string last_name;
	int group, n;
	cout << "Enter number: ";
	cin >> n;
	cout << "Enter list of students:\n";
	for (int i = 0; i < n; i++)
	{
		cin >> group >> last_name;
		ex.emplace_back(pair<int, string>(group, last_name));
	}
	cout << "\nAnswer: \n";
	for (auto it = ex.begin(); it != ex.end(); it++)
		cout << it->first << " " << it->second << "\n";
	cout << "\n";
}

string ign(string word) //убирает  символы с текста
{
	char symbol[10] = { ',', '.', '!', '?', ';', ':', '%','(', ')', '\"' };

	for (int j = 0; j < 10; j++)
		if (word.find(symbol[j]) != -1)
			word.erase(word.find(symbol[j]), 1);

	return word;
}

void task_map()
{
	string word;
	ifstream text;
	text.open("text.txt");
	map<string, double> counter;
	int n = 0;
	word = "das,dsa!lfds";
	if (!text)
		cout << "File not found. \n";
	while (text >> word) {
		counter[ign(word)]++;
		n++;
	}
	cout << "Percentage: \n";
	for (auto it = counter.begin(); it != counter.end(); it++)
		cout << it->first << "\t\t" << round(it->second / n * 10000) / 100 << "%\n";
	cout << "\n";
	text.close();
}

int main()
{
	int key = 1;
	while (key != 0)
	{
		cout <<"1. Queue\n"
			 <<"2. Set and Unordered set\n"
			 <<"3. List\n"
			 <<"4. Map\n"
			 <<"0. Exit\n\n"
			 << "Select task: ";
		cin >> key;
		cout << "\n";
		switch (key)
		{
		case 1: task_queue();
			break;

		case 2: task_set();
			break;

		case 3: task_list();
			break;

		case 4: task_map();
			break;

		default:
			return 0;
		}
	}
}