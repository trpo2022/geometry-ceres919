#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "liby/fun.h"

int main()
{
    char strf[50];
    printf("Enter figure and parameters: ");
	fgets(strf, 50, stdin);
    checkfigure(strf);
    return 0;
}
