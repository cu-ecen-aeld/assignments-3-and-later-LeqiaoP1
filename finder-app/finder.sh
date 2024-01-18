#!/bin/sh

filedir=$1
searchstr=$2

if [ $# -lt 2 ]; then
    echo "less than 2 parameters"
    return 1
fi

if [ ! -d "$filedir" ]; then
    echo "directory $filedir does not exist"
    return 1
else
    X=$(ls "$filedir" | wc -l)
    Y=$(grep -c "$searchstr" -r "$filedir" | wc -l)

    echo "The number of files are ${X} and the number of matching lines are ${Y}"
fi




