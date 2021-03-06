#include "GW_launcher_header.h"
#include "CCmd.h"

int main() {
	LoadIcon(NULL, (LPCWSTR)"Guild Wars.ico");
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);

	if (system(NULL)) {
		CCmd cmd;

		cmd.str = cmd.output("where -r \"C:\\Program Files (x86)\" Gw.exe");
		if (cmd.str != "") {
			cmd.modify();
			system(cmd.str.c_str());

			return 0;
		}
		else {
			MessageBox(NULL, (LPCWSTR)L"Guild Wars was not found on your computer.\nPlease check if you have it installed in the following directory:\nC:\\Program Files (x86)\\\nand its exe file is named Gw.exe",
				(LPCWSTR)L"Guild Wars Launcher",
				MB_OK | MB_ICONERROR);

			return 0;
		}
	}
	else {
		MessageBox(NULL, (LPCWSTR)L"Something went wrong.\nGuild Wars Launcher cannot gain acces to the command line in your computer.\nTry run it as an administrator.",
			(LPCWSTR)L"Guild Wars Launcher",
			MB_OK | MB_ICONERROR);

		return 0;
	}
}