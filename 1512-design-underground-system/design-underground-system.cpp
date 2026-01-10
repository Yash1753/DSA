class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkInMap; //id->{station,timeBoarded}
    unordered_map<string,pair<int,int>> checkOutMap; // route -> {totaltime on this route , number of ids}
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(checkInMap.count(id) == 0) checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string stationA = checkInMap[id].first;
        int timeS = checkInMap[id].second;

        string route = stationA + "_" + stationName;

        //int totaltime  = checkOutMap[route].first;
        checkOutMap[route].first += t - timeS;

        checkOutMap[route].second = checkOutMap[route].second + 1;

        //checkOutMap[route] = {totaltime,count};

        checkInMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        int totaltime = checkOutMap[route].first;
        int cnt = checkOutMap[route].second;

        return (double)totaltime/cnt;
    }

};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */