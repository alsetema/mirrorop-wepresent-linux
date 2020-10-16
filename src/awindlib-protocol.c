#include <netinet/in.h>
#include "awindib-protocol.h"

#define CHECK_FRAME_LENGTH(len)                                 \
        if (length < AWINDIB_HEADER_SIZE + AWINDIB_TAIL_SIZE) { \
            return AWINDIB_INVALID_FRAME;                       \
        }

int awindib_get_framenum(uint8_t *frame_start, unsigned int length, uint32_t *result) {
    CHECK_FRAME_LENGTH(length)

    uint8_t *framenum = frame_start + length - AWINDIB_TAIL_SIZE - AWINDIB_FRAME_NUM_OFFSET;
    uint32_t *framenum_int = (uint32_t *) framenum;

    *result = ntohl(*framenum_int);
    return AWINDIB_OK;
}

int awindib_get_length(uint8_t *frame_start, unsigned int length, uint32_t *result) {
    CHECK_FRAME_LENGTH(length)

    uint8_t *data_length = frame_start + AWINDIB_DATA_LENGTH_OFFSET;
    uint32_t *data_length_int = (uint32_t *) data_length;
    uint32_t first_value = ntohl(*data_length_int);
    uint32_t second_value = ntohl(*(data_length_int + 1));

    if (first_value != second_value) {
        return AWINDIB_ERROR;
    }
    *result = first_value;
    return AWINDIB_OK;
}

int awindib_get_data(uint8_t *frame_start, unsigned int length, uint8_t **result_start, uint32_t *result_length) {
    CHECK_FRAME_LENGTH(length)

    uint32_t frame_length;
    int success = awindib_get_framenum(frame_start, length, &frame_length);
    if (success != AWINDIB_OK) {
        return AWINDIB_ERROR;
    }

    *result_length = frame_length - AWINDIB_HEADER_SIZE - AWINDIB_TAIL_SIZE;
    *result_start = frame_start + AWINDIB_HEADER_SIZE;
    return AWINDIB_OK;
}