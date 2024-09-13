#!/bin/bash

read n

echo $n | awk '{ printf "%.6f", $1 * 0.09144 }'