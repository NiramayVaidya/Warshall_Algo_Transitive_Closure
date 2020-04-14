#include <stdio.h>

#define MAX 32

int max(int,int);

void warshall(int p[MAX][MAX], int n);

int main() {
	int p[MAX][MAX] = {0}, n, e, u, v, i, j;
	printf("Enter the number of vertices(n): ");
	scanf("%d", &n);
	printf("Enter the number of edges(n): ");
	scanf("%d", &e);
	for(i = 1; i <= e; i++) {
		printf("Enter the end vertices of edge %d: ", i);
		scanf("%d%d", &u, &v);
		p[u][v] = 1;
	}
	printf("Matrix of input data:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d\t", p[i][j]);
		}
		printf("\n");
	}
	warshall(p, n);
	return 0;
}

void warshall(int p[MAX][MAX],int n) {
        int i, j, k;
        for(k = 0; k < n; k++) {
                for(i = 0; i < n; i++) {
                        for(j = 0; j < n; j++) {
//				printf("p[i][j]=%d  p[i][k]=%d  p[k][j]=%d  i=%d  k=%d  j=%d\n", p[i][j], p[i][k], p[k][j], i, k, j);
                                p[i][j] = max(p[i][j], (p[i][k] && p[k][j]));
                        }
                }
        }
        printf("Transitive closure:\n");
        for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                        printf("%d\t", p[i][j]);
                }
                printf("\n");
        }
}

int max(int a,int b) {
        if(a > b) {
                return(a);
        }
        else {
                return(b);
        }
}
