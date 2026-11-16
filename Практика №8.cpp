// Баканов Олег ЭФБО-08-26
// Контрольная работа 2
// Задание 1
// #include <iostream>
// using namespace std;

// // Быстрое возведение в степень: a^n
// long long fastPow(long long a, long long n) {
//     long long result = 1;
//     while (n > 0) {
//         if (n % 2 == 1) {
//             result *= a;
//         }
//         a *= a;
//         n /= 2;
//     }
//     return result;
// }

// int main() {
//     long long a, n;
//     cin >> a >> n;
//     cout << a << "^" << n << " = " << fastPow(a, n) << endl;
//     return 0;
// }



// Задание 2
// #include <iostream>
// using namespace std;

// // Рекурсивная функция для нахождения НОД
// int gcd(int a, int b) {
//     if (b == 0) {
//         return a; // Базовый случай: если второе число 0, то НОД - это первое число
//     }
//     return gcd(b, a % b); // Рекурсивный шаг
// }

// int main() {
//     // Ускоряем ввод/вывод (полезно для больших чисел)
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int a, b;
//     cin >> a >> b; // Читаем два числа
    
//     cout << gcd(a, b) << "\n"; // Выводим результат
    
//     return 0;
// }



// Задание 3
// #include <iostream>
// using namespace std;

// // Функция перекладывания
// // n - количество ингредиентов
// // from - с какой салфетки
// // to - на какую салфетку
// // aux - вспомогательная салфетка
// void moveIngredients(int n, int from, int to, int aux) {
//     if (n == 0) {
//         return; // Базовый случай: перекладывать нечего
//     }
    
//     // Шаг 1: Перекладываем n-1 ингредиентов на вспомогательную салфетку
//     moveIngredients(n - 1, from, aux, to);
    
//     // Шаг 2: Перекладываем самый большой (n-й) ингредиент на целевую салфетку
//     cout << "Ingredient " << n << " move from " << from << " to " << to << "\n";
    
//     // Шаг 3: Перекладываем n-1 ингредиентов со вспомогательной на целевую
//     moveIngredients(n - 1, aux, to, from);
// }

// int main() {
//     // Ускоряем ввод/вывод
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin >> n;
    
//     // Вызываем функцию: n ингредиентов, с 1-й салфетки на 3-ю, 2-я - вспомогательная
//     moveIngredients(n, 1, 3, 2);
    
//     return 0;
// }



// Задание 1 (2 способ)
#include <iostream>
using namespace std;

// Рекурсивная функция быстрого возведения в степень
long long fastPow(long long a, long long n) {
    // Базовый случай: любое число в степени 0 равно 1
    if (n == 0) {
        return 1;
    }
    
    // Если степень чётная: a^n = (a^(n/2))^2
    if (n % 2 == 0) {
        long long half = fastPow(a, n / 2); // считаем половину
        return half * half;                 // и возводим её в квадрат
    }
    
    // Если степень нечётная: a^n = a * a^(n-1)
    return a * fastPow(a, n - 1);
}

int main() {
    // Ускоряем ввод/вывод
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, n;
    
    cout << "Enter base and exponent: ";
    cin >> a >> n;

    cout << a << "^" << n << " = " << fastPow(a, n) << endl;

    return 0;
}