#include <iostream>
using namespace std;
// Прототипи функцій
void MenuTask();
void task1();
void task2();
int main() {
    int task;
    MenuTask(); // Виклик функції MenuTask()
    cout << "Enter task number (1,2): ";
    cin >> task;
    switch (task) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    default:
        cout << "Error\n";
    }
    return 0;
}


