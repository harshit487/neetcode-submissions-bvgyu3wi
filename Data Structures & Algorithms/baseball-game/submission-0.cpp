class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        int n = operations.size();
        int sum = 0;

        for(int i = 0;i < n;i++)
        {
            if(operations[i] == "+")
            {
                int top = s.top();
                s.pop();
                int newTop = top + s.top();
                sum += newTop;
                s.push(top);
                s.push(newTop);
                
            }

            else if(operations[i] == "C")
            {
                sum -= s.top();
                s.pop();
            }

            else if(operations[i] == "D")
            {
                int newTop = 2 * s.top();
                sum += newTop;
                s.push(newTop);
            }

            else
            {
                int x = stoi(operations[i]);
                sum += x;
                s.push(x);
            }
        }

         return sum;
    }
};