# Project: Creating and Reading a File (assembly_code.asm)

## Overview

This project demonstrates the creation, reading, and writing of text files using assembly language. The program, named "CreateReadFile.asm," utilizes the Irvine32 library and macros for file I/O operations. It prompts the user to enter a string, writes it to an output file, and then reads and displays the contents of an input file.

## Instructions

To run the program, follow these steps:

1. Assemble the code using an assembler compatible with the Irvine32 library.
2. Link the assembled object code with the Irvine32 library to create an executable file.
3. Execute the executable file.

## User Input

The program prompts the user for two inputs:

1. **Enter a string:** The user enters a string of up to 500 characters. This string is written to the output file "output.txt".

2. **Enter an input filename:** The user enters the name of an existing text file. The contents of this file are read and displayed.

## Output

The program displays the following information to the console:

1. **Number of bytes written:** After writing the user's input string to the output file, the program displays the number of bytes written.

2. **File size:** After reading the contents of the input file, the program displays the size of the file.

3. **Buffer contents:** The program displays the contents of the buffer, which contains the read file contents.

**Error Handling**

The program handles file I/O errors by displaying appropriate error messages and exiting the program.

**Dependencies**

The program requires the Irvine32 library and macros for file I/O operations.

## Video Demo

A video demonstration of the program is available at the following link:
https://file.garden/ZMu15i0EPHK4dj3e/Videos/COAL_Project-Video_Demo