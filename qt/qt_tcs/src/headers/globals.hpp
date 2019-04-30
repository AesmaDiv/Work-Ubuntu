#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <vector>
#include <string>

#include "./dispatcher.hpp"
#include "./database.hpp"

namespace Globals {
    namespace Consts {
        static const std::vector<std::string> TESTLIST_COLUMNS = {
            "ID","EndDT","OrderNum","Serial"
        };
        static const std::vector<std::string> RECORD_COLUMNS = {
            "ID","BeginDT","EndDT","Customer","OrderNum","StationType","StationClass","Serial","CurrentRat","CurrentMinLim","CurrentMaxLim",
            "Timer","Operator","DataStages","ResultID","Verdict","Information","Note","Stand","d1","d2","d3","d4","d5"
        };
        static const std::vector<std::string> TYPE_COLUMNS = {
            "ID","Producer","StationType","Inom","Imax","Pnom","Usec","MaxRPM","MinRPM","EngineControl","IsSpeedChanging","Instruction"
        };
    }
    namespace Vars {
        Dispatcher *dispatcher = nullptr;
    }
}

#endif // GLOBALS_HPP
