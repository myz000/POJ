#include<iostream>
#include<cstring>
using namespace std;
int minstep;
typedef struct rec{
	int b;
	int w;
	int step;
	int H[4][4];
};
int dir[5][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1}};
void dfs(rec R,int pos){
	if(pos>16)return;
	if(R.b==16||R.w==16){
		if(R.step<minstep){
			minstep=R.step;
			return;
		}
	}
	int x,y,i,j,x1,y1;
	rec r;
	x=pos/4;
	y=pos%4;
	dfs(R,pos+1);	
	memcpy(&r,&R,sizeof(R));
	for(i=0;i<5;i++){
		x1=x+dir[i][0];
		y1=y+dir[i][1];
		if(x1<0||x1>3||y1<0||y1>3)
		continue;
		if(r.H[x1][y1]==0){
			r.H[x1][y1]=1;
			r.b++;
			r.w--;
		}
		else{
			r.H[x1][y1]=0;
			r.b--;
			r.w++;
		}		
	}
	r.step++;
	dfs(r,pos+1);
} 
int main(){
	int i,j,b=0,w=0;
	rec R;
	char c;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++){
		cin>>c;
		if(c=='b'){
			R.H[i][j]=1;
			b++;
		}
		else{
		   R.H[i][j]=0;
			w++;	
		}
	}
	R.b=b;
	R.w=w;
	R.step=0;
	if(R.b==16||R.w==16){
		cout<<"0"<<endl;
	}
	else{
	minstep=10000000;
	dfs(R,0);
	if(minstep==10000000){
		cout<<"Impossible"<<endl;
	}
	else{
	cout<<minstep<<endl;
	}
}
	return 0;	
}

