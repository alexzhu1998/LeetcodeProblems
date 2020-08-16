#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'detect_probes' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY order_sizes as parameter.
 */

vector<int> detect_probes(vector<int> order_sizes) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string order_sizes_count_temp;
    getline(cin, order_sizes_count_temp);

    int order_sizes_count = stoi(ltrim(rtrim(order_sizes_count_temp)));

    vector<int> order_sizes(order_sizes_count);

    for (int i = 0; i < order_sizes_count; i++) {
        string order_sizes_item_temp;
        getline(cin, order_sizes_item_temp);

        int order_sizes_item = stoi(ltrim(rtrim(order_sizes_item_temp)));

        order_sizes[i] = order_sizes_item;
    }

    vector<int> result = detect_probes(order_sizes);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
