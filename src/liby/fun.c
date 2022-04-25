#include "fun.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float S_circle(float r)
{
    float S_cir = M_PI * r * r;
    return S_cir;
}
float P_circle(float r)
{
    float P_cir = 2 * M_PI * r;
    return P_cir;
}
int checkfigure(char strf[])
{
    float r;
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
            && (strf[i + 1] == '\0' || strf[i + 1] == '\n'
                || strf[i + 1] == ' ')) {
            flag2++;
        } else {
            if (flag2 == 3 && strf[i] == ')'
                && (strf[i + 1] != '\n' || strf[i + 1] != '\0'
                    || strf[i + 1] != ' ')) {
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
            printf("\nFigure: %s", figure);
            parx = &strf[7];
            parrad = &strf[kr];
            printf("\nx=%.2f", strtod(parx, &pary));
            printf("\ny=%.2f", strtod(pary, &end));
            printf("\nradius=%.2f", r = strtod(parrad, &end));
        }
    }
    if (flag2 == 4) {
        printf("\nS=%.2f", S_circle(r));
        printf("\nP=%.2f", P_circle(r));
    }
    return 1;
}
