class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
//         greedy
        vector<int> A(amount+1,amount+1);
        A[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                A[i] = min(A[i], A[i-coin]+1);
                // cout << A[i] << endl;
            }
        }
        
        // for (int a: A) {
        //     cout << a << " ";
        // }
        // cout << endl;
        // return 0;
        // vector<int> A(amount+1, amount+1);
        // A[0] = 0;
        // for (int coin : coins) {
        //     for (int i = coin; i <= amount; i++) {
        //         A[i] = min(A[i], A[i - coin] + 1);
        //     }
        // }
        return A[amount] > amount ? -1 : A[amount];
    }
};
