#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int,int>
#define ll long long
#define N (int)(1e5+10)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define nd second
#define st first
#define inf mod
#define endl '\n'
#define rgt (lft|1)
#define lft (root<<1)
#define mid (beg+end)/2
#define bit(x,y) ((x>>y)&1)

ll St[4*N],L[4*N];
int n,m,x,y,t,val;

void push(int root,int beg,int end){
	St[lft] += ((ll)mid-beg+1) * L[root];
	St[rgt] += ((ll)end-mid) * L[root];
	L[lft] += L[root];
	L[rgt] += L[root];
	L[root] = 0;
}

ll que(int root,int beg,int end,int x,int y){

	if(beg > y or end < x)
		return 0;
	
	if( x <= beg and end <= y)
		return St[root];
	
	push(root,beg,end);

	return que(lft,beg,mid,x,y) + que(rgt,mid+1,end,x,y);
}

ll upd(int root,int beg,int end,int x,int y,int val){

	if(beg > y or end < x)
		return St[root];
	
	if( x <= beg and end <= y){
		L[root] += val;
		return St[root] += ((ll)end-beg+1) * (val);
	}

	push(root,beg,end);

	return St[root] = upd(lft,beg,mid,x,y,val) + upd(rgt,mid+1,end,x,y,val);
}

int main(){
	cin >> n >> m;

	for(int i=1 ; i<=m; i++){
		cin >> t >> x >> y;

		if(t == 1){
			cin >> val;

			upd(1,1,n,x,y,val);
		}

		else{
			cout << que(1,1,n,x,y) << endl;
		}
	}
}