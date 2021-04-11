#include <iostream>
#include <string>
using namespace std;

struct Cat {
    int hair_length;
    string hair_color;
    int fatness = 5;

    struct Ringworm {
        int fatness;
    }
};

int main() {
    Cat purrple{ 8, "Black and White", 5 };
    Cat meowzer = { 5, "Calico", 3 };

    cout << purrple.hair_color << endl;
    cout << meowzer.hair_length << endl;
    purrple.hair_length = 10;
    meowzer = { 6, "calico", 7 };
    cout << meowzer.hair_length << endl;

    Cat::Ringworm r{ 1 };
    cout << r.fatness << endl;
    return 0;
}