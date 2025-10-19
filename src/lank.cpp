#include <iostream>

#include <fstream>

#include "lib/ast/lexer.cpp"

void live_mode(std::string prompt);
void script_mode(std::string script);
std::string run_string(std::string code);

#include "commands/init.cpp"

void live_mode(std::string prompt = "Lank (unstable 0.0.1)>> ") {
    while (true) {
        std::string cmd;
        std::string ret = "";
        std::cout << prompt;
    
        std::cin.clear();

        std::getline(std::cin, cmd);

        if (cmd.empty()) {
            continue;
        }

        ret = run_string(cmd);

        if (ret == "exit") break;
    }
}

void script_mode(std::string script) {
    std::ifstream input(script);
    std::string line;

    std::string ret = "";

    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }
        ret = run_string(line);

        if (ret == "exit") break;
    }
}

std::string run_string(std::string code) {
    std::vector<std::string> lexed_code = split(code);
    std::vector<std::string> collected = {};

    std::string ret = "";

    for (std::string elem : lexed_code) {
        if (elem == ";") {
            ret = exec(collected);
            collected.clear();

            if (ret == "exit") {
                return ret;
            }

        }
        else {
            collected.push_back(elem);
        }
    }
    
    if (!collected.empty()) {
        ret = exec(collected);
    }

    return ret;
}
