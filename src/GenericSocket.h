
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
   int m_AIsocketType = AF_UNSPEC; // Either AP_INET (IPv4), AP_INET5 (IPv6), or AF_UNSPEC (Undefined)
   
   struct addrinfo m_Hints;
   struct addrinfo m_AddressInfo;
   int socketFD;

   void* m_IpAddress; // Either a struct in_addr (IPv4) or struct in6_addr (IPv6)
   
   std::string m_message;

public:
   GenericSocket(/* args */);
   ~GenericSocket();

   std::string message() {return m_message;}
   int setMessage(std::string message);
   int sendMessage();

   virtual int buildSocket() = 0;

   static int localPortNumber(int socketFileDescriptor);
   static int remotePortNumber(struct sockaddr* socketAdrress);
};

#endif