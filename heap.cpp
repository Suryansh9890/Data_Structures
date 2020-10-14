#include <bits/stdc++.h>
using namespace std;
class Heap{
public:
    int size;
    int index;
    int *arr;
    Heap(int s){
        size=s;
        index=0;
        arr = new int[size+1];
    }
    void Insert(int key);
    int deleteHeap();
    void Display();
    bool isEmpty();
    void heapSort(vector<int> &vec);
};
void Heap::Insert(int val){
    index++;
    if(index > size){
        cout<<"\nHeap is full!!\n";
        return;
    }
    int i=index;
    while(i>1 && val > arr[i/2]){
        arr[i]=arr[i/2];
        i=i/2;
    }
    arr[i] = val;
}
void Heap::Display(){
    cout<<"\n";
    if(isEmpty())
        cout<<"Empty Heap!!!\n";
    for(int i =1 ; i<=index ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int Heap::deleteHeap(){
    if(isEmpty()){
        cout<<"Cannot Delete from an Empty Heap \n";
        return 0;
    }
    int i=1;
    int val = arr[1];
    arr[1] = arr[index];
    index--;
    while(i<=index){
       if(arr[2*i] > arr[(2*i)+1] && arr[2*i] > arr[i] && 2*i <= index){
                    std::swap(arr[i] , arr[2*i]);
                    i=2*i;
                }
                else if(arr[2*i] < arr[(2*i)+1] && arr[(2*i)+1] > arr[i] && (2*i)+1 <=index){
                    std::swap(arr[i] , arr[(2*i)+1] );
                     i=(2*i)+1;
                }
                else
                    break;
            }
    return val;
}

bool Heap::isEmpty(){
    return index<=0;
}
void Heap::heapSort(vector<int> &vec){
    for(int i = index-1 ; i>=0 ; i--){
        vec[i] = deleteHeap(); 
    }
    
}
int main()
{
	Heap heap(7);
    vector<int> vec ={10,20,30,25,5,40,35};
    for(int i=0;i<7;i++){
        heap.Insert(vec[i]);
    }
    heap.Display();
    for(int i = 1 ; i <= 7 ; i++){
        vec[i-1] = (heap.arr[i]);
    }
    for(auto i : vec)
        cout<<i<<" ";
    cout<<"\n";
   for(int i=1;i<=7;i++){
   cout<<heap.deleteHeap()<<" ";
   }
    heap.heapSort(vec);
     for(auto i : vec)
        cout<<i<<" ";
    cout<<"\n";
   heap.deleteHeap();
	return 0;
}