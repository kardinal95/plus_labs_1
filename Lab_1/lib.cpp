#include <iostream>
#include "lib.h"

/*
Возвращает точное значение заданной функции y=2*((cosx)^2-1)
x - параметр функции; любое число
*/
double find_exact(double x)
{
	return 2 * (pow(cos(x), 2) - 1);
}

/*
Возвращает n-ный член заданного степенного ряда (для формулы y=2*((cosx)^2-1)) для данного x
n - порядковый номер искомого члена последовательности; целое число больше нуля
x - параметр функции; любое число
*/
double find_seq_member(double x, int n)
{
	double result = pow(-1, n) * (pow((2 * x), (2 * n)) / fact(2 * n));
	return result;
}

/*
Возвращает факториал для числа
num - число, для которого ищется факториал; целое число больше нуля
*/
double fact(int num)
{
	double result = 1.0;
	for (int i = num; i > 0; i--)
	{
		result *= i;
	}
	return result;
}

/*
Возвращает значение суммы заданного степенного ряда длиной n для данного x
n - длина искомого степенного ряда; целое число
x - параметр функции; любое число
*/
double calc_by_n(double x, int n)
{
	double result = 0.0;                 // для нулевой длины - возвращаем ноль
	for (int i = 1; i <= n; i++)
	{
		result += find_seq_member(x, i); // прибавляем последовательно члены последовательности
	}
	return result;
}

/*
Возвращает значение суммы степенного ряда для данного x с искомой точностью accuracy
accuracy - необходимая точность; положительное число
x - параметр функции; любое число
*/
double calc_by_e(double x, double accuracy)
{
	int current_n = 1;                   // текущая длина последовательности
	double result = 0.0;
	double current;                      // текущий член последовательности
	do
	{
		current = find_seq_member(x, current_n);
		result += current;               // прибавляем последовательно члены последовательности
		current_n++;                     // увеличиваем текущую длину
	} while (abs(current) >= accuracy);  // пока член последовательности не достигнет точности
	return result;
}