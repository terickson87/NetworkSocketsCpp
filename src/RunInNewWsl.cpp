

#include "src/RunInNewWsl.h"
#include <cstdlib>

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
   m_wslCommand += m_command;
   m_wslCommand += m_commandSuffix;
}

int RunInNewWsl::executeWslCommand() {
   this->buildWslCommand();
   system(m_wslCommand.c_str());
}