#include <bits/stdc++.h>
using namespace std;
int main(){
	string n;
	vector<char> ans;
	while(cin>>n&&n!="-1"){
		if(n=="0"){
			cout<<n<<endl;
			continue;
		}
		ans.clear();
		int l=n.size(),d=0;
		for(int i=0;i<l;i++){
			d=d*10+n[i]-48;
			ans.push_back(char((int)d/9+'0')) ;
			d=d%9;
		}
		l=ans.size();
		int start;
		for(start=0;start<l;start++){
			if(ans[start]!='0')break;
		}
		if(d){
			int a=1;
			for(int i=l-1;i>=start&&a;i--){
				int b=(ans[i]+a-48)%10;
				a=(ans[i]+a-48)/10;
				ans[i]=(b+'0');
			}
			if(a)cout<<a;
		}
		for(int i=start;i<l;i++)cout<<ans[i];
		cout<<endl;
	}
	return 0;
}