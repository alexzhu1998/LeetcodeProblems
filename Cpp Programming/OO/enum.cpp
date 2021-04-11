#include <iostream>

// issues with redeclaration
// enum Clothes { shirt, cap, dress };
// enum Pen { cap, body, ink };

enum nonClassColors {
    red = 0x00FF00,
    green,
    blue
};
enum class ClassColors {
    red = 'a',
    green = 0x00FF00,
    blue = 0x0000FF
};
enum asdf : char {
    a1 = 'C', b1,c1
};

int main () {
    std::cout << red << '\n';
    std::cout << (int)ClassColors::red;
    std::cout << '\n' << b1;
    return 0;
}