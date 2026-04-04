class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
 
        for(int i = 0;i <9;i++)
        {
            unordered_map<char,int>freq;
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] == '.') continue;
                if(freq.find(board[i][j])!=freq.end()) return false;
                else
                freq[board[i][j]]++;
            }
        }

         for(int i = 0;i <9;i++)
        {
            unordered_map<char,int>freq;
            for(int j = 0;j<9;j++)
            {
                if(board[j][i] == '.') continue;
                if(freq.find(board[j][i])!=freq.end()) return false;
                else
                freq[board[j][i]]++;
            }
        }
         
        
       

    for(int square = 0;square<9;square++)
    {
        unordered_map<char,int>freq;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int row = (square/3)*3+i;
                int col = (square%3)*3+j;
                if(board[row][col] == '.') continue;
             
            if(freq.find(board[row][col])!=freq.end()) return false;
            else
            freq[board[row][col]]++;

            }
        }
    }
        return true;
        
        
    }
};