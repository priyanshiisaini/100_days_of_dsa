#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int sum = 0;
    int value;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &value);

            // Primary diagonal condition
            if(i == j) {
                sum += value;
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}
