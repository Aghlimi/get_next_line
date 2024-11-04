#!/usr/bin/bash
list=$(find . -type f);
rm -rf tests.txt
for item in ${list[@]}; do
    echo ============$item============= >> tests.txt
    ./a.out $item > t
    diff t $item >> tests.txt
done
rm -rf t