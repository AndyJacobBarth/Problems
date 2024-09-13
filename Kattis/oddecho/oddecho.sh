#!/bin/bash

read n

while [ "$n" -gt 1 ]; do
    read oddInput
    echo "$oddInput"

    read evenInput

    let n-=2
done

if [ "$n" == 1 ]; then
    read oddInput
    echo "$oddInput"
fi