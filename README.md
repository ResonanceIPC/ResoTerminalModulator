# Project Title

This is a program for converting text to sinusoid

## Table of Contents

- [Installation](git clone)
- [Usage](resopcinfo -h)
- [Contributing](https://github.com/ResonanceIPC)
- [License](GNU GENERAL PUBLIC LICENSE)

## Installation

First of all you must download source code from github.

--$ git clone https://github.com/ResonanceIPC/ResoTerminalModulator

Then you must make project

--$ make 

Then just run file

--$ ./resomodulator

## Usage

First of all write string you want to convert to sinusoid.

Also the result is saved in file sinusoid.txt


Configure:

If you wnat to edit parameters open resomodulator.c and edit few variables.

int width = 950; // Set width of your terminal
int height = 80; // Set height of every line
int amplitude_0 = 2; // Amplitude of signal 0
int amplitude_1 = 8; // Amplitude of signal 1
char matrix[80][100000]; // Also put height here and put width very big
char filename[] = "sinusoid.txt"; // Filename where will be saved sinusoid
                                                                                                                                                                                                                                           
Powered by RESONANCE  

## Contributing

Just if you want you can follow me on github if you want more - https://github.com/ResonanceIPC

## License

This project is licensed under the terms of the [GNU General Public License (GPL)](https://www.gnu.org/licenses/gpl-3.0.html).
