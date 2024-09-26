#!/bin/bash

read n

if [[ $n =~ ^555 ]]; then
    echo 1
else
    echo 0
fi