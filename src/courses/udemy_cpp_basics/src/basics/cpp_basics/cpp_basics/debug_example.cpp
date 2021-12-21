#include <iostream>

int main() {
	int sum = 0;
	int A[] = { 2,3,4,5,6 };
	for (int i = 0; i <= 4; i++) {
		sum += A[i];
		std::cout << sum << std::endl;
	}
}