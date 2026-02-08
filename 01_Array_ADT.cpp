#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;

void clrscr(){
    cout<<"\n\n\tPress Enter to continue";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::system("cls");

}
void clrscrall(){
        std::system("cls");
}
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
class Array{
 
private:
    int* A;
    int size;
    int length=0;
    bool isSorted = 0;
 
public:
    Array(int size){
        this->size = size;
        A = new int [size];
    }
    void increaseSize(){
        int *temp = new int[2*size];
        for (int i = 0; i < length; i++)
        {
            temp[i]=A[i];
        }
        delete []A;
        this->size = 2*size;
        A = temp;
        temp = NULL;
        cout<<"\n\t------------Current Array size incresed to "<<size<<"------------------\n";
        
    }
    void bulkAppend(){
        int limit,i=length;
        cout << "\n\tEnter number of elements: " << flush;
        cin >> limit;
        limit += length;
        cout << "\n\tEnter the array elements: " << endl;
        for (i; i < limit; i++){
            cout << "\tArray element: " << i << " = " << flush;
            cin >> A[i];
            length++;
            if(length==size||length>size){
                increaseSize();
            }
        }
        isSorted = 0;
    }
 
    void display(){
        if(length==0){
            cout<<"\tArray is empty\n";
            return;
        }
        cout<<"\tYour Array ADT ->  ";
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }
    void sort(){
        for (int i = 0; i < this->length-1; i++)       
        {
            for (int j = 0; j < this->length-i-1; j++)
            {
                if(A[j]>A[j+1]){
                    swap(&A[j],&A[j+1]);
                }
            }
            
        }
        isSorted = 1;
    }
    void append(){
        int value;
        cout<<"\n\tEnter the value -> ";
        cin>>value;
        if(length==size||length>size){
            increaseSize();
        }
        A[length] = value;
        cout<<"\n\t"<<value<<" is Appendeded in the list";
        length++;
        isSorted = 0;
    }
    void insert(){
        int value,index;
        cout<<"\n\tEnter the value -> ";
        cin>>value;
        cout<<"\n\tEnter the index -> ";
        cin>>index;

        while (index<0||index>length)
        {
            cout<<"\n\tEnter valid index->";
            cin>>index;
        }
        
        if(index>=0&&index<=length){
            for (int i = this->length; i >index; i--)
            {
                A[i] = A[i-1];
            }
            A[index] = value;
            cout<<"\n\t"<<value<<" is Inserted in the list";
            length++;
            
        }
        if(length==size||length>size){
            increaseSize();
        }
        isSorted = 0;
    }
    int binarySearch(){
        int key,mid,high,low;
        cout<<"\n\tEnter the value you want to search -> ";
        cin>>key;
        if(!isSorted)sort();
        low = 0;
        high = this->length-1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(A[mid]==key){
                cout<<"\n\t"<<key<<" is at index "<<mid;
                return mid;
            }
            else if(A[mid]>key){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        cout<<"\n\tNot found";
        return -1;
    }
    int linearSearch(){
        int key;
        cout<<"\n\tEnter the value you want to search -> ";
        cin>>key;
        for(int i=0;i<length;i++){
            if(A[i]==key){
                cout<<"\n\tFound at index "<<i;
                return i;
            }
        }
        cout<<"\n\tNot in the list";
        return -1;
    }
    int linearSearch2(int key){
        for(int i=0;i<length;i++){
            if(A[i]==key){
                cout<<"\n\tFound at index "<<i;
                return i;
            }
        }
        cout<<"\n\tNot in the list";
        return -1;
    }
    void deleteByValue(){
        int value,index;
        cout<<"\n\tEnter the value you want to delete -> ";
        cin>>value;  
        index =  linearSearch2(value);
        if(index!=-1){
            deleteByIndex1(index);
            return;
        }
        else{
            cout<<"\n\tThe value is not in the list";
            return;
        }


    }
    void deleteByIndex1(int index){
        int value = A[index];
        for (int i = index; i < length-1; i++)
        {
            A[i] = A[i+1];
            
        }
        cout<<"\n\t"<<value<<" is Deleted";
        length--;
        

    }
    void deleteByIndex(){
        int index,value;
        cout<<"\n\tEnter the index -> ";
        cin>>index;

        while (index<0||index>=length)
        {
            cout<<"\n\tEnter valid index->";
            cin>>index;
        }
        value = A[index];
        for (int i = index; i < length-1; i++)
        {
            A[i] = A[i+1];
            
        }
        cout<<"\n\t"<<value<<" is Deleted";
        length--;
        

    }
    int get(){
        int index,value;
        cout<<"\n\tEnter the index -> ";
        cin>>index;
        while (index<0||index>=length)
        {
            cout<<"\n\tEnter valid index-> ";
            cin>>index;
        }
        value = A[index];
        cout<<"\n\tThe value at index "<<index<<" is "<<value;
        return value;
    }
    void set(){
        int index,value,new_value;
        cout<<"\n\tEnter the index which value you want to set -> ";
        cin>>index;
        while (index<0||index>length)
        {
            cout<<"\n\tEnter valid index->";
            cin>>index;
        }
        value = A[index];
        cout<<"\n\tEnter the new value -> ";
        cin>>new_value;
        A[index] = new_value;
        cout<<"\n\t"<<value<<" is updated to "<<new_value<<" at index "<<index;

    }
    int max(){
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if(A[i]>max){
                max = A[i];
            }
        }
        cout<<"\n\tMax Value is "<<max;
        return max;
        
    }
    int min(){
        int min = A[0];
        for (int i = 1; i < length; i++)
        {
            if(A[i]<min){
                min = A[i];
            }
        }
        cout<<"\n\tMin Value is "<<min;
        return min;

    }
    int sum(){
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum+=A[i];
        }
        cout<<"\n\tSum of the Values is "<<sum;
        return sum;
    }
    void reverse(){
        int temp,i=0,j=length-1;
        while(i<j){
            swap(&A[i++],&A[j--]);
        }
        cout<<"\n\tThe Array is reversed";
        isSorted = 0;
    }
    void rightShift(){
        // for (int i = length-1; i >0; i--)
        // {
        //     A[i+1] = A[i];
        // }
        // A[0] = 0; 
        for(int i = length-1; i > 0; i--)
            A[i] = A[i-1];
        A[0] = 0;
        cout<<"\n\tThe Array is Shifted Right" ;

        
    }
    void leftShift(){
        for (int i = 0; i <length-1;i++ )
        {
            A[i] = A[i+1];
        }
        length--;
        cout<<"\n\tThe Array is Shifted Left" ;

    }
    void rightRotate(){
        int last = A[length-1];
        for(int i = length-1; i > 0; i--)
            A[i] = A[i-1];
        A[0] = last;
        cout<<"\n\tThe Array is Rotated Right" ;
    }
    void leftRotate(){
        int i = 0,value = A[i]; 
        for (int i = 0; i <length-1;i++ )
        {
            A[i] = A[i+1];
        }
        A[length-1] = value;
        cout<<"\n\tThe Array is Rotated left" ;

    }
    ~Array(){
        delete[] A;
        // cout << "Array destroyed" << endl; distructor should never print
    }
};

