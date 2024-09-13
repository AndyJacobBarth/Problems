#!/bin/bash

read N

echo $N | awk -F. '
{ 
    if (substr($2,1,1) >= 5) { 
        print $1 + 1
    } 
    else { 
        print $1 
    }
}'