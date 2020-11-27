// Name        : Packet.h
// Author      :  Giovanni Parati
// Date        : 10/24/2020
// h file for Packet.cpp

#include <string>
using namespace std;

class Packet
{
public:
    Packet();
    Packet(int arrivalTime, int processTime);

    int getArrivalTime();
    int getProcessTime();
    int getFinishTime();

    void setProcessTime(int i);
private:
    int arrivalTime;
    int processTime;
    int finishTime;
};