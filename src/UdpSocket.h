

#include "GenericSocket.h"

class UdpSocket :public GenericSocket {
private:
   /* data */
public:
   UdpSocket(/* args */);
   ~UdpSocket();
};

UdpSocket::UdpSocket(/* args */) {
   setScoketFamily(SOCK_DGRAM);
}

UdpSocket::~UdpSocket() {
}
