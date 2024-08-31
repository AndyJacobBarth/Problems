#!/bin/bash

read s
read digit

for i in $(seq 1 $digit)
do
    echo -n "$s"
done
echo