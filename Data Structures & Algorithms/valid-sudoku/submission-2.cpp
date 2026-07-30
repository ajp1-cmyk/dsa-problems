class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i< board.size(); i++){
            set<char> st;
            for(int j=0; j<board[0].size(); j++ ){
                    if(board[i][j]=='.'){
                        continue;
                    }
                    if(st.contains(board[i][j])) {
                        return false;
                    }
                st.insert(board[i][j]);
            }
        }

        for(int j=0; j<board[0].size();j++){
             set<char> st;
            
            for(int i=0; i<board.size(); i++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(st.contains(board[i][j])){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        for(int row=0; row < 3; row++){
            for(int col =0; col < 3; col++) {

                set<char> st;
                for(int i =0; i<3; i++){
                    for(int j=0; j<3;j++){
                        if(board[row*3+i][col*3+j] == '.'){
                            continue;
                        }
                        if(st.contains(board[row*3+i][col*3+j])){
                            return false;
                        }
                        st.insert(board[row*3+i][col*3+j]);
                    }

                }
            }
        }
        return true;
    }
};
