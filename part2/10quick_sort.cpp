#include <bits/stdc++.h>

using namespace std;

int partitionQuickasc(int a[], int l, int h ,bool random){
	
	if(random== true){
		srand(time(NULL));
		int r = l + rand()%(h-l);
		swap(a[r] , a[l]);
	}
	
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



void quickSort(int a[], int l, int h, bool rand){

    if(l<h){
    	int j;
    	j=partitionQuickasc(a,l,h , rand);
		quickSort(a,l,j ,rand);
        quickSort(a,j+1,h , rand);
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
	cout<<"Sorted Element using random pivot: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0 , n-1 ,false);
	cout<<"Sorted Element using last element: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;
    return 0;
}
