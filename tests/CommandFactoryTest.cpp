#include "gtest/gtest.h"
#include "CommandFactory.h"
#include "Commands.h"
#include <fstream>

TEST(CommandFactoryTest, ParseFileValid) {
    const std::string filename = "test_commands.txt";
    std::ofstream file(filename);
    file << "DIMENSION 3\nMOVE_TO 1,1\nLINE_TO 2,2\n";
    file.close();

    CommandFactory factory;
    auto commands = factory.parseFile(filename);

    EXPECT_EQ(commands.size(), 3);
}

TEST(CommandFactoryTest, ParseFileInvalidCommand) {
    const std::string filename = "test_invalid.txt";
    std::ofstream file(filename);
    file << "UNKNOWN_CMD 1\n";
    file.close();

    CommandFactory factory;
    EXPECT_THROW(factory.parseFile(filename), std::runtime_error);
}