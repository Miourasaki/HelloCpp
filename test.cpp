#include <iostream>
int fn(int n);

int main() {
    int qipan[30][30] = {0};
    int n,m;
    std::cin >> n >> m;
    for (int i =0 ; i<=n; i ++) {
        for (int j =0 ; j<=m; j ++) {
            if (i==0 && j==0) {
                continue;
            }
            if (i==0 || j==0) {
                qipan[i][j]=1;
            }else {
                qipan[i][j] = qipan[i-1][j] + qipan[i][j-1];
            }
        }
    }

    std::cout << qipan[n][m];
}



int fn(int n) {
    if (n <= 1) {
        return 1;
    }
    return fn(n - 1) * n;
}


