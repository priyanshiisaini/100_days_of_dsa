#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int start, end;
    char temp;

    // Input
    scanf("%s", s);

    start = 0;
    end = strlen(s) - 1;

    // Reverse the string
    while (start < end) {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }

    // Output
    printf("%s", s);

    return 0;
}
