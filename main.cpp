#include "messageHandler.h"

int main () {

  messageHandler J1939_IDs;

  int testSourceAddress = 240; 
  long long testECU = 01020304050610; 

  canFrame Test;
  Test.SourceAddress = testSourceAddress;

  for (int i = 0; i<8; i++){
    long long mask = 0xFF<<8*i;
    Test.DataBytes[i] = testECU&mask; // Assign the test ECU to data field of can Frame.
  }

  J1939_IDs.processACM(Test); // Test which must change our default ECU

  testSourceAddress = 240; 
  testECU = 01020304050600; 

  canFrame Test2;
  Test2.SourceAddress = testSourceAddress;

  for (int i = 0; i<8; i++){
    long long mask = 0xFF<<8*i;
    Test2.DataBytes[i] = testECU&mask; // Assign the test ECU to data field of can Frame.
  }

  J1939_IDs.processACM(Test2); // Test which must change our default ECU

  testSourceAddress = 241; 
  testECU = 01020304050600; 

  canFrame Test3;
  Test3.SourceAddress = testSourceAddress;

  for (int i = 0; i<8; i++){
    long long mask = 0xFF<<8*i;
    Test2.DataBytes[i] = testECU&mask; // Assign the test ECU to data field of can Frame.
  }

  J1939_IDs.processACM(Test3); // Test which must change our default ECU


  return 0;
}