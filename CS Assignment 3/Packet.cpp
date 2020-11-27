// Name        : Packet.cpp
// Author      :  Giovanni Parati
// Date        : 10/24/2020
// class for one packet. Contains arrival, process and finish times.
#include <string>
#include "Packet.h"
using namespace std;

Packet::Packet(){
    arrivalTime=0;
    processTime=0;
    finishTime=0;
}

Packet::Packet(int at, int pt){
    arrivalTime=at;
    processTime=pt;
    finishTime=0;
}

int Packet::getArrivalTime(){
    return arrivalTime;
}
int Packet::getProcessTime(){
    return processTime;
}
int Packet::getFinishTime(){
    return finishTime;
}

void Packet::setProcessTime(int i){
    processTime=i;
}