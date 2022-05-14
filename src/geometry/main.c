#include "liby/fun.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char strf[50];
    double xfig[5] = {0}, yfig[5] = {0}, rfig[5] = {0}, Sfig[5] = {0},
           Pfig[5] = {0};
    int n = 0;
    int id = 1;
    while (id != 0) {
        printf("\nEnter figure and parameters: ");
        fgets(strf, 50, stdin);
        checkfigure(strf, n, xfig, yfig, rfig, Sfig, Pfig);
        printf("\nanother one figure? 1/0  ");
        scanf("%d", &id);
        flush_input();
        if (id == 0)
            break;
        n++;
    }
    for (int j = 0; j < n; j++) {
        print(j, xfig, yfig, rfig, Sfig, Pfig);
        if (n > 0)
            intersect(j, n, xfig, yfig, rfig);
    }
    return 0;
}
