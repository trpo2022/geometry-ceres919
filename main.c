#include <stdio.h>
int main()
{
    FILE* TXT;
    char n[20];
    char* an;
    TXT = fopen("input.txt", "r");
    if (TXT == 0) {
        printf("Error\n");
        return 0;
    } else
        printf("line reading:\n");
    do {
        an = fgets(n, sizeof(n), TXT);
        if (an == NULL) {
            if (getc(TXT) != 0) {
                printf("Reading a file 'input' end\n");
                break;
            } else {
                printf("\nFile error 'input'\n");
                break;
            }
        }
        printf("%s", n);
    } while (1);
    printf("Result:");
    if (fclose(TXT) == 1)
        printf("Error\n");
    else
        printf("Complete\n");
    return 0;
}