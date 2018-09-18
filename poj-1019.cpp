#include<iostream>
#include<cmath>
using namespace std;
int getW(int n){
	int i=0;
	while(n){
		i++;
		n=n/10;
	}
	return i;
}
int getDigit(int n,int i){
	double temp=pow(10.0,(double)i-1);
	return (n/(int)temp)%10;
}
int main(){
	int t,i,n,j,k,add;
	long long count;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n;
		j=1;
		count=0;
		add=0;
		while(1){
	    add+=getW(j);
	    if(count+add>=n)
	    break;
	    count+=add;
	    j++;	
		}
		for(k=1;k<=j;k++){
			if(count+getW(k)>=n)
			break;
			count+=getW(k);
		}
		cout<<getDigit(k,getW(k)-(n-count)+1)<<endl;	
	}
	return 0;
}
