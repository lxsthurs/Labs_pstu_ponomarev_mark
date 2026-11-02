#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Вариант 19: a_n = n/(n-1)^2, n = 2,3,... ; eps = 1e-4
// Рекуррентная формула: a_{n+1}/a_n = (n+1)(n-1)^2 / (n * n^2)
int main()
{
    const double eps = 1e-4;
    int n = 2;
    double a = 2.0;            // a_2 = 2/1^2
    double s = 0;
    while (a >= eps)           // точность достигнута, если a_n < eps
    {
        s += a;
        a *= (n + 1.0) * (n - 1.0) * (n - 1.0) / ((double)n * n * n);
        n++;
    }
    cout << "Сумма ряда с точностью eps=" << eps << ": S = "
         << setprecision(10) << s << "\nЧисло слагаемых: " << n - 2
         << "\nПоследний член a_n = " << a << " (n=" << n << ")\n";
    // проверка по общей формуле
    double c = 0;
    for (int k = 2; k < n; k++) c += k / pow(k - 1.0, 2);
    cout << "Контроль по общей формуле: " << c << endl;
    return 0;
}
