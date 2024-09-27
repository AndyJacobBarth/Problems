#!/bin/bash

read A B C

if [[ $((A+B)) -eq $C ]]; then
    echo "correct!"
else
    echo "wrong!"
fi