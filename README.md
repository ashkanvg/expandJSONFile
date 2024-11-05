
# JSON Expander to 1GB File

This project contains a C++ program that reads a small JSON file where each line represents a JSON record, duplicates each line randomly, and writes the duplicated records to a new file. The process continues until the output file reaches approximately 1 GB in size.

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Example](#example)
- [License](#license)

## Overview

The purpose of this project is to generate a larger JSON file from a small input JSON file by duplicating lines randomly. This can be helpful for testing applications or algorithms that process large JSON files.

## Requirements

- A C++ compiler (e.g., g++)
- C++11 or later for compatibility with `<random>` and `<fstream>`

## Usage

1. **Clone the Repository**
   ```bash
   git clone https://github.com/yourusername/JSON-Expander.git
   cd JSON-Expander
   ```

2. **Prepare the Input File**

   Create a file named `input.json` in the same directory as the code. Each line should contain a valid JSON object. For example:
   ```json
   {"name": "Alice", "age": 30}
   {"name": "Bob", "age": 25}
   ```

3. **Compile the Code**
   ```bash
   g++ -O3 -std=c++11 json_expander.cpp -o json_expander
   ```

4. **Run the Program**
   ```bash
   ./json_expander
   ```

5. **Output**

   After running the program, you will find a file named `expanded_output.json` in the same directory, expanded to approximately 1 GB.

## How It Works

1. The program reads each line from `input.json` into a vector, treating each line as an independent JSON record.
2. It duplicates each record a random number of times (between 1 and 10) and writes these duplicates to `expanded_output.json`.
3. The writing process continues until `expanded_output.json` reaches a size close to 1 GB.

The code uses `<random>` to apply a random duplication factor, and `<fstream>` to read and write files.

## Example

Given an input file `input.json`:
```json
{"name": "Alice", "age": 30}
{"name": "Bob", "age": 25}
```

The output file `expanded_output.json` will contain a large number of these JSON lines, randomly duplicated, until it reaches approximately 1 GB in size.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
