//#include <iostream>
//#include <string>
//#include <cctype>
//
//using namespace std;
//
//int main() {
//    string word1, word2, w1, w2;
//
//    cout << "enter the first string: ";
//    getline(cin, word1);
//    cout << "enter the second string: ";
//    getline(cin, word2);
//
//    for (char c : word1) {
//        if (isalpha(c)) {
//            w1 += tolower(c);
//        }
//    }
//
//    for (char c : word2) {
//        if (isalpha(c)) {
//            w2 += tolower(c);
//        }
//    }
//
//    if (w1 == w2) {
//        cout << "IDENTICAL" << endl;
//    }
//    else {
//        cout << "NOT IDENTICAL" << endl;
//    }
//
//    return 0;
//}


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool pas(const string password) {
    if (password.length() < 8) return false;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (ispunct(ch)) hasSpecial = true;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

string genPass() {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    string password;
    for (int i = 0; i < 12; ++i) password += chars[rand() % chars.size()];
    return password;
}

int main() {
    system("chcp 1251>null");
    cout << "Вимоги до пароля:\n"
        << "1. Довжина пароля має бути не менше 8 символів.\n"
        << "2. Має містити принаймні одну велику літеру (A - Z).\n"
        << "3. Має містити принаймні одну малу літеру (a - z).\n"
        << "4. Має містити принаймні одну цифру (0 - 9).\n"
        << "5. Має містити принаймні один спеціальний символ (!, @, #, $, тощо).\n" << endl;

    cout << "Введіть пароль: ";
    string password; cin >> password;

    if (pas(password)) cout << "Пароль надійний." << endl;
    else {
        cout << "Пароль не відповідає вимогам.\nЗгенерований пароль: " << genPass() << endl;
    }

    return 0;
}
