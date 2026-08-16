class Solution {
public:

void solve(int idx,string&digits,unordered_map<int, string>&map,vector<string>&ans,string curr){
      
      if(curr.size()==digits.size()){
        ans.push_back(curr);
        return;
    }

    int digit = digits[idx]-'0';
    string letters = map[digit];

    for(char letter:letters){
        curr.push_back(letter);
        solve(idx+1,digits,map,ans,curr);
        curr.pop_back();
    }

    
}

vector<string> letterCombinations(string digits) {
        
        vector<string>ans ;
        int n = digits.size();
        if(n==0) return ans;
    
    unordered_map<int, string> map = {
    {2, "abc"},
    {3, "def"}, 
    {4, "ghi"}, 
    {5, "jkl"},
    {6, "mno"}, 
    {7, "pqrs"},
    {8, "tuv"}, 
    {9, "wxyz"},
    {0,"+"},
    {-1, "*"},  
    {-2, "#"}
};
   solve(0,digits,map,ans,"");
  return ans;
}
};
