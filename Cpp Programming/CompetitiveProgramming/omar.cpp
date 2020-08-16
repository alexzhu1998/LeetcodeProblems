#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char* argv[]) {
    int number;
    cin >> number;
    vector<int> v;
    for (int i = 0; i < number; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // for (int i = 0; (unsigned)i < v.size(); i++) {
    //     cout << v[i] << endl;
    // }

    return 0;
}

// https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c



// #include <fstream>
// std::ifstream infile("thefile.txt");

// Method 1
// int a, b;
// while (infile >> a >> b)
// {
//     // process pair (a,b)
// }


// Method 2
// #include <sstream>
// #include <string>

// std::string line;
// while (std::getline(infile, line))
// {
//     std::istringstream iss(line);
//     int a, b;
//     if (!(iss >> a >> b)) { break; } // error

//     // process pair (a,b)
// }