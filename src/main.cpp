#include <iostream>

#include <fstream>

#include "lib/lexer.cpp"
#include "commands/init.cpp"

void live_mode(std::string prompt = ">>> ") {
    while (true) {
        std::string cmd;
        std::cout << prompt;
        std::getline(std::cin, cmd);
    
        if (cmd.empty()) {
            continue;
        }

        std::vector<std::string> lexed_cmd = split(cmd);
    
        std::string ret = exec(lexed_cmd);
    }
}

void script_mode(std::string script) {
    std::ifstream input(script);
    std::string line;

    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }
        std::vector<std::string> lexed_line = split(line);
        std::string ret = exec(lexed_line);
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        script_mode(argv[1]);
    } else {
        live_mode();
    }
    return 0;
}