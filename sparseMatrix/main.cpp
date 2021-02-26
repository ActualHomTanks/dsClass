#include <iostream>
#include <stack>
#include "sparseMatrix.hpp"

void readKey(spm* a)
{
	spm a1;
	int key;
	std::cout << "Enter element to check: ";
	std::cin >> key;

	if (a1.search(a, key)) {
		std::cout << "true" << '\n';
	}
	else {
		std::cout << "false" << '\n';
	}

	return;
}

int main()
{
	spm a1, a[maximum], b[maximum]; //maximum defined in sparseMatrix.hpp
	int meth;

	a1.read(a);
	a1.display(a);
	a1.displayMatrix(a);

	std::cout << "1. Transpose  2. FastTranspose  3. Exit" << '\n';
	std::cin >> meth;

	switch (meth) {
	case 1: {
		a1.transpose(a, b);
		a1.display(b);
		a1.displayMatrix(b);
		break;
	}
	case 2: {
		a1.fastTranspose(a, b);
		a1.display(b);
		a1.displayMatrix(b);
		break;
	}
	case 3: {
		return EXIT_SUCCESS;
	}
	}

	return 0;
}