struct compare {
    bool operator() (tuple<int,int,int> &p1, tuple<int,int,int> &p2) {
        if (get<1>(p1) == get<1>(p2)) {
            return get<2>(p1) < get<2>(p2);
        }
        return get<1>(p1) < get<1>(p2);
    }
};

class FreqStack {
public:
    
    FreqStack() {
        
    }
    
    void push(int x) {
        if (m.find(x) == m.end() || m[x] == 0) {
            m[x] = 1;
        } else {
            m[x]++;
        }
        tuple<int,int,int> p(x,m[x],iter);
        heap.push(p);
        iter++;
    }
    
    int pop() {
        tuple<int,int,int> p = heap.top();
        heap.pop();
        m[get<0>(p)]--;
        return get<0>(p);
    }
private:
    int iter = 1;
    unordered_map<int,int> m;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,compare> heap;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */


// unordered_map<int, int> freq;
// unordered_map<int, stack<int>> m;
// int maxfreq = 0;

// void push(int x) {
//     maxfreq = max(maxfreq, ++freq[x]);
//     m[freq[x]].push(x);
// }

// int pop() {
//     int x = m[maxfreq].top();
//     m[maxfreq].pop();
//     if (!m[freq[x]--].size()) maxfreq--;
//     return x;
// }
