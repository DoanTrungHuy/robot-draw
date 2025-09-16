#include "CommandFactory.h"
#include <sstream>
#include <fstream>
#include <stdexcept>
using namespace std;

vector<unique_ptr<ICommand>> CommandFactory::parseFile(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("Cannot open file: " + filename);

    vector<unique_ptr<ICommand>> commands;
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string cmd;
        iss >> cmd;

        if (cmd == "DIMENSION") {
            int n; iss >> n;
            commands.push_back(make_unique<DimensionCommand>(n));
        }
        else if (cmd == "MOVE_TO" || cmd == "LINE_TO") {
            string coord; iss >> coord;
            auto pos = coord.find(',');
            int x = stoi(coord.substr(0, pos));
            int y = stoi(coord.substr(pos + 1));

            if (cmd == "MOVE_TO")
                commands.push_back(make_unique<MoveCommand>(x, y));
            else
                commands.push_back(make_unique<LineCommand>(x, y));
        }
        else {
            throw runtime_error("Unknown command: " + cmd);
        }
    }
    return commands;
}