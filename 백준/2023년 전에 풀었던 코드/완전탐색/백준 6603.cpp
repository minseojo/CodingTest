#include <bits/stdc++.h>
using namespace std;

int arr[13];
int tmp[13];
bool check[13];
int n;

void f(int pos, int index) {
	if(pos==6) {
		for(int i=0; i<6; i++) {
			cout << tmp[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for(int i=index; i<n; i++) {
		if(!check[i]) {
			check[i]=true;
			tmp[pos]=arr[i];
			f(pos+1, i);
			check[i]=false;
		}
	}
}

int main() {
	while(1) {
		cin >> n;
		if(n==0) break;
		
		memset(arr, 0, sizeof(arr));
		
		for(int i=0; i<n; i++)
			cin >> arr[i];
			
		f(0, 0);
		cout << endl; 
	}
} 
