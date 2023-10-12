class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, b = 0, c = 0;
        for(auto &i: s){
            if(i=='A')a++,b=0;
            else if(i=='L')b++;
            else b = 0;
            if(b>=3)c = 1;
        }
        if(c||a>1)return false;
        return true;
    }
};
