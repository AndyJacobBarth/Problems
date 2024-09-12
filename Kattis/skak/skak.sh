#!/bin/bash

read xh yh
read xp yp

if [[ xh -eq xp || yh -eq yp ]]; then
    echo 1
else
    echo 2
fi