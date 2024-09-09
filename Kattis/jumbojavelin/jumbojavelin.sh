#!/bin/bash

read N
sum=1-$N

while [ $N -gt 0 ]
do
    read l
    let sum+=l
    let N--
done
echo $sum