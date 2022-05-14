#include "fun.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double S_circle(double r)
{
    double S = M_PI * r * r;
    return S;
}
double P_circle(double r)
{
    double P = 2 * M_PI * r;
    return P;
}

void parsstr(
        char strf[], int kr, int n, double xfig[], double yfig[], double rfig[])
{
    char *parx, *pary, *parrad, *end;
    parx = &strf[7];
    parrad = &strf[kr];
    xfig[n] = strtod(parx, &pary);
    yfig[n] = strtod(pary, &end);
    rfig[n] = strtod(parrad, &end);
}

int checkfigure(
        char strf[],
        int n,
        double xfig[],
        double yfig[],
        double rfig[],
        double Sfig[],
        double Pfig[])
{
    char figure[] = "circle";
    int i = 0, kr, flag1 = 0, flag2 = 0;
    if (strncasecmp(strf, figure, 6) == 0) {
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
    }
    if (flag2 == 4) {
        parsstr(strf, kr, n, xfig, yfig, rfig);
        Sfig[n] = S_circle(rfig[n]);
        Pfig[n] = P_circle(rfig[n]);
    }
    return 1;
}
void intersect(int j, int n, double xfig[], double yfig[], double rfig[])
{
    float d;
    int g = 0;
    char figure[] = "circle";
    for (int k = 0; k <= n; k++) {
        if (k == j)
            continue;
        d = fabs(sqrt(
                pow((xfig[k] - xfig[j]), 2) + pow((yfig[k] - yfig[j]), 2)));
        if (d <= (rfig[j] + rfig[k]))
            g++;
    }
    if (g > 0) {
        printf("\nintersect: ");
        for (int i = 0; i < g; i++)
            printf("\n%s", figure);
    }
}
void print(
        int j,
        double xfig[],
        double yfig[],
        double rfig[],
        double Sfig[],
        double Pfig[])
{
    char figure[] = "circle";
    printf("\n\nFigure: %s", figure);
    printf("\nx=%.2f", xfig[j]);
    printf("\ny=%.2f", yfig[j]);
    printf("\nradius=%.2f", rfig[j]);
    printf("\narea=%.2f", Sfig[j]);
    printf("\nperimetr=%.2f", Pfig[j]);
}
void flush_input()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}
