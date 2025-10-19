#include <filesystem>

#include "../lib/exceptions/exceptions.h"

std::string sh_cd(std::vector<std::string> cmd) {
    std::string path;
    if (cmd.size() >= 2) {
        path = cmd[1];
    }
    else {
        path = "/";
    }
    try {
        std::filesystem::current_path(path);
    } catch (const std::filesystem::filesystem_error& err) {
        DirNotFound(path);
        return "1";
    }
    return "0";
}