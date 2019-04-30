//
// Created by aesma on 11.04.19.
//

#include "AesmaTcp.h"
#include "AesmaFuncs.h"

/* ********** PUBLIC ************ */
void AesmaTcp::SetReading(const bool &state) {
    _is_reading = state;
    if (_is_reading) {
        std::thread th([&](){
		  _Thread_MainCycle();
        });
        th.detach();
    }
}

ushort AesmaTcp::GetChannel(AesmaTcp::SlotType slot_type, const ushort &slot, const ushort &channel) const {
	return __bswap_16(slot_type == Analog ? _analog[slot][channel] : _digital[slot]);
}
ushort AesmaTcp::GetChannel_Analog(const ushort &slot, const ushort &channel) const {
	return __bswap_16(_analog[slot][channel]);
}
ushort AesmaTcp::GetChannel_Digital(const ushort &slot, const ushort &channel) const {
	return  __bswap_16(_digital[slot]);
}

void AesmaTcp::SetChannel(AesmaTcp::SlotType slot_type, const ushort &slot, const ushort &channel, const ushort &value) {
	_BuildCommand(slot_type, slot, channel, value);
}
void AesmaTcp::SetChannel_Analog(const ushort &slot, const ushort &channel, const ushort &value) {
	_BuildCommand_Analog(slot, channel, value);
}
void AesmaTcp::SetChannel_Digital(const ushort &slot, const ushort &channel, const bool &value) {
	_BuildCommand_Digital(slot, channel, value);
}


/* ********** PRIVATE *********** */
bool AesmaTcp::_RequestValues(AesmaTcp::SlotType slot_type) {
    static int i = 0;
    bool is_analog = slot_type == Analog;
    const char* command = is_analog ? _command_read_analog : _command_read_digital;
    std::string type = is_analog ? "Analog" : "Digital";

    char* bytes = new char[256]{0};
    int len = 12;
    _Thread_WriteRead(command, len, bytes);

    if (len > 0) {
        if (is_analog) {
        	if (len == 137) {
				_ProcessValues_Analog(bytes, len);
			}
        } else {
        	if (len == 25) {
				_ProcessValues_Digital(bytes, len);
			}
        }
        i++;

        return true;
    } else {
        return false;
    }
}

void AesmaTcp::_ProcessValues_Analog(char *bytes, const int &size) {
//    std::string hexstring = AesmaFuncs::bytes_to_hex(bytes, size);
	_lock.lock();
	memcpy(_analog, (ushort*)(&bytes[9]), sizeof(ushort) * 8 * 8);
//	memcpy(_analog, (SlotAnalog*)(&bytes[9]), sizeof(SlotAnalog) * 8);
    _lock.unlock();
}
void AesmaTcp::_ProcessValues_Digital(char *bytes, const int &size) {
//    std::string hexstring = AesmaFuncs::bytes_to_hex(bytes, size);
	_lock.lock();
	memcpy(_digital, (ushort*)(&bytes[9]), sizeof(ushort) * 8);
//	memcpy(_analog, (SlotDigital*)(&bytes[9]), sizeof(SlotDigital) * 8);
	_lock.unlock();
}

void AesmaTcp::_BuildCommand(AesmaTcp::SlotType slot_type, const ushort &slot, const ushort &channel, const ushort &value) {
	if ((slot < 8) && (channel < 8)) {
		char reg = (slot * 16) + channel;
		char cmd = slot_type == Analog ? 0x6 : 0x5;
		char* val = new char[4] {0};

		if (slot_type == Analog) {
			memcpy((ushort*)val, &value, 1);
		} else {
			val[1] = value ? char(0xff) : 0x0;
		}

		char* command = new char[12]{
			0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
			0x1, cmd, 0x0, reg, val[1], val[0]
		};
		_command = command;
		_command_len = 12;
	}
}
void AesmaTcp::_BuildCommand_Analog(const ushort &slot, const ushort &channel, const ushort &value) {
	if ((slot < 8) && (channel < 8)) {
		char reg = (slot * 16) + channel;
		char* val = new char[4];
		memcpy((ushort*)val, &value, 1);
		char *cmd = new char[12]{
			0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
			0x1, 0x6,
			0x0,
			reg,
			val[1],
			val[0]
		};
		_command = cmd;
		_command_len = 12;
	}
}
void AesmaTcp::_BuildCommand_Digital(const ushort &slot, const ushort &channel, const bool &value) {
	if ((slot < 8) && (channel < 8)) {
		char reg = (slot * 16) + channel;
		char val = value ? char(0xff) : 0x0;
		char *cmd = new char[12]{
			0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
			0x1, 0x5,
			0x0,
			reg,
			val,
			0x0
		};
		_command = cmd;
		_command_len = 12;
	}
}

void AesmaTcp::_Thread_MainCycle() {
    using namespace std;
    bool read_analog = true;
    while(_is_reading) {
        if ((_command != nullptr) && (_command_len == 12)) {
			_Thread_Write(_command, _command_len);
			_command = nullptr;
			_command_len = 0;
			this_thread::sleep_for(chrono::milliseconds(250));
			continue;
        }
        // reading current values
        if (read_analog) {
			_RequestValues(Analog);
			read_analog = false;
			this_thread::sleep_for(chrono::milliseconds(250));
			continue;
		}
		_RequestValues(Digital);
		read_analog = true;
		this_thread::sleep_for(chrono::milliseconds(250));
    }
}
/* ****************************** */