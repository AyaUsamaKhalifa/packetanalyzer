#include <iostream>
#include <fstream>
#include <DataFormatterVisitor.h>
#include <PacketParser.h>

using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    std::string line;

    PacketParser* parser = new PacketParser();
    
    inputFile.open("io/input_packets", ios::in);
    outputFile.open("io/output_packets", ios::out);

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
        cout << "File didn't open succesfully" << endl;
    }

    return 0;
}