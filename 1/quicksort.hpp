// quicksort.hpp
// Nicholas Alexeev
// Implements algorythm on assignment web page

#ifndef QUICKSORT
#define QUICKSORT
#include <vector>
// Preconditions low and high are greater then zero and less then in.size()
int partition(std::vector<int> &in, int low,int high){
	int pivot = in[high];
	int i = low-1;
	for(int j = low;j<=high;j++){
		if(in[j]<=pivot){
			i = i+1;
			int temp = in[j];
			in[j]=in[i];
			in[i]=temp;

		}

	}
	return i;


}
// Preconditions low and high are greater then zero and less then in.size()
void sort(std::vector<int> &in,int low,int high){
	if(low>=0 && high>=0){
		if(low<high){
			int p = partition(in,low,high);
			sort(in,low,p-1);
			sort(in,p+1,high);
		}
	}
}

#endif
