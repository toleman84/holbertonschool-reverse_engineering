#!/bin/bash

libraries_output=$(ldd "$1" | grep 'not found' | awk '{print $1}')

echo "$libraries_output" > external_library.txt
