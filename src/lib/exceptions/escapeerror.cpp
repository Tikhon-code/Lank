void EscapeError(std::string code, int count_chars, char escape_char) {
    std::cerr << code << "\n";
    for (int pos = 0; pos <= count_chars; pos++) {
        if (pos == count_chars) {
            std::cerr << " ^^";
        }
        else {
            std::cerr << " ";
        }
    }
    std::cerr << "\nEscapeError (Invalid escape): \\" << escape_char << "\n";
}