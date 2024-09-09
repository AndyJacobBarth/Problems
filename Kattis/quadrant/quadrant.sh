#!/bin/bash

read x
read y

if [ $x -gt 0 ]
then
    if [ $y -gt 0 ]
    then
        echo 1
    else
        echo 4
    fi
else
    if [ $y -gt 0 ]
    then
        echo 2
    else
        echo 3
    fi
fi