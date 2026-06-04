#include<fstream>
#include<iostream>
using namespace std;


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int A[], int size ){
    int i, j, flag =0;
    for(i = 0; i<size-1;i++){
        flag = 0;
        for(j=0;j<size-1-i;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(!flag) break;
    }
}
void insertionSort(int A[], int size){
    int i,j,x;
    for(i=1;i<size;i++){
        j =i-1;
        x =A [i] ;
        while(j>-1&&x<A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;

    }
}
void selectionSort(int A[] , int size){
    int i,j,k;
    for(i=0;i<size-1;i++){
        for(j=k=i;j<size;j++){
            if(A[k]>A[j]) k=j;
        }
        swap(&A[i],&A[k]);
    }
}

//QuickSort

int partition(int A[],int l,int h ){
    int Pivot = A[l];
    int i = l,j=h;
    do{
        do{i++;}while(A[i]<=Pivot);
        do{j--;}while(A[j]>Pivot);
        if(i<j) swap(&A[i],&A[j]);
    }while(i<j);
    swap(&A[l],&A[j]);
    return j;

}
void quickSort(int A[],int l, int h){
    int j;
    if(l<h){
        j=partition(A,l,h);
        quickSort(A,l,j);
        quickSort(A,j+1,h);
    }
}
int main(){
    int A[10] = {1,3,6,4,3,2,7,8,1,9};
    int size = 10;
    // bubbleSort(A,10);
    // insertionSort(A,10);
    // selectionSort(A,10);
    quickSort(A,0,9);
    for(int i = 0; i<size; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
