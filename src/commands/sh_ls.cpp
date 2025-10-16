#include <filesystem>

#include "../lib/exceptions/dirnotfound.cpp"

std::string sh_ls(std::vector<std::string> cmd) {
    std::string path;
    std::filesystem::directory_iterator iterator;
    if (cmd.size() >= 2) {
        path = cmd[1];
    }
    else {
        path = ".";
    }

    try {
        iterator = std::filesystem::directory_iterator(path);
    } catch (const std::filesystem::filesystem_error& err) {
        DirNotFound(path);
        return "1";
    }

    for (const auto & entry : iterator) {
        
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