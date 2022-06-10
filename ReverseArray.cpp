#include<iostream>
#include<stdio.h>
using namespace std;

void revArray(int arr[], int n){
    int arr2[n],i=0;
    for(i=0;i<n;i++){
        arr2[i]=arr[n-1-i];
    }
    for(i=0;i<n;i++){
        arr[i]=arr2[i];
    }
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

    revArray(arr,n);
    cout<<"\nArray reversed, array after reversal: -\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}