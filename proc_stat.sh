#!/bin/bash

PID=$1

CAT_OUTPUT=`cat /proc/$PID/stat`
SPLIT=$CAT_OUTPUT

argc=$#


if [ "$argc" -ge 2 ]; then
    INPUT=$2
fi

arr=$(echo $SPLIT | tr " " "\n")

i=1
for stat in $arr
    do
        if [ "$#" -lt 2 ]; then
            echo "[$i]  $stat"

        else
            if [ $INPUT -eq $i ]; then
                echo "[$i]  $stat"
            fi
        fi
            i=`expr $i + 1`
    done