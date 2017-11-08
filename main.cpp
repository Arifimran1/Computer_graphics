#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<bits/stdc++.h>
#include"bresenham.h"
#include"two_dimensional_transformation.h"
#include"cohen_sutherland.h"

void _bresenham();
void _translation();
void _rotation();
void scaling();
void mirroring();
void _two_D();
void _clip_point();
void _cohen_sutherland();


using namespace std;
int main()
{
    //int r;
    //string file_name = "abcd.txt";
    //cout << "Please enter radius for a circle:" << endl;


    //cin >> r;
    ///cin >> r >> file_name;

    //print_in_file_circle(r, 100, 0, file_name);


    //print_from_file_circle_or_line(file_name);

    //int x1, x2, y1, y2;
    //cout << "Please enter x1,y1 and x2,y2 for a line" << endl;
    //cin >> x1 >> y1 >> x2 >> y2;
    ///cin >> x1 >> y1 >> x2 >> y2 >> file_name;

    //print_in_file_line(x1, y1, x2, y2, file_name);
    //print_from_file_circle_or_line(file_name);

    //cout << "translation" << endl;
    //translation(20, 30, file_name);
    //cout << "rotation" << endl;
    //rotation(180, file_name);
    //cout << "scaling" << endl;
    //scaling(2, .5, file_name);
    //cout << "mirror" << endl;
    //mirror('y', file_name);


    //cout << "end" << endl;

    string choice;
    while(1)
    {
        cout << "1. Bresenham line and circle" << endl;
        cout << "2. Two dimensional transformation" << endl;
        cout << "3. Rectangle" << endl;
        cout << "4. Point clipping" << endl;
        cout << "5. Conhen Sutherland" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter number: " ;
        cin >> choice;
        if(choice == "1")
        {
            system("cls");
            _bresenham();
        }
        else if(choice == "2")
        {
            system("cls");
            _two_D();
        }
        else if(choice == "3")
        {
            int x1, y1, x2, y2;
            string ff;
            system("cls");
            cout << "Enter x1, y1, x2, y2" << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> ff;
            print_in_file_line(x2, y2, x2, y1, ff, "a+", "n");
            print_in_file_line(x1, y2, x1, y1, ff, "a+","n");
            print_in_file_line(x1, y2, x2, y2, ff, "a+","n");
            print_in_file_line(x1, y1, x2, y1, ff, "a+","n");
            print_from_file_circle_or_line(ff);
        }
        else if(choice == "4")
        {
            system("cls");
            _clip_point();
        }
        else if(choice == "5")
        {
            system("cls");
            _cohen_sutherland();
        }
        else if(choice == "0")
            break;
        else
        {
            cout << "wrong key!!!" << endl;
            Sleep(500);
        }

        system("cls");
    }

    return 0;
}

void _bresenham()
{
    int x1, x2, y1, y2;
    int r,tx, ty;
    string file_name, choice;
    while(1)
    {
        cout << "1. Bresenham line" << endl;
        cout << "2. Bresenham Circle" << endl;
        cout << "3. Draw from file" << endl;
        cout << "0. Back" << endl;
        cout << "Enter number: " ;
        cin >> choice;
        if(choice == "1")
        {
            cout << "Enter x1, y1, x2, y2" << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            print_in_file_line(x1, y1, x2, y2, file_name,"w+","y");
        }
        else if(choice == "2")
        {
            cout << "Enter radious:" << endl;
            cin >> r;
            cout << "Enter the circle points(x, y)" << endl;
            cin >> tx >> ty;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;

            print_in_file_circle(r, tx, ty, file_name, "w+","y");
        }
        else if(choice == "3")
        {
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            print_from_file_circle_or_line(file_name);
        }
        else if(choice == "0")
            break;
        else
        {
            cout << "wrong key!!!" << endl;
            Sleep(500);
        }

        system("cls");
    }
}

