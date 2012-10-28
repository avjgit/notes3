// REQUIREMENTS:
// C15. Skaitļu trijnieks nosaka taisni, kas uzdota sekojošā veidā: ax+by=c.
// Dotas n (n<=6) taisnes.
// Noteikt, kuras no taisnēm ir paralēlas.
// Vai eksistē trīs tādas taisnes, kas krustojas vienā punktā.
// Ja eksistē, tad izdrukāt šo taišņu parametrus.
// ----------------------------------------------
#include "utils.h"

const int parameters = 3;           // number of line describing parameters (a, b and c)
const int max_number_of_lines = 2;  // maximal number of lines allowed to enter

// order of parameters in line-describing array
const int a            = 0;
const int b            = 1;
const int c            = 2;
const int state        = 3;
const int parallelness = 4;

// checks if line equation is wrong (a and b parameters are 0)
bool is_line_wrong(double line[parameters])
{
    return line[a] == 0 &&
           line[b] == 0;
}

// checks if user stopped entering lines
bool is_stop(double line[parameters])
{
    return line[a] == 0 &&
           line[b] == 0 &&
           line[c] == 0;
}

// gets line parameters from user
double* get_line()
{
    double line[parameters] = {0, 0, 0};
    while (is_line_wrong(line))
    {
        print("If you want to stop, enter 0 0 0.");
        print("Enter line's ax + by = c parameters, as space-separated integers a b c: ");
        cin >> line[a];
        cin >> line[b];
        cin >> line[c];

        if (is_stop(line))
            break;

        if (is_line_wrong(line))
            print("You have entered incorrect parameter A and B. They can not be 0 simultaneously.");
    }
    return line;
}

// checks if lines are horizontal (thus, parallel to x axis)
bool are_parallel_to_abscissa(double line1[3], double line2[3])
{
    return line1[a] == 0 &&
           line2[a] == 0;
}

// checks if lines are vertical (thus, parallel to y axis)
bool are_parallel_to_ordinate(double line1[3], double line2[3])
{
    return line1[b] == 0 &&
           line2[b] == 0;
}

// checks if lines have same angle
bool have_same_slope(double line1[3], double line2[3])
{
    // transforming line equation
    // from ax + by = c
    // to slope-intercept form y = slope * x + y_intercept:
    // ax + by =  c
    //      by =  c - ax
    //      by =  -ax + c
    //       y = (-ax + c)/b
    //       y = (-a/b)x + c/b
    // so, slope is -a/b and y_intercept is c/b
    // lines are parallel, when their slopes are equal
    double slope1 = -1 * line1[a] / line1[b];
    double slope2 = -1 * line2[a] / line2[b];
    return slope1 == slope2;
}

// checks if two lines are parallel
bool is_parallel(double line1[3], double line2[3])
{
    return are_parallel_to_abscissa(line1, line2)
        || are_parallel_to_ordinate(line1, line2)
        || have_same_slope(line1, line2);
}

// find intersection of two lines
double* intersection(double line1[3], double line2[3])
{
    // variable for params for easier understanding
    double a1 = line1[a];
    double b1 = line1[b];
    double c1 = line1[c];

    double a2 = line2[a];
    double b2 = line2[b];
    double c2 = line2[c];

    // step 0: initial
    // a1x + b1y = c1
    // a2x + b2y = c2

    // step 1: multiply 1st by b2, 2nd by b1
    // a1b2x + b1b2y = c1b2
    // a2b1x + b2b1y = c2b1

    // step 2: substract 2nd from 1st
    // a1b2x + b1b2y - a2b1x - b2b1y =  c1b2 - c2b1
    // a1b2x         - a2b1x         =  c1b2 - c2b1
    //(a1b2          - a2b1)x        =  c1b2 - c2b1
    //                      x        = (c1b2 - c2b1)/(a1b2 - a2b1)

    double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);

    // step 3: entering x in first initial equation
    // a1x + b1y = c1
    //       b1y = c1 - a1x
    //         y =(c1 - a1x)/b1

    double y = (c1 - a1 * x)/b1;

    double intersection_point[2] = {x, y};
    return intersection_point;
}
void c15()
{
    double lines[max_number_of_lines][parameters + 2]; // array to store lines, entered by user
    int lines_entered     = 0;                         // counter, how many lines are entered
    const int checked     = 1;                         // flag line is already processed (used in parallelness check and printing)
    const int not_checked = -1;                        // flag line is not yet processed

    // getting lines from user
    for (int line = 0; line < max_number_of_lines; line++, lines_entered++)
    {
        double* input_line = get_line();

        if (is_stop(input_line))
        {
            lines_entered--;
            break;
        }
        else
        {
            lines[line][a]  = input_line[a];
            lines[line][b]  = input_line[b];
            lines[line][c]  = input_line[c];
            lines[line][state]        = not_checked;
            lines[line][parallelness] = not_checked;
        }
    }

    bool exists_parallels = false;

    // mark lines parallel
    for (int line = 0; line < lines_entered; line++)
    {
        // if line not yet marked as being parallel
        if (lines[line][state] == not_checked)
        {
            // loop through lines, starting from next one till end
            for (int next_line = line + 1; next_line < lines_entered; next_line++)
            {
                if (is_parallel(lines[line], lines[next_line]))
                {
                    // mark current line as parallel to line from outer loop
                    lines[next_line][state] = checked;
                    lines[next_line][parallelness] = line;
                    exists_parallels = true;
                }
            }
        }
    }

    // reseting state for printing
    for (int line = 0; line < lines_entered; line++)
        lines[line][state] = not_checked;

    // for (int line = 0; line < lines_entered; line++)
    // {
    //     cout << endl << "line " << line << ": ";
    //     for (int i = 0; i <= parallelness; i++)
    //         cout << lines[line][i] << " ";
    // }

    // print out result of parallelness check
    if (exists_parallels)
    {
        bool has_parallels;
        print("Parallel lines are:");
        for (int line = 0; line < lines_entered; line++)
        {
            // cout << "entering with line " << line + 1 << endl;

            string output_lines = "    Line " + to_char(line+1);
            has_parallels = false;

            // if line is not yet printed
            if (lines[line][state] == not_checked)
            {
                for (int next_line = line + 1; next_line < lines_entered; next_line++)
                {
                    if (lines[next_line][parallelness] == line)
                    {
                        lines[next_line][state] = checked;
                        output_lines += ", line " + to_char(next_line+1);
                        has_parallels = true;
                    }
                }
            }
            if (has_parallels) print(output_lines);
        }
    }
    else
    {
        print("There are no parallel lines.");
    }

    double* intersection_of_1_and_2 = intersection(lines[0], lines[1]);

    cout << "Intersection is " << intersection_of_1_and_2[0] << ";" << intersection_of_1_and_2[1];


    cout << endl;
    cout << "Your input is being interpreted as "
        << lines[0][a] << ", "
        << lines[0][b] << " and "
        << lines[0][c] << endl;


    cout << "Your input is being interpreted as "
        << lines[1][a] << ", "
        << lines[1][b] << " and "
        << lines[1][c] << endl;

    cout << "Your enetered " << lines_entered << " lines. ";

}
int main()
{
    c15();

    system("pause");
    return 0;
}
