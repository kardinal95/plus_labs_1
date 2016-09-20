#include <iostream>

using namespace std;

double fact(int);
double calc_by_n(double, int);
double calc_by_e(double);
double find_seq_member(double, double);

void main() {
	/*
	Вычисляет и выводит последовательно:
	Текущее значение х, сумму степенного ряда для данной длины,
	сумму степенного ряда для требуемой точности, точное значение функции
	Выводит по строкам, для каждого х с требуемым шагом
	*/
	double a = 0.1;
	double b = 1.0;
	int n = 15;
	double step = (b - a) / 10;
	for (double x = a; x <= b; x += step) { // перебираем х от а до b с требуемым шагом
		double res = 2 * (pow(cos(x), 2) - 1); // вычисляем точное значение
		double sum_n = calc_by_n(x, n); // вычисляем сумму по n
		double sum_e = calc_by_e(x); // вычисляем сумму по точности
		printf("X=%f SN=%f SE=%f Y=%f\n", x, sum_n, sum_e, res); // выводим значения для текущего х
	}
	system("PAUSE");
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
	double res = 0.0; // для нулевой длины - возвращаем ноль
	for (int i = 1; i <= n; i++) {
		res += find_seq_member(x, i); // прибавляем последовательно члены последовательности
	}
	return res;
}

double calc_by_e(double x) {
	/*
	Возвращает значение суммы степенного ряда для данного x с точностью 0.0001
	*/
	const double E = 0.0001; // требуемая точность
	int current_n = 1; // текущая длина последовательности
	double res = 0.0;
	double current_mem; // текущий член последовательности
	do {
		current_mem = find_seq_member(x, current_n);
		res += current_mem; // прибавляем последовательно члены последовательности
		current_n++; // увеличиваем текущую длину
	} while (abs(current_mem) >= E); // пока член последовательности не достигнет точности
	return res;
}