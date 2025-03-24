# Inverted Search

A command-line Search Indexing and Querying System in C for efficient word indexing and searching across multiple files.

## Features

- **Indexing (Database Creation):** Parses input files, extracts words, and stores them in a sorted linked list or hash table.
- **Persistent Database:** Stores indexed words and their corresponding file locations for efficient retrieval.
- **Dynamic Index Updates:** Automatically updates the index when files are added or removed.
- **Querying:** Searches for words efficiently by reconstructing the index into a hash table for fast lookups.
- **Optimized Memory Management:** Ensures efficient memory utilization and robust error handling for large datasets.

## Usage

1. Compile the program using a C compiler (e.g., `gcc`).
2. Run the program and provide the input files for indexing.
3. Use the query functionality to search for words efficiently.

## Requirements
- C Compiler (e.g., GCC)
- Basic understanding of Hash Tables and Linked Lists

## Future Enhancements
- Support for wildcard searches
- Graphical User Interface (GUI) for better user experience


