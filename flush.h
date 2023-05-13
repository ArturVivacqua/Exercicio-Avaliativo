#include <stdio.h>

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
