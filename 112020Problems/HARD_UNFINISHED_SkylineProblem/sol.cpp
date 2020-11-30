class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> curr = {0,0};
        vector<vector<int>> result;
        multiset<vector<int>> seq;
        vector<int> temp;
        for(auto p:buildings){
            temp = {p[0],-p[2]};
            seq.emplace(temp);
            temp  = {p[1],p[2]};
            seq.emplace(temp);
        }
        multiset<int> height({0});
        for(auto p:seq){
            if(p[1]<0)height.emplace(-p[1]);
            else height.erase(height.find(p[1]));
            if(*height.rbegin()!=curr[1]){
                curr[0] =p[0];
                curr[1]=*height.rbegin();
                result.push_back(curr);
            }
        }
        return result;
    }
};
// class Solution {
// public:
//     vector<vector<int>> getSkyline(vector<vector<int>>& b) {
// //         for each skyline, first observe the height (input is sorted)
//         vector<vector<int>> heights;
//         vector<vector<int>> crit;
//         vector<int> temp;
// //         arrange it according to start and end ( very typical)
//         for (int i = 0; i < b.size(); i++) {
//             temp = {b[i][0],b[i][2],0};
//             crit.push_back(temp);
//             temp = {b[i][1],b[i][2],1};
//             crit.push_back(temp);
//         }
//         std::sort(crit.begin(),crit.end());
        
//         vector <int> heap = {0};
        
//         make_heap(heap.begin(),heap.end());
        
//         for (int i = 0; i < crit.size();i++) {
// //             indicating start
//             if (crit[2] == 0) {
// //                 first ignore duplicate start and end values
//                 if (crit[1] > heap.front()) {
//                     heap.push_back(crit[1]);
//                     make_heap(heap.begin(),heap.end());
//                     temp = {crit[0],crit[1]};
//                     heights.push_back(temp);
//                 } else if () {
                    
//                 }
// //             indicating end
//             } else {
//                 int prevMax = heap.top();
//                 heap.erase(find(heap.begin(),heap.end(),crit[1]));
//                 make_heap(heap.begin(),heap.end());
//                 if (prevMax < heap.top()) {
                    
//                 } else if (crit[1] == heap.top()) {
//                     heap.pop();
//                     temp = {crit[0],crit[1]};
//                     heights.push_back(temp);
//                 }
//             }
            
//         }
        
//         return heights;
//     }
    
// };

// // for each rectangle r:
// //     for each critical point c:
// //         if c.x >= r.left && c.x < r.right:
// //             c.y gets the max of r.height and the previous value of c.y

// // no horizontal skyline

// // [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// // should return
// // [[2,10],[3,15],[7,12],[15,10],[20,8],[24,0]]