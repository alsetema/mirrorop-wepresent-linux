#ifndef OPMIRROR_AWINDIB_PROTOCOL_H
#define OPMIRROR_AWINDIB_PROTOCOL_H

#include <stdint.h>

#define AWINDIB_OK 0
#define AWINDIB_ERROR -1
#define AWINDIB_INVALID_FRAME -2

#define AWINDIB_HEADER_SIZE 46
#define AWINDIB_TAIL_SIZE 42
#define AWINDIB_DATA_LENGTH_OFFSET 30
#define AWINDIB_FRAME_NUM_OFFSET 0


int awindib_get_framenum(uint8_t *frame_start, unsigned int length, uint32_t *result);

int awindib_get_length(uint8_t *frame_start, unsigned int length, uint32_t *result);

int awindib_get_data(uint8_t *frame_start, unsigned int length, uint8_t **result_start, uint32_t *result_length);

#endif //OPMIRROR_AWINDIB_PROTOCOL_H
