#include <iostream>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "pt_BR");

	// std::cout << "Olá, Mundo" << std::endl;
	for (int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}

	getchar();

	return 0;
}