#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Задание 1: ((a+b)^4 - (a^4 + 4a^3 b + 6a^2 b^2)) / (4ab^3 + b^4)
template <class T>
void calc(T a, T b)
{
    T s4  = pow(a + b, 4);      // (a+b)^4
    T a4  = pow(a, 4);          // a^4
    T c   = 4 * pow(a, 3) * b;  // 4a^3 b
    T d   = 6 * a * a * b * b;  // 6a^2 b^2
    T num = s4 - (a4 + c + d);  // числитель
    T e   = 4 * a * pow(b, 3);  // 4ab^3
    T f   = pow(b, 4);          // b^4
    T den = e + f;              // знаменатель
    cout << setprecision(15);
    cout << "(a+b)^4 = " << s4 << "\na^4 = " << a4 << "\n4a^3b = " << c
         << "\n6a^2b^2 = " << d << "\nчислитель = " << num
         << "\nзнаменатель = " << den << "\nрезультат = " << num / den << endl;
}

int main()
{
    cout << "=== Задание 1 (float) ===\n";
    calc<float>(100.0f, 0.001f);
    cout << "\n=== Задание 1 (double) ===\n";
    calc<double>(100.0, 0.001);

    cout << "\n=== Задание 2 ===\n";
    int m, n, r;
    cout << "Введите m и n: ";
    cin >> m >> n;
    int m0 = m, n0 = n;

    r = - -m - ++n;
    cout << "1) - -m-++n  = " << r << "  (m=" << m << ", n=" << n << ")\n";

    m = m0; n = n0;
    r = m * n < n++;
    cout << "2) m*n<n++   = " << r << "  (m=" << m << ", n=" << n << ")\n";

    m = m0; n = n0;
    r = n-- > m++;
    cout << "3) n-- > m++ = " << r << "  (m=" << m << ", n=" << n << ")\n";
    return 0;
}
