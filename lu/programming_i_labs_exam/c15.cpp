// REQUIREMENTS:
// C15. Skaitļu trijnieks nosaka taisni, kas uzdota sekojošā veidā: ax+by=c.
// Dotas n (n<=6) taisnes.
// Noteikt, kuras no taisnēm ir paralēlas.
// Vai eksistē trīs tādas taisnes, kas krustojas vienā punktā.
// Ja eksistē, tad izdrukāt šo taišņu parametrus.
// ----------------------------------------------
#include "utils.h"

const int parameters = 3;
const int max_number_of_lines = 2;
const int parameter_a = 0;
const int parameter_b = 1;
const int parameter_c = 2;

bool is_line_wrong(int line[parameters])
{
    return line[parameter_b] == 0;
}

int* get_line()
{
    int line[parameters] = {0, 0, 0};
    while (is_line_wrong(line))
    {
        cout << "Enter line's ax + by = c parameters, as space-separated integers a b c: ";
        cin >> line[parameter_a];
        cin >> line[parameter_b];
        cin >> line[parameter_c];

        if (is_line_wrong(line))
            cout << "You have entered incorrect parameter B. It can not be 0." << endl;
    }
    return line;
}

// transforming line equation
// from ax + by = c
// to slope-intercept form y = slope * x + y_intercept:
// ax + by =  c
//      by =  c - ax
//      by =  -ax + c
//       y = (-ax + c)/b
//       y = (-a/b)x + c/b
// so, slope is -a/b and y_intercept is c/b

int main()
{
    // http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-using-new
    int** lines = new int*[max_number_of_lines];
    int real_number_of_lines = 0;

    for (int line = 0; line < max_number_of_lines; line++, real_number_of_lines++)
    {
        cout << "lines is " << line;
        lines[line] = new int[parameters];
        lines[line] = get_line();


    cout << "Your input is being interpreted as "
        << lines[line][parameter_a] << ", "
        << lines[line][parameter_b] << " and "
        << lines[line][parameter_c] << endl;

    }

    cout << "Your input is being interpreted as "
        << lines[0][parameter_a] << ", "
        << lines[0][parameter_b] << " and "
        << lines[0][parameter_c] << endl;


    cout << "Your input is being interpreted as "
        << lines[1][parameter_a] << ", "
        << lines[1][parameter_b] << " and "
        << lines[1][parameter_c] << endl;


    cout << "Your enetered " << real_number_of_lines << " lines. ";
    system("pause");
    return 0;
}