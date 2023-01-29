/*
Link to the "LFU Cache" Problem ==>>  https://leetcode.com/problems/lfu-cache/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/M92VpzdLU24

*/

class LFUCache {
    int maxSizeCache;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> keyNode;
    unordered_map<int, list<int>::iterator> keylist;
    unordered_map<int, list<int>>  freqKeyLt;
public:

    LFUCache(int capacity) {
        maxSizeCache = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(keyNode.count(key)==0)
            return -1;
        freqKeyLt[keyNode[key].second].erase(keylist[key]);
        keyNode[key].second++;
        freqKeyLt[keyNode[key].second].push_back(key);
        keylist[key]=--freqKeyLt[keyNode[key].second].end();
        if(freqKeyLt[minFreq].size()==0 ) 
              minFreq++;
        return keyNode[key].first;
    }
    
   void put(int key, int value) {
        if(maxSizeCache<=0)
            return;
        int storedValue=get(key);
        if(storedValue!=-1){
            keyNode[key].first=value;
            return;
        }
        if(size >= maxSizeCache){
            keyNode.erase( freqKeyLt[minFreq].front() );
            keylist.erase( freqKeyLt[minFreq].front() );
            freqKeyLt[minFreq].pop_front();
            size--;
        }
        keyNode[key]={value, 1};
        freqKeyLt[1].push_back(key);
        keylist[key]=--freqKeyLt[1].end();
        minFreq=1;
        size++;
    }
};