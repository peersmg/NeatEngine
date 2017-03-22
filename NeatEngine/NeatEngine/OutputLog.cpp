#include "OutputLog.h"
#include <iostream>

OutputLog::OutputLog()
{

}

OutputLog::~OutputLog()
{

}

void OutputLog::Output(std::string text, OutputLog::MessageType type)
{
  switch (type)
  {
  case OutputLog::MessageType::MESSAGE:
    std::cout << "Message: " << text << std::endl;
    break;
  case OutputLog::MessageType::ERROR:
    std::cout << "ERROR: " << text << std::endl;
    break;
  default:
    break;
  }
}