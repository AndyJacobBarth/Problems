#!/bin/bash

read name
read x

while [ "$x" -gt 0 ]
do
    echo "Hipp hipp hurra, $name!"
    let x--
done