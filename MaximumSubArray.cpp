//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

#include<iostream>
#include<stdio.h>
using namespace std;


int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: -\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int curSum=arr[0];
    int maxSum=arr[0];
    for(int i=1;i<n;i++){
        curSum=max(curSum+arr[i],arr[i]);
        if(maxSum<curSum){
            maxSum=curSum;
        }
    }
    cout<<"\nSum of Maximum Sub Array: "<<maxSum<<endl;
}