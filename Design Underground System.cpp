/*
Link to the " Design Underground System " Problem ==>> https://leetcode.com/problems/design-underground-system/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/kr5up2nnDxM

*/

#define ll double
class UndergroundSystem {
    unordered_map<string,vector<ll>> sum;

    unordered_map<int,pair<string,ll>> entry;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id]={stationName,t};       
    }
    
    void checkOut(int id, string stationName, int t) {

        stationName += '-'+entry[id].first;
        auto tr=sum.find(stationName);
        if (tr == sum.end()) 
        {
            sum[stationName]={1,t-entry[id].second};
        }
        else
        {
            tr->second[0]++;
            tr->second[1] += t-entry[id].second;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        endStation += '-'+startStation;
        auto tr=sum.find(endStation);
        if (tr != sum.end())
        {
            return ((double) tr->second[1])/(double)tr->second[0];
        }
        else return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */