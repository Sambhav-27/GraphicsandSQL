#include<stdio.h>
/*If n is odd then initialize min and max as first element.
If n is even then initialize min and max as minimum and maximum of the first two elements respectively.
For rest of the elements, pick them in pairs and compare*/

struct pair
{
  int min;
  int max;
};

struct pair getMinMax(int arr[], int n)
{
  struct pair minmax;
  int i;
  if (n%2 == 0)
  {
    if (arr[0] > arr[1])
    {
      minmax.max = arr[0];
      minmax.min = arr[1];
    }
    else
    {
      minmax.min = arr[0];
      minmax.max = arr[1];
    }
    i = 2;
  }


  else
  {
    minmax.min = arr[0];
    minmax.max = arr[0];
    i = 1;
  }


  while (i < n-1)
  {
    if (arr[i] > arr[i+1])
    {
      if(arr[i] > minmax.max)
        minmax.max = arr[i];
      if(arr[i+1] < minmax.min)
        minmax.min = arr[i+1];
    }
    else
    {
      if (arr[i+1] > minmax.max)
        minmax.max = arr[i+1];
      if (arr[i] < minmax.min)
        minmax.min = arr[i];
    }
    i += 2;
  }

  return minmax;
}

int main()
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arr_size = 6;
  struct pair minmax = getMinMax (arr, arr_size);
  printf("\nMinimum element is %d", minmax.min);
  printf("\nMaximum element is %d", minmax.max);
}
