#include "lank.cpp"

int main(int argc, char **argv) {
    if (argc == 3) {
        if ((std::string)argv[1] == "-s") {
            std::string code = argv[2];
            run_string(code);
        }
    } 
    else if (argc == 2) {
        script_mode(argv[1]);
    }
    else {
        live_mode();
    }
    return 0;
}