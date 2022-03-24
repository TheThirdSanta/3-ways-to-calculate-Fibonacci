#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;

struct matrix{long m[2][2];};
matrix A = { 1,1,1,0 };

matrix one(matrix a, matrix b) {
	matrix c;
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			c.m[i][j] = 0;
			for (k = 0; k <= 1; k++) {
				c.m[i][j] += a.m[i][k] * b.m[k][j];
			}
		}
	}
	return c;
}

matrix fib(matrix A, int n) {
	matrix q, w;
	w = { 1,0,0,1 };
	q = w;
	if (n == 0) return q;
	else if (n == 1) return A;
	else if (n % 2 == 0) return one(fib(A, n / 2), fib(A, n / 2));
	else return one(one(fib(A, (n - 1) / 2), fib(A, (n - 1) / 2)), A);
}

int main() {
	auto start1 = high_resolution_clock::now();
	for (int i = 1; i <= 10; i++) {
		fib(A,i);
	}
	auto end1 = high_resolution_clock::now();
	duration<double,milli> runtime1{ end1 - start1 };
	cout << runtime1.count() <<"ms" << endl;

	auto start2 = high_resolution_clock::now();
	for (int i = 1; i <= 20; i++) {
		fib(A,i);
	}
	auto end2 = high_resolution_clock::now();
	duration<double, milli> runtime2{ end2 - start2 };
	cout << runtime2.count() << "ms" << endl;

	auto start3 = high_resolution_clock::now();
	for (int i = 1; i <= 30; i++) {
		fib(A,i);
	}
	auto end3 = high_resolution_clock::now();
	duration<double, milli> runtime3{ end3 - start3 };
	cout << runtime3.count() << "ms" << endl;

	auto start4 = high_resolution_clock::now();
	for (int i = 1; i <= 40; i++) {
		fib(A,i);
	}
	auto end4 = high_resolution_clock::now();
	duration<double, milli> runtime4{ end4 - start4 };
	cout << runtime4.count() << "ms" << endl;

	auto start5 = high_resolution_clock::now();
	for (int i = 1; i <= 50; i++) {
		fib(A,i);
	}
	auto end5 = high_resolution_clock::now();
	duration<double, milli> runtime5{ end5 - start5 };
	cout << runtime5.count() << "ms" << endl;
	return 0;
}