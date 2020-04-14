#include <stdio.h>

#define MAX 32

void algo_1(int p[MAX][MAX], int n);

int main() {
	int p[MAX][MAX], n, val, i, j;
	printf("Enter no. of elements in the set: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("Enter zero/one value at position %d %d of the relation matrix: ", i, j);
			scanf("%d", &val);
			p[i][j] = val;
		}
	}
	printf("The input relation matrix is:\n");
        for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                        printf("%d\t", p[i][j]);
                }
		printf("\n");
        }
	algo_1(p, n);
	return 0;
}

void algo_1(int p[MAX][MAX], int n) {
	int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX], i, j, k, l, sum = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			a[i][j] = b[i][j] = p[i][j];
		}
	}
	for(l = 1; l < n; l++) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				for(k = 0 ; k < n; k++) {
					sum = sum + a[i][k] * p[k][j];
				}
			c[i][j] = sum;
			sum = 0;
			}
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				a[i][j] = c[i][j];
			}
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				b[i][j] = b[i][j] || a[i][j];
			}
		}
	}
	printf("The transitive closure matrix is:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
}
	
