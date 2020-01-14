

#include <algorithm>
#include <stdexcept>

#include "GenericSocket.h"

// Constructor
GenericSocket::GenericSocket() {
   mp_Hints = new struct addrinfo;
   mp_AddressInfo = new struct addrinfo;
}

GenericSocket::GenericSocket(int socketFamily) : m_SocketFamily{socketFamily} {
   GenericSocket();
}

GenericSocket::GenericSocket(int socketFamily, int socketType) : m_GoodScoketType{socketType} {
   GenericSocket(socketFamily);
}

// Destructor
GenericSocket::~GenericSocket() {
   delete mp_Hints;
   delete mp_AddressInfo;
}

// Setters
int GenericSocket::setScoketType(int socketType) {
   bool goodScoketType = isGoodSocketType(socketType);
   return 0;
}

int GenericSocket::setScoketFamily(int socketFamily) {
   bool goodScoketFamily = isGoodSocketFamily(socketFamily);
   return 0;
}

int GenericSocket::setMessage(std::string message) {
   m_Message = message;
   return 0;
}

// Getters

// Actuators
int GenericSocket::sendMessage() {

   return 0;
}

int GenericSocket::buildSocket() {

   return 0;
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

// Static Methods
int GenericSocket::localPortNumber(int socketFileDescriptor) {

}

int GenericSocket::remotePortNumber(pSocketAddress_t socketAdrress) {

}