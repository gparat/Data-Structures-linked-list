// Name        : Response.h
// Author      :  Giovanni Parati
// Date        : 10/24/2020
// h file for Response.cpp

#include <string>
using namespace std;

class Response
{
public:
    Response(int time);

    int getStartProcessingTime();
private:
    int startProcessingTime;
};