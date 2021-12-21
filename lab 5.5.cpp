// lab 5.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//36 варіант

#include <iostream>
#include <cmath>

using namespace std;

double f(double x);
double findX(double a, double b, double eps, int& deep);

int main()
{
    double a, b, eps, x;
    int deep = 0;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "eps = "; cin >> eps;
    cout << endl;

    x = findX(a, b, eps, deep);

    cout << "x: " << x << endl;
    cout << "Deep: " << deep << endl;
}

double findX(double a, double b, double eps, int& deep)
{
    double m, f1, f2;

    deep += 1;

    f1 = f(a);
    m = (a + b) / 2;
    f2 = f(m);

    if (abs(a - b) / 2 >= eps && f2 != 0) {
        if (f1 * f2 < 0)
            b = m; // відкидаємо праву частину
        else
            a = m; // відкидаємо ліву частину

        return findX(a, b, eps, deep);
    }
    else
    {
        return m;
    }
}

double f(double x)
{
    return sin(x) - cos(x);
}