

#include "GenericSocket.h"

class TcpSocket : public GenericSocket {
private:
   
public:
   TcpSocket(/* args */);
   ~TcpSocket();
};

TcpSocket::TcpSocket(/* args */) {
   setScoketFamily(SOCK_STREAM);
}

TcpSocket::~TcpSocket() {
}


