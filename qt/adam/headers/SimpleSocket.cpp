//
// Created by aesma on 15.04.19.
//

#include "SimpleSocket.h"
bool SimpleSocket::Connect(const char* ip_address, const char* port) {
	if (!_is_connected) {
		_ip_address = ip_address;
		_port = port;

		_Init();

		return _CheckAddress() && _CreateSocket() && _Connect();
	}
	return true;
}
void SimpleSocket::Disconnect() {
	if (_is_connected) {
		close(_socket);
		_is_connected = false;
	}
}

int SimpleSocket::Write(const char* input, const int &size) {
	int result = size;
	std::thread th([&]() {
		_Thread_Write(input, std::ref(result));
	});
	th.join();
	return result;
}
char* SimpleSocket::Read() {
	return nullptr;
}
int SimpleSocket::WriteRead(const char *input, const int &size, char *&output) {
	int result = size;
	std::thread th([&]() {
		_Thread_WriteRead(input, std::ref(result), std::ref(output));
	});
	th.detach();
	return result;
}

bool SimpleSocket::_Init() {
	memset(&_hints, 0, sizeof(_hints));
	_hints.ai_family    = AF_UNSPEC;
	_hints.ai_socktype  = SOCK_STREAM;
	_hints.ai_flags     = AI_PASSIVE;
}
bool SimpleSocket::_CheckAddress() {
	int addr_info = getaddrinfo(_ip_address, _port, &_hints, &p);
	return (addr_info == 0) && (p != nullptr);
}
bool SimpleSocket::_CreateSocket() {
	_socket = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
	return _socket >= 0;
}

bool SimpleSocket::_Connect() {
	int con_res = connect(_socket, p->ai_addr, p->ai_addrlen);
	if (con_res == -1) {
		close(_socket);
		_is_connected = false;
		return false;
	}
	_is_connected = true;
	return true;
}

void SimpleSocket::_Thread_Write(const char *input, int &size) {
	if (_is_connected) {
		size = send(_socket, input, size, 0);
		return;
	}
	size = -1;
}
void SimpleSocket::_Thread_Read(char *&output, int &size, const int timeout) {
	if (_is_connected) {
		size = recv(_socket, output, 256, 0);
		return;
	}
	size = -1;
}
void SimpleSocket::_Thread_WriteRead(const char *input, int &size, char *&output) {
	if (_is_connected) {
		int sended_size = send(_socket, input, size, 0);
		if (sended_size != size) {
			size = -2;
			return;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
		char receive[256]{0};
		size = recv(_socket, receive, 256, 0);
		if (size == -1) {
			size = -3;
			return;
		}
		output = receive;
		return;
	}
	size = -1;
}
