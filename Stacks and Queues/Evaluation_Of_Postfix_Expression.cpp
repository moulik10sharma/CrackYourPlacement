class Solution
{
    public:    
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for (char c : S)
        {
            if (isdigit(c))
            {
                st.push(c - '0');
            }
            else
            {
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();
                
                switch (c)
                {
                    case '+': st.push(val1 + val2); break;
                    case '-': st.push(val1 - val2); break;
                    case '*': st.push(val1 * val2); break;
                    case '/': st.push(val1 / val2); break;
                }
            }
        }
        return st.top();
    }
};