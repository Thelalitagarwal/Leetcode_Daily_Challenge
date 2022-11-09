class StockSpanner {
public:
    stack<pair<int, int>> s;
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        while(s.size() && s.top().first <= price) 
        span += s.top().second, s.pop();
        s.push({price, span});
        return span;
    }
};