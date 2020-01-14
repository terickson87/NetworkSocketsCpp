
#ifndef RUN_IN_NEW_WSL_H
#define RUN_IN_NEW_WSL_H

// Standard Libraries
#include <string>

class RunInNewWsl {
private:
   const std::string m_commandPredicate{"cmd.exe /c start cmd.exe /k 'wsl -- cd "};
   const std::string m_commandSuffix{"'"};
   std::string m_directory{"~"};
   std::string m_command{"pwd; ls; echo Hello World!"};
   std::string m_wslCommand{""};
   
   int buildWslCommand();
   // cmd.exe /c start cmd.exe /k 'wsl -- cd ~/Documents/NetworkSocketsCpp; pwd; ls; echo Hello World!'

public:
   RunInNewWsl(/* args */);
   ~RunInNewWsl();

   std::string getDir() const { return m_directory; }
   std::string getCommand() const { return m_command; }

   int setDir(std::string directory);
   int setCommand(std::string command);

   int executeWslCommand();
};

#endif