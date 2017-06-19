#ifndef COMMAND_HANDLER_H_INCLUDED
#define COMMAND_HANDLER_H_INCLUDED
#include "File_IO.h"
#include "rs232.h"

#define BITRATE 115200

void command_execution(char *instruction);

#endif // COMMAND_HANDLER_H_INCLUDED
