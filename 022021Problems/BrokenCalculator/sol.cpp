class Solution {
public:
    int brokenCalc(int X, int Y) {
        int count = 0;
        while (X < Y) {
            if (Y%2) {
                Y++;
            } else {
                Y/=2;
            }
            // cout << Y << endl;
            count++;
        }
        
        return count + X - Y;
        
        
    }
    
    // int brokenCalc(int X, int Y) {
    //     if(X >= Y) return X - Y;
    //     if(Y & 1) return brokenCalc(X, Y + 1) + 1;
    //     else return brokenCalc(X, Y / 2) + 1;
    // }
};
