#!/bin/bash

read m

if [ "$m" -eq 2 ]
then
    echo 28
elif [ "$m" -eq 4 ] || [ "$m" -eq 6 ] || [ "$m" -eq 9 ] || [ "$m" -eq 11 ]
then
    echo 30
else
    echo 31
fi