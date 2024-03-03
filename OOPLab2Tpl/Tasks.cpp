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


