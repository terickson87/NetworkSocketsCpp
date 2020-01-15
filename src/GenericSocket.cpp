

#include <algorithm>
#include <stdexcept>

#include "GenericSocket.h"

// Constructor
GenericSocket::GenericSocket() {
   mp_AddressInfo = new struct addrinfo;
}

GenericSocket::GenericSocket(int socketFamily) : GenericSocket() {
   setScoketFamily(socketFamily);
}

GenericSocket::GenericSocket(int socketFamily, int socketType) : GenericSocket(socketFamily) {
   setScoketType(socketType);
}

// Destructor
GenericSocket::~GenericSocket() {
   freeaddrinfo(&mp_Hints);
   freeaddrinfo(mp_AddressInfo);
   delete mp_AddressInfo;
}

// Setters
int GenericSocket::setScoketType(int socketType) {
   bool goodScoketType = this->isGoodSocketType(socketType);
   return m_RETURN_SUCCESS;
}

int GenericSocket::setScoketFamily(int socketFamily) {
   bool goodScoketFamily = this->isGoodSocketFamily(socketFamily);
   return m_RETURN_SUCCESS;
}

int GenericSocket::setMessage(std::string message) {
   m_Message = message;
   return m_RETURN_SUCCESS;
}

// Getters

// Actuators
int GenericSocket::buildClientSocket() {
   for(pAddressInfo_t iAI = mp_AddressInfo; iAI != NULL; iAI = iAI->ai_next) {
      int success = m_RETURN_FAILURE;
      while (success != m_RETURN_SUCCESS) {

         // get the socket file descriptor from socket(). If it fails, call again on
         // the next addrinfo in the linked list.
         m_SocketFileDescriptor = socket(iAI->ai_family, iAI->ai_socktype, iAI->ai_protocol);
         if (m_SocketFileDescriptor == -1) {
            perror("buildClientSocket: socket");
            success = m_RETURN_FAILURE;
         } else {
            mp_i_AddressInfo = iAI;
            success = m_RETURN_SUCCESS;
         }

      }
   }
   return m_RETURN_SUCCESS;
}

int GenericSocket::connectSocket() {
   // connect to the socket. If it failes, exit this loop iteration and
   // continue on the next one.
   int returnVal = connect(m_SocketFileDescriptor, mp_i_AddressInfo->ai_addr, mp_i_AddressInfo->ai_addrlen);
   if ( returnVal == -1) {
      perror("connectSocket: connect");
      closeSocket();
      return m_RETURN_FAILURE;
   }
   return returnVal;
}

int GenericSocket::buildServerSocket() {

   return m_RETURN_SUCCESS;
}

int GenericSocket::closeSocket() {
   close(m_SocketFileDescriptor);
   return m_RETURN_SUCCESS;
}

// Value check methods
bool GenericSocket::isGoodSocketFamily(int socketFamily) {
   if (std::end(m_GoodScoketFamily) 
      == std::find(std::begin(m_GoodScoketFamily), std::end(m_GoodScoketFamily), socketFamily)) {
         throw std::invalid_argument("Bad Socket Family Value");
   } else {
         return true;
   }
}

bool GenericSocket::isGoodSocketType(int socketType) {
   if (std::end(m_GoodScoketType) 
      == std::find(std::begin(m_GoodScoketType), std::end(m_GoodScoketType), socketType)) {
         throw std::invalid_argument("Bad Socket Type Value");
   } else {
         return true;
   }
}

// Helper Functions
int GenericSocket::initializeHints() {
   memset(&mp_Hints, 0, sizeof mp_Hints);
   mp_Hints.ai_family = m_SocketFamily;
   mp_Hints.ai_socktype = m_SocketType;
   return m_RETURN_SUCCESS;
}

int GenericSocket::getAddressInfo() {
   int returnVal = getaddrinfo(m_IpAddressAsAString.c_str(), this->portNumberAsAString().c_str(), &mp_Hints, &mp_AddressInfo);
   if (returnVal != 0) {
      std::string gaiStandardError(gai_strerror(returnVal));
      std::string errorMessage = "getaddrinfo: " + gaiStandardError;
      // std::cout << "Error getaddrinfo: " << gai_strerror(returnVal) << std::endl;
      throw std::runtime_error(errorMessage);
   } else {
      return m_RETURN_SUCCESS;
   }
}

int GenericSocket::bypassBindNameInUseError() {
   // Bypass "Address already in use" error messages
   // Set the socket's options. On failure, throw error.
   // http://pubs.opengroup.org/onlinepubs/7908799/xns/setsockopt.html
   int yes = 1;
   int returnVal = setsockopt(m_SocketFileDescriptor, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
   if ( returnVal != 0) {
      perror ("The following error occurred");
      throw std::runtime_error("bypassBindNameInUseError: setsockopt");
   } else {
      return m_RETURN_SUCCESS;
   }
}

int GenericSocket::bindSocket() {
   int returnVal = bind(m_SocketFileDescriptor, mp_AddressInfo->ai_addr, mp_AddressInfo->ai_addrlen);
   if ( returnVal != 0) {
      this->closeSocket();
      perror ("The following error occurred");
      return m_RETURN_FAILURE;
   } else {
      return m_RETURN_SUCCESS;
   }
}

// Static Methods
int GenericSocket::localPortNumber(int socketFileDescriptor) {

}

int GenericSocket::remotePortNumber(pSocketAddress_t socketAdrress) {

}