#include <iostream>
#include <iomanip>

class ArgumentParser {
	public:
		void RegisterFlag(const std::string& flag) {

		}

		bool GetFlag(const std::string& flag) {

			return 0;
		}

		void Parse(int agrc, char* argv[]) {

		}

	private:
};

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "pt_BR");

	ArgumentParser argParser;
	argParser.RegisterFlag("rename");
	argParser.RegisterFlag("convert");
	argParser.RegisterFlag("resize");
	argParser.RegisterFlag("scale");

	argParser.Parse(argc, argv);

	std::cout << std::boolalpha << "Rename : " << argParser.GetFlag("rename") << std::endl;
	std::cout << "Convert : " << argParser.GetFlag("convert") << std::endl;
	std::cout << "Resize : " << argParser.GetFlag("resize") << std::endl;
	std::cout << "Scale : " << argParser.GetFlag("scale") << std::endl;


	getchar();

	return 0;
}