# Задание 1. НОД трёх или четырёх чисел

def nod(a, b):
    # Алгоритм Евклида через остаток от деления
    while b:
        a, b = b, a % b
    return abs(a)

variant = input("Вариант (нечётный/чётный): ").strip().lower()

if variant in ("нечётный", "нечетный", "1", "odd"):
    a, b, c = map(int, input("Введите 3 числа через пробел: ").split())
    print("НОД =", nod(nod(a, b), c))
elif variant in ("чётный", "четный", "2", "even"):
    a, b, c, d = map(int, input("Введите 4 числа через пробел: ").split())
    print("НОД =", nod(nod(nod(a, b), c), d))
else:
    print("Не удалось определить вариант.")


# Задание 2. Факторизация простым перебором
# Решето Эратосфена используется для поиска простых делителей.

from math import isqrt

n = int(input("Введите целое число больше 1: "))
if n < 2:
    print("Число должно быть больше 1.")
else:
    limit = isqrt(n)
    prime = [True] * (limit + 1)
    if limit >= 0:
        prime[0] = False
    if limit >= 1:
        prime[1] = False

    for p in range(2, isqrt(limit) + 1):
        if prime[p]:
            for j in range(p * p, limit + 1, p):
                prime[j] = False

    factors = {}
    for p in range(2, limit + 1):
        if prime[p]:
            while n % p == 0:
                factors[p] = factors.get(p, 0) + 1
                n //= p
    if n > 1:
        factors[n] = factors.get(n, 0) + 1

    for p, count in factors.items():
        print(f"{p} — кратность {count}")


# Задание 3. Факторизация нечётного числа методом Ферма

from math import isqrt

def is_prime(n):
    if n < 2:
        return False
    for d in range(2, isqrt(n) + 1):
        if n % d == 0:
            return False
    return True

def fermat(n):
    a = isqrt(n)
    if a * a < n:
        a += 1
    while True:
        b2 = a * a - n
        b = isqrt(b2)
        if b * b == b2:
            return a - b, a + b
        a += 1

def factor(n, result):
    if n == 1:
        return
    if is_prime(n):
        result.append(n)
        return
    a, b = fermat(n)
    factor(a, result)
    factor(b, result)

n = int(input("Введите нечётное число больше 1: "))
if n <= 1 or n % 2 == 0:
    print("Нужно нечётное число больше 1.")
else:
    result = []
    factor(n, result)
    for p in sorted(set(result)):
        print(f"{p} — кратность {result.count(p)}")


# Задание 4. Проверка числа Мерсенна тестом Люка — Лемера

from math import isqrt

p = int(input("Введите номер числа Мерсенна (показатель степени): "))

def is_prime(n):
    if n < 2:
        return False
    for d in range(2, isqrt(n) + 1):
        if n % d == 0:
            return False
    return True

if p < 2:
    print("Номер должен быть не меньше 2.")
else:
    m = 2 ** p - 1
    if p == 2:
        prime = True
    elif not is_prime(p):
        prime = False
    else:
        s = 4
        for _ in range(p - 2):
            s = (s * s - 2) % m
        prime = (s == 0)

    print("Число Мерсенна:", m)
    print("Простое" if prime else "Составное")


# Задание 5. Десять пятизначных чисел фон Неймана

seed = int(input("Введите начальное пятизначное число: "))

if not 10000 <= seed <= 99999:
    print("Число должно состоять из пяти цифр.")
else:
    for _ in range(10):
        # Дополняем квадрат нулями, чтобы получить 10 цифр,
        # затем берём пять цифр из середины.
        square = str(seed * seed).zfill(10)
        seed = int(square[2:7])
        print(seed)


# Задание 6. Поиск простых чисел решетом Сундарама

limit = int(input("Введите верхнюю границу: "))

if limit < 2:
    print("Простых чисел нет.")
else:
    n = (limit - 1) // 2
    marked = [False] * (n + 1)

    for i in range(1, n + 1):
        j = i
        while i + j + 2 * i * j <= n:
            marked[i + j + 2 * i * j] = True
            j += 1

    primes = [2] if limit >= 2 else []
    for i in range(1, n + 1):
        number = 2 * i + 1
        if number <= limit and not marked[i]:
            primes.append(number)

    print(*primes)  
    123
    