#pragma once

namespace libmath
{

int addition(int a, int b, int& c)
{
    if ((b > 0) && (a > INT_MAX - b))
    {
        return -2;
    }

    if ((b < 0) && (a < INT_MIN - b))
    {
        return -2;
    }

    c = a + b;
    return 0;
}

int subtraction(int a, int b, int& c)
{
    if ((b > 0) && (a > INT_MAX - b))
    {
	return -2;
    }

    if ((b < 0) && (a < INT_MIN - b))
    {
	return -2;
    }

    c = a - b;
    return 0;
}

int multiplication(int a, int b, int& c)
{
    // Частный случай: INT_MIN * -1 = INT_MAX + 1 (переполнение)
    if (a == INT_MIN && b == -1) {
        return -2;
    }
    if (b == INT_MIN && a == -1) {
        return -2;
    }

    // Умножение на ноль
    if (b == 0 || a == 0) {
        c = 0;
        return 0;
    }

    if ((b > 0) && (a > INT_MAX / b)) {
        return -2; // Переполнение в положительную сторону
    }
    if ((b < 0) && (a < INT_MIN / b)) {
        return -2; // Переполнение в отрицательную сторону
    }

    c = a * b;
    return 0;
}

int division(int a, int b, int& c)
{
    if (b == 0)
    {
	return -1;
    }

    // Проверка переполнения
    if (a == INT_MIN && b == -1)
    {
	return -2;
    }

    c = a / b;
    return 0;
}

int power(int a, int b, int& c)
{
    // Отрицательная степень для целых чисел не поддерживается
    if (b < 0) {
        return -3;
    }

    // Ситуация, когда a == 0 и b == 0 — математически не определена
    if (a == 0 && b == 0) {
        return -4;
    }

    int c = 1;
    for (int i = 0; i < b; ++i) {
        // Проверка на переполнение
        if (c > INT_MAX / a) {
            return -2;
        }
        c = c * a;
    }
    return 0;
}

int factorial(int a, int& c)
{
    // Отрицательное число
    if (a < 0) {
        return -5;
    }

    // 0! = 1, 1! = 1
    if (a <= 1) {
        c = 1;
        return 0;
    }

    // Рекурсивный вызов
    int sub_result;
    int status = factorial(a - 1, sub_result);
    if (status != 0)
    {
	return status;
    }
    
    if (sub_result > INT_MAX / a) {
        return -2; // Переполнение
    }

    c = sub_result * a;
    return 0;
}
