class StockSpanner {
public:
    StockSpanner() : index(-1) {
    }    
    int next(int price) {
        index += 1;        
        while (!stk.empty() && stk.top().first <= price) {
            stk.pop();
        }        
        int span = stk.empty() ? index + 1 : index - stk.top().second;        
        stk.push({price, index});        
        return span;
    }
private:
    std::stack<std::pair<int, int>> stk;
    int index;
};