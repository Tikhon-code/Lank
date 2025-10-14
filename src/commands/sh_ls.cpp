#include <filesystem>

std::string sh_ls(std::vector<std::string> cmd) {
    std::string path;
    if (cmd.size() >= 2) {
        path = cmd[1];
    }
    else {
        path = ".";
    }

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        
        if (std::filesystem::is_directory(entry.path())) {
            std::cout << "[DIR]\t";
        }
        else {
            std::cout << "[FILE]\t";
        }
        std::cout << entry.path() << "\n";
    }
    return "0";
}