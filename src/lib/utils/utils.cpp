#include <cctype>

bool is_int(std::string num) {
    for (int pos = 0; pos < num.length(); pos++) {
        if (!isdigit(num[pos])) return false;
    }
    return true;
}