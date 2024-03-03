#include <iostream>
using namespace std;
void task1() {
    int a, b, c, d;
    cout << "Enter values for a, b, c, d: ";
    cin >> a >> b >> c >> d;
    // Обчислення виразу без використання множення та ділення
    int result = (b << 5) + b + ((d << 5) + (a << 3) + (a << 2)) - (c << 6) + c + (d << 4);

