#include <iostream>
#include "sparseMatrix.hpp"

void spm::read(spm* a)
{
	int count = 1;
	int m, n;
	int element;

	std::cout << "Enter order: ";
	std::cin >> m >> n;

	std::cout << "Enter Elements: "; //outside for loop because you can input the entire matrix at once
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> element;

			if (element == 0) {
				continue;
			}

			a[count].v = element;
			a[count].r = i;
			a[count].c = j;
			count++;
		}
	}

	a[0].r = m;
	a[0].c = n;
	a[0].v = count - 1;

	return;
}

bool spm::search(spm* a, int key)
{
	for (int i = 1; i <= a[0].v; i++) {
		if (key == a[i].v) {
			return true;
		}
	}
	return false;
}

void spm::display(spm* a)
{
	std::cout << "| r | c | v |" << '\n';
	std::cout << "| " << a[0].r << " | " << a[0].c << " | " << a[0].v << " |" << '\n';
	std::cout << "*************" << '\n';

	for (int i = 1; i <= a[0].v; i++) {
		std::cout << "| " << a[i].r << " | " << a[i].c << " | " << a[i].v << " |" << '\n';
	}
}

void spm::displayMatrix(spm* a)
{
	int count = 1;

	std::cout << "2-D Display: " << '\n';

	for (int i = 0; i < a[0].r; i++) {
		for (int j = 0; j < a[0].c; j++) {
			if (i == a[count].r && j == a[count].c) {
				std::cout << a[count++].v;
			}
			else {
				std::cout << "0";
			}
		}
		std::cout << '\n';
	}

	return;
}


void spm::transpose(spm* a, spm* b)
{
	int count = 1;

	b[0].r = a[0].c;
	b[0].c = a[0].r;
	b[0].v = a[0].v;

	for (int i = 0; i < a[0].c; i++) {
		for (int j = 1; j <= a[0].v; j++) {
			if (a[j].c == i) {
				b[count].r = a[j].c;
				b[count].c = a[j].r;
				b[count].v = a[j].v;

				count++;
			}
		}
	}
	return;
}

void spm::fastTranspose(spm* a, spm* b)
{

	//frequency count of column values
	int r[maximum] = { 0 };

	for (int i = 1; i < a[0].v; i++) {
		r[a[i].c]++;
	}

	//prints out values inside r
	// std::cout << "r: " << '\n';
	// for (int i = 0; i < a[0].c; i++) {
	//   std::cout << r[i];
	// }
	// std::cout << '\n';

	//starting positions of transpose elements
	int s[maximum];
	s[0] = 1;

	for (int i = 1; i < a[0].c; i++) {
		s[i] = s[i - 1] + r[i - 1];
	}

	// prints values inside s
	// std::cout << "s: " << s[0];
	// for (int i = 1; i < a[0].c; i++) {
	//   std::cout << s[i];
	// }
	// std::cout << '\n';

	//transposing loop
	b[0].r = a[0].c;
	b[0].c = a[0].r;
	b[0].v = a[0].v;

	int j;
	for (int i = 1; i <= a[0].v; i++) {
		j = s[a[i].c]++;

		b[j].r = a[i].c;
		b[j].c = a[i].r;
		b[j].v = a[i].v;
	}

	return;
}