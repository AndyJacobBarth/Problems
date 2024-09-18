#!/bin/bash

read a

echo $a | awk '{ print 100 / $1; print 100 / (100 - $1) }'