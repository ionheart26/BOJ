#include <iostream>
using namespace std;
int map[100][100];
long long d[100][100];
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    d[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int k = map[i][j];
            if (k == 0) continue;
            if (j+k < n) d[i][j+k] += d[i][j];
            if (i+k < n) d[i+k][j] += d[i][j];
        }
    }
    printf("%ld", d[n-1][n-1]);
    return 0;
}
