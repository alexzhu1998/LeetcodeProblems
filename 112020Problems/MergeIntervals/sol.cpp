bool myfunction(vector<int> a,vector<int> b) {
    if (a[0] == b[0]) {
        return (a[1] < b[1]);
    } else {
        return (a[0] < b[0]);
    }
}
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end(), myfunction);
        vector<vector<int>> ans = {intervals[0]};
        int i = 0;
        for (int j = 1; j < intervals.size() ;j++) {
//             if element i's second item is larger than element i+1's first item,
//             then 
            if (ans[ans.size()-1][1] < intervals[j][0]) {
                ans.push_back(intervals[j]);
            } else {
                vector<int> merged = {ans[ans.size()-1][0],max(ans[ans.size()-1][1],intervals[j][1])};
                ans.pop_back();
                ans.push_back(merged);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     struct Interval{
// 	int start;
// 	int end;
//     };

//     struct compareInt{
// 	    bool operator()(Interval &i1, Interval &i2){
// 	    return i2.start < i1.start? true: false;
//     }
// };

//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        	priority_queue<Interval,  vector<Interval>, compareInt > pq;
//     	vector<vector<int> > result;
//         vector<int> temp;
// 	    int i=0;
// 	    for(;i <intervals.size();i++){
// 		    temp = intervals[i];
// 		    struct Interval intV;
// 		    intV.start=temp[0];
// 		    intV.end=temp[1];
		
// 		    pq.push(intV);
//     	}
	
// 	    stack<Interval> s;
// 	    s.push(pq.top());
// 	    pq.pop();	
  
//      	while(!pq.empty()){
// 	    	Interval t = s.top();
// 		    Interval next = pq.top();
		
// 		    if(next.start <= t.end){
// 			    if(next.end > t.end)
// 				    t.end=next.end;
// 			    s.pop();
// 		    	s.push(t);
// 	    	}
// 	    	else s.push(next);
// 		    pq.pop();
// 	    }

//         while(!s.empty()){
//             temp.clear();
//             Interval t = s.top();
// 		    temp.push_back(t.start);
// 		    temp.push_back(t.end);
// 		    result.push_back(temp);
// 		    s.pop();
// 	    }
//         return result;
//     }
// };