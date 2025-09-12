#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char key[100];
    int i, len;

    if (argc != 2)
        return 1;

    len = strlen(argv[1]);
    for (i = 0; i < len; i++)
        key[i] = argv[1][i] + len;  /* Example logic from original keygen */

    key[len] = '\0';

    printf("%s", key);  // NO newline!
    return 0;
}
