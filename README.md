# Mini C Preprocessor

## 📌 Project Description

This project implements a simple C preprocessor using C programming.

The preprocessor reads a C source file and performs basic preprocessing operations before generating the preprocessed output file.

The project is implemented using modular programming, where different preprocessing functionalities are divided into separate C source files.

## 🚀 Features

- Command-line argument support
- Single-line comment removal (`//`)
- Multi-line comment removal (`/* ... */`)
- File inclusion using `#include`
- Simple macro substitution using `#define`
- Macro substitution with arguments
- Generates preprocessed output
- Modular programming using multiple `.c` and `.h` files
- Makefile support for compilation

## 📂 Project Structure

```text
mini-c-preprocessor/
│
├── main.c
├── comment_removal.c
├── file_inclusion.c
├── macro_handler.c
├── preprocessor.h
├── Makefile
│
├── demo.c
├── demo_file_include.c
└── header.h
