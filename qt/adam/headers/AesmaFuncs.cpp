//
// Created by aesma on 11.04.19.
//

#include "AesmaFuncs.h"
#include <thread>

std::string AesmaFuncs::bytes_to_hex(const char* bytes, const int &len) {
    using namespace std;
    string result = "";
    char* hex = new char[4] {' ', ' ', ' ', ' '};
    for (int i = 0; i < len; ++i) {
        sprintf(hex, "0x%02X", bytes[i]);
        result.append(hex);
        result.append(" ");
    }
    return result;
}
std::vector<std::string> AesmaFuncs::split_string(const std::string &source, const std::string &delimiter) {
	using namespace std;
	vector<std::string> result;
	thread th([&]() {
		string temp = source;
		string sub;
		int pos = 0;
		while ((pos = temp.find(delimiter)) != string::npos) {
			try {
				sub = temp.substr(0, pos);
				result.push_back(sub);
				temp.erase(0, pos + delimiter.length());
			} catch (int ex) {
				break;
			}
		}
		result.push_back(temp);
	});
	th.join();

	return result;
}
