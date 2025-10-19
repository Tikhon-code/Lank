#include "../src/lank.cpp"

int main() {
    std::string test_string = "echo 'files in dir:'; ls";
    run_string(test_string);
    return 0;
}