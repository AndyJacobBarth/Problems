#!/bin/bash

read n

while [[ $n -gt 0 ]]; do
    read r e c

    ((e-=c))

    if [[ $e -gt $r ]]; then
        echo "advertise"
    elif [[ $e -lt $r ]]; then
        echo "do not advertise"
    else
        echo "does not matter"
    fi
    ((n--))
done