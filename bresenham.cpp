#include "bresenham.h"
#include <graphics.h>
#include <conio.h>

///write x,y coordinates of circle in a file
void print_in_file_circle(int r, int tx, int ty, string file_name, string r_w, string check_print_y_or_n)
{
    if (r < 0)
        r = -r;
    FILE *fp = fopen(file_name.c_str(), r_w.c_str());
    int x = 0, y = r, d = 3 - 2 * r;
    while(x <= y)
    {
        fprintf(fp, "%d %d\n",x+tx,y+ty);
        fprintf(fp, "%d %d\n",x+tx,-y+ty);
        fprintf(fp, "%d %d\n",-x+tx,y+ty);
        fprintf(fp, "%d %d\n",-x+tx,-y+ty);
        fprintf(fp, "%d %d\n",y+tx,x+ty);
        fprintf(fp, "%d %d\n",y+tx,-x+ty);
        fprintf(fp, "%d %d\n",-y+tx,x+ty);
        fprintf(fp, "%d %d\n",-y+tx,-x+ty);


        if(d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    fclose(fp);
    if(check_print_y_or_n == "Y" || check_print_y_or_n == "y")
        print_from_file_circle_or_line(file_name);

}
///write x,y coordinates of line in a file
void print_in_file_line(int x1, int y1,int x2, int y2, string file_name, string r_w, string check_print_y_or_n)
{
    FILE *fp = fopen(file_name.c_str(), r_w.c_str());

    int x, y;
    //cin >> x1 >> y1 >> x2 >> y2;
    //initwindow(500, 500, "f");
    if(x1 == x2 && y1 == y2) //for 45 degree
    {
        x = x1, y = y1;
        while(x <= x1)
        {
            fprintf(fp, "%d %d\n",x,y);
            //putpixel(250 + x,250 + -y, RED);
            y++;
            x++;
        }
    }
    else if(x1 == x2) //for vertical
    {
        if(y1 > y2)
        {
            int t = y1;
            y1 = y2;
            y2 = t;

        }
        x = x1, y = y1;
        while(y <= y2)
        {
            fprintf(fp, "%d %d\n",x,y);
            //putpixel(250 + x,250 + -y, RED);
            y++;
        }
    }
    else if(y1 == y2) //for horizontal
    {
        if(x1 > x2)
        {
            int t = x1;
            x1 = x2;
            x2 = t;
        }
        x = x1, y = y1;
        while(x <= x2)
        {
            fprintf(fp, "%d %d\n",x,y);
            //putpixel(250 + x,250 + -y, RED);
            x++;
        }
    }
    else //for another
    {
        float m = (float)(y2 - y1) / (x2 - x1);

        int a = 0;

        if(0 < m && m <= 1) //0 t0 45 degree
        {
            if((x2 - x1) < 0 && (y2 - y1) < 0) //direction one way
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            a = 1;
        }
        else if(-1 <= m && m < 0) //0 t0 -45 degree
        {
            if((x2 - x1) < 0 && (y2 - y1) > 0) //one way dir
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            a = 2;
            y1 = -y1;
            y2 = -y2;

        }
        else if(m < -1) //90 to 120
        {
            if((x2 - x1) > 0 && (y2 - y1) < 0)
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            a = 3;
            int temp = x1;
            x1 = y1;
            y1 = -temp;
            temp = x2;
            x2 = y2;
            y2 = -temp;
        }
        else if(m > 1) //90 to 45
        {
            if((x2 - x1) < 0 && (y2 - y1) < 0)
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            a = 4;
            int temp = x1;
            x1 = y1;
            y1 = temp;
            temp = x2;
            x2 = y2;
            y2 = temp;
        }

        //cout << "done"  << endl;
        x = x1, y = y1;
        int dx = x2 - x1, dy = y2 - y1, dT = 2 * (dy - dx), dS = 2 * dy;
        int d = 2 * dy - dx;

        if(a == 2)
            fprintf(fp, "%d %d\n",x,-y);
        //putpixel(250 + x,250 + -(-y), RED);
        else if(a == 3)
            fprintf(fp, "%d %d\n",y,-x);
        //putpixel(250 + y,250 + -(-x), RED);
        else if(a == 4)
            fprintf(fp, "%d %d\n",y,x);
        //putpixel(250 + y,250 + -x, RED);
        else
            fprintf(fp, "%d %d\n",x,y);
        //putpixel(250 + x,250 + -y, RED);
        while(x < x2)
        {
            x++;
            if(d < 0)
                d = d + dS;
            else
            {
                y++;
                d = d + dT;
            }
            if(a == 2)
                fprintf(fp, "%d %d\n",x,-y);
            //putpixel(250 + x,250 + -(-y), RED);
            else if(a == 3)
                fprintf(fp, "%d %d\n",y,-x);
            //putpixel(250 + y,250 + -(-x), RED);
            else if(a == 4)
                fprintf(fp, "%d %d\n",y,x);
            //putpixel(250 + y,250 + -x, RED);
            else
                fprintf(fp, "%d %d\n",x,y);
            //putpixel(250 + x,250 + -y, RED);
        }
    }

    fclose(fp);
    if(check_print_y_or_n == "Y" || check_print_y_or_n == "y")
        print_from_file_circle_or_line(file_name);
}
///print x,y coordinates from file
void print_from_file_circle_or_line(string file_name)
{

    //int a = 0;
    int xco = 1200, yco = 760;
    initwindow(xco, yco, "bresenham algorithm");
    for(int i = 0; i < xco; i++)
        for(int j = 0; j < yco; j++)
        {
            if(i % 20 == 0 || j % 20 == 0)
                putpixel(i, j, GREEN);
            if(i == xco / 2 || j == yco / 2)
                putpixel(i, j, RED);

            //    outtext(2,2,"bfds")
        }

   /* while(a < xco/2)
    {

                putpixel(xco/2 + a, yco/2 + 0, GREEN);
                putpixel(xco/2 + 0, yco/2 + -a, GREEN);
                putpixel(xco/2 - a, yco/2 + 0, GREEN);
                putpixel(xco/2 + 0, yco/2 + a++, GREEN);

    }
*/
    int x, y;
    FILE *fp = fopen(file_name.c_str(), "r");
    if(fp)
    {


        while((fscanf(fp, "%d %d\n", &x, &y)) != EOF)
        {

            putpixel(xco/2 + x, yco/2 + -y, WHITE);

            //delay(50);

        }

    }

    fclose(fp);
    getch();
    closegraph();
}

