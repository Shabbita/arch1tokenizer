Project 1: Tokenizer
====================
# Instructions:

You should document your tokenizer in this file.

This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).

# Notes on the tokenizer (Salvador)

## How the program works
* The menu has 4 options:
  1. To see the current history and select one
sentence of it.
  2. To add a new sentence to the history.
  3. To tokenize the selected sentence on 1.
  4. To exit the program.

### Starting adding sentences.
To add the first sentence, select the option 3 and add a new sentence. Once
you write down your sentence and click Enter, you will return to the main
menu. If you want to add a new sentence, select 3 again.

To see your added sentences, select 1 from the main menu. After printing the
current history, you will be prompted to select one of the sentences on the
history.

To exit the program, just select 4 from the main menu.

### Handling errors
If you select 1 or 3 before adding a new sentence, you will receive a
notification that the list is empty or that you should select a sentence
first.

When looking at the history and selecting a sentence to tokenize, if you write
a greater number than what is already on the list, you will also receive a
notification that this option is not available.

## Commands
* scanf("%[^\n]s", str) is used to read a string including the spaces until
the next line is received or to read string until line break, that is, \n is
encountered and store it on an arrays named "str". "^\n" stands for taking
input until a new line isn't encountered.

## Makefile
The Makefile contains the next functions to run the program:
1. **make all:** runs all the commands on the Makefile.
2. **make tokenizer.o and make history.o:** Out files of the .h files.
3. **make tokenizer:** compiles the files and create the out files.
4. **make clean:** removes the out files and (~) files.
5. **make run:** runs the out file.






