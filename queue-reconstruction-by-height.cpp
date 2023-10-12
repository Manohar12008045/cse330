struct lessThanComp{
      bool operator()(const vector<int>&a1 , const vector<int> &a2){
          if(a1[0] == a2[0]){
              return a1[1] < a2[1];
          }
          else{
              return a1[0] < a2[0];
          }
      }
};
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
         int n = people.size();
         vector<vector<int>> result(n , vector<int>());
         sort(people.begin() , people.end() , lessThanComp());
        //  for(auto x : people)cout<<x[0]<<" "<<x[1]<<endl;
        for(int i = 0 ; i < n ; i++)
        {
            int count = people[i][1];
            int he = people[i][0];
            for(int j = 0 ; j < n ; j++)
            {
                if(result[j].size()==0 && count==0)
                {
                    result[j] = people[i];
                    break;
                }
                else if(result[j].size()==0 || result[j][0]>=he)count--;
            }
        }
         return result;
    }
};
