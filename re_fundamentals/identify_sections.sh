#!/bin/bash

# Identify the Sections in the Binary.

# Use the readelf command to list all sections of the ELF file.
# This command will show you the different sections that make up the binary.
command_used="readelf -S $1"
echo "$command_used" > command.txt

# Search a unusual section (por ejemplo, .upx, .debug, .note, etc.)
unusual_section=$(readelf -S "$1" | grep -E "\.upx|\.debug|\.note")

# Obtain the Size of the Unusual Section.
section_size=$(readelf -S task1 | grep -E '\.upx|\.debug|\.note' | awk '{print $2}' | tail -n 1 | tr -d ']')

# Once the unusual section is identified, obtain its size from the output of the readelf command.
echo "$section_size" > size.txt
