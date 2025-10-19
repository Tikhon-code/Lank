#include <iostream>
#include <fstream>

#include "sh_echo.cpp"
#include "sh_ls.cpp"
#include "sh_cd.cpp"
#include "sh_cat.cpp"
#include "sh_clear.cpp"
#include "sh_path.cpp"

std::string exec(std::vector<std::string> cmd) {
    if (cmd.size() == 0) {
        return "";
    }

    if (cmd.empty()) {
        return "";
    }

    if (cmd[0] == "exit") return "exit";
    if (cmd[0] == "echo") return sh_echo(cmd);
    else if (cmd[0] == "ls") return sh_ls(cmd);
    else if (cmd[0] == "cd") return sh_cd(cmd);
    else if (cmd[0] == "cat") return sh_cat(cmd);
    else if (cmd[0] == "clear") return sh_clear();
    else if (cmd[0] == "path") return sh_path();
    else if (cmd[0] == "run") script_mode(cmd[1]);
    else {
        if (!cmd[0].empty()) {
            std::cerr << "Lank: Command '" << cmd[0] << "' not found.\n";
        }
    }
    return "";
}