/*
Link to the " Minimum Deletions to Make Character Frequencies Unique " Problem ==>> https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/?envType=daily-question&envId=2023-09-12 
   
Link to the complete Explaination Video ==>> https://youtu.be/L2-9goh3GwU

*/

class Solution {
public:
    int minDeletions(string s) {

        unordered_map<char, int> count;

        for(char c : s)
            count[c]++;

        unordered_set<int> freqcount;

        int ans = 0;

        for(auto& k : count)
        {
            int freq = k.second;
            while(freq>0 && freqcount.find(freq) != freqcount.end())
            {
                freq--;
                ans++;
            }
            freqcount.insert(freq);
        }
        
        return ans;
    }
};