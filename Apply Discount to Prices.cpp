class Solution {
	public:
		string discountPrices(string sen, int dis) {
			int n=sen.size();
			string ans="";
			for(int i=0;i<n;i++){
				ans+=sen[i];
				if(i+1<n && sen[i]=='$' && isdigit(sen[i+1]) && ((i>=1 && sen[i-1]==' ') || i==0)){
					string str="";
					int j;
					bool flag=true;
					for(j=i+1;j<n;j++){
						if(isdigit(sen[j])) str+=sen[j];
						else{
							if(sen[j]!=' ') flag=false;
							break;
						}    
					}
					if(!flag) continue;
					long double num=stold(str);
					num-=num*dis*0.01;
					num=abs(num);
					string s=to_string(num);
					s.pop_back();
					s.pop_back();
					s.pop_back();
					s.pop_back();
					ans+=s;
					i=j-1;
				}
			}
			return ans;
		}
	};
