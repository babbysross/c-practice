#include <stdio.h>
#define MAXLINE 1000


int getaline(char s[], int lim) {
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int trimline(char s[]) {
    int i = 0;

    while (s[i] != '\0') ++i;
    --i;

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) --i;
    ++i;
    s[i] = '\0';
    return i;
}

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = getaline(line, MAXLINE)) > 0) {
        int new_len = trimline(line);

        if (new_len > 0) {
            printf("%s\n", line);
        }
    }
    return 0;
}
