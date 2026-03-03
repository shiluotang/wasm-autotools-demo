#include <cstdlib>
#include <iostream>
#include <fstream>

// #include <gtest/gtest.h>

void test_ifstream() {
    std::string const filename = "a.txt";
    std::ifstream infile(filename.c_str());
    if (!infile)
        throw std::runtime_error("file i/o failed!");
    std::string sep(20, '=');
    std::cout << sep << " " << filename << " " << sep << std::endl;
    std::cout << infile.rdbuf() << std::endl;
}

#ifdef __EMSCRIPTEN__
extern "C"
#endif
int main(int argc, char* argv[]) try {
    test_ifstream();
    return EXIT_SUCCESS;
} catch (std::exception const &e) {
    std::cerr << "[c++ exception] " << e.what() << std::endl;
    return EXIT_FAILURE;
} catch (...) {
    std::cerr << "[c++ exception] " << "<UNKNOWN CAUSE>" << std::endl;
    return EXIT_FAILURE;
}

