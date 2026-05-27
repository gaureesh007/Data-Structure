#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
public:
    Queue() : head_(nullptr), tail_(nullptr), size_(0) {}
    ~Queue() { clear(); }

    void enqueue(const T& value) {
        Node* node = new Node(value);
        if (tail_) tail_->next = node;
        tail_ = node;
        if (!head_) head_ = node;
        ++size_;
    }

    T dequeue() {
        if (empty()) throw std::out_of_range("dequeue from empty queue");
        Node* node = head_;
        T value = node->data;
        head_ = head_->next;
        if (!head_) tail_ = nullptr;
        delete node;
        --size_;
        return value;
    }

    const T& front() const {
        if (empty()) throw std::out_of_range("front from empty queue");
        return head_->data;
    }

    const T& back() const {
        if (empty()) throw std::out_of_range("back from empty queue");
        return tail_->data;
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }

    void clear() {
        while (head_) {
            Node* tmp = head_;
            head_ = head_->next;
            delete tmp;
        }
        tail_ = nullptr;
        size_ = 0;
    }

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    Node* head_;
    Node* tail_;
    std::size_t size_;
};

int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Front: " << q.front() << " Back: " << q.back() << " Size: " << q.size() << "\n";
    while (!q.empty()) {
        std::cout << "Dequeued: " << q.dequeue() << "\n";
    }
    return 0;
}
