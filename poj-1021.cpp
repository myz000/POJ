#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int test_num;
int W,H,N;
int direct[][2]={{-1,0},{1,0},{0,-1},{0,1}};
int board[103][103];
typedef struct point{
	int x;
	int y;
};
point pointA [10003];
point pointB [10003];
int cluA[2500];
int cluB[2500];
int CluAnum;
int CluBnum;
int temp;
void getClu(int x,int y){
	  board[x][y]=-1;
	  temp++;
	  int i,x1,y1;
	  for(i=0;i<4;i++){
	  	x1=x+direct[i][0];
	  	y1=y+direct[i][1];
	  	if(x1<0||x1>=W||y1<0||y1>=H)continue;
	  	if(board[x1][y1]==1){
	  		getClu(x1,y1);
	  	}
	  }
}
int main(){
	int t,i,x,y;
	cin>>test_num;
	for(t=0;t<test_num;t++){
	cin>>W>>H>>N;
	memset(cluA,0,sizeof(cluA));
	memset(cluB,0,sizeof(cluB));
	CluAnum=0;
	CluBnum=0;
	for(i=0;i<N;i++){
		cin>>x>>y;
		pointA[i].x=x;
		pointA[i].y=y;
	}	
		for(i=0;i<N;i++){
		cin>>x>>y;
		pointB[i].x=x;
		pointB[i].y=y;
	}	
	memset(board,0,sizeof(board));
	for(i=0;i<N;i++){
		x=pointA[i].x;
		y=pointA[i].y;
		board[x][y]=1;
	}
	for(i=0;i<N;i++){
		x=pointA[i].x;
		y=pointA[i].y;
		if(board[x][y]==-1)continue;
		temp=0;
		getClu(x,y);
		cluA[CluAnum]=temp;
		CluAnum++;
	}
	
	memset(board,0,sizeof(board));
	for(i=0;i<N;i++){
		x=pointB[i].x;
		y=pointB[i].y;
		board[x][y]=1;
	}
	
	for(i=0;i<N;i++){
		x=pointB[i].x;
		y=pointB[i].y;
		if(board[x][y]==-1)continue;
		temp=0;
		getClu(x,y);
		cluB[CluBnum]=temp;
		CluBnum++;
	}
	
	for(i=0;i<CluAnum;i++){
		cout<<cluA[i]<<"-";
	}
	cout<<endl;
	for(i=0;i<CluBnum;i++){
		cout<<cluB[i]<<"-";
	}
	cout<<endl;
	if(CluAnum!=CluBnum){
		cout<<"NO"<<endl;
	}
	else{
		sort(cluA,cluA+CluAnum);
		sort(cluB,cluB+CluBnum);
		int flag=1;
		for(i=0;i<CluAnum;i++){
			if(cluA[i]!=cluB[i]){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}	
	}		
	}
	return 0;
} 
