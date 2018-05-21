#include "CCmd.h"

CCmd::CCmd() {
}

CCmd::~CCmd() {

}

std::string CCmd::output(const char* cmd) {

	char buffer[128];
	std::string output = "";
	FILE* pipe = _popen(cmd, "r");

	if (!pipe) throw std::runtime_error("popen() failed!");
	try {
		while (!feof(pipe)) {
			if (fgets(buffer, 128, pipe) != NULL)
				output += buffer;
		}
	}
	catch (...) {
		_pclose(pipe);
		throw;
	}
	_pclose(pipe);
	return output;
}

void CCmd::modify() {
	str = ReplaceAll(this->str, "\\", "\\\\");
	str = ReplaceAll(this->str, "\n", "");
	str = "\"" + str + "\" -lodfull";
}

std::string CCmd::ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}