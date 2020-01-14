

#include "GenericSocket.h"

class UdpSocket :public GenericSocket {
private:
   
public:
   UdpSocket();
   ~UdpSocket();

   int receiveMessage();
};
