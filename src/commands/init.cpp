#include <iostream>

#include "sh_echo.cpp"
#include "sh_ls.cpp"
#include "sh_cd.cpp"

std::string exec(std::vector<std::string> cmd) {
    if (cmd[0] == "echo") {
        return sh_echo(cmd);
    }
    else if (cmd[0] == "ls") {
        return sh_ls(cmd);
    }
    else if (cmd[0] == "cd") {
        return sh_cd(cmd);
    }
    else {
        std::cerr << "Command '" << cmd[0] << "' not found.\n";
    }
    return "";
}