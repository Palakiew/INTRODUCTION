// Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers, for example, 
// for the decimal system, b is 10. What is the value of d? If k is the maximum possible value, 
// then d would be O(logb(k)). So overall time complexity is O((n+b) * logb(k)).

#include<stdio.h>
 
void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }
 
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++){
        arr[i] = output[i];
    }
}
 
void radixsort(int arr[], int n) {
    int m = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>m)
        m=arr[i];
    }
 
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10){
        countSort(arr, n, exp);
    }
}
 
void print(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
 
int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}