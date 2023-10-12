#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	
	int T;
	cin>>T;
	while(T--){
	    int x,y;
	    cin>>x>>y;
	    int gd=__gcd(x,y);
	    cout<<2*gd<<endl;
	}
	return 0;
}

