#ifndef OPMIRROR_PROTOCOL_H
#define OPMIRROR_PROTOCOL_H

#define C_STR 'w', 'p', 'p'

extern const int CMD_CLIENT_ROCK_SIZE;
extern const unsigned char CMD_CLIENT_ROCK[];

extern const int CMD_CLIENT_INFO_REQ_SIZE;
extern const unsigned char CMD_CLIENT_INFO_REQ[];

extern const int CMD_CLIENT_AUTH_REQ_SIZE;
extern const unsigned char CMD_CLIENT_AUTH_REQ[];

extern const int CMD_CLIENT_UID_REQ_SIZE;
extern const unsigned char CMD_CLIENT_UID_REQ[];

extern const int CMD_CLIENT_START_SIZE;
extern const unsigned char CMD_CLIENT_START_TRANS[];

extern const int CMD_CLIENT_CHK_SIZE;
extern const unsigned char CMD_CLIENT_CHK_FLAG[];


extern const int CMD_SERVER_ROLL_SIZE;
extern const unsigned char CMD_SERVER_ROLL[];

extern const int CMD_SERVER_INFO_RESP_SIZE;
extern const unsigned char CMD_SERVER_INFO_RESP[];

extern const int CMD_SERVER_STATUS_SIZE;
extern const unsigned char CMD_SERVER_STATUS[];

extern const int CMD_SERVER_AUTH_RESP_SIZE;
extern const unsigned char CMD_SERVER_AUTH_RESP[];

extern const int CMD_SERVER_UID_RESP_SIZE;
extern const unsigned char CMD_SERVER_UID_RESP[];

extern const int CMD_SERVER_SND_FLAG_SIZE;
extern const unsigned char CMD_SERVER_SND_FLAG[];


#endif //OPMIRROR_PROTOCOL_H
