class Solution {
public:
    vector<int> findNext(vector<int>& cells){
        int n=cells.size();
        vector<int> newcell(n, 0);
        for(int i=1; i<n-1; i++){
            if(cells[i-1] == cells[i+1])
                newcell[i]=1;
        }
        return newcell;
    }
    
    string cellToString(vector<int>& cells){
        string strcell = "";
        int n=cells.size();
        for(int i=0; i<n; i++){
            strcell += cells[i] + '0';
        }
        return strcell;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int n=cells.size(), i=0;
        unordered_map<string, int> ht;
        
        vector<int> newcell = cells;
        
        while(i<N){
            newcell = findNext(newcell);
            string strcell = cellToString(newcell);
            
            if(ht.find(strcell) != ht.end()){
                int cycle = i-ht[strcell];
                N = (N-i-1)%cycle;
                i=0;
                while(i<N){
                    newcell = findNext(newcell);
                    i++;
                }
                return newcell;
            }
            
            ht[strcell] = i;
            i++;
            
        }
        
        return newcell;
    }
};

