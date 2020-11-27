// Name        : Response.cpp
// Author      : Giovanni Parati
// Date        : 10/24/2020
// class for one response. Contains startProcessingTime.

#include <string>
#include "Response.h"
using namespace std;

Response::Response(int t){
    startProcessingTime=t;
}

int Response::getStartProcessingTime(){
    return startProcessingTime;
}