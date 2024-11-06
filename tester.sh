#!/bin/bash
list=$(find files -type f);
rm -rf tests.txt
# gcc get_next_line*b*.c main.c -D BUFFER_SIZE=$1
for item in ${list[@]}; do
    echo ============$item============= #>> tests.txt
    ./a.out $item > t
    diff t $item # >> tests.txt
done
rm -rf t