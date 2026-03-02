#include <cstdlib>
#include <iostream>
#include <fstream>

// #include <gtest/gtest.h>

void test_ifstream() {
    std::string const filename = "a.txt";
    std::ifstream infile(filename.c_str());
    if (!infile)
        throw std::runtime_error("file i/o failed!");
}

#ifdef __EMSCRIPTEN__
int main() try {
#else
int main(int argc, char* argv[]) try {
#endif
    test_ifstream();
    return EXIT_SUCCESS;
} catch (std::exception const &e) {
    std::cerr << "[c++ exception] " << e.what() << std::endl;
    return EXIT_FAILURE;
} catch (...) {
    std::cerr << "[c++ exception] " << "<UNKNOWN CAUSE>" << std::endl;
    return EXIT_FAILURE;
}

