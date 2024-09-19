#!/bin/bash

read N
sum=0

read -r nums

for num in $nums; do
    let sum+=num
done

echo $sum