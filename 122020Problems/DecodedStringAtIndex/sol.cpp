class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long n = 0;
        int i = 0;
        vector<int> stor;
        while (i < S.size()) {
            if (isdigit(S[i])) {
                
                n = n*(S[i]-'0');    
                
                
            } else {
                n++;
            }
            
            std::cout<< n <<std::endl;
            stor.push_back(n);
            if (n>=K) {
                break;
            }
            
            i++;
            
        }
        
        while( K%stor.back() != 0) {
            
            // std::cout<< K << std::endl;
            stor.pop_back();
            K = K%stor.back();
            i--;
        } 
        while (isdigit(S[i])) {
            i--;
        }
        
        return {S[i]};
    }
};

// class Solution {
// public:    
//     string decodeAtIndex(string S, int K) {
//         long N = 0, i;
//         for (i = 0; N < K; ++i)
//             N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
//         while (i--)
//             if (isdigit(S[i]))
//                 N /= S[i] - '0', K %= N;
//             else if (K % N-- == 0)
//                 return string(1, S[i]);
//         return "";
//     }
// };
