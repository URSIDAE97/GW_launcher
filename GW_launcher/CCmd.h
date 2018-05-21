#pragma once
#include "GW_launcher_header.h"

class CCmd {

public:
	std::string str;

	CCmd();
	~CCmd();
	std::string output(const char* cmd);
	void modify();

private:
	std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
};