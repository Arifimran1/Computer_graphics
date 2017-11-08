#include "cohen_sutherland.h"
#include "bresenham.h"
#include <graphics.h>
#include <conio.h>

void cohen_suthenland()
{

}

int get_region_code(int xmin, int xmax, int ymin, int ymax, int x, int y)
{
    int bit1 = 0, bit2 = 0, bit3 = 0, bit4 = 0, num = 0;
    if((y-ymax) >= 0)
        bit1 = 1;
    if((ymin-y) >= 0)
        bit2 = 1;
    if((x-xmax) >= 0)
        bit3 = 1;
    if((xmin-x) >= 0)
        bit4 = 1;
    num = bit1 * 8 + bit2 * 4 + bit3 * 2 + bit4 * 1;
    return num;
}

void _cohen_sutherland()
{
    //int x1, y1, x2, y2;
    int xmin, xmax, ymin, ymax;
    string ff;
    system("cls");
    cout << "Enter xmin, ymin, xmax, ymax: " << endl;
    cin >> xmin >> ymin >> xmax >> ymax;
    cout << "enter file name(path:\folder\folder...)" << endl;
    cin >> ff;
    print_in_file_line(xmin, ymin, xmax, ymin, ff, "w+", "n");
    print_in_file_line(xmin, ymax, xmax, ymax, ff, "a+","n");
    print_in_file_line(xmin, ymin, xmin, ymax, ff, "a+","n");
    print_in_file_line(xmax, ymin, xmax, ymax, ff, "a+","n");

    int nn;
    int linee[100][4];
    cout << "enter the number of lines:" << endl;
    cin >> nn;
    for(int i = 0; i < nn; i++)
    {
        cout << "enter line " << i << " x1, y1, x2, y2: " << endl;
        cin >> linee[i][0] >> linee[i][1] >> linee[i][2] >> linee[i][3];

        if((get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1]) == 0) && (get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3]) == 0))
        {

            print_in_file_line(linee[i][0], linee[i][1], linee[i][2], linee[i][3], ff, "a+","n");
        }
        else if((get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1]) & get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3])) == 0)
        {
            //cout << get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1]) << endl;
            //cout << get_region_code(xmin, xmax, ymin, ymax, linee[i][3], linee[i][4]) << endl;
            //cout << (get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1]) & get_region_code(xmin, xmax, ymin, ymax, linee[i][3], linee[i][4])) << endl;

            float m = (linee[i][1] - linee[i][3]) / (linee[i][0] - linee[i][2]);

            if(get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1])!=0)
            {

                while(1)
                {
                    if((get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1])&8)==8)
                    {
                        linee[i][0] = int(linee[i][0] + (ymax - linee[i][1]) / m);
                        linee[i][1] = ymax;
                    }
                    else if((get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1])&4)==4)
                    {
                        linee[i][0] = int(linee[i][0] + (ymin - linee[i][1]) / m);
                        linee[i][1] = ymin;
                    }
                    else if((get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1])&2)==2)
                    {
                        linee[i][1] = int(linee[i][1] + (xmax - linee[i][0]) * m);
                        linee[i][0] = xmax;
                    }
                    else if((get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1])&1)==1)
                    {
                        linee[i][1] = int(linee[i][1] + (xmin - linee[i][0]) * m);
                        linee[i][0] = xmin;
                    }
                    if(get_region_code(xmin, xmax, ymin, ymax, linee[i][0], linee[i][1])!=0)
                        break;

                }
            }
            if(get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3])!=0)
            {


                while(1)
                {
                    if((get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3])&8)==8)
                    {
                        linee[i][2] = int(linee[i][2] + (ymax - linee[i][3]) / m);
                        linee[i][3] = ymax;
                    }
                    else if((get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3])&4)==4)
                    {
                        linee[i][2] = int(linee[i][2] + (ymin - linee[i][3]) / m);
                        linee[i][3] = ymin;
                    }
                    else if((get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3])&2)==2)
                    {
                        linee[i][3] = int(linee[i][3] + (xmax - linee[i][2]) * m);
                        linee[i][2] = xmax;
                    }
                    else if((get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3])&1)==1)
                    {
                        linee[i][3] = int(linee[i][3] + (xmin - linee[i][2]) * m);
                        linee[i][2] = xmin;
                    }
                    if(get_region_code(xmin, xmax, ymin, ymax, linee[i][2], linee[i][3])!=0)
                        break;

                }
            }

            print_in_file_line(linee[i][0], linee[i][1], linee[i][2], linee[i][3], ff, "a+","n");
        }
    ///
    }
    print_from_file_circle_or_line(ff);

}
