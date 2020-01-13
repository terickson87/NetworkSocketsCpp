

#include "RunInNewWsl.h"
#include <cstdlib>
#include <iostream>

RunInNewWsl::RunInNewWsl() {
}

RunInNewWsl::~RunInNewWsl() {
}
   
int RunInNewWsl::setDir(std::string directory) {
   m_directory = directory;
   return 0;
}

int RunInNewWsl::setCommand(std::string command) {
   m_command = command;
   return 0;
}

int RunInNewWsl::buildWslCommand() {
   m_wslCommand = m_commandPredicate;
   m_wslCommand += m_directory;
   m_wslCommand += "; ";
   m_wslCommand += m_command;
   m_wslCommand += m_commandSuffix;
   std::cout << "wslCommand String: \"" << m_wslCommand << "\"" << std::endl;
   return 0;
}

int RunInNewWsl::executeWslCommand() {
   this->buildWslCommand();
   return system(m_wslCommand.c_str());
}