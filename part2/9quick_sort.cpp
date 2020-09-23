#include <bits/stdc++.h>

using namespace std;

int partitionQuickdsc(int a[], int l, int h){

    int pivot=a[l];
    int i=l;
    int j=h;

    while(i<j && i<=h && j>=l){
        while(a[i]>=pivot && i<h){i++;}
        while(a[j]<=pivot && j>l){j--;}

        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}

int partitionQuickasc(int a[], int l, int h){

    int pivot=a[l];
    int i=l;
    int j=h;

    while(i<j && i<=h && j>=l){
        while(a[i]<=pivot && i<h){i++;}
        while(a[j]>=pivot && j>l){j--;}

        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}



void quickSort(int a[], int l, int h, bool asc){

    if(l<h){
    	int j;
    	if(asc==true)j=partitionQuickasc(a,l,h);
        else j=partitionQuickdsc(a,l,h);
		quickSort(a,l,j ,asc);
        quickSort(a,j+1,h , asc);
    }
}



int main()
{
    int n;
    
    cout<<"Enter the total number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the element: "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];

    quickSort(arr,0 , n-1 ,true);
	cout<<"Sorted Element in ascending order: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0 , n-1 ,false);
	cout<<"Sorted Element in descending order: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;
    return 0;
}
