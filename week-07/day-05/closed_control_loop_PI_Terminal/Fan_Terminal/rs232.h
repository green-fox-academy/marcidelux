#ifndef RS232_H
#define RS232_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

    int comEnumerate();

    int comGetNoPorts();

    void comTerminate();

    const char * comGetPortName(int index);

    const char * comGetInternalName(int index);

    int comFindPort(const char * name);

    int comOpen(int index, int baudrate);

    void comClose(int index);

    void comCloseAll();

    int comWrite(int index, const char * buffer, size_t len);

    int comRead(int index, char * buffer, size_t len);

#ifdef __cplusplus
}
#endif

#endif // RS232_H
