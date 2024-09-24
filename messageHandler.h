// messageHandler.h
#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

using namespace std;
#include <iostream>
#include <vector>

#include <unordered_map> 

struct canFrame {

  int SourceAddress;
  int DataBytes[7];
  int PGN;
  int Priority;

};

class messageHandler{

private:

    long long CurrentECU;    
    int mySourceAddress = 240; // Every ECU has its own default address.
    long long myECU = 01020304050607; // Every ECU has its own ISO name.
    unordered_map<int, long long> msgID;

public:

messageHandler();
void processACM(canFrame Frame);
void handleACMCollisions(pair<int, long long> ACM);
void extractECU(canFrame Frame);


};

#endif