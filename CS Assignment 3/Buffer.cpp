// Name        : Buffer.cpp
// Author      :  Giovanni Parati
// Date        : 10/24/2020
// class for the Buffer. Contains a data queue of items, size, head, tail, and count, as well as enqueue, dequeue, is full/empty,
//and some other getters.

#include <string>
#include "Buffer.h"
using namespace std;

template <class T>
BufferTemplate<T>::BufferTemplate(){
    size=100;
    data=new T[size];
    head=0;
    count=0;
    tail=0;
}

template <class T>
BufferTemplate<T>::BufferTemplate(int s){
    size=s;
    data=new T[size];
    head=0;
    count=0;
    tail=0;
}

//place an item into the back of the queue
template <class T>
void BufferTemplate<T>::enqueue(T item)
{
    data[tail] = item;

    tail = (tail + 1) % size;

    count++;

}

//remove an item from the front of the queue
template <class T>
T BufferTemplate<T>::dequeue()
{
    T item = data[head];

    head = (head + 1) % size;

    count--;

    return item;

}

template <class T>
bool BufferTemplate<T>::isEmpty()
{
    return count == 0;

}

 
template <class T>
bool BufferTemplate<T>::isFull()
{
    return count == size;

}

//return index of the head
template <class T>
int BufferTemplate<T>::front()
{
    return data[head];

}

//return the item at the head
template <class T>
T BufferTemplate<T>::atHead(){
    return data[head];
}

//return index of the tail
template <class T>
int BufferTemplate<T>::back()
{
    return data[tail];

}