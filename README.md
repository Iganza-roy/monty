![MONTY](https://user-images.githubusercontent.com/86312558/149395152-c1163d94-e5b8-4cb4-a95f-00e4534fb058.png)
# Monty


The goal of this project is to create an interpreter for Monty ByteCodes files.
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

***Monty byte code files***

Files containing Monty byte codes usually have the ***.m*** extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.


## The monty program 

- Usage: ```monty file```
    - where *file* is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message 
    - ```USAGE: monty file```, followed by a new line, and exit with the status ```EXIT_FAILURE```
- If, for any reason, it’s not possible to open the file, print the error message ```Error: Can't open file <file>```, followed by a new line, and exit with the status ```EXIT_FAILURE```
    - where *<file>* is the name of the file
- If the file contains an invalid instruction, print the error message ```L<line_number>: unknown instruction <opcode>```, followed by a new line, and exit with the status ```EXIT_FAILURE```
    - where ```L``` is the line number where the      instruction appears.
    - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
    - it executed properly every line of the file
    - it finds an error in the file
    - an error occured
- If you can’t malloc anymore, print the error message ```Error: malloc failed```, followed by a new line, and exit with status ```EXIT_FAILURE```.

## Compilation & Output
The code should be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

- Any output is printed on stdout
- Any error message is printed on the stderr

### Example usage:
For push & Pall:

```
root@8d26002bc878:/monty# cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
root@8d26002bc878:/monty# ./monty bytecodes/00.m
3
2
1
root@8d26002bc878:/monty# 
```

## Contribution

 - [Iganza-roy](https://github.com/Iganza-roy)
 - [Lumasia07](https://github.com/lumasia07)


## Acknowledgements

 - [ALX](https://www.bing.com/ck/a?!&&p=34548abe14e954a1JmltdHM9MTcwMzI4OTYwMCZpZ3VpZD0wMzYwYmU4OC1lM2YzLTZmNGQtMjAwZi1hZDEzZTI2NTZlNWUmaW5zaWQ9NTE5NQ&ptn=3&ver=2&hsh=3&fclid=0360be88-e3f3-6f4d-200f-ad13e2656e5e&psq=alx&u=a1aHR0cHM6Ly93d3cuYWx4YWZyaWNhLmNvbS8&ntb=1)



![Logo](https://hashnode.com/utility/r?url=https:%2F%2Fcdn.hashnode.com%2Fres%2Fhashnode%2Fimage%2Fupload%2Fv1662833626860%2FChnPmLVjW.webp%3Fw%3D1200%26auto%3Dcompress%2Cformat%26format%3Dwebp%26fm%3Dpng)

