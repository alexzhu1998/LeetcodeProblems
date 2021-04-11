class Solution {
public:
    int countSubstrings(string s) {
    //        count single letter palindromic
    //        build a vector array
        int n = s.length();
        vector<int> t(n,0);
        vector<vector<int>> v(n,t);
        for (int i = 0 ; i < n; i++) {
            v[i][i] =1;
            if (i < n-1 && s[i+1] == s[i]) {
                v[i][i+1] = 1;
            } 

        }

        
        
        for (int diag = 1; diag < n; diag++) {
            int i = 0;
            int j = diag;    
            while (j < n && i < n-diag) {
                if (s[i] == s[j] && v[i+1][j-1]) {
                    v[i][j] = 1;
                }
                i++;
                j++;
            }
            
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += v[i][j];
                // cout << v[i][j] << " ";
            }
            // cout << endl;
        }
        //            for each i, check i-1 letter, 
        //            if same, add v[i] = v[i-1] +1
        //            else check i-2 letter,
        //            if same add v[i] = v[i-2] + 1
        //            else v[i] = 1
        //            
        

        // for (auto a:v) {
        //     cout << a << " ";
        // }
        // cout << endl;
        return sum;
        //        return last element

    }
};

// dabcba
