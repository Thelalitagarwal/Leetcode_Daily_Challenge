class Solution {
public:
    /*int maximum69Number (int num) {
        string s=to_string(num);
        for(int i=0;i<s.length();++i){
            if(s[i]=='6'){
                s[i]='9';
                break;
            }
        }
        int ans =stoi(s);
        return ans;
    }*/
    int maximum69Number (int num) {
        int i=num;
        if(i/1000==6){
            return 9*1000+num%1000;
        }
        else if(i/100==96 ||i/100==6){
            return ((i/100) +3)*100+num%100;
        }
        else if(i/10==996 || i/10==96|| i/10==6){
            return (i/10 +3)*10+num%10;
        }
        else if(i%10==6){
            return num+3;
        }
        return num;
    }
};