 #include <iostream>
using namespace std;
template <class T>
class Doubly_Circular_list{
    private:
    Doubly_Circular_list * prev;
    T data;
    Doubly_Circular_list * next;

    public:
    bool isEmpty(){
        if(this->prev==nullptr&&this->next==nullptr){
            return true;
        }
        return false;
    }
    int size(Doubly_Circular_list * head){
        if(isEmpty()){
            return 0;
        }
        Doubly_Circular_list * temp== head;
        int size = 0;
        while(temp->next!=head){
            size++;
            temp = temp->next;
        }
    }
    Doubly_Circular_list(){
        prev = nullptr;
        next = nullptr;
        data = -1;
    }



    
};
int main(){
    
    return 0;
}