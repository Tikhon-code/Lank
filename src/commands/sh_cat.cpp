std::string sh_cat(std::vector<std::string> cmd) {
    std::ifstream file(cmd[1]);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }

    return "0";
}