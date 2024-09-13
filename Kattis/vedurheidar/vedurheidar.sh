#!/bin/bash

read v
read n

while [ $n -gt 0 ]; do
    read s k

    if [ $v -gt $k ]; then
        echo "$s lokud"
    else
        echo "$s opin"
    fi
    let n--
done