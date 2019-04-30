//
// Created by aesma on 11.04.19.
//

#ifndef ADAM_TCP_AESMATCP_H
#define ADAM_TCP_AESMATCP_H

#include "SimpleSocket.h"

#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
#include <mutex>
#include <byteswap.h>

class AesmaTcp : public SimpleSocket {
public:
//	struct SlotAnalog { ushort channels[8]; };
//	struct SlotDigital { char channels[8]; };

	enum SlotType { Analog, Digital};

	AesmaTcp() : SimpleSocket() {}
	~AesmaTcp() = default;

	void SetReading(const bool &state);
	void SetEchoState(const bool &state) { _is_echo_on = state; }

	ushort GetChannel(SlotType slot_type, const ushort &slot, const ushort &channel) const;
	ushort GetChannel_Analog(const ushort &slot, const ushort &channel) const;
	ushort GetChannel_Digital(const ushort &slot, const ushort &channel) const;

	void SetChannel(SlotType slot_type, const ushort &slot, const ushort &channel, const ushort &value);
	void SetChannel_Analog(const ushort &slot, const ushort &channel, const ushort &value);
	void SetChannel_Digital(const ushort &slot, const ushort &channel, const bool &value);

//	SlotAnalog GetSlot_Analog(const int &slot) const;
//	SlotDigital GetSlot_Digital(const int &slot) const;

private:

	bool _is_echo_on = false;
    bool _is_reading = false;
    const char* _command_read_analog = new char[12] {
        0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
        0x1, 0x4, 0x0, 0x0, 0x0, 0x40
    };
    const char* _command_read_digital = new char[12] {
        0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
        0x1, 0x1, 0x0, 0x0, 0x0, (char)0x80
    };
    char* _command = nullptr;
    int _command_len = 0;
	std::mutex _lock;

//	SlotAnalog* _slots_analog = new SlotAnalog[8];
//  SlotDigital* _slots_digital  = new SlotDigital[8];
    ushort _analog[8][8] {0};
	ushort _digital[8] {0};

	bool _RequestValues(SlotType slot_type);

    void _ProcessValues_Analog(char *bytes, const int &size);
    void _ProcessValues_Digital(char *bytes, const int &size);

	void _BuildCommand(SlotType slot_type, const ushort &slot, const ushort &channel, const ushort &value);
	void _BuildCommand_Analog(const ushort &slot, const ushort &channel, const ushort &value);
	void _BuildCommand_Digital(const ushort &slot, const ushort &channel, const bool &value);

    void _Thread_MainCycle();
};


#endif //ADAM_TCP_AESMATCP_H
