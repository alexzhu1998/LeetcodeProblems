#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void print(vector<int> v) {
    for (auto x:v) {
        cout<< x << " ";
    }
    cout<< endl;
}

bool next_permutate(vector<int>::iterator begin, vector<int>::iterator end) {
    // empty
    if (begin == end) return false;
    // only one element
    if (begin+1 == end) return false;
    vector<int>::iterator i = end-1;

    while (true) {
        vector<int>::iterator j = i;
        i--;
        // move to an increasing iterator
        if (*i < *j) {
            // start from the end, iterate back one by one and then swap
            vector<int>::iterator k = end;
            while (!(*i < *k)) k--;
            iter_swap(i,k);
            reverse(j,end);
            return true;
        }

        if (i == begin) {
            reverse(begin,end);
            return false;
        }
    }
}

void lexicalGraphic(int n) {
    // initialising the vector
    vector<int> permVec;
    for (int i = 0; i < n; i++) permVec.push_back(i);
    vector<vector<int>> stor;
    // permutate
    do {
        // print(permVec);
        stor.push_back(permVec);
    }
    while(next_permutate(permVec.begin(),permVec.end()));
}

void dfs(vector<int>& v, int i, vector<vector<int>> &storage) {
    if (i == v.size()) {
        // print(v);
        storage.push_back(v);
    } else {
        for (int j = i; j < v.size();j++) {
            swap(v[i],v[j]);
            dfs(v,i+1,storage);

            // use this for pass by reference
            swap(v[i],v[j]);
        }
    }
}

void dfsMethod(int n) {
    vector<int> permVec;
    vector<vector<int>> stor;
    for (int i = 0; i < n; i++) permVec.push_back(i);
    dfs(permVec,0,stor);
    // for (auto i: stor) {
    //     print(i);
    // }
}



int main() {
    
    lexicalGraphic(11);
    // dfsMethod(11);

    return 0;
}