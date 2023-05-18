#include <iostream>
#include<algorithm>
using namespace std; 

int partition(int arr[], int a, int c)
{
	int pivot;
	int mid=(a+c)/2;
	
	 if ((arr[a] < arr[mid] && arr[mid] < arr[c]) || (arr[c] < arr[mid] && arr[mid] < arr[a])){
	 	pivot=arr[mid];
	 }
    else if ((arr[mid] < arr[a] && arr[a] < arr[c]) || (arr[c] < arr[a] && arr[a] < arr[mid])){
    	pivot=arr[a]; 
	}
    else{
    	pivot=arr[c];
	}
  int i = (a - 1); //this part until the end of the partition function was adapted from https://www.programiz.com/dsa/quick-sort
  for (int j = a; j < c; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[c]);
  
  // partition
  return (i + 1);
       
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int pi = partition(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);
}


int main (){
	int length=6;
	int ary[length]={0, 50, 10, 4, 8, 21};
	cout << "Before sorting: " ;
	 for (int i = 0; i < length; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;
	quickSort(ary, 0, length - 1);
 	cout << "After sorting: ";
    for (int i = 0; i < length; i++) {
        cout << ary[i] << " ";
    }
}

