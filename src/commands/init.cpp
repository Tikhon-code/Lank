#include <iostream>

#include "sh_echo.cpp"

std::string exec(std::vector<std::string> cmd) {
    if (cmd[0] == "echo") {
        return sh_echo(cmd);
    }
    else {
        std::cout << "Command '" << cmd[0] << "' not found.\n";
    }
    return "";
}