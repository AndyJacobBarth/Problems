#!/bin/bash

read startWord
read endWord
total=1
wordLength=${#startWord}

for ((i=0;i<wordLength;i++)); do
    if [[ ${startWord:$i:1} != ${endWord:$i:1} ]]; then
        ((total++))
    fi
done

echo $total