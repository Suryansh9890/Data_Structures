#include <bits/stdc++.h>
using namespace std;
class QueueNode{
public:
    int data;
    QueueNode *next;
    QueueNode (int d){
        data=d;
        next=nullptr;
    }
};
class CircularQueue{
public :
    QueueNode *front,*rear;
    CircularQueue(){
        front=rear=nullptr;
    }
    void enqueue(int data);
    void dequeue();
    void display();
};
void CircularQueue::enqueue(int key){
    QueueNode* node = new QueueNode(key);
    if(rear==nullptr){
        front = rear = node;
        return;
    }
    node->next = front;
    rear->next=node;
    rear = node;
}
void CircularQueue::dequeue(){
    if(rear==nullptr)
        return;
    QueueNode* temp = front;
    front = front->next;
    if(front==nullptr){
        rear= nullptr;
        delete(temp);
    }
    rear->next = front;
    delete(temp);
}
void CircularQueue::display(){
    QueueNode* temp = front;
    if(rear==nullptr)
        return;
    while(temp != rear){
        cout<<temp->data<<" ---> ";
        temp=temp->next;
    }
    cout<<temp->data<<"\n";
}
int main()
{
	CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
	return 0;
}
