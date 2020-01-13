

#include <iostream>
#include "RunInNewWsl.h"

int main()
{
   RunInNewWsl wslRunner;
   wslRunner.setDir("~/Documents/NetworkSocketsCpp");
   wslRunner.setCommand("pwd; ls; echo Hello World!");
   wslRunner.executeWslCommand();

   return 0;
}
