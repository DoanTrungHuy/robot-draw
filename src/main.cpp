#include "CommandFactory.h"
#include "Grid.h"
#include "Robot.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: robot <command_file>\n";
        return 1;
    }
    try {
        auto commands = CommandFactory::parseFile(argv[1]);
        Grid grid;
        Robot robot;
        for (auto &cmd : commands) {
            cmd->execute(grid, robot);
        }
        grid.print();
    }
    catch (const exception &ex) {
        cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}