#!/bin/bash

read n

while [ $n -gt 0 ]
do
    read name
    echo "Takk $name"
    let n--
done