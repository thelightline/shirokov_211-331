#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

void proverka(string str) {
    bool flag = true;
    char sim;
    stack<char> skob;
    for (int i = 0; i < str.length(); i++) {
        if (flag == false) break;
        sim = str[i];
        switch (sim)
        {
        case 40:
        case 91:
        case 123:
        {
            skob.push(sim);
            break;
        }
        case 41:
        {
            if (skob.top() == 40) {
                skob.pop();
                break;
            }
            else {
                flag = false;
                break;
            }
        }
        case 93:
        {
            if (skob.top() == 91) {
                skob.pop();
                break;
            }
            else {
                flag = false;
                break;
            }
        }
        case 125:
        {
            if (skob.top() == 123) {
                skob.pop();
                break;
            }
            else {
                flag = false;
                break;
            }
        }
        default:
            break;
        }
    }


    if (skob.size() != 0)   flag = false;
    if (flag == true) {
        cout << "Скобочное выражение верно." << "\n";
    }
    else {
        cout << "В скобочном выражении допущена ошибка." << "\n";
    }
}





int main()
{
    setlocale(LC_ALL, "RUS");
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    cout << "\n";
    proverka(str);
}