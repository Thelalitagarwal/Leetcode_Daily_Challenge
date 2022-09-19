class Solution {
public:
    
    unordered_map<string, vector<string>> contentDirectories; 
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for (string& s : paths) {
            size_t index = s.find_first_of(' ');
            
            string pathInfo(s.substr(0, index) + '/');
            
            while (index != string::npos) {
                size_t i = s.find_first_of('(', index + 1);
                
                string filename(s.substr(index + 1, i - (index + 1)));
                
                string content(s.substr(i + 1, s.find_first_of(')', i + 1) - i - 1));
                contentDirectories[content].push_back(pathInfo + filename);
                index = s.find_first_of(' ', index + 1);
            }
        }
        
        vector<vector<string>> ans;
        for (const pair<string, vector<string>>& mapData : contentDirectories) {
            if (mapData.second.size() != 1) {
                ans.push_back(mapData.second);
            }
        }
        return ans;
    }
};