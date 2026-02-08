#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;



template<class T>
class Array{
 
private:
    T* A;
    int size;
    int length=0;
    bool isSorted = 0;
    void swap(T* a,T* b);
 
public:
    Array(int size) {
        this->size = size;
        A = new T[size];

    }
    int getLength() const{
        return length;
    }
    int getCapacity() const{
        return size;
    }
    Array(const Array& other) {
    size = other.size;
    length = other.length;
    A = new T[size];
    for(int i = 0; i < length; i++)
        A[i] = other.A[i];
    }
    Array& operator=(const Array& other) {
    if(this != &other) {
        delete[] A;
        size = other.size;
        length = other.length;
        A = new T[size];
        for(int i = 0; i < length; i++)
            A[i] = other.A[i];
    }
    return *this;
    }
    void increaseSize(){
        T *temp = new T[2*size];
        for (int i = 0; i < length; i++)
        {
            temp[i]=A[i];
        }
        delete []A;
        this->size = 2*size;
        A = temp;
        temp = NULL;
        
    }
 
    void display() const{
        if(length==0){
            cout<<"\tArray is empty\n";
            return;
        }
        cout<<"\tYour Array ADT ->  ";
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }
    void append(T value){
        while(length==size||length>size){
            increaseSize();
        }
        A[length++] = value;
        isSorted = 0;
    }
    void insert(T value,int index){
        if(index<0||index>length)
        {
            throw std::out_of_range("Index out of bounds");
        }
        while(length==size||length>size){
            increaseSize();
        }
        if(index>=0&&index<=length){
            for (int i = this->length; i >index; i--)
            {
                A[i] = A[i-1];
            }
            A[index] = value;
            length++;
            
        }
        isSorted  = 0;
    }
    int linearSearch(T key) const{
        for(int i=0;i<length;i++){
            if(A[i]==key){
                return i;
            }
        }
        return -1;
    }

    int deleteByValue(T value){
        int index =  linearSearch(value);
        if(index==-1){
            throw std::out_of_range("Value does not exist");
        }
        return deleteByIndex(index);
        
    }
    int deleteByIndex(int index){
        if(index<0||index>=length)
        {
            throw std::out_of_range("Index out of bounds");
        }
        int value = A[index];
        for (int i = index; i < length-1; i++)
        {
            A[i] = A[i+1];
            
        }
        length--;
        isSorted = 0;
        return value;
        

    }
    T get(int index) const {
        if(index<0||index>=length)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return A[index];
    }
    void set(int index,T value){
        if(index<0||index>=length)
        {
            throw std::out_of_range("Index out of bounds");
        }
        A[index] = value;
        isSorted = 0;
        return;
    }
    T max() const {
        T max = A[0];
        for (int i = 1; i < length; i++)
        {
            if(A[i]>max){
                max = A[i];
            }
        }
        return max;
        
    }
    T min() const{
        T min = A[0];
        for (int i = 1; i < length; i++)
        {
            if(A[i]<min){
                min = A[i];
            }
        }
        return min;

    }
    T sum() const{
        static_assert(std::is_arithmetic<T>::value,
              "sum() requires numeric type");
        T sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum+=A[i];
        }
        return sum;
    }
    void reverse(){
        int temp,i=0,j=length-1;
        while(i<j){
            swap(&A[i++],&A[j--]);
        }
        isSorted = 0;
    }
    void rightShift(){
        for(int i = length-1; i > 0; i--)
        A[i] = A[i-1];
        A[0] = T{};
        isSorted = false;
    }
    void leftShift(){
        for (int i = 0; i <length-1;i++ )
        {
            A[i] = A[i+1];
        }
        isSorted = false;
        length--;
    }
    void rightRotate(){
        T last = A[length-1];
        for(int i = length-1; i > 0; i--)
            A[i] = A[i-1];
        A[0] = last;
        isSorted = 0;
    }
    void leftRotate(){
        T value = A[0]; 
        for (int i = 0; i <length-1;i++ )
        {
            A[i] = A[i+1];
        }
        isSorted = 0;
        A[length-1] = value;

    }
    ~Array(){
        delete[] A;
    }
};
template <class T>
void Array<T>:: swap(T*a,T*b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

//debug code 

