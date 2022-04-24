class UndergroundSystem {
    
    
    map<pair<string, string>, pair<int,int>> avg; // {source, dest} -> {sum, n}
    map<int, pair<string, int>> mp; // {id} -> {checkin, t}
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        
        avg[{mp[id].first, stationName}].first += (t - mp[id].second);
        avg[{mp[id].first, stationName}].second++; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        int num = avg[{startStation, endStation}].first;
        int den = avg[{startStation, endStation}].second;
        
        return (num * 1.0) / den;
    }
};