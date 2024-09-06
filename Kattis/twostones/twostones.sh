#!/bin/bash

read N

if (( $N & 1 == 1 ))
then
    echo "Alice"
else
    echo "Bob"
fi