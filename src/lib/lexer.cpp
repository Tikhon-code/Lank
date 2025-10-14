#include <string>
#include <vector>
#include <iostream>

#include "exceptions/escapeerror.cpp"

std::vector<std::string> split(std::string code) {
    std::string current;
    std::vector<std::string> all;
    
    bool string = false;
    char quote_char = '\0';

    bool escape = false;

    int count_chars = 0;

    for (char c : code) {
        if (c == '\\') {
            escape = true;
            continue;
        }

        if (escape) {
            escape = false;
            if (c == 'n') {
                current += "\n";
            }
            else if (c == 't') {
                current += "\t";
            }
            else if (c == 'r') {
                current += "\r";
            }
            else if (c == '\'') {
                current += "\'";
            }
            else if (c == 'b'){
                current += "\b";
            }
            else {
                EscapeError(code, count_chars, c);
            }
            continue;
        }

        if ((c == '"' || c == '\'') && !string) {
            string = true;
            quote_char = c;
            continue;
        }

        if (c == quote_char && string) {
            string = false;
            quote_char = '\0';
            if (!current.empty()) {
                all.push_back(current);
                current.clear();
            }
            continue;
        }

        if (isspace(c) && !string) {
            if (!current.empty()) {
                all.push_back(current);
                current.clear();
            }
            continue;
        }
        current += c;
        count_chars++;
    }

    if (string) {
        std::cout << "ERROR! two time quote not found!\n";
    }

    if (!current.empty()) {
        all.push_back(current);
    }

    return all;
}