#include <iostream>
#include <string>

#include <cstdlib>

int compile(std::string target) {
    int ret = 0;

    #ifdef _WIN32
        std::cout << "Compiling for win...\n";
    #else
        ret = system("\
            sh_interp=$(which sh) \n\
            if [[ $? == 0 ]]; then \n\
                $sh_interp ./build.sh \n\
            else \n\
                printf 'shell interpreter not found' \n\
            fi \n\
        ");
    #endif
    return ret;
}

void build() {
    std::string target = "src/lank.cpp";

    compile(target);
}

int main() {
    build();
    return 0;
}