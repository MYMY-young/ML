#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int** visited;
int** square;
int n;
int k = 1;
int* result;
int dfs(int a, int b);
int main() {
	
	scanf("%d", &n);
	
	square = (int**)malloc(sizeof(int*) * n);
	for (int i = 0;i < n;i++) {
		square[i] = (int*)malloc(sizeof(int) * n);
	}
	
	visited = (int**)malloc(sizeof(int*) * n);
	for (int i = 0;i < n;i++) {
		visited[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			visited[i][j] = 0;
		}
	}
	
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%1d", &square[i][j]);
		}
	}
	result = (int*)malloc(sizeof(int) * (n*n));
	//printf("%d", square[0][1]);
	int num = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (square[i][j] == 1 && !visited[i][j]) {
			//	printf("aa %d %d\n", i, j);
				result[num++] = dfs(i,j);
				
				k = 1;
				
				//printf("aa : %d\n", a);
			}
		}
	}
	printf("%d\n", num);
	sort(result,result+num);
	for (int i = 0;i < num;i++) {
		printf("%d\n", result[i]);
		
	}
	return 0;
}

int dfs(int a, int b) {
	visited[a][b] = 1;
	
	if (b<n-1 && square[a][b + 1] == 1 && !visited[a][b + 1]) {
	///	printf("%d %d\n", a, b + 1);
		dfs(a, b + 1);
		k++;
	}
	if (a<n-1&&square[a+1][b] == 1 && !visited[a+1][b]) {
	//	printf("%d %d\n", a+1, b);
		dfs(a + 1, b);
		k++;
	}
	if (a>=1 && square[a-1][b] == 1 && !visited[a-1][b]) {
	//	printf("%d %d\n", a-1, b);
		dfs(a - 1, b);
		k++;
	}
	if (b>=1 && square[a][b - 1] == 1 && !visited[a][b - 1]) {
	//	printf("%d %d\n", a, b - 1);
		dfs(a, b - 1);
		k++;
	}
	if(k==1) {
		k = 1;
	}
	return k;
}