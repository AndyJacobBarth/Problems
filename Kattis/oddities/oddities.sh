#!/bin/bash

read n

while [ $n -gt 0 ]; do
    read x
    if (($x & 1 == 1)); then
        echo "$x is odd"
    else
        echo "$x is even"
    fi
    let n--
done