#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Вариант 19: y = exp(2x), 0.1<=x<=1, n=20
// S = 1 + 2x/1! + ... + (2x)^n/n!;  a_{k+1} = a_k * 2x/(k+1)
int main()
{
    const int N = 20, K = 10;
    const double A = 0.1, B = 1.0, eps = 1e-4;
    double h = (B - A) / K;
    cout << "\t\tВычисление функции y = exp(2x)\n";
    cout << fixed << setprecision(6);
    for (int i = 0; i <= K; i++)
    {
        double x = A + i * h;
        // а) арифметический цикл, заданное n
        double a = 1, sn = 1;
        for (int k = 1; k <= N; k++) { a *= 2 * x / k; sn += a; }
        // б) итерационный цикл, заданная точность
        double se = 1; a = 1; int k = 0;
        do { k++; a *= 2 * x / k; se += a; } while (fabs(a) >= eps);
        double y = exp(2 * x);
        cout << "X=" << x << "\tSN=" << sn << "\tSE=" << se << "\tY=" << y
             << "\t(членов для eps: " << k + 1 << ")\n";
    }
    return 0;
}
