# Invert rgb

Invert rgb is a application to invert rgb color build in C, it use is only with the terminal.

## Installation

Only you need to set into the proyect folder and compile the main file, example.

```bash
gcc main.c -o invertrgb
```

## Usage

The application can read parameters inline, you need to use the -i flag (inline) to read the rgb color, only can read one set of rgb colors.
Next commit you can to put multiple colors and files.
Use the binary previous compiled.

```bash
./invertrgb -i 255 255 255
# Output
# R: 0
# G: 0
# B: 0
```
