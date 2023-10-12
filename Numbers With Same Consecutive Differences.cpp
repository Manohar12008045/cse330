class Solution {
public:
    vector<int>ans;
    vector<int> numsSameConsecDiff(int n, int k) 
    { 
        string temp="";
        fun(n,k,temp);     
        return ans;
    }   
    void fun(int n,int k,string temp)
    {
        if(n==0)
        {
            int num=stoi(temp);
            ans.push_back(num);
            return;
        }
         if(temp.length()==0)        //we have empty string
         { 
              for(int i=1;i<=9;i++)   //it will have all the choises as the string length is 0 ie empty
              {
                  char ch = i + '0';	         
                  fun(n-1,k,temp+ch);
              }     	
         }
         else if(temp.length()>0)   //stirng length is more than 0
         {
              for(int i=0;i<=9;i++)     //it will have some certain choise as we have to check the abs diff of k
              {
                 char currch = i + '0';
                 char lastch = temp[temp.length()-1];

                 int currnum = currch - '0';
                 int lastnum = lastch - '0';

                 if(abs(currnum-lastnum)==k)
                 {
                    fun(n-1,k,temp+currch);
                 }
              }
         }
    }
};
