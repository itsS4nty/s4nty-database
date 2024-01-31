#include "Utils.h"
#include <map>
#include <algorithm>

using namespace std;

Commands resolveCommand(const string& command) {
    static const map<string, Commands> commandsString {
        { "use", USE },
        { "select", SELECT },
        { "create", CREATE },
        { "display", DISPLAY }
    };

    string cmd = command.substr(0, command.find(" "));
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    auto it = commandsString.find(cmd);
    return it != commandsString.end() ? it->second : UNKNOWN;
}

string extractCommandArgument(const string& command) {
    size_t spaceIndex = command.find(" ") + 1;
    return spaceIndex < command.size() ? command.substr(spaceIndex) : "";
}
