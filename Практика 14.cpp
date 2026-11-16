// // Задание 1.

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s;
//     getline(cin, s);

//     int balance = 0;

//     for (char c : s) {
//         if (c == '(') balance++;
//         if (c == ')') balance--;

//         if (balance < 0) {
//             cout << "no";
//             return 0;
//         }
//     }

//     cout << (balance == 0 ? "yes" : "no");
// }

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
    string text, line;
    while (getline(cin, line))
        text += line + " ";

    set<string> seen;
    vector<string> result;
    string word;

    for (int i = 0; i < text.size();) {
        unsigned char a = text[i];
        unsigned char b = (i + 1 < text.size())
                        ? (unsigned char)text[i + 1] : 0;

        if (a < 128) {
            if ((a >= 'A' && a <= 'Z') ||
                (a >= 'a' && a <= 'z') ||
                (a >= '0' && a <= '9')) {
                if (a >= 'A' && a <= 'Z') a += 32;
                word += (char)a;
            } else {
                if (!word.empty()) {
                    if (seen.insert(word).second) result.push_back(word);
                    word.clear();
                }
            }
            i++;
        } else if (a == 0xD0 || a == 0xD1) {
            // Проверяем, что это именно русская буква
            bool letter = (a == 0xD0 && b >= 0x90 && b <= 0xBF) ||
                          (a == 0xD1 && b >= 0x80 && b <= 0x8F);

            if (letter) {
                // А-Я -> а-я
                if (a == 0xD0 && b >= 0x90 && b <= 0x9F) b += 0x20;
                else if (a == 0xD0 && b >= 0xA0 && b <= 0xAF) {
                    a = 0xD1;
                    b -= 0x20;
                } else if (a == 0xD0 && b == 0x81) {
                    a = 0xD1;
                    b = 0x91; // Ё -> ё
                }

                word += (char)a;
                word += (char)b;
            } else if (!word.empty()) {
                if (seen.insert(word).second) result.push_back(word);
                word.clear();
            }
            i += 2;
        } else {
            // Знак препинания или другой символ — конец слова
            if (!word.empty()) {
                if (seen.insert(word).second) result.push_back(word);
                word.clear();
            }
            i++;
        }
    }

    if (!word.empty() && seen.insert(word).second)
        result.push_back(word);

    for (const string& w : result)
        cout << w << '\n';
}