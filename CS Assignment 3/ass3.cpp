// Name        : main.cpp
// Author      :  Main function provided by Professor Li, 
//               readPackets(), processPackets(), printResponses() added by Giovanni Parati
// Date        : 10/24/2020
// contains main method, readPackets(), processPackets(), printResponses()
#include <iostream>
#include <vector>
#include "Response.h"
#include "Buffer.cpp"

using namespace std;

//…
//read inputs into a packet vector based on the number of packets user supplied
vector<Packet> readPackets(){
    vector<Packet> v;
    int num;
    cin>>num;
    int at;
    int pt;
    for(int i=0; i<num; i++){
        cin>>at>>pt;
        v.push_back(Packet(at,pt));
    }
    return v;
}

//process the packets by traversing the packet vector and adding packets to the buffer, while processing
//and removing packets from the buffer and storing their response times to a response vector
vector<Response> processPackets(vector<Packet> p, Buffer* pb){
    int time=0;         //current time
    int targetTime=0;   //the time when the first packet in the buffer will be done processing
    int pos=0;          //packet vector index

    bool first=true;
    vector<Response> r;

    //special case: packet vector is empty
    if(p.size()==0){
        return r;
    }
    
    targetTime=p[0].getProcessTime()+p[0].getArrivalTime();

    //process packets based on times in the packet vector
    while(pos<p.size()){
        
        time=p[pos].getArrivalTime();
        if(time>=targetTime){
            if(!(pb->isEmpty())){
                pb->dequeue();
                r.push_back(Response(time));
            }
            targetTime=p[pos].getProcessTime()+time;
        }

        if(!(pb->isFull())){
            if(first){
                //special case: packet is the very first to be enqueued
                r.push_back(Response(time));
                first=false;
            }
            pb->enqueue(p[pos]);
        }
        else{
            //packet is dropped
            r.push_back(Response(-1));
        }

        pos++;
    }
    
    //process packets that are still in the buffer
    while(!pb->isEmpty()){
        pb->dequeue();
        if(!pb->isEmpty()){
            r.push_back(Response(targetTime));
        } 
        targetTime+=pb->atHead().getProcessTime();
    }

    return r;
}

//print all responses
void printResponses(vector<Response> r){
    cout<<endl;
    for(int i=0; i<r.size(); i++){
        cout<<r[i].getStartProcessingTime()<<endl;
    }
    //if no packets are recieved or processed, print idle
    if(r.size()==0){
        cout<<"idle"<<endl;
    }
}

//please don't modify main function
int main() {
    int bufferSize;
    cin >> bufferSize;
    vector<Packet> requests = readPackets(); //read packets from user

    //create buffer with the given size
    Buffer buffer(bufferSize);

    //process the packets
    vector<Response> responses = processPackets(requests, &buffer);

    //print responses
    printResponses(responses);

    return 0;
}