#include<iostream>
#include<stdio.h>
using namespace std;

int max(int arr[], int n){
    int big=arr[0],i;
    for(i=1;i<n;i++){
        if(arr[i]>big){
            big=arr[i];
        }
    }
    return big;
}

int min(int arr[], int n){
    int small=arr[0],i;
    for(i=1;i<n;i++){
        if(arr[i]<small){
            small=arr[i];
        }
    }
    return small;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: -\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nMaximum: "<<max(arr,n);
    cout<<"\nMinimum: "<<min(arr,n);
    
    return 0;
}