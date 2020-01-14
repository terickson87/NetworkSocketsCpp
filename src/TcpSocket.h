

#include "GenericSocket.h"

class TcpSocket : public GenericSocket {
private:
   
public:
   TcpSocket();
   ~TcpSocket();

   int connect();
   int acceptConnection();
   int receiveMessage();
};
