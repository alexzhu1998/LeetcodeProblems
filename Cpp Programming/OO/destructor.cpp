#include <iostream>
#include <string>

using namespace std;

class RipTire {
public:
    RipTire()
    {
        cout << "Fire in the Hole!" << endl;
    }
    // destructors should not have any parameters
    // stop the program from raising any errors
    ~RipTire() noexcept
    {
        cout << "Squigly BOOM" << endl;
    }
};

int main () {
    {
        RipTire r;
    }
    string y;
    getline(cin,y);
    return 0;
}