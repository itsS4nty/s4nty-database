#include "Utils.h"
#include <map>
#include <algorithm>

Commands resolveCommand(const std::string& command) {
    static const std::map<std::string, Commands> commandsString {
        { "use", USE },
        { "select", SELECT },
    };

    std::string cmd = command.substr(0, command.find(" "));
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    auto it = commandsString.find(cmd);
    return it != commandsString.end() ? it->second : UNKNOWN;
}

std::string extractCommandArgument(const std::string& command) {
    size_t spaceIndex = command.find(" ") + 1;
    return spaceIndex < command.size() ? command.substr(spaceIndex) : "";
}
