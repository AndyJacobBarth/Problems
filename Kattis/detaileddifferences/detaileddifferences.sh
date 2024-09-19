#!/bin/bash

read n

while [ $n -gt 0 ]; do
    read s1
    read s2
    s1_length=${#s1}

    echo "$s1"
    echo "$s2"

    for ((i=0; i<s1_length;i++)); do
        if [ "${s1:i:1}" == "${s2:i:1}" ]; then
            echo -n "."
        else
            echo -n "*"
        fi
    done
    echo
    let n--
done