void _translation()
{
    while(1)
    {


        int tx, ty;
        string file_name, choice;
        int x1, x2, y1, y2;

        cout << "1. Draw line with two points" << endl;
        cout << "2. Draw from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter number: " ;
        cin >> choice;
        if(choice == "1")
        {
            cout << "Enter x1, y1, x2, y2" << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            print_in_file_line(x1, y1, x2, y2, file_name, "w+","n");
            cout << "Enter tx, ty:" << endl;
            cin >> tx >> ty;
            translation(tx, ty, file_name);
        }
        else if(choice == "2")
        {
            cout << "Enter tx, ty:" << endl;
            cin >> tx >> ty;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            translation(tx, ty, file_name);
        }
        else if(choice == "0")
            break;
        else
        {
            cout << "wrong key!!!" << endl;
            Sleep(500);

        }

        system("cls");
    }
}
void _rotation()
{
    while(1)
    {

        float degree;
        string file_name, choice;
        int x1, x2, y1, y2;

        cout << "1. Draw line with two points" << endl;
        cout << "2. Draw from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter number: " ;
        cin >> choice;
        if(choice == "1")
        {
            cout << "Enter x1, y1, x2, y2" << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            print_in_file_line(x1, y1, x2, y2, file_name,"w+","n");
            cout << "Enter rotation in degree:" << endl;
            cin >> degree;
            rotation(degree, file_name);

        }
        else if(choice == "2")
        {
            cout << "Enter Degree:" << endl;
            cin >> degree;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            rotation(degree, file_name);

        }
        else if(choice == "0")
            break;
        else
        {
            cout << "wrong key!!!" << endl;
            Sleep(500);

        }

        system("cls");
    }
}
void _scaling()
{
    while(1)
    {

        int x1, x2, y1, y2;
        float sx, sy;
        string file_name, choice;

        cout << "1. Draw line with two points" << endl;
        cout << "2. Draw from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter number: " ;
        cin >> choice;
        if(choice == "1")
        {
            cout << "Enter x1, y1, x2, y2" << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            print_in_file_line(x1, y1, x2, y2, file_name,"w+", "n");
            cout << "Enter sx, sy:" << endl;
            cin >> sx >> sy;
            scaling(sx, sy, file_name);

        }
        else if(choice == "2")
        {
            cout << "Enter sx, sy:" << endl;
            cin >> sx >> sy;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            scaling(sx, sy, file_name);

        }
        else if(choice == "0")
            break;
        else
        {
            cout << "wrong key!!!" << endl;
            Sleep(500);

        }

        system("cls");
    }
}
void _mirroring()
{
    while(1)
    {

        int x1, x2, y1, y2;
        string file_name, axis, choice;

        cout << "1. Draw line with two points" << endl;
        cout << "2. Draw from file" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter number: " ;
        cin >> choice;
        if(choice == "1")
        {
            cout << "Enter x1, y1, x2, y2" << endl;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            print_in_file_line(x1, y1, x2, y2, file_name,"w+","n");
            cout << "Enter axis(x or y)," << endl;
            cin >> axis;
            mirror(axis, file_name);
        }
        else if(choice == "2")
        {
            cout << "Enter axis(x or y):" << endl;
            cin >> axis;
            cout << "enter file name(path:\folder\folder...)" << endl;
            cin >> file_name;
            mirror(axis, file_name);

        }
        else if(choice == "0")
            break;
        else
        {
            cout << "wrong key!!!" << endl;
            Sleep(500);

        }

        system("cls");
    }
}

void _two_D()
{
    string choice;
    while(1)
    {
        cout << "1. Translation" << endl;
        cout << "2. Rotation" << endl;
        cout << "3. Scaling" << endl;
        cout << "4. Mirroring" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter number: " ;
        cin >> choice;
        if(choice == "1")
        {
            system("cls");
            _translation();
        }
        else if(choice == "2")
        {
            system("cls");
            _rotation();
        }
        else if(choice == "3")
        {
            system("cls");
            _scaling();
        }
        else if(choice == "4")
        {
            system("cls");
            _mirroring();
        }
        else if(choice == "0")
            break;
        else
        {
            cout << "wrong key!!!" << endl;
            Sleep(500);

        }

        system("cls");
    }
}
void _clip_point()
{
    int x1, y1, x2, y2, px, py;
    string ff = "ab.txt";
    system("cls");
    cout << "Enter x1, y1, x2, y2" << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    //cout << "enter file name(path:\folder\folder...)" << endl;
    //cin >> ff;
    cout << "enter point: (x, y): " << endl;
    cin >> px >> py;
    print_in_file_line(x2, y2, x2, y1, ff, "w+", "n");
    print_in_file_line(x1, y2, x1, y1, ff, "a+","n");
    print_in_file_line(x1, y2, x2, y2, ff, "a+","n");
    print_in_file_line(x1, y1, x2, y1, ff, "a+","n");
    if(x1 <= px && x2 >= px && y1 >= py && y2 <= py)
        print_in_file_circle(3, px, py, ff, "a+", "n");
    print_from_file_circle_or_line(ff);
}

/*void _rectangle()
{



    print_in_file_line(x2, y2, x2, y1, ff, "n");
    print_in_file_line(x1, y2, x1, y1, ff, "n");
    print_in_file_line(x1, y2, x2, y2, ff, "n");
    print_in_file_line(x1, y1, x2, y1, ff, "n");
    print_from_file_circle_or_line(ff);
}


*/
