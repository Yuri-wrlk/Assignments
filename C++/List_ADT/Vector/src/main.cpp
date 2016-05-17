#include <iostream>

#include "vector.hpp"

int main() {
    Vector<int> v(10);
    std::cout << v.size() << std::endl;

    return EXIT_SUCCESS;
}
