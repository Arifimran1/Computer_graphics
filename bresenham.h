#ifndef BRESENHAM_H_INCLUDED
#define BRESENHAM_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

///write x,y coordinates of circle in a file
void print_in_file_circle(int r, int tx, int ty, string file_name, string r_w, string check_print_y_or_n);
///write x,y coordinates of line in a file
void print_in_file_line(int x1, int y1,int x2, int y2, string file_name,string r_w, string check_print_y_or_n);
///print x,y coordinates from file
void print_from_file_circle_or_line(string file_name);


#endif // BRESENHAM_H_INCLUDED