int main() {
 
    int size,choice;
    char any;
    clrscrall();
    cout<<"\n\n\n-------------------Welcome To Array ADT-----------------------------\n\n\n";
    cout<<"Enter the size of the array -> ";
    cin>>size;
    Array arr1(size);
    cout<<"\nArray ADT of Size "<<size<<" is created in the Heap......\n";
    
    while(1){
        cout<<"\n\n\tArray ADT Main Menu :-\n\n\t0.Bulk Append\n\t1.Display\n\t2.Append\n\t3.Insert\n\t4.Delete\n\t5.Search\n\t6.Get\n\t7.Set\n\t8.Sum\n\t9.Max\n\t10.Min\n\t11.Reverse\n\t12.Shift\n\t13.Rotate\n\t14.Exit\n\n\tYour choice -> ";
        cin>>choice;
        if(choice==0){
            clrscrall();
            arr1.bulkAppend();
            clrscr();
        }
        else if(choice==1){
            arr1.display();
            clrscr();
        }
        else if (choice==2){
            arr1.append();
            clrscr();
        }
        else if (choice==3){
            arr1.insert();
            clrscr();
        }
        else if (choice==4){
            clrscrall();
            while(1){
                cout<<"\n\n\tDelete Menu\n";
                cout<<"\n\t1.Delete By Value\n\t2.Delete By Index\n\t3.Display\n\t4.Exit\n\n\tYour Choice -> ";
                cin>>choice;
                if(choice==1){
                    arr1.deleteByValue();
                    clrscr();
                }
                else if(choice==2){
                    arr1.deleteByIndex();
                    clrscr();
                }
                else if(choice==3){
                    arr1.display();
                    clrscr();
                }
                else if(choice==4){
                    cout<<"\n\tExiting...";
                    clrscr();
                    break;
                }
                else{
                    continue;
                }
            }
        }
        else if (choice==5){
            clrscrall();
            while(1){
                cout<<"\n\n\tSearch Menu\n";
                cout<<"\n\t1.Binary Search(This will sort your array!!)\n\t2.Linear Search\n\t3.Display\n\t4.Exit\n\n\tYour Choice -> ";
                cin>>choice;
                if(choice==1){
                    arr1.binarySearch();
                    clrscr();
                }
                else if(choice==2){
                    arr1.linearSearch();
                    clrscr();
                }
                else if(choice==3){
                    arr1.display();
                    clrscr();
                }
                else if(choice==4){
                    cout<<"\n\tExiting...";
                    clrscr();
                    break;
                }
                else{
                    continue;
                }
            }
        }
        else if (choice==6){
            int value = arr1.get();
            clrscr();
        }
        else if (choice==7){
            arr1.set();
            clrscr();
        }
        else if (choice==8){
            int sum1 = arr1.sum();
            clrscr();
        }
        else if (choice==9){
            int max1 = arr1.max();
            clrscr();
        }
        else if (choice==10){
            int min = arr1.min();
            clrscr();
        }
        else if (choice==11){
            arr1.reverse();
            clrscr();
        }
        else if (choice==12){
            clrscrall();
               while(1){
                
                cout<<"\n\n\tShift Menu\n";
                cout<<"\n\t1.Right Shift\n\t2.Left Shift\n\t3.Display\n\t4.Exit\n\n\tYour Choice -> ";
                cin>>choice;
                if(choice==1){
                    arr1.rightShift();
                    clrscr();
                }
                else if(choice==2){
                    arr1.leftShift();
                    clrscr();
                }
                else if(choice==3){
                    arr1.display();
                    clrscr();
                }
                else if(choice==4){
                    cout<<"\n\tExiting.....";
                    clrscr();
                    break;
                }
                else{
                    continue;
                }
            }
        }
        else if (choice==13){
            clrscrall();
               while(1){
                
                cout<<"\n\n\tRotate Menu\n";
                cout<<"\n\t1.Right Rotate\n\t2.Left Rotate\n\t3.Display\n\t4.Exit\n\n\tYour Choice -> ";
                cin>>choice;
                if(choice==1){
                    arr1.rightRotate();
                    clrscr();
                }
                else if(choice==2){
                    arr1.leftRotate();
                    clrscr();
                }
                else if(choice==3){
                    arr1.display();
                    clrscr();
                }
                else if(choice==4){
                    cout<<"\n\tExiting...";
                    clrscr();
                    break;
                }
                else{
                    continue;
                }
            }
        }
        else if (choice==14){
            clrscrall();
            cout<<"\n-------------------------------------------Exiting------------------------------------------------------------\n";
            break;
        }
        else{
            cout<<"\nEnter valid Choice...\n";
            clrscrall();
            continue;
        }
    }

 
 
    return 0;
}