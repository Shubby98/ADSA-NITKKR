#include <iostream>

using namespace std;

int partitionQuick(int a[], int l, int h){

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

void quickSort(int a[], int l, int h){

    if(l<h){
        int j=partitionQuick(a,l,h);
        quickSort(a,l,j);
        quickSort(a,j+1,h);
    }
}

int main()
{
    int n;
    cout<<"Enter the total number of elements: ";
    cin>>n;

    int a[n];
    cout<<"Enter the element: "<<endl;
    for(int i=0;i<n;i++) cin>>a[i];

    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
