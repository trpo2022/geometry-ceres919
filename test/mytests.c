#include <liby/fun.h>
#include <ctest.h>
#include <math.h>
#include <stdlib.h>
double xfig[5]={0}, yfig[5]={0}, rfig[5]={0}, Sfig[5]={0}, Pfig[5]={0};
CTEST(suite, area1) {
    rfig[0] = 3;
    const double exp = 28.274334;
    double real = S_circle(rfig[0]);
    ASSERT_DBL_NEAR(exp, real);
}
CTEST(suite, area2) {
    rfig[0] = 8.5;
    const double exp = 226.980072;
    double real = S_circle(rfig[0]);
    ASSERT_DBL_NEAR(exp, real);
}
CTEST(suite1, perimetr1) {
    rfig[0] = 5;
    const double exp = 31.415926;
    double real = P_circle(rfig[0]);
    ASSERT_DBL_NEAR(exp, real);
}
CTEST(suite1, perimetr2) {
    rfig[0] = 1.5;
    const double exp = 9.424778;
    double real = P_circle(rfig[0]);
    ASSERT_DBL_NEAR(exp, real);
}
CTEST(suite2, check1)
{
    char strf[50] = "circle(4 -5, 10)";
    int n = 0;
    int exp = 1;
    int real = 0;
    checkfigure(strf, n, xfig, yfig, rfig, Sfig, Pfig);
    if (xfig[0] == 4 && yfig[0] == -5 && rfig[0] == 10)
        real = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(suite2, check2)
{
    char strf[50] = "circle(-6.56 8, 8.9)";
    int n = 0;
    int exp = 1;
    int real = 0;
    checkfigure(strf, n, xfig, yfig, rfig, Sfig, Pfig);
    if (xfig[0] == -6.56 && yfig[0] == 8 && rfig[0] == 8.9)
        real = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(suite2, check3)
{
    char strf[50] = "circle(98 2.25, 3)";
    int n = 0;
    int exp = 1;
    int real = 0;
    checkfigure(strf, n, xfig, yfig, rfig, Sfig, Pfig);
    if (xfig[0] == 98 && yfig[0] == 2.25 && rfig[0] == 3)
        real = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(suite3, intersect1)
{
    xfig[0] = 5;
    yfig[0] = 3;
    rfig[0] = 3;
    int n = 0;
    int real = 0;
    int j = 0;
    for (int k = 0; k <= n; k++) {
		if (k == j) continue;
		float d = fabs(sqrt(pow((xfig[k]-xfig[j]), 2) + pow((yfig[k]-yfig[j]), 2)));
		if (d <= (rfig[j] + rfig[k])) real++;
	}
    int exp = 0;
    ASSERT_EQUAL(exp, real);
}
CTEST(suite3, intersect2)
{
    xfig[0] = 5;
    yfig[0] = 3;
    rfig[0] = 3;
    xfig[1] = 9;
    yfig[1] = 5;
    rfig[1] = 2;
    int n = 1;
    int real = 0;
    int j = 0;
    for (int k = 0; k <= n; k++) {
		if (k == j) continue;
		float d = fabs(sqrt(pow((xfig[k]-xfig[j]), 2) + pow((yfig[k]-yfig[j]), 2)));
		if (d <= (rfig[j] + rfig[k])) real++;
	}
    int exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(suite3, intersect3)
{
    xfig[0] = 5;
    yfig[0] = 3;
    rfig[0] = 3;
    xfig[1] = 9;
    yfig[1] = 5;
    rfig[1] = 2;
    xfig[2] = 9;
    yfig[2] = 5;
    rfig[2] = 2;
    int n = 2;
    int real = 0;
    int j = 0;
    for (int k = 0; k <= n; k++) {
		if (k == j) continue;
		float d = fabs(sqrt(pow((xfig[k]-xfig[j]), 2) + pow((yfig[k]-yfig[j]), 2)));
		if (d <= (rfig[j] + rfig[k])) real++;
	}
    int exp = 2;
    ASSERT_EQUAL(exp, real);
}