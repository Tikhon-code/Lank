#include <filesystem>
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
        std::cerr << "Directory not found: " << path << "\n";
        return "1";
    }
    return "0";
}