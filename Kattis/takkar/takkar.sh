#!/bin/bash

read a
read b

if [ $a -gt $b ]; then
    echo "MAGA!"
elif [ $b -gt $a ]; then
    echo "FAKE NEWS!"
else
    echo "WORLD WAR 3!"
fi