#include "protocol.h"

/**
 * All client-originating packets
 */
const unsigned char CMD_CLIENT_ROCK[] = {C_STR, 'a', 'l', 'i', 'v', 'e', 'R', 'O', 'C', 'K'};
const int CMD_CLIENT_ROCK_SIZE = sizeof(CMD_CLIENT_ROCK);

const unsigned char CMD_CLIENT_INFO_REQ[] = {CMD_STR, 0x00, 0x00, 0x90};
const int CMD_CLIENT_INFO_REQ_SIZE = sizeof(CMD_CLIENT_INFO_REQ);

const unsigned char CMD_CLIENT_AUTH_REQ[] = {CMD_STR, 0x00, 0x00, 0x92};
const int CMD_CLIENT_AUTH_REQ_SIZE = sizeof(CMD_CLIENT_AUTH_REQ);

const unsigned char CMD_CLIENT_UID_REQ[] = {CMD_STR, 0x00, 0x00, 0xB2};
const int CMD_CLIENT_UID_REQ_SIZE = sizeof(CMD_CLIENT_UID_REQ);

const unsigned char CMD_CLIENT_START_TRANS[] = {CMD_STR, 0x00, 0x00, 0xC0};
const int CMD_CLIENT_START_TRANS_SIZE = sizeof(CMD_CLIENT_START_TRANS);

const unsigned char CMD_CLIENT_CHK_FLAG[] = {CMD_STR, 0x00, 0x00, 0x88};
const int CMD_CLIENT_CHK_FLAG_SIZE = sizeof(CMD_CLIENT_CHK_FLAG);


/**
 * All server-originating packets
 */
const unsigned char CMD_SERVER_ROLL[] = {C_STR, 'a', 'l', 'i', 'v', 'e', 'R', 'O', 'L', 'L'};
const int CMD_SERVER_ROLL_SIZE = sizeof(CMD_CLIENT_ROCK);

const unsigned char CMD_SERVER_INFO_RESP[] = {CMD_STR, 0x00, 0x00, 0x81};
const int CMD_SERVER_INFO_RESP_SIZE = sizeof(CMD_SERVER_INFO_RESP);

const unsigned char CMD_SERVER_STATUS[] = {CMD_STR, 0x00, 0x00, 0x91};
const int CMD_SERVER_STATUS_SIZE = sizeof(CMD_SERVER_STATUS);

const unsigned char CMD_SERVER_AUTH_RESP[] = {CMD_STR, 0x00, 0x00, 0x93};
const int CMD_SERVER_AUTH_RESP_SIZE = sizeof(CMD_SERVER_AUTH_RESP);

const unsigned char CMD_SERVER_UID_RESP[] = {CMD_STR, 0x00, 0x00, 0xB3};
const int CMD_SERVER_UID_RESP_SIZE = sizeof(CMD_SERVER_UID_RESP);

const unsigned char CMD_SERVER_SND_FLAG[] = {CMD_STR, 0x00, 0x00, 0x89};
const int CMD_SERVER_SND_FLAG_SIZE = sizeof(CMD_SERVER_SND_FLAG);
