#!/bin/bash

read compString

echo "$compString" | awk '
BEGIN { 
    count1 = 0
    count2 = 0
}
{
    compString_length = length($0)
    for (i = 1; i <= compString_length; i++) {
        char = substr($0, i, 1)
        if (char ~ /[aeiou]/) {
            count1++
            count2++
        }
        if (char ~ /y/) {
            count2++
        }
    }
}
END { print count1 " " count2 }'