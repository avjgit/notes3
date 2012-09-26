/* qsort example */
#include <stdio.h>
#include <stdlib.h>

double values[] = { 40.2, 10.1, 100.0, 90.0, 20.0, 25.0 };

int compare (const void * a, const void * b)
{
  return ( *(double*)a - *(double*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(double), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}
