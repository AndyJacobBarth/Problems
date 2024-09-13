#!/bin/bash

read n x

while [ $n -gt 0 ]; do
    read ai
    let x-=ai
    if [ $x -lt 0 ]; then
        echo "Neibb"
        exit
    fi

    let n--
done

echo "Jebb"