
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

class GenericSocket {
private:
   int m_AIsocketFamily; // Either SOCK_STREAM (TCP) or SOCK_DGRAM (UDP)
   int m_GoodScoketFamily[2] = {SOCK_STREAM, SOCK_DGRAM};
   int m_AIsocketType = AF_UNSPEC; // Either AF_INET (IPv4), AF_INET6 (IPv6), or AF_UNSPEC (Undefined)
   int m_GoodScoketType[3] = {AF_INET, AF_INET6, AF_UNSPEC};

   struct addrinfo m_Hints;
   struct addrinfo m_AddressInfo;
   int socketFD;

   void* m_IpAddress; // Either a struct in_addr (IPv4) or struct in6_addr (IPv6)
   
   std::string m_message;

public:
   // Constructor
   GenericSocket(/* args */);

   // Destructor
   ~GenericSocket();

   // Setters
   int setScoketType(int socketType);
   int setScoketFamily(int socketFamily);
   int setMessage(std::string message);

   // Getters
   int scoketType();
   int scoketFamily();
   std::string message() {return m_message;}
   
   // Actuators
   int sendMessage();
   virtual int buildSocket() = 0;

   // Static Methods
   static int localPortNumber(int socketFileDescriptor);
   static int remotePortNumber(struct sockaddr* socketAdrress);
};

#endif