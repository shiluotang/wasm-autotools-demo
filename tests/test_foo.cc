#include <cstdlib>
#include <iostream>
#include <foo.h>

void test_foo() {
    foo();
}

#ifdef __EMSCRIPTEN__
int main() try {
#else
int main(int argc, char* argv[]) try {
#endif
    test_foo();
    return EXIT_SUCCESS;
} catch (std::exception const &e) {
    std::cerr << "[c++ exception] " << e.what() << std::endl;
    return EXIT_FAILURE;
} catch (...) {
    std::cerr << "[c++ exception] " << "<UNKNOWN CAUSE>" << std::endl;
    return EXIT_FAILURE;
}
