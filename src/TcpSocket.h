

#include "GenericSocket.h"

class TcpSocket : virtual public GenericSocket {
private:
   
public:
   TcpSocket();
   ~TcpSocket();

   int connect();
   int acceptConnection();

   int sendMessage();
   int receiveMessage();
};
