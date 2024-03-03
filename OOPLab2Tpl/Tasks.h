#include <iostream>
using namespace std;
// Прототипи функцій
void MenuTask();
void task1();
void task2();
void task3();
int main() {
    int task;
    MenuTask(); // Виклик функції MenuTask()
    cout << "Enter task number (1,2,3): ";
    cin >> task;
    switch (task) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        cout << "Error\n";
    }
    return 0;
}
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}



