#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Illegal number of arguments!"
    exit 1
fi

if ! { test -f $1; }; then
    echo "File does not exist!"
    exit 1
fi

echo "RUN: $1"

./pforth_standalone -m $1 1> /dev/null &
sleep 1
./monitor.out

exit 0
