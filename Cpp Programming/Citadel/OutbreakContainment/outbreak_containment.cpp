#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'min_cleaning_cost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER P
 *  2. INTEGER Q
 *  3. INTEGER_ARRAY rooms
 */

int min_cleaning_cost(int P, int Q, vector<int> rooms) {
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string P_temp;
    getline(cin, P_temp);

    int P = stoi(ltrim(rtrim(P_temp)));

    string Q_temp;
    getline(cin, Q_temp);

    int Q = stoi(ltrim(rtrim(Q_temp)));

    vector<int> rooms(Q);

    for (int i = 0; i < Q; i++) {
        string rooms_item_temp;
        getline(cin, rooms_item_temp);

        int rooms_item = stoi(ltrim(rtrim(rooms_item_temp)));

        rooms[i] = rooms_item;
    }

    int result = min_cleaning_cost(P, Q, rooms);

    fout << result << "\n";

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
