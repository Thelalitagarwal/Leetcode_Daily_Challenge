class Solution {
public:
	//To find digits in the current number
    int counts(int x) {
        int len = 0;
        while(x)
        {
			len++;
            x = x/10;
        }
        return len;
    }
    void findnum(int x, int n ,int k, vector<int> &res){
        if(counts(x) == n) //Base case
        {
            res.push_back(x);
            return;
        }
        for(int i=0;i<10;i++) {
           int last_digit = x % 10;
           if(abs(last_digit - i) == k) 
           {
               findnum((x*10 + i), n, k, res); 
           } 
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res; 
        if(n == 1) //Special Case where 0 can be included if given 'N' is 1
        {
            res.push_back(0);
        }
        for(int i=1;i<10;i++) {
            findnum(i, n, k, res);    
        }
        return res; 
    }
};