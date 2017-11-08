#ifndef TWO_DIMENSIONAL_TRANSFORMATION_H_INCLUDED
#define TWO_DIMENSIONAL_TRANSFORMATION_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

///translation of one point to another
void translation(int tx, int ty, string file_name);
///rotation of a point about degrees
void rotation(float degree, string file_name);
///scaling if a point
void scaling(float sx, float sy, string file_name);
///mirror reflecting
void mirror(string x_or_y, string file_name);

#endif // TWO_DIMENSIONAL_TRANSFORMATION_H_INCLUDED
