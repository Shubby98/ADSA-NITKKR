#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[] , int n ){
	
	for(int i = 0 ; i < n-1 ; i++ ){
		int min_index = i;
		for(int j = i+1 ; j < n ; j++){
			if(arr[min_index]>arr[j]){
				min_index = j;
			}
		}
		swap(arr[min_index] , arr[i]);
	}
	return;
}

int main()
{
    int n;
    
    cout<<"Enter the total number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the element: "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];

    selection_sort(arr,n);
    cout<<"Sorted Element : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
