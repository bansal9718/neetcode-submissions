class Solution {
   public:
    bool validWordAbbreviation(string word, string abbr) {
        
        if(word==abbr) return true;
        int n = word.length();
        int m = abbr.length();

        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (isalpha(abbr[j])) {
                if (word[i] != abbr[j]) return false;

                i++;
                j++;
            }

            else {
                if (abbr[j] == '0') return false;

                int num = 0;

                while (j < m && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                i += num;

                if (i > n) return false;
            }
        }

        return i == n && j == m;
    }
};