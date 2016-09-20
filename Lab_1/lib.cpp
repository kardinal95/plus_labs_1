#include <iostream>
#include "lib.h"

double find_exact(double x) {
	/*
	Возвращает точное значение функции для заданного х
	*/
	return 2 * (pow(cos(x), 2) - 1);
}

double find_seq_member(double x, int n) {
	/*
	Возвращает n-ный член степенного ряда для данного x
	*/
	double res = pow(-1, n) * (pow((2 * x), (2 * n)) / fact(2 * n));
	return res;
}

double fact(int inp) {
	/*
	Возвращает факториал для данного inp
	*/
	double res = 1.0;
	for (int i = inp; i > 0; i--) {
		res *= i;
	}
	return res;
}

double calc_by_n(double x, int n) {
	/*
	Возвращает значение суммы степенного ряда длиной n для данного x
	*/
	double res = 0.0;                 // для нулевой длины - возвращаем ноль
	for (int i = 1; i <= n; i++) {
		res += find_seq_member(x, i); // прибавляем последовательно члены последовательности
	}
	return res;
}

double calc_by_e(double x) {
	/*
	Возвращает значение суммы степенного ряда для данного x с точностью 0.0001
	*/
	const double E = 0.0001;         // требуемая точность
	int current_n = 1;               // текущая длина последовательности
	double res = 0.0;
	double current_mem;              // текущий член последовательности
	do {
		current_mem = find_seq_member(x, current_n);
		res += current_mem;          // прибавляем последовательно члены последовательности
		current_n++;                 // увеличиваем текущую длину
	} while (abs(current_mem) >= E); // пока член последовательности не достигнет точности
	return res;
}