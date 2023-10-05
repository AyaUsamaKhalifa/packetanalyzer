#include <iostream>
#include <fstream>
#include "libs/PacketParser.h"

int main()
{
    std::ifstream inputFile;
    std::ofstream outputFile("io/output_packets");
    std::string line;

    PacketParser *parser;

    inputFile.open("io/input_packets", std::ios::in);

    // Condition to check if the file was opened successfully
    if (inputFile.is_open())
    {

        // Read each line in the file and parse it.
        while (getline(inputFile, line))
        {
            outputFile << parser->ParsePacket(line); // Parse the input line and append the formatted data to the output file
        }

        // Close the file when done
        inputFile.close();
        outputFile.close();
    }
    else
    {
        std::cout << "File didn't open successfully" << std::endl;
    }

    return 0;
}