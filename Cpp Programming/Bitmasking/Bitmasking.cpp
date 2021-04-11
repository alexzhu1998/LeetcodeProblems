#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Sol {
    public:
        
        int NumberofOnesInBinary(int n) {
            int sum = 0;
            // O(n) solution
            while (n > 0) {
                // if n is divisible by 2, add 1, else add 0
                sum += n^1;
                // shifting bits to the right by 1
                n >>= 1; // same as n = n>>1;
                cout << n << endl;
            }
            return sum;
        }

        // rotate the bits of a number
        int rotateBits(int n, int N) {
            const int BITS_IN_INT = 32;

            return (n>>N | n << (BITS_IN_INT-N));
            // return (n<<N | n >> (BITS_IN_INT-N));
        }

        // swap without using temp variable
        void swap(int a, int b) {
            cout << a << " " << b << endl;
            a = a^b;
            b = a^b;
            a = a^b;
            cout << a << " " << b << endl;
        }

        // check if two numbers are one bit off
        bool gray(int a, int b) {
            if (a==b) return 0;
            int k = a^b;
            // naive solution
            // while (k>0) {
            //     if (k%2 == 1 && k>>1 >0) return false;
            //     k >>= 1;
            // }
            // return true;
            
            // advanced O(1) solution, powers of 2 are the only numbers with the property below
            return (k & (k-1)) == 0;
            
        }

        // addition without using math operators
        int sum(int a, int b) {
            if (b == 0) return a;
            int partialSum = a^b;
            int carryover = (a&b)<< 1;
            return sum(partialSum,carryover);
        }

        // find the two missing number in an array
        int oneMissing(vector<int> arr) {
            // boolean array
            // time - O(n)
            // space - O(n)

            // sort
            // time - O(nlogn)
            // space - O(1)

            // sum
            // time - O(n)
            // space - O(1)
            // may have overflow

            // xor

            int totalXor = 0;
            int arrXor = 0;

            for (int i = 1; i <= arr.size()+1; i++) totalXor ^= i;
            for (int i : arr) arrXor ^= i;
            return totalXor^arrXor;

        }

        void twoMissing(vector<int> arr) {
            // idea is to find the sum of the missing elements, half them, and find the one missing number greater and less than.
            int size = arr.size()+2;
            long total = size*(size+1)/2;
            for (int i:arr) total -= i;
            int pivot = total/2;

            int first = 0;
            int second = 0;
            for (int i = 0; i < arr.size();i++) {
                if (arr[i] <= pivot) {
                    first ^= arr[i];
                } else {
                    second ^= arr[i];
                }
            }
            int firsthalf = 0;
            for (int i = 1; i <= pivot; i++) {
                firsthalf ^= i;
            }
            int secondhalf = 0;
            for (int i = pivot+1; i <= size; i++) {
                secondhalf ^= i;
            }
            cout << (first^firsthalf)<< endl;
            cout << (second^secondhalf)<<endl;

        }
       // 1111110
       //  101111
       //  110111
};

int main () {
    Sol s;
    // 1010
    // int res = s.NumberofOnesInBinary(10);
    // int res = s.rotateBits(7,8);
    // s.swap(1,2);
    // bool res = s.gray(2,2);
    // int res = s.sum(1,5);
    vector<int> v {1,2,3,4,7};

    

    s.twoMissing(v);
    // cout<<res<<endl;
    return 0;
}