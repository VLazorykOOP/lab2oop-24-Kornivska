#include <iostream>
using namespace std;
void task1() {
    int a, b, c, d;
    cout << "Enter values for a, b, c, d: ";
    cin >> a >> b >> c >> d;
    // Обчислення виразу (37*b)+(((d*31)+(12*a))/2048)-(65*c)+(d*14) без використання множення та ділення
    int result = (b << 5) + b + ((d << 5) + (a << 3) + (a << 2)) - (c << 6) + c + (d << 4);
    // Виведення результату
    cout << "Result: " << result << endl;
}


