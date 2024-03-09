#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cstring> // Для використання функції strcpy_s
using namespace std;

short getParity(unsigned int n) {
    bool parity = 1; // Ініціалізуємо змінну для зберігання парності
    for (int i = 1; i < 16; i++) { // Перевіряємо кожен біт числа, починаючи з другого
        if (((n >> i) & 1) == 1) { // Якщо біт дорівнює 1
            parity = !parity; // Змінюємо парність
        }
    }
    return parity; // Повертаємо значення парності
}

void task1() {
    int a = 0, b = 0, c = 0, d = 0; // Ініціалізуємо змінні
    cout << "Enter values for a, b, c, d: ";
    cin >> a >> b >> c >> d; // Зчитуємо значення змінних з консолі
    int result = (b << 5) + b + ((d << 5) + (a << 3) + (a << 2)) - (c << 6) + c + (d << 4); // Обчислюємо результат
    cout << "Result: " << result << endl; // Виводимо результат
}

void task2() {
    char input[128] = ""; // Ініціалізуємо масив для зберігання введеного тексту
    short symCounter = 0; // Ініціалізуємо лічильник символів
    cout << "1. Input from file input.txt" << endl; // Виводимо повідомлення про вибір введення з файлу
    cout << "2. Input from stdin" << endl; // Виводимо повідомлення про вибір введення з консолі
    cout << "Choose: ";
    char choose;
    cin >> choose; // Зчитуємо вибір користувача
    switch (choose) {
    case '1': { // Вибрано введення з файлу
        ifstream inputFile("D:\\visual studio\\ООП\\lab2.OPP.Kornivska\\inputt.txt", ios::in); // Відкриваємо файл для читання
        if (inputFile.is_open()) { // Якщо файл відкрито успішно
            while (inputFile.peek() != EOF && symCounter < 128) { // Читаємо символи з файлу поки не кінець файлу або досягнуто максимальну кількість символів
                char symbol;
                inputFile.get(symbol);
                input[symCounter++] = symbol; // Зберігаємо символ у масив
            }
            inputFile.close(); // Закриваємо файл
        }
        else {
            cout << "Can't open file" << endl; // Виводимо повідомлення про неможливість відкриття файлу
            return;
        }
        break;
    }
    case '2': { // Вибрано введення з консолі
        cout << "Input text: ";
        string inp;
        cin >> inp; // Зчитуємо рядок з консолі
        symCounter = inp.length(); // Запам'ятовуємо довжину рядка
        if (symCounter > 128) { // Перевіряємо, чи рядок не перевищує максимальну довжину
            cout << "Input text is too long." << endl;
            return;
        }
        strcpy_s(input, inp.c_str()); // Копіюємо рядок у масив input
        break;
    }
    default:
        cout << "Invalid option." << endl; // Виводимо повідомлення про невірний вибір
        return;
    }

    for (int i = symCounter; i < 128; i++) { // Заповнюємо решту масиву пробілами
        input[i] = ' ';
    }

    unsigned short* result = new unsigned short[128]; // Виділяємо пам'ять під масив результатів
    for (int i = 0; i < 128; i++) { // Шифруємо кожен символ і записуємо результат у масив result
        result[i] = 0;
        result[i] = (input[i] >> 4) & 0x0F;
        result[i] <<= 7;
        result[i] |= i;
        result[i] <<= 4;
        result[i] |= input[i] & 0x0F;
        result[i] <<= 1;
        short parity;
        parity = getParity(result[i]);
        result[i] |= parity;
        cout << "Encrypted " << (char)input[i] << " successfully. Result is: " << bitset<16>(result[i]) << endl; // Виводимо зашифрований символ та його результат
    }

    ofstream outputb("D:\\visual studio\\ООП\\lab2.OPP.Kornivska\\output.bin", ios::out | ios::binary); // Відкриваємо файл для запису результату
    outputb.write((char*)result, 128 * sizeof(unsigned short)); // Записуємо результат у файл
    outputb.close(); // Закриваємо файл
    delete[] result; // Звільняємо пам'ять, виділену для масиву result
}

void task3() {
    ifstream inputBinary("D:\\visual studio\\ООП\\lab2.OPP.Kornivska\\output.bin", ios::in | ios::binary); // Відкриваємо бінарний файл для читання
    if (!inputBinary.is_open()) { // Якщо не вдалося відкрити файл
        cout << "Error: Unable to open input binary file." << endl; // Виводимо повідомлення про помилку
        return;
    }

    unsigned short fromBinary[128] = { 0 }; // Ініціалізуємо масив для зберігання даних, прочитаних з файлу
    inputBinary.read(reinterpret_cast<char*>(&fromBinary), 128 * sizeof(unsigned short)); // Читаємо дані з файлу у масив
    inputBinary.close(); // Закриваємо файл

    char result[128] = { 0 }; // Ініціалізуємо масив для зберігання розкодованого тексту
    for (int i = 0; i < 128; i++) { // Декодуємо кожен елемент з масиву fromBinary та записуємо результат у масив result
        short parity = (fromBinary[i]) & 1;
        short lowerChast = (fromBinary[i] >> 1) & 0b1111;
        short position = (fromBinary[i] >> 5) & 0b1111111;
        short starshaChast = (fromBinary[i] >> 12) & 0b1111;
        char symbol = starshaChast << 4 | lowerChast;
        result[position] = symbol;
    }

    ofstream out("D:\\visual studio\\ООП\\lab2.OPP.Kornivska\\output_decrypted.txt", ios::out | ios::app); // Відкриваємо файл для запису результату
    cout << "Printing decrypted array: "; // Виводимо повідомлення про виведення розкодованого тексту
    for (int i = 0; i < 128; i++) { // Виводимо розкодований текст на екран та записуємо його у файл
        cout << result[i];
        out << result[i];
    }
    cout << endl;
    out.close(); // Закриваємо файл
}

int main() {
    int task;
    cout << "Enter task number (1, 2, 3): ";
    cin >> task; // Зчитуємо номер завдання з консолі
    switch (task) { // Виконуємо відповідну функцію відповідно до вибраного завдання
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
        cout << "Error: Invalid task number." << endl; // Виводимо повідомлення про невірний номер завдання
    }
    return 0;
}
