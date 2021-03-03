#include<bits/stdc++.h>
#define N 5
using namespace std;
int Partition(int a[], int low, int high) {
   int pivot, index, i;
   index = low;
   pivot = high;
   for(i=low; i < high; i++) {
      if(a[i] < a[pivot]) {
         swap(a[i], a[index]);
         index++;
      }
   }
   swap(a[pivot], a[index]);
   return index;
}
int random_pivot(int a[], int low, int high){
   int pvt, n, temp;
   n = rand();
   pvt = low + n%(high-low+1); 
   swap(a[high], a[pvt]);
   return Partition(a, low, high);
}
void quick_sort(int arr[], int p, int q) {
   int pindex;
   if(p < q) {
      pindex = random_pivot(arr, p, q); 
     
      quick_sort(arr, p, pindex-1);
    quick_sort(arr, pindex+1, q);
}
}
int main() {
int i;
int arr[N];
for (i = 0;i < N; i++)
arr[i] = 100 - i;
quick_sort(arr, 0, N - 1); 
for (i = 0; i < N; i++)
cout << arr[i] << " ";
cout << endl;
return 0;
}