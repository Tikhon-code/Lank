#include "exceptions.h"

void DirNotFound(std::string dir) {
    std::cerr << "Directory not found: " << dir << "\n";
}