class Solution {
public:

    void filln(queue<string>& que, string& curr, unordered_set<string>& dead) {

        for(int i = 0;i < 4 ; i++) {
            char ch = curr[i];

            char inc = ch == '9' ? '0' : ch + 1;
            char dec = ch == '0' ? '9' : ch - 1;
            curr[i] = inc;
            if(dead.find(curr) == dead.end()) {
                dead.insert(curr);
                que.push(curr);
            }
            curr[i] = dec;
            if(dead.find(curr) == dead.end()) {
                dead.insert(curr);
                que.push(curr);
            }
            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {

        unordered_set<string>dead(deadends.begin(),deadends.end());
        string start = "0000";
        if(dead.find(start) != dead.end()) return -1;
        queue<string>q;
        q.push(start);

        int level = 0;

        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                string curr = q.front();
                q.pop();
                if(curr == target) return level;
                filln(q,curr,dead);
            }
            level++;
        }
        return -1;
    }
};