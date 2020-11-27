// Name        : Buffer.h
// Author      :  Giovanni Parati
// Date        : 10/24/2020
// h file for Buffer.cpp

#include <string>
#include "Packet.h"
using namespace std;


template <class T> class BufferTemplate
{
private:
    int size;

    T* data;

    int head;

    int tail;

    int count;


public:
    BufferTemplate();
    BufferTemplate(int s);

    void enqueue(T item);

    T dequeue();

    bool isFull();

    bool isEmpty();

    int front();

    int back();

    T atHead();
};

class Buffer : public BufferTemplate<Packet> {
    public:
    Buffer(int s) : BufferTemplate<Packet>(s){};
};