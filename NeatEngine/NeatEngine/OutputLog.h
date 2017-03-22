#include <string>

class OutputLog
{
private:

public:
  OutputLog();
  ~OutputLog();

  enum class MessageType {MESSAGE, ERROR};

  void Output(std::string text, MessageType type);
};