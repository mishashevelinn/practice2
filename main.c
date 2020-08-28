#include <stdio.h>
#include "bits1.h"

int main() {
    char str[] = "ababd01233ababd456789ababd";
    char sbstr[] = "ababd";
    char insert[] = "in";
    char* res = substitute(str, sbstr, insert, 2);
    printf("%s", res);
    return 0;
}
