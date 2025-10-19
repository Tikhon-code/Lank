#include <filesystem>

std::string sh_path() {
    std::cout << std::filesystem::current_path() << "\n";
    return "0";
}