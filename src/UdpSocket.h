

#include "GenericSocket.h"

class UdpSocket : virtual public GenericSocket {
private:
   
public:
   UdpSocket();
   ~UdpSocket();

   int sendMessage();
   int receiveMessage();
};
