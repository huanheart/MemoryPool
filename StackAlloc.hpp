#include<memory>

using namespace std;
template <typename T>
struct StackNode_
{
    T data;
    StackNode_ * prev;
    StackNode_()
    {
        prev=nullptr;
    }
};

//T为存储对象的类型，Alloc为分配器，默认使用std::allocator这个分配器
template <typename T,typename Alloc=std::allocator<T> >
class StackAlloc
{

public:
    typedef StackNode_<T> Node;
    typedef typename Alloc::template rebind<Node>::other allocator;

    //默认构造
    StackAlloc(){
        head_=nullptr;
    }

    ~StackAlloc(){
        clear();
    }

    bool empty(){
        return (head_==nullptr);
    }

    void clear(); //释放栈中的所有内存

    void push(T element);

    T pop();

    T top(){
        return (head_->data);
    }

private:
    allocator allocator_;
    Node* head_;

};




template <typename T,typename Alloc>
void StackAlloc<T,Alloc>::clear(){
    Node * curr=head_;
    //逐个出栈

    while(curr != 0){
        Node * tmp=curr->prev;
        //先析构，再进行回收内存
        allocator_.destroy(curr);
        allocator_.deallocate(curr,1);
        curr = tmp;
    }
    head_=nullptr;

}

template<typename T,typename Alloc>
void StackAlloc<T,Alloc>::push(T element){
    //先分配内存
    Node * newNode=allocator_.allocate(1);
    //然后调用其构造函数
    allocator_.construct(newNode,Node() );

    //入栈操作
    newNode->data =element;
    newNode->prev=head_;
    head_=newNode;

}

//出栈：
template<typename T,typename Alloc>
T StackAlloc<T,Alloc>::pop(){
    T result =head_->data;
    Node * tmp=head_->prev;
    //先调用析构函数，再来释放内存
    allocator_.destroy(head_);
    allocator_.deallocate(head_,1);
    head_=tmp;
    return result;
}