#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string,int> m;

    m["hi"] = 20;
    m["practice"] = 30;

    for (auto x: m) {
        cout << x.first << " " << x.second << endl;
    }

    unordered_map<string, int>:: iterator itr;
    for (itr = m.begin(); itr != m.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }
    m.insert(make_pair("e",2));
    
    string key = "hi";
    if (m.find(key) == m.end()) {
        cout << key << " not found" << endl;
    } else {
        cout << "Found " << key << endl;
    }
    
    
    
    return 0;
}