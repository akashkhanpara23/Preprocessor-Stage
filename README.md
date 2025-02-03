# Preprocessor Macro Expander

## About
This project is a C program that processes a source code file (`myprog.c`) and expands `#define` macros, replacing occurrences of defined macros with their corresponding values. The program reads the file, identifies `#define` directives, and substitutes macro occurrences while maintaining the structure of the original file.

## Features
- Reads a C source file (`myprog.c`).
- Identifies and stores `#define` macro definitions.
- Replaces all instances of macros with their defined values.
- Removes `#define` directives from the final output.
- Writes the processed code into a temporary file without macros.

## How It Works
1. The program reads `myprog.c` and counts characters, lines, and longest line length.
2. It extracts `#define` macro definitions and stores them in separate buffers.
3. It creates a temporary file (`temp.txt`), replacing occurrences of macros with their values.
4. It removes all `#define` directives from the processed file.
5. The final output is written into `temp2.txt` and then restored to `temp.txt` before cleanup.

## Requirements
- GCC Compiler
- C Standard Library (stdio.h, stdlib.h, string.h)

## Compilation
To compile the program, run:
```sh
gcc -o macro_expander macro_expander.c
```

## Usage
Run the program with:
```sh
./macro_expander
```
Ensure `myprog.c` exists in the same directory before execution.

## Limitations
- Assumes `#define` macros follow a simple format.
- Does not handle multi-line macro definitions.
- Limited to `#define` replacement without parameterized macros.

## License
This project is open-source and licensed under the MIT License. Contributions and improvements are welcome!

## Author
Akash Sureshbhai Khanpara
