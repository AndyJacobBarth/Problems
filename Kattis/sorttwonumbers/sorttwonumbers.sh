#!/bin/bash

read a b

if [[ $a -lt $b ]]; then
    echo "$a $b"
else
    echo "$b $a"
fi