class UndergroundSystem {
public:
    
    unordered_map<int,int> time;
    unordered_map<int,string> station;
    unordered_map<string,int> totalTime;
    unordered_map<string,int> count;
    UndergroundSystem() {
        
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        time[id] = t;
        station[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        string temp = station[id]+" "+ stationName;
        totalTime[temp] += t- time[id];
        count[temp]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string temp = startStation + " " + endStation;
        return (double) totalTime[temp]/ (double) count[temp];
        
        
    }
};

// class UndergroundSystem {
//   struct Ride {
//     size_t from_id;
//     int start_time;
//   };
//   unordered_map<int, Ride> rides;
//   struct TravelStat {
//     int rides_count = 0;
//     int current_time_sum = 0; 
//   };
//   unordered_map<size_t, unordered_map<size_t, TravelStat>> travel_stat;
//   unordered_map<string, size_t> name_to_id;
//   size_t id = 0;
  
//   size_t station_id(const string& name) {
//     if (auto it = name_to_id.find(name); it != name_to_id.end())  {
//       return it->second;
//     }
//     name_to_id[name] = id++;
//     return id-1;
//   }
//   public:
//   UndergroundSystem() {

//   }

//   void checkIn(int id, string from, int time) {
//     rides[id] = Ride{station_id(from), time}; 
//   }

//   void checkOut(int id, string to, int time) {
//     auto it = rides.find(id);
//     auto &stat = travel_stat[it->second.from_id][station_id(to)];
//     stat.rides_count++;
//     stat.current_time_sum += time - it->second.start_time;
//     rides.erase(it);
//   }

//   double getAverageTime(string from, string to) {
//     const auto& stat = travel_stat[station_id(from)][station_id(to)];
//     return 1.0 * stat.current_time_sum / stat.rides_count;
//   }
// };

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
