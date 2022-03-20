#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkfigure(char strf[])
{
    char figure[] = "circle";
    int i = 0, kr, flag1 = 0, flag2 = 0;
    if (strncmp(strf, figure, 6) == 0) {
        if (strf[6] == '(') {
            flag1 = 1;
        } else {
            if (strf[6] == ' ') {
                printf("\nError: unexpected space");
                return 1;
            } else {
                printf("\nError: wrong name figure");
                return 2;
            }
        }
    } else {
        printf("\nError: wrong name figure");
        return 3;
    }

    if (flag1 == 1) {
        i = 7;
        while (strf[i] != ')' && strf[i] != '\0') {
            if (strf[i - 1] == '(' && strf[i] == ' ') {
                printf("\nError: unexpected space after '('");
                return 9;
            }
            if (flag2 == 0
                && (isdigit(strf[i]) != 0 || strf[i] == '-'
                    || strf[i] == '.')) {
                i++;
                if (strf[i] == ' ') {
                    flag2++;
                    i++;
                }
            }
            if (flag2 == 0 && strf[i] == ',') {
                printf("\nError: unexpected token #1");
                return 4;
            }
            if (flag2 == 1 && strf[i] == ',') {
                printf("\nError: unexpected token #2");
                return 4;
            }
            if (flag2 == 1
                && (isdigit(strf[i]) != 0 || strf[i] == '-'
                    || strf[i] == '.')) {
                i++;
                if (strf[i] == ',' && strf[i + 1] == ' '
                    && strf[i + 2] != '-') {
                    flag2++;
                    kr = i + 1;
                    i += 2;
                }
                if (strf[i] == ',' && strf[i + 1] != ' ') {
                    printf("\nError: expected space after ','");
                    return 4;
                }
                if (strf[i] == ',' && strf[i + 2] == '-') {
                    printf("\nError: unexpected '-'");
                    return 13;
                }
            }
            if (flag2 == 2 && strf[i] == ' ') {
                printf("\nError: unexpected token #3, i=%d", i);
                return 4;
            }
            if (flag2 == 2 && (isdigit(strf[i]) != 0 || strf[i] == '.')) {
                i++;
                if (strf[i] == ')') {
                    flag2++;
                }
            }
            if (isdigit(strf[i]) == 0 && strf[i] != '-' && strf[i] != '.'
                && strf[i] != ',' && strf[i] != ' ' && strf[i] != ')') {
                printf("\nError: unexpected token %d", i);
                return 5;
            }
            if (strf[i] == ')')
                continue;
        }
        if (flag2 == 3 && strf[i] == ')'
            && (strf[i + 1] == '\0' || strf[i + 1] == '\n'  || strf[i + 1] == ' ')) {
            flag2++;
        } else {
            if (flag2 == 3 && strf[i] == ')'&& (strf[i + 1] != '\n' || strf[i + 1] != '\0' || strf[i + 1] != ' ')) {
                printf("\nError: unexpected token after ')'");
                return 6;
            }
            if (flag2 != 3 && strf[i] == ')') {
                printf("\nError: wrong parametrs");
                return 7;
            }
        }
        if (flag2 == 4) {
            char *parx, *pary, *parrad, *end;
            printf("\nFigure: %s\n", figure);
            parx = &strf[7];
            parrad = &strf[kr];
            printf("x=%.2f\n", strtod(parx, &pary));
            printf("y=%.2f\n", strtod(pary, &end));
            printf("radius=%.2f\n", strtod(parrad, &end));
        }
    }
    return 1;
}

int main()
{
    char strf[50];
    printf("Enter figure and parameters: ");
	fgets(strf, 50, stdin);
    checkfigure(strf);
    return 0;
}