#include"Array.h"
#include<iostream>

template<class T>
void appendArray(Array<T>& dest,const Array<T>&src){
    for(int i = 0; i<src.getLength();i++){
        dest.append(src.get(i));
    }
}
template<class T>
Array<T> concatArray(const Array<T>& a,const Array<T>&b){
    Array<T> res(a.getLength()+b.getLength());
    int i;
    for(i=0;i<a.getLength();i++){
        res.append(a.get(i));
    }
    for(i=0;i<b.getLength();i++){
        res.append(b.get(i));
    }

    return res;
}
template<class T>
Array<T> mergeArray(const Array<T>& a,const Array<T>&b){
    Array<T> res(a.getLength()+b.getLength());
    int i=0,j=0,m = a.getLength(),n = b.getLength();
    while(i<m&&j<n){
        if(a.get(i)<b.get(j)){
            res.append(a.get(i++));
        }
        else if(a.get(i)>b.get(j)){
            res.append(b.get(j++) );
        }
        else{
            res.append(b.get(j));
            i++;
            j++;
        }
    }
    while(i<m){
        res.append(a.get(i++) );
    }
    while(j<n){
        res.append(b.get(j++) );
    }
    return res;
}
template<class T>
Array<T> unionArray(const Array<T>&a,const Array<T>&b,bool isSorted){
    Array<T> res(a.getLength()+b.getLength());
    int j=0; 
    if(!isSorted){
        appendArray(res,a);
        for(j;j<b.getLength();j++){
            if(res.linearSearch(b.get(j))!=-1){
            }
            else{
                res.append(b.get(j));
            }
        }
        return res;
    }
    else{
        return mergeArray(a,b);
    }
}
template<class T>
Array<T> intersectionArray(const Array<T>& a,const Array<T>&b,bool isSorted){
    Array<T> res(a.getLength()+b.getLength());
    int i=0,j=0,m = a.getLength(),n = b.getLength(); 
    if(!isSorted){
        for ( i = 0; i < a.getLength(); i++)
        {
            for ( j = 0; j < b.getLength(); j++)
            {
                if(a.get(i)==b.get(j)){
                    res.append(a.get(i));
                }
            }
            
        }
        
        return res;
        
    }
    else{
        while(i<m&&j<n){
        if(a.get(i)<b.get(j)){
            i++;
        }
        else if(a.get(i)>b.get(j)){
            j++;
        }
        else{
            res.append(a.get(i));
            i++;
            j++;
        }
    }
        
        return res;
    }
}
template<class T>
Array<T> differenceArray(const Array<T>& a,const Array<T>&b,bool isSorted){
    Array<T> res(a.getLength()+b.getLength());
    int i=0,j=0,m = a.getLength(),n = b.getLength(); 
    if(!isSorted){
        for(i;i<a.getLength();i++){
            if(b.linearSearch(a.get(i))==-1){
                res.append(a.get(i));
            }
        }
        return res;
        
    }
    else{
        while(i<m&&j<n){
            if(a.get(i)<b.get(j)){
                res.append(a.get(i++));
            }
            else if(a.get(i)>b.get(j)){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        while(i<m){
            res.append(a.get(i++) );
        }
        
        return res;
    }
}







int main(){
    Array<float> a(3),b(2);
    a.append(0.9);
    a.append(1.1);
    a.append(1.0);
    a.append(2.0);
    b.append(0.9);
    a.append(2.2);
    b.append(1.0);
    b.append(3.4);
    b.append(2.2);
    b.append(6.4);
    b.append(4.3);
    // appendArray(a,b);
    // cout<<"Length = "<<a.getLength()<<" capacity = "<<a.getCapacity();
    // a.display();
    // Array<float> concat = concatArray(a,b) ;
    // cout<<"Length = "<<concat.getLength()<<" capacity = "<<concat.getCapacity();
    // concat.display();
    // Array<float> union1=unionArray(a,b,0);
    // union1.display();
    // Array<float> inter = intersectionArray(a,b,0);
    // inter.display();
    // Array<float> difference  = differenceArray(b,a,0);
    // difference.display();

}