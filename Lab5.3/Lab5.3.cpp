#include <iostream>
#include "Matr.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Матрица: " << endl;
    Matr MtrA;
    MtrA.input(2);
        cout << MtrA;
    Matr MtrC;
    MtrC.input(2);
       cout << MtrC;
    cout << MtrC * MtrA;
    cout << endl;


    MtrA.print();
    double tr = MtrA.tr();
    cout << tr <<endl;
    -MtrA;
    cout << MtrA;
    Matr MtrB;
    MtrB.input(5);

}