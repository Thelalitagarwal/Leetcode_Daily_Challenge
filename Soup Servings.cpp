/*
Link to the "Soup Servings" Problem ==>> https://leetcode.com/problems/soup-servings/ 
   
Link to the complete Explaination Video ==>> https://youtu.be/lxTblMLfbMk

*/


class Solution {
public:
double help(int a, int b, map< pair<int,int>, double>& mp)
{

    if (a<=0 && b<=0)
        return 0.5;
    if (a<=0)
        return 1;
    if (b<=0)
        return 0;
    if (mp.count({a,b}))    
        return mp[{a,b}];
        
    double ans = 0;

    ans += help(a-100, b, mp);
    ans += help(a-75, b-25, mp);
    ans += help(a-50, b-50, mp);
    ans += help(a-25, b-75, mp);

    return mp[{a,b}] = (double)ans / (double)4;
}

double soupServings(int n) {

    if (n>=5000)        
        return 1.0;
    
    map< pair<int,int>, double> mp;

    return help(n, n, mp);
}

};