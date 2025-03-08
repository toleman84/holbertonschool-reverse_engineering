#!/bin/bash

libraries_output=$(ldd "$1")

echo "$libraries_output" > external_library.txt
