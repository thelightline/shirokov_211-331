#include <iostream>
#include <string>

using namespace std;

struct pers {
    string surname, name;
    int age;
};

bool cmp(pers& a, pers& b, int choise){
    if (choise == 0)
        return a.surname <= b.surname;
    if (choise == 1)
        return a.name <= b.name;
    if (choise == 2)
        return a.age <= b.age;
}

template <typename T>
bool cmp(T a, T b, int choise){
    return a <= b;
}

template <typename T>
int partition(T array[], int low, int high, int choise){
    T mid = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++){
        if (cmp(array[j], mid, choise)){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

template <typename T>
void quickSort(T array[], int low, int high, int choise){
    if (low < high){
        int pi = partition(array, low, high, choise);
        quickSort(array, low, pi - 1, choise);
        quickSort(array, pi + 1, high, choise);
    }
}

pers d[] =
{
    {"White", "John", 17}, {"Brown", "Mike", 24}, {"Green", "Alex", 34},
    {"Red", "Josh", 15}, {"Brown", "Anna", 49}, {"Green", "Alex", 21}
};

int main()
{
    setlocale(LC_ALL, "RUS");
    int n = 8, choise = 0;
    cout << "Сортировка натуральных чисел: ";
    int a[8] = { 1, 5, 15, 7, 8, 1000, 14, 1 };
    quickSort(a, 0, n - 1, 0);
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;

    cout << "Сортировка вещественных чисел: ";
    double b[8] = { 1.5, 4.8, 12.4, 10.2, 8.9, 100.4, 10000.2, 4.8};
    quickSort(b, 0, n - 1, 0);
    for (int i = 0; i < n; i++) 
        cout << b[i] << " ";
    cout << endl;

    cout << "Сортировка типа string: ";
    char c[8] = { 'c', 'a', 'r', 't', 'u', 'z', 'a' , 'q' };
    quickSort(c, 0, n - 1, 0);
    for (int i = 0; i < n; i++) 
        cout << c[i] << " ";
    cout << "\n\n";

    cout << "Исходный список" << "\n\n";
    for (int i = 0; i < 6; i++)
        cout << d[i].surname << " " << d[i].name << " " << d[i].age << endl;
    
    cout << "\n" << "Сортировка по фамилии" << "\n\n";
    quickSort(d, 0, 6 - 1, 0);
    for (int i = 0; i < 6; i++)
        cout << d[i].surname << " " << d[i].name << " " << d[i].age << endl;

    cout << "\n" << "Сортировка по имени" << "\n\n";
    quickSort(d, 0, 6 - 1, 1);
    for (int i = 0; i < 6; i++)
        cout << d[i].surname << " " << d[i].name << " " << d[i].age << endl;

    cout << "\n" << "Сортировка по возрасту"<< "\n\n";
    quickSort(d, 0, 6 - 1, 2);
    for (int i = 0; i < 6; i++)
        cout << d[i].surname << " " << d[i].name << " " << d[i].age << endl;
    return 0;
}