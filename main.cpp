#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

// Function to get file size in bytes
streampos getFileSize(const std::string &filename) {
    ifstream file(filename, std::ios::binary | std::ios::ate);
    return file.tellg();
}

int main() {
    // Define input and output file paths
    string inputFile = "input.json";
    string outputFile = "expanded_output.json";

    // Open input file
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Could not open input file.\n";
        return 1;
    }

    // Read all lines (JSON records) from the input file into a vector
    vector<std::string> jsonRecords;
    string line;
    while (getline(inFile, line)) {
        jsonRecords.push_back(line);
    }
    inFile.close();

    // Open output file
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error: Could not open output file.\n";
        return 1;
    }

    // Random number generator for duplicating lines
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);  // Random duplication factor between 1 and 10

    // Write duplicated records until output file reaches approximately 1 GB
    const std::streampos targetSize = 1LL * 1024 * 1024 * 1024;  // 1 GB
    while (getFileSize(outputFile) < targetSize) {
        for (const auto &record : jsonRecords) {
            int repeatCount = dis(gen);  // Get random duplication factor
            for (int i = 0; i < repeatCount; ++i) {
                outFile << record << "\n";
                if (getFileSize(outputFile) >= targetSize) {
                    break;
                }
            }
            if (getFileSize(outputFile) >= targetSize) {
                break;
            }
        }
    }

    // Close the output file
    outFile.close();
    cout << "File expanded to approximately 1 GB.\n";

    return 0;
}
