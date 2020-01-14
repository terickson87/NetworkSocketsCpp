
#ifndef GENERIC_SOCKETS_H
#define GENERIC_SOCKETS_H

// Socket Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
// #include <signal.h> //Needed for cleanUpChildProcesses

// Standard Libraries
#include <iostream>
#include <string>

typedef struct addrinfo* pAddressInfo_t;
typedef struct sockaddr* pSocketAddress_t;

class GenericSocket {
private:
   int m_SocketFamily; // Either SOCK_STREAM (TCP) or SOCK_DGRAM (UDP)
   const int m_GoodScoketFamily[2] = {SOCK_STREAM, SOCK_DGRAM};
   int m_SocketType = AF_UNSPEC; // Either AF_INET (IPv4), AF_INET6 (IPv6), or AF_UNSPEC (Undefined)
   const int m_GoodScoketType[3] = {AF_INET, AF_INET6, AF_UNSPEC};

   pAddressInfo_t mp_Hints;
   pAddressInfo_t mp_AddressInfo;
   int socketFD;

  union {
     struct in_addr;
     struct in6_addr;
  } m_IpAddress; // Either a struct in_addr (IPv4) or struct in6_addr (IPv6)
   
   std::string m_Message;

   // Value check methods
   bool isGoodSocketFamily(int socketFamily);
   bool isGoodSocketType(int socketType);

public:
   // Constructor
   GenericSocket();
   GenericSocket(int socketFamily);
   GenericSocket(int socketFamily, int socketType);

   // Destructor
   ~GenericSocket();

   // Setters
   int setScoketType(int socketType);
   int setScoketFamily(int socketFamily);
   int setMessage(std::string message);

   // Getters
   int scoketType() {return m_SocketType;}
   int scoketFamily() {return m_SocketFamily;}
   std::string message() {return m_Message;}
   
   // Actuators
   int sendMessage();
   int buildSocket();

   // Static Methods
   static int localPortNumber(int socketFileDescriptor);
   static int remotePortNumber(pSocketAddress_t p_SocketAdrress);
};

#endif