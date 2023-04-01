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

		void Parse(int agrc, char* argv[]) {

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