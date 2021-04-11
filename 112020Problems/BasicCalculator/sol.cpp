class Solution {
public:
    int calculate(string s) {
//         store each operation in vector
//         store each number in vector
//         do all the * and / operation first
//         then proceed in order
        vector<int> numVector;
        long num = 0;
        char sign = '+';
        int val;
        for (int i=0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = num*10+s[i] - '0';
            }
            if (i+ 1 == s.length() or (s[i] == '+' || s[i] == '-' ||s[i] == '*'||s[i] == '/')) {
                if (sign == '+') {
                    numVector.push_back(num);
                } else if (sign == '-') {
                    numVector.push_back(-1*num);
                } else if (sign == '*') {
                    val = numVector.back();
                    numVector.pop_back();
                    numVector.push_back(val*num);
                } else if (sign == '/') {
                    val = numVector.back();
                    numVector.pop_back();
                    numVector.push_back(val/num);
                }
                sign = s[i];
                num = 0;
            }
            
        }
        int sum = 0;
        std::for_each(numVector.begin(), numVector.end(), [&] (int n) {
            // std::cout << n << std::endl;
            sum += n;
        });
        return sum;
        
        
    }
};
