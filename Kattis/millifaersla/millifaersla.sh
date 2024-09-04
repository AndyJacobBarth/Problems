#!/bin/bash

read a
read b
read c

if [ "$a" -lt "$b" ]
then
    if [ "$a" -lt "$c" ]
    then
        echo "Monnei"
    else
        echo "Dolladollabilljoll"
    fi
elif [ "$b" -lt "$c" ]
then
    echo "Fjee"
else
    echo "Dolladollabilljoll"
fi