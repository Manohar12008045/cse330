class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        ans.push_back({});
        int col, row=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ') //If whitespace is encountered
            {
                col++;
                row=0;
                continue;
            }
            if(row>=ans.size()) //Insert new row
                ans.push_back({});
            if(ans[row].size()<col) //Insert whitespaces
                ans[row].append(string(col-ans[row].size(), ' '));
            ans[row++].push_back(s[i]);
        }
        return ans;
    }
};
