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

    int dr = r, dc = c;
    //check lower left diagonal
    while(dr<n && dc>=0){ 
        if(board[dr][dc]=='Q') {return false;}
        dr++;
        dc--;
    }

    int hr = r, hc = c;
    //check horizontal left
    while(hc>=0){
        if(board[hr][hc]=='Q') {return false;}
        hc--;
    }

    return true;

}

void backtrack(int c, vector<string>&board,vector<vector<string>>&ans){

    if(c==board.size()){
        ans.push_back(board);
        return;
    }

    for(int r=0;r<board.size();r++){
        if(isSafe(r,c,board)){
           board[r][c]='Q';
           backtrack(c+1,board,ans);
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