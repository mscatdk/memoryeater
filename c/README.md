# memoryeater written in C

This is a memory eater written in C that will enable you to allocate memory certain increments.

## Options

| Option | Description | Default |
|---|---|---|
| -s | Allocation step size | 1 MB |
| -m | Max allocation | INT_MAX |
| -w | Wait for any key before starting | false |

## User Guide

````bash
# Compile the code
gcc memoryeater.c -o memoryeater

# Try to allocate 100 MB in 10 MB increments
./memoryeater -s 10 -m 100
````
