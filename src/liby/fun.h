#pragma once

double S_circle(double r);
double P_circle(double r);
int checkfigure(
        char strf[],
        int n,
        double xfig[],
        double yfig[],
        double rfig[],
        double Sfig[],
        double Pfig[]);
void intersect(int j, int n, double xfig[], double yfig[], double rfig[]);
void print(
        int j,
        double xfig[],
        double yfig[],
        double rfig[],
        double Sfig[],
        double Pfig[]);
void flush_input();
