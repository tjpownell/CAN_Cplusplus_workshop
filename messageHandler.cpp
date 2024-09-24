#include "messageHandler.h"


  
messageHandler::messageHandler(){
  // Explicit Constructor
  pair<int, long long> defaultACM(mySourceAddress, myECU);
  msgID.insert(defaultACM);
  
}

void messageHandler::processACM(canFrame& Frame){
  
  extractECU(Frame);

  pair<int, long long> currentACM(Frame.SourceAddress, CurrentECU);

  bool success = get<1>(msgID.insert(currentACM));

  if (success){
    cout << "Address " << Frame.SourceAddress << " Claimed" << endl;
  }
  else if (Frame.SourceAddress==mySourceAddress) {

    handleACMCollisions(currentACM);

  }
}

void messageHandler::handleACMCollisions(pair<int, long long>& ACM){
  // Handle collisions on same Source Address

  // Compare Current ECU at SA in map to ECU of current ACM.
  if (ACM.second > myECU){
    // If larger, reassign 
    cout << "callback to change myECU" << endl;
  }
  else {
    // If smaller, reclaim address
    cout << "callback to ACM send to reclaim" << endl;
  }
  
}

void messageHandler::extractECU(canFrame& Frame){
  int it = 0;
  for (auto x : Frame.DataBytes){
    CurrentECU += CurrentECU<<8*it;
    it++;
  }
}
