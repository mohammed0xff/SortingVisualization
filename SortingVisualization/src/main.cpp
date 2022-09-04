#include "program.hpp"


int main(int argc, char** argv) {
    Program p;
    if (p.init()) {
        p.run();
    }
    return 0;
}
