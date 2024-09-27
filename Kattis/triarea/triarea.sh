#!/bin/bash

read b h

echo "$b $h" | awk '{
    print 0.5*$1*$2
}'