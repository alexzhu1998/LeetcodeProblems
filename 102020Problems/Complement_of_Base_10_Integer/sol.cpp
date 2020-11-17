#include <iostream>
#include <cmath>

int main () {
    int num = 10;
    // left bit shift on -1 by however many units log base 2 +1 of the number
    int l = std::log(num)/std::log(2)+1;
    // 00000111 11111000 00000000
    // 00000101 11111000 11111010
    std::cout<< (((unsigned)(-1) << l)^(~num)) << std::endl;
    // std::cout << l << std::endl;
    // std::cout << num << std::endl;
    return 0;
}