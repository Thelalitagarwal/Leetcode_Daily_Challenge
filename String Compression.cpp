/*
Link to the " String Compression " Problem ==>>  https://leetcode.com/problems/string-compression/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/-1jhUCSVvbY

*/

class Solution {
public:
    int compress(vector<char>& chars) {

        int count = 1;
        string ans;
        ans.push_back(chars[0]);
        for(int i=1; i<chars.size(); i++){
            if(chars[i] == chars[i-1])
                count++;
            else{
                if(count > 1)
                    ans = ans + to_string(count);      
                count = 1;
                ans.push_back(chars[i]);
            }
        }
        if(count > 1)
            ans = ans + to_string(count);
        for(int i=0; i<ans.length(); i++)
            chars[i] = ans[i];       
        return ans.size();
    }
};