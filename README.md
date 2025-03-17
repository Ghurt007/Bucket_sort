# Bucket_sort
This project implements a bucket sort algorithm in C to sort a collection of strings entered via standard input (stdin). The program divides the input words into buckets based on command-line arguments (CLAs) and sorts each bucket using insertion sort. The sorted words from each bucket are then displayed in alphabetical order.

Files

bucketsort.c - The main implementation of the bucket sort algorithm.

bucketsort.h - Header file containing macro definitions and function declarations.

Makefile - For compiling the project.

Compilation

To compile the program, use the provided Makefile:

make

This will generate an executable named bucketsort.

To clean up the compiled object files and executable, use:

Usage

Run the program with at least one command-line argument specifying the bucket boundaries:

./bucketsort <bucket1> <bucket2> ... <bucketN>

Example

./bucketsort apple orange zebra

Input words via stdin (keyboard input) separated by spaces:

Enter input: cat banana apple zebra orange

The output will display the words sorted within their respective buckets:

bucket 0: apple
bucket 1: banana cat
bucket 2: orange
bucket 3: zebra

Program Logic

Input Validation:

Ensures at least one command-line argument is provided.

Validates that command-line arguments are in alphabetical order.

Bucket Initialization:

Creates an array of buckets where each bucket corresponds to a provided command-line argument.

Input Processing:

Reads a line of input from stdin.

Tokenizes the input by spaces and distributes words into appropriate buckets.

Bucket Sorting:

Uses insertion sort within each bucket to maintain alphabetical order.

Output:

Prints each bucket and the words it contains in sorted order.

Notes

Buckets are determined based on the alphabetical range defined by the provided command-line arguments.

Case-insensitive comparison is used (strcasecmp function).

Memory is dynamically allocated and freed at the end to prevent leaks.

Error Handling

If no command-line arguments are provided, the program exits with an error:

bucketsort: Fatal error! there must be at-least one CLA.

If the command-line arguments are not in alphabetical order:

bucketsort: Fatal error! CLAs must be entered in alphabetical order

If stdin is empty:
stdin is empty!
