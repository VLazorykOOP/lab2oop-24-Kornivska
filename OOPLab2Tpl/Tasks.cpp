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
 // Функція для доповнення вхідного тексту пробілами до заданої максимальної довжини
void padText(string& text, int maxLength) {
    while (text.length() < maxLength) {
        text += ' ';
    }
}
// 	Цикл, що проходить крізь кожен символ вхідного тексту
void encryptText(const string& inputText, string& encryptedText) {
    for (char ch : inputText) {
        // Конвертація символу в ASCII-код
        int asciiCode = static_cast<int>(ch);
        // Обчислюємо позицію символу в рядку, який вже був зашифрований
        int position = encryptedText.length() % 128;
        // Отримуємо старшу та молодшу ASCII-коду символу
        int highBits = (asciiCode >> 4) & 0x0F;
        int lowBits = asciiCode & 0x0F;
        bool parityBit = true; // Припустимо, що біт парності завжди true
        // Формуємо два байти для кожного символу
        char byte1 = (highBits << 4) | (position >> 3);
        char byte2 = ((position & 0x07) << 5) | lowBits;
        byte1 |= (parityBit << 7); // Встановлюємо біт парності
        // Накопичення зашифрованого тексту по мірі обробки кожного символу вхідного тексту
        encryptedText += byte1;
        encryptedText += byte2;
    }
}
// Вказуються шляхи до вхідного текстового файлу та файлу для збереження зашифрованого тексту 
void task2() {
    string inputFileName = "D:\\visual studio\\ООП\\лаб2\\input.txt";
    string outputFileName = "output.bin";
    // строка для зберігання введеного тексту та зашифрованого тексту
    string inputText, encryptedText;
    // Зчитуємо текст з текстового файлу
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open file " << inputFileName << endl;
        return;
    }
    getline(inputFile, inputText);
    inputFile.close();

