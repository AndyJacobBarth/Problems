#!/bin/bash

read n
read name fun_metric

best_metric="$fun_metric"
best_name="$name"

while [ "$n" -gt 1 ]
do
    read name fun_metric

    if [ "$fun_metric" -gt "$best_metric" ]
    then
        best_metric="$fun_metric"
        best_name="$name"
    fi
    let n--
done

echo "$best_name"