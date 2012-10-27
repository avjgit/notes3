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

const int not_checked = 0;
// const int checked =

bool is_line_wrong(double line[parameters])
{
    return
    (
        line[parameter_b] == 0 &&
        line[parameter_a] == 0
    );
}

double* get_line()
{
    double line[parameters] = {0, 0, 0};
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
    double lines[max_number_of_lines][parameters];
    int real_number_of_lines = 0;

    // getting lines from user
    for (int line = 0; line < max_number_of_lines; line++, real_number_of_lines++)
    {
        double* temp_line = get_line();
        for (int i = parameter_a; i <= parameter_c; i++)
            lines[line][i] = temp_line[i];
    }

    cout << "Your input is being interpreted as "
        << lines[0][parameter_a] << ", "
        << lines[0][parameter_b] << " and "
        << lines[0][parameter_c] << endl;


    cout << "Your input is being interpreted as "
        << lines[1][parameter_a] << ", "
        << lines[1][parameter_b] << " and "
        << lines[1][parameter_c] << endl;

    // checking parallelness

    cout << "Your enetered " << real_number_of_lines << " lines. ";
    system("pause");
    return 0;
}