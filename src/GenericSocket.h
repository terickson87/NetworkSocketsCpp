
#include <iostream>
#include <string>

class GenericSocket
{
private:
   std::string message; 

public:
   GenericSocket(/* args */);
   ~GenericSocket();
   std::string getMessage();
   int sendMessage(std::string);
};
