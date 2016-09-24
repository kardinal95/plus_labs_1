#include <iostream>
#include "lib.h"

using namespace std;

/*
Вычисляет и выводит последовательно:
Текущее значение х, сумму степенного ряда для данной длины,
сумму степенного ряда для требуемой точности, точное значение функции
Выводит по строкам, для каждого х с требуемым шагом
*/
void main()
{
	double a = 0.1;
	double b = 1.0;
	int n = 15;
	double step = (b - a) / 10;

	for (double x = a; x <= b; x += step)                          // перебираем х от а до b с требуемым шагом
	{
		double exact = find_exact(x);                              // вычисляем точное значение
		double sum_n = calc_by_n(x, n);                            // вычисляем сумму по n
		double sum_e = calc_by_e(x, 0.0001);                       // вычисляем сумму по точности (0.0001)
		printf("X=%f SN=%f SE=%f Y=%f\n", x, sum_n, sum_e, exact); // выводим значения для текущего х
	}
	system("PAUSE");
}