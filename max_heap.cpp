#include<iostream>
#include<algorithm>
#include<string>
#include<cassert>

using namespace std;

template<typename Item>
class Maxheap{
private:
  Item* data;
  int count;
  int capacity;
// move index k up to the top
  void shiftup(int k){

    while(k>1 && data[k]>data[k/2]){
      swap(data[k],data[k/2]);
      k/=2;
    }
  }

  void shiftdown(int k){
    while(2*k<=count ){
      int j=2*k;
      if(j+1<=count && data[j+1]>data[j])
        j+=1
        if(data[k]>=data[j])
        break;
        swap(data[k],data[j]);
        k=j;
    }
  }


public:
  MaxHeap(int capacity){
    data=new Item[capacity+1];
    count=0;
    this->capacity=capacity;
  }

  MaxHeap(Item arr[],int n){
    data=new Item[n+1];
    capacity=n;
    for(int i=0;i<n;i++){
      data[i+1]=arr[i];
    }
    count=n;

    for(int i=count/2;i>=1;i--){
      shiftDown(i);
    }

  }



 ~MaxHeap(){
   delete [] data;
 }

 int size(){
   return count;
 }

 bool isEmpty(){
   return count==0;
 }

 void insert(Item item){
   assert(count+1<=capacity);
   data[count+1]=item; //count [1....count]
   count++;
   shiftup(count);
 }
Item extractMax(){
  assert(count>0);
  Item ret=data[1];
  swap(data[1],data[count]);
  count--;
  shiftdown(1);
  return ret;
}


};


int main(){
  MaxHeap<int> maxheap=MaxHeap<int>(100);
  return 0;
}
