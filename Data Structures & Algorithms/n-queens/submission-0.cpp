class Solution {
public:

bool isSafe(int r, int c, vector<string>&board) { 
    
int n = board.size();

    int tr = r, tc = c;
    //check upper left diagonal 
    while(tr>=0 && tc>=0){
        if(board[tr][tc]=='Q') {return false;}
        tr--;
        tc--;
    }

    tr = r, tc = c;
    //check upper right diagonal
    while(tr>=0 && tc<n){ 
        if(board[tr][tc]=='Q') {return false;}
        tr--;
        tc++;
    }

    tr = r, tc = c;
    //check vertical up
    while(tr>=0){
        if(board[tr][tc]=='Q') {return false;}
        tr--;
    }

    return true;

}

void backtrack(int r, vector<string>&board,vector<vector<string>>&ans){

    if(r==board.size()){
        ans.push_back(board);
        return;
    }

    for(int c=0;c<board.size();c++){
        if(isSafe(r,c,board)){
           board[r][c]='Q';
           backtrack(r+1,board,ans);
           board[r][c]='.';
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;

    vector<string> board(n,string(n,'.'));
    backtrack(0,board,ans);
    return ans;
    }
};
