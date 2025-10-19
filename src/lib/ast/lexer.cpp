#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "../exceptions/escapeerror.cpp"
#include "../utils/utils.cpp"

std::vector<std::string> split(std::string code) {
    std::string current = "";
    std::vector<std::string> all = {};
    std::vector<char> literals = {'(', ')', ',', '<', '>', '[', ']', '{', '}', '=', '+', '-', ';'};
    

    bool string = false;
    bool comment = false;

    char quote_char = '\0';

    bool escape = false;

    int count_chars = 0;

    for (char c : code) {
        count_chars++;
        if (c == '#') {
            comment = true;
            continue;
        }
        

        if (c == '\\') {
            escape = true;
            continue;
        }

        if (comment && escape && c == 'n') {
            comment = false;
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
            else if (c == '\"') {
                current += "\"";
            }
            else if (c == 'b'){
                current += "\b";
            }
            else {
                count_chars -= 3;
                EscapeError(code, count_chars, c);
                return {""};
            }
            continue;
        }

        if (comment) {
            continue;
        }


        if ((c == '"' || c == '\'') && !string) {
            string = true;
            quote_char = c;
            current += quote_char;
            continue;
        }

        if (c == quote_char && string) {
            string = false;
            
            if (!current.empty()) {
                current += quote_char;
                all.push_back(current);
                current.clear();
            }
            quote_char = '\0';
            continue;
        }

        if ((std::find(literals.begin(), literals.end(), c) != literals.end()) && !string) {
            if (!current.empty()) {
                all.push_back(current);
                current.clear();
            }
            all.emplace_back(1, c);
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
        
    }

    if (string) {
        std::cout << "ERROR! two time quote not found!\n";
    }

    if (!current.empty()) {
        all.push_back(current);
    }

    return all;
}

std::vector<std::vector<std::string>> tokenize(std::vector<std::string> splitted) {
    std::vector<std::vector<std::string>> lexed; 

    for (std::string elem : splitted) {
        if (elem == "(") lexed.push_back({elem, "LPAREN"});
        else if (is_int(elem)) lexed.push_back({elem, "INT"});
        else if (elem == ")") lexed.push_back({elem, "RPAREN"});
        else if (elem == ",") lexed.push_back({elem, "COMMA"});
        else if (elem == ".") lexed.push_back({elem, "DOT"});
        else if (elem == "<") lexed.push_back({elem, "LESS"});
        else if (elem == ">") lexed.push_back({elem, "GREATER"});
        else if (elem == "[") lexed.push_back({elem, "LBRACKET"});
        else if (elem == "]") lexed.push_back({elem, "RBRACKET"});
        else if (elem == "{") lexed.push_back({elem, "LBRACE"});
        else if (elem == "}") lexed.push_back({elem, "RBRACE"});
        else if (elem == "=") lexed.push_back({elem, "EQUAL"});
        else if (elem == "+") lexed.push_back({elem, "PLUS"});
        else if (elem == "-") lexed.push_back({elem, "MINUS"});
        else if ((elem.front() == '"' && elem.back() == '"') || (elem.front() == '\'') && elem.back() == '\'') lexed.push_back({elem, "STRING"});
        else lexed.push_back({elem, "ID"});
    }
    return lexed;
}