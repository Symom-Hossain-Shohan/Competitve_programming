#include<bits/stdc++.h>
using namespace std;

// Function to get the largest element from an array
long long aray[10000000+1]; 
  long long output[10000007];



long long getMax(long long array[], long long n) {
  long long max = array[0];
  for (long long i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(long long array[], long long size, long long place) {
  const long long max = 10;
  long long count[max];

  for (long long i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (long long i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (long long i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (long long i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (long long i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(long long array[], long long size) {
  // Get maximum element
  long long max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (long long place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

// Prlong long an array
void printArray(long long array[], long long size) {
  long long i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


// Driver code
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("output.txt", "r", stdin);
    freopen("input.txt", "w", stdout);
  long long n = 1000000; 
  long long x = 1e18; 
  for(long long i=0;i<n;i++, x--)
  {
    cin >> x; 
    aray[i] = x; 
  }
  
  radixsort(aray, n);
  //printArray(aray, n);
  cerr << (clock()*1.0)/CLOCKS_PER_SEC << endl; 
}