#!/bin/bash

read X
read N

answer=$(( X * (N + 1) ))

while [ $N -gt 0 ]; do
    read P
    ((answer-=P))
    
    ((N--))
done

echo $answer