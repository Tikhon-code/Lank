#include <iostream>

std::string sh_echo(std::vector<std::string> cmd) {
    for (size_t i = 1; i < cmd.size(); i++) {
        std::cout << cmd[i] << " ";
    }
    std::cout << "\n";
    return "0";
}