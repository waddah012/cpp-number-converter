# Number converter

I wrote this program to convert numbers between binary, hexadecimal, and decimal without using built in conversion functions.

It has a menu where you choose the conversion and enter a number. The binary option takes exactly 16 bits. The hexadecimal option accepts up to 8 digits, and decimal input can go up to 4294967295. Choose 4 to exit.

For a quick example, enter 0000000000001010 in the binary option. It should give you 0x000A and the decimal value 10.

To build and run it, you need a C++17 compiler and Make. Open a terminal in this folder and run:

```sh
make
make run
```

You can also run `make check` to check the sample output. That needs Python 3. Use `make clean` if you want to remove the compiled program.
