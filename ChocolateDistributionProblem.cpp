/*
Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 
i)  Each student gets one packet.
ii) The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
*/

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

int ChocolateDistributionProblem(int *arr, int n, int m){
    if(m==0 || n==0){
        return 0;
    }
    quickSort(arr,0,n-1);
    int ans=INT_MAX;
    for(int i=0;i+m-1<n;i++){
        if(arr[i+m-1]-arr[i] < ans){
            ans=arr[i+m-1]-arr[i];
        }else{
            continue;
        }
    }
    return ans;
}

int main(){
    cout<<"How many packet of chocolates do you have?\n";
    int n;
    cin>>n;
    cout<<"Enter no. of chocolates in each packet: -\n";
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cout<<"How many children are there?\n";
    cin>>m;
    cout<<"Minimum Difference: "<<ChocolateDistributionProblem(arr,n,m);
    delete arr;
}