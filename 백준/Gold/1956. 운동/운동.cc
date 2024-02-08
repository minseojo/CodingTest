#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int dist[401][401];
int main() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
	
	for (int k = 1; k <= n; k++) { // 중간 노드 
		for (int i = 1; i <= n; i++) { // 시작 노드 
			for (int j = 1; j <= n; j++) { // 끝 노드 
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	int answer = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (dist[i][j] != INF && dist[j][i] != INF) {
				answer = min(answer, dist[i][j] + dist[j][i]);
			}
		}
	}
	
	if (answer == INF) {
		cout << -1;
	} else {
		cout << answer;
	}
	
	return 0;
}