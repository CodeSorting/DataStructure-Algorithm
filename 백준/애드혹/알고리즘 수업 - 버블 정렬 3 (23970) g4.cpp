#include <cstdio>
#include <algorithm>

int A[10000],B[10000];
int eq[10000];

int main() {
    int n; scanf("%d", &n); //시간 때문에 scanf 사용
    for (int i=0;i<n;++i) scanf("%d", A+i);
    for (int i=0;i<n;++i) scanf("%d", B+i);

    int mismatches = 0;
    for (int i=0;i<n;++i) {
        if (A[i]==B[i]) eq[i] = 1;
        else {
            eq[i] = 0;
            ++mismatches;
        }
    }
    if (mismatches==0) {
        printf("1");
        return 0;
    }
    for (int i=n-1;i>0;--i) {
        for (int j=0;j<i;++j) {
            if (A[j] > A[j+1]) {
                int eq1 = eq[j]; int eq2 = eq[j+1];
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                int new1 = (A[j]   == B[j]); int new2 = (A[j+1] == B[j+1]);
                mismatches += (eq1 - new1) + (eq2 - new2);
                eq[j] = new1; eq[j+1] = new2;
                if (mismatches == 0) {
                    printf("1");
                    return 0;
                }
            }
        }
    }
    printf("0");
    return 0;
}
