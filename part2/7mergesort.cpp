#include <iostream>

using namespace std;

void merge(int arr[] , int start , int mid , int end ){
	int left_len =  mid - start+1 ;		//length of left array
	int right_len = end - mid ;			//length of right array
	int larr[left_len]; 
	int rarr[right_len];
	
	for(int k = 0 ; k<left_len ; k++){
		larr[k] = arr[start + k];
	}
	
	for(int k = 0 ; k<right_len ; k++){
		rarr[k] = arr[mid+1 + k];
	}
	
	int left_index = 0;
	int right_index = 0;
	int main_index = start;
	
	while(left_index < left_len && right_index < right_len){
		
		if(larr[left_index]  <= rarr[right_index]){
			arr[main_index] = larr[left_index];
			main_index++;
			left_index++;
		}
		
		else{
			arr[main_index] = rarr[right_index];
			main_index++;
			right_index++;
		}
		
	}	         
	
	while(left_index < left_len ){
		arr[main_index] = larr[left_index];
			main_index++;
			left_index++;
	}
	
	
	while(right_index < right_len){
		arr[main_index] = rarr[right_index];
			main_index++;
			right_index++;
	}
	
	return;                           
}

void merge_sort(int arr[] , int start , int end){
	if(start>=end){
		return;
	}
	
	int mid = (start+end)/2;
	
	merge_sort(arr, start , mid );
	merge_sort(arr , mid+1 , end);
	
	merge(arr , start,mid , end);
	
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

    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
