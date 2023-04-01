#include <iostream>
#include <iomanip>
#include <map>

class ArgumentParser {
	public:
		void RegisterFlag(const std::string& flag) {
			if (!flag.empty()) {
				m_Flags[flag] = false;
			}
		}

		bool GetFlag(const std::string& flag) const {
			if (!flag.empty()) {
				auto flagIt{ m_Flags.find(flag) };
				if (flagIt != std::end(m_Flags)) {
					return flagIt->second;
				}
			}


			return false;
		}

		void Parse(int argc, char* argv[]) {
			if (argc > 1) {
				for (int i = 1; i < argc; ++i) {
					std::string arg = argv[i];

					if (arg.length() >= 3) {
						// Argumentos tem que ter pelo menos 3 caracteres
						// os "--" iniciais e pelo menos um terceiro carater
						if (arg[0] == '-' && arg[1] == '-') {
							// Primeiro vamos remover os "--" iniciasi
							arg = arg.substr(2);
							if (arg.find_first_of('=') != std::string::npos) {

							}
							else {
								auto flagIt = m_Flags.find(arg);
								if (flagIt != std::end(m_Flags)) {
									flagIt->second = true;
								}
							}
						}
					}
				}
			}
		}

	private:
		std::map<std::string, bool> m_Flags;
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


	return 0;
}