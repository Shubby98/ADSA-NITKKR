#include <iostream>

using namespace std;
int linear_search(int arr[], int n , int num){
	for(int i = 0; i < n ;i++){
		if(arr[i]==num){
			return i;
		}
	}
	return -1;
	
}

int binary_search(int arr[] , int n ,int num){
	int l = 0, r = n;
	while(l<=r){
		int mid = (l+r)/2;
		
		if(arr[mid] == num){
			return mid;
		}
		
		if(arr[mid] > num){
			r = mid-1;
		}
		if(arr[mid] < num){
			l = mid+1;
		}
	}
	return -1;
}

int main()
{
    int n;
    cout<<"Enter the total number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the element: "<<endl;
    for(int i=0;i<n;i++){
		int x ;
		cin>>x;
		arr[i] = x; 
	}
	int num;
	cout<<"Enter the number to be search: ";
    cin>>num;

	
    int index = linear_search(arr , n  , num );
    //int bindex = binary_search(arr , n , num);
	
	cout<<"Your element is at "<<index + 1<<" position"<<endl;

    return 0;
}

/*
Linear Search  
Best Case : O(1)
Worst Case : O(n)

Binary Search 
Best Case : O(1)
Worst Case : O(logn)

*/
