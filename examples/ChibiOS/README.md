# ChibiOS Examples

These examples are written using the [ChibiOS RTOS](http://chibios.org/dokuwiki/doku.php). 

## Prerequisites

### Software

 * GCC build essentials
 * [The ARM gcc toolchain, 7.3.1 or above](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
 * [dfu-util](http://dfu-util.sourceforge.net/)
 * ChibiOS Supporting Files (see below)

### ChibiOS Library

The ChibiOS library is included as a git submodule and needs to be initialized before you can compile any of the examples. (These steps should only need to be run once)

```bash
git submodule init
git submodule update
```

## Compiling

1. Be sure you've installed the prerequisite software and initialized the ChibiOS library first. (see instructions above)
2. Now go into one of the example directories and run `make`.

## Flash the program

Put the board into bootloader (DFU) mode by pressing the user button while turning the board on. Now you can run the following command to flash the program to the board:

```bash
dfu-util -d 0483:df11 -a 0 -s 0x08000000:leave -D build/program.bin
```

Or you can simply run:

```bash
make flash-dfu
```