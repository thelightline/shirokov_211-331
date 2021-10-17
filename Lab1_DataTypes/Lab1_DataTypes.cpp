#include <iostream>
#include <bitset>
int main(){
            //task 1
    std::cout << "Shirokov Matvey Sergeevich, group 211-331. \n " << "\n";

            //task 2
            //std::cout << sizeof(int); == 4 bit
    std::cout << "min_int:- " << 0b10000000000000000000000000000000 << "\n"
        << "max_int: " << 0b01111111111111111111111111111111 << "\n"
        << "size of int: " << sizeof(int) << "\n" << "\n";

            //std::cout << sizeof(unsigned int); == 4 bit
    std::cout << "min_unsigned: 0 \n" << "max_unsigned: " 
        << 0b11111111111111111111111111111111 << "\n" 
        << "size of unsigned int: " << sizeof(unsigned int) << "\n" << "\n";

            //std::cout << sizeof(short); == 2 bit
    std::cout << "min_short: -" << 0b1000000000000000 << "\n"
        << "max_short: " << 0b0111111111111111 << "\n" 
        << "size of short: " << sizeof(short) << "\n" << "\n";

    std::cout << "min_unsigned_short: 0 \n" << "max_unsigned_short: "
        << 0b1111111111111111 << "\n"
        << "size of unsigned short: " << sizeof(unsigned short) << "\n" << "\n";

            //std::cout << sizeof(long); == 4
    std::cout << "min_long: " << "-" << 0b10000000000000000000000000000000 << "\n"  
        << "max_long: " << 0b01111111111111111111111111111111 << "\n" 
        << "size of long: " << sizeof(long) << "\n" << "\n";

            //std::cout << sizeof(long long); == 8
    std::cout << "min_longlong: -" << 0b1000000000000000000000000000000000000000000000000000000000000000 << "\n"
        << "max_longlong: " << 0b0111111111111111111111111111111111111111111111111111111111111111 << "\n" 
        << "size of long long: " << sizeof(long long) << "\n" << "\n";
            
            //std::cout << sizeof(char); == 1
    std::cout << "min_char: 0 \n"                      
        << "max_char: " << 0b11111111 << "\n" 
        << "size of char: " << sizeof(char) << "\n" << "\n";

            //std::cout << sizeof(bool); == 1
    std::cout << "min_bool: 0 \n"
        << "max_bool: " << 0b11111111 << "\n" 
        << "size of bool: " << sizeof(bool) << "\n" << "\n";

            //std::cout << sizeof(double); == 8
    std::cout << "min_double: -" << 0b1000000000000000000000000000000000000000000000000000000000000000 << "\n"
        << "max_double: " << 0b0111111111111111111111111111111111111111111111111111111111111111 << "\n"
        << "size of double: " << sizeof(double) << "\n" << "\n";

            // task 3

    int a, b;
    std::cout << "Enter a number: ";
    std::cin >>  a;
    std::cout << "Binary: " << std::bitset<32>(a) << "\n";
    std::cout << "Hexadecimal: " << std::hex << a << "\n";
    std::cout << "Bool: "<< bool(a) << "\n";
    std::cout << "Double: "<< double(a) << "\n";
    std::cout << "Char: "<< char(a) << "\n" << "\n";
    
            // task 4
    std::cout << "Enter odds  a * x = b: ";
    double n, z;
    std::cin >> n >> z;
    std::cout << n << " * x = " << z << "\n";
    std::cout << "x = " << z << "/" << n << "\n";
    std::cout << "x = " << z / n << "\n";   
    std::cout << "Answer: " << z/n << "\n";

            //task 5
    int m, l;
    std::cout << "Enter the coordinates of a line segment: ";   
    std::cin >> m >> l;
    std::cout << "The midpoint of the line is at the point: " << (double(m) + double(l)) / 2 << "\n";
}
