#!/bin/bash

read M
sum=0

read -a T

for (( i=0;i<M;i++)); do
    ((sum+=T[$i]))
done

echo $((sum/M))