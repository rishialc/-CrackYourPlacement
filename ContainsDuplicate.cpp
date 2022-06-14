//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
#include<iostream>
#include<stdio.h>
using namespace std;

int partition(int arr[], int start, int end)
{ 
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
 
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

bool containDuplicate(int *arr, int n){
    quickSort(arr,0,n-1);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            return true;
        }
    }
    return false;
}

int main(){
    cout<<"How many elements you wish to enter?\n";
    int n;
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter "<<n<<" elements: -\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(containDuplicate(arr,n)==true){
        cout<<"It contains duplicate element";
    }else{
        cout<<"It doesn't contains duplicate element";
    }
    delete arr;
    return 0;
}