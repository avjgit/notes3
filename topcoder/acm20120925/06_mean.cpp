#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int main()
{
    ifstream input;
    ofstream output;

    int elements;
    int ktruncate;

    input.open("mean.in");

    input >> elements;
    input >> ktruncate;

    float score;
    int scores [elements-1];

    for (int i = 0; i < elements; i++)
    {
        input >> score;
        scores[i] = (int)(score*1000);
    }

//    cout << endl << "scores before sorting: " << endl;
//    for (int i = 0; i < elements; i++)
//    {
//        cout << scores[i] << " ";
//    }

    // sort array
    qsort (scores, elements, sizeof(int), compare);

//    for(int y=0; y < elements; y++)
//    {
//        for ( int k =0; k < elements-1-y; k++ )
//        if(scores[k]>scores[k+1])
//        {
//        int temp = scores[k+1];
//        scores[k+1] = scores[k];
//        scores[k] = temp;
//        }
//    }

//    cout << endl << "scoress after sorting: " << endl;
//    for (int i = 0; i < elements; i++)
//    {
//        cout << scores[i] << " ";
//    }

    int ksum = 0;
    for (int i = ktruncate; i < elements-ktruncate; i++)
    {
        ksum += scores[i];
    }

    int min_replace = scores[ktruncate];
    int max_replace = scores[elements - 1 - ktruncate];

//    cout << endl << "min replace is " << min_replace << endl;
//    cout << endl << "max replace is " << max_replace << endl;

    // replace minimals
    for (int i = 0; i < ktruncate; i++)
    {
        scores[i] = min_replace;
    }
    for (int i = 0; i < ktruncate; i++)
    {
        scores[elements-1-i] = max_replace;
    }

    int winsum = 0;
    for (int i = 0; i < elements; i++)
    {
        winsum += scores[i];
    }

//    cout << endl << "scoress after min max replace: " << endl;
//    for (int i = 0; i < elements; i++)
//    {
//        cout << scores[i] << " ";
//    }

    output.open("mean.out");

//    int kmean = ksum/ (elements-(ktruncate*2));
//    int wmean = winsum/ elements;

//    output << floor((kmean*100)+0.5)/100.0 << endl;
//    output << floor((wmean*100)+0.5)/100.0;

//    cout << setprecision (5) << f << endl;
//    output << fixed << setprecision (2) << kmean << endl;
//    output << fixed << setprecision (2) << wmean;

    float ksumfloat = ksum * 1.0;
    float wmeanfloat = winsum * 1.0;

    output << fixed << setprecision (2) << (ksumfloat/ (elements-(ktruncate*2))) /1000 << endl;
    output << fixed << setprecision (2) << (wmeanfloat/ elements) /1000;

    input.close();
    output.close();
    return 0;
}


