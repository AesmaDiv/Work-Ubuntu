//
// Created by aesma on 15.04.19.
//

#ifndef ADAM_TCP_HEADERS_SIMPLESOCKET_H_
#define ADAM_TCP_HEADERS_SIMPLESOCKET_H_

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

//#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include <mutex>
//#include <byteswap.h>

class SimpleSocket {
public:
	SimpleSocket() = default;
	~SimpleSocket() = default;

	bool Connect(const char *ip_address, const char *port);
	void Disconnect();

	int Write(const char *input, const int &size);
	int WriteRead(const char *input, const int &size, char *&output);
	char *Read();

protected:
	const char *_ip_address = "0.0.0.0";
	const char *_port = "502";

	int _socket = -1;
	addrinfo _hints = {}, *p = {};
	bool _is_connected = false;

	bool _Init();
	bool _CheckAddress();
	bool _CreateSocket();
	bool _Connect();

	void _Thread_Write(const char *input, int &size);
	void _Thread_Read(char *&output, int &size, const int timeout);
	void _Thread_WriteRead(const char *input, int &size, char *&output);
};

#endif //ADAM_TCP_HEADERS_SIMPLESOCKET_H_
