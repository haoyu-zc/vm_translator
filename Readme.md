# VM-Translator for Coursera Course Nand2tetris

Translates Hack-platform virtual machine code into corresponding machine code.

## Directory structure

```shell
├─src		# Sources code.
└─tests		# Test files and translated .asm files which passed their tests.
./Makefile
```

## How to use

In this project's root directory, run:

```shell
make
```

Then run:

```shell
./VMTranslator <target-vm_file_path>
```

or if it's a directory:

```shell
./VMTranslator <target-directory_path>
```

You can find generated .asm file in the given path.

## Tip

You can use the .asm files here and a file comparison tool like Beyond Compare to spot bugs, if yours failed tests in the CPU Emulator.

