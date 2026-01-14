#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;

struct Graph {
	int len[N];
	int parent[N];
	int next[N];
	bool bennE[N];
} g;

int dfs(int u) {
	g.bennE[u]=1;
	if (g.len[u]!=-1) {
		g.bennE[u]=0;
		return g.len[u];
	}
	int v=g.next[u];

	if (g.bennE[v]) {
		int circle=0;
		for (int w=u; ; w=g.parent[w]) {
			circle++;
			if (w==v) break;
		}
		for (int w=u; ; w=g.parent[w]) {
			g.len[w]=circle;
			if (w==v) break;
		}
		g.bennE[u]=0;
		return g.len[u];
	}
	g.parent[v]=u;
	int help=dfs(v);
	
	if (g.len[u]==-1) {
		g.len[u]=help+1;
	}
	g.bennE[u]=0;
	return g.len[u];
} 

int main() {
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> g.next[i]; 
	}
	memset(g.len, -1, sizeof g.len); // mint egy init for csak gyorsabb elv.

	int megold=0, legtobb=0; 
	for (int i=1; i<=n; i++) {
		int tmp=dfs(i);
		if (tmp>legtobb) {
			legtobb=tmp;
			megold=i;
		}
	}
	cout << megold << " " << legtobb;
}
