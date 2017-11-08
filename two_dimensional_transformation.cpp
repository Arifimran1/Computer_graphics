#include "two_dimensional_transformation.h"
#include <graphics.h>
#include <conio.h>

///translation of one point to another
void translation(int tx, int ty, string file_name)
{
    int a = 0;
    int xco = 1200, yco = 760;
    initwindow(xco, yco, "two_D algorithm");
    for(int i = 0; i < xco; i++)
        for(int j = 0; j < yco; j++)
        {
            if(i % 20 == 0 || j % 20 == 0)
                putpixel(i, j, GREEN);
            if(i == xco / 2 || j == yco / 2)
                putpixel(i, j, RED);

            //    outtext(2,2,"bfds")
        }


    int x, y;
    FILE *fp = fopen(file_name.c_str(), "r");
    if(fp)
    {


        while((fscanf(fp, "%d %d\n", &x, &y)) != EOF)
        {

            putpixel(xco/2 + x, yco/2 + -y, WHITE);
            x = x + tx;
            y = y + ty;
            putpixel(xco/2 + x, yco/2 + -y, YELLOW);
            //delay(50);

        }

    }

    fclose(fp);
    getch();
    closegraph();
}

///rotation of a point about degrees
void rotation(float degree, string file_name)
{

    degree = degree * 3.14159 / 180;
    int a = 0;
    int xco = 1200, yco = 760;
    initwindow(xco, yco, "two_D algorithm");
    for(int i = 0; i < xco; i++)
        for(int j = 0; j < yco; j++)
        {
            if(i % 20 == 0 || j % 20 == 0)
                putpixel(i, j, GREEN);
            if(i == xco / 2 || j == yco / 2)
                putpixel(i, j, RED);

            //    outtext(2,2,"bfds")
        }


    int x, y;
    FILE *fp = fopen(file_name.c_str(), "r");
    if(fp)
    {


        while((fscanf(fp, "%d %d\n", &x, &y)) != EOF)
        {

            putpixel(xco/2 + x, yco/2 + -y, WHITE);
            x = int(x * cos(degree) - y * sin(degree));
            y = int(x * sin(degree) + y * cos(degree));
            putpixel(xco/2 + x, yco/2 + -y, YELLOW);

            //cout << x << " " << y << endl;
        }


    }

    fclose(fp);
    getch();
    closegraph();
}
///scaling if a point
void scaling(float sx, float sy, string file_name)
{


    int a = 0;
    int xco = 1200, yco = 760;
    initwindow(xco, yco, "two_D algorithm");
    for(int i = 0; i < xco; i++)
        for(int j = 0; j < yco; j++)
        {
            if(i % 20 == 0 || j % 20 == 0)
                putpixel(i, j, GREEN);
            if(i == xco / 2 || j == yco / 2)
                putpixel(i, j, RED);

            //    outtext(2,2,"bfds")
        }


    int x, y;
    FILE *fp = fopen(file_name.c_str(), "r");
    if(fp)
    {


        while((fscanf(fp, "%d %d\n", &x, &y)) != EOF)
        {

            putpixel(xco/2 + x, yco/2 + -y, WHITE);
            x = int(x * sx);
            y = int(y * sy);
            putpixel(xco/2 + x, yco/2 + -y, YELLOW);
        }


    }

    fclose(fp);
    getch();
    closegraph();
}
///mirror reflecting
void mirror(string x_or_y, string file_name)
{

    int a = 0;
    int xco = 1200, yco = 760;
    initwindow(xco, yco, "two_D algorithm");
    for(int i = 0; i < xco; i++)
        for(int j = 0; j < yco; j++)
        {
            if(i % 20 == 0 || j % 20 == 0)
                putpixel(i, j, GREEN);
            if(i == xco / 2 || j == yco / 2)
                putpixel(i, j, RED);

            //    outtext(2,2,"bfds")
        }


    int x, y;
    FILE *fp = fopen(file_name.c_str(), "r");
    if(fp)
    {


        while((fscanf(fp, "%d %d\n", &x, &y)) != EOF)
        {

            putpixel(xco/2 + x, yco/2 + -y, WHITE);
            if(x_or_y == "x" || x_or_y == "X")
                y = -y;
            else
                x = -x;
            putpixel(xco/2 + x, yco/2 + -y, YELLOW);
        }


    }

    fclose(fp);
    getch();
    closegraph();
}
