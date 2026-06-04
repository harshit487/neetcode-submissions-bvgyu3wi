class FreqStack {
    vector<int>st;
    unordered_map<int,int>map;
public:
    FreqStack() {}
    
    void push(int val) {
        st.push_back(val);
        map[val]++;
    }
    
    int pop() {
        int maxCnt = 0;
        for(auto& [_,frequency] : map)
        {
            maxCnt = max(maxCnt,frequency);
        }
        int i = st.size() - 1;

        while(map[st[i]] != maxCnt)
        {
            i--;
        }
        int val = st[i];
        st.erase(st.begin() + i);
        map[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */