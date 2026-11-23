// Баканов Олег ЭФБО-08-26
// Задача 1
// #include <iostream>
// using namespace std;

// int fibonacci(int n) {
//     if (n <= 1)
//         return n;
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;

//     if (n < 0)
//         cout << "Error";
//     else
//         cout << fibonacci(n);

//     return 0;
// }

// Задача 2
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// using namespace std;

// int main() {
//     ifstream in("input.txt");
//     ofstream out("output.txt");

//     if (!in || !out) {
//         cout << "File error";
//         return 1;
//     }

//     string line, word;
//     int words = 0, sentences = 0, paragraphs = 0;
//     bool inParagraph = false;

//     while (getline(in, line)) {
//         if (line.find_first_not_of(" \t\r") == string::npos) {
//             inParagraph = false;
//             continue;
//         }

//         if (!inParagraph) {
//             paragraphs++;
//             inParagraph = true;
//         }

//         stringstream ss(line);
//         while (ss >> word)
//             words++;

//         for (char c : line) {
//             if (c == '.' || c == '!' || c == '?')
//                 sentences++;
//         }
//     }

//     out << "Words: " << words << endl;
//     out << "Sentences: " << sentences << endl;
//     out << "Paragraphs: " << paragraphs << endl;

//     cout << "Done!";
//     return 0;
// }


// Задача 3

// #include <iostream>
// #include <string>
// #include <cctype>
// using namespace std;
// int main() {
//     string text;

//     cout << "Enter text: ";
//     getline(cin, text);

//     if (!text.empty())
//         text[0] = toupper(text[0]);

//     cout << text;

//     return 0;
// }
