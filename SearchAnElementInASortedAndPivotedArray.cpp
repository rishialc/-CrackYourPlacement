/*
An element in a sorted array can be found in O(log n) time via binary search.
But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
So for instance, 1 2 3 4 5 might become 3 4 5 1 2.
Devise a way to find an element in the rotated array in O(log n) time.
*/
#include<iostream>
#include<conio.h>
using namespace std;

int bSearch(int *arr, int n, int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[low]<arr[mid]){
            if(key>=arr[low] && key<arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(key>arr[mid] && key<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
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
    int key;
    cout<<"Enter the element you wish to search: ";
    cin>>key;
    cout<<"Element found at index: "<<bSearch(arr,n,key);
    delete arr;
}
