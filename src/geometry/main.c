#include "liby/fun.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char strf[50];
    printf("Enter figure and parameters: ");
    fgets(strf, 50, stdin);
    checkfigure(strf);
    return 0;
}