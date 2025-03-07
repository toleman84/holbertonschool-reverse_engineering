#!/bin/bash

# comprobar si el archivo existe
if [ ! -f "$1" ]; then
    echo "Error: file don't exist."
    exit 1
fi

#verificar si el archivo es un archivo ELF
file_type=$(file "$1" | grep -o "ELF")
if [ "$file_type" != "ELF" ]; then
    echo "Error: isn't a ELF file."
    exit 1
fi

# Extraer la información del encabezado ELF usando readelf
magic_number=$(xxd -l 4 -p "$1")
class=$(readelf -h "$1" | grep "Class" | awk '{print $2}')
byte_order=$(readelf -h "$1" | grep "Data" | awk '{print $2}')
entry_point_address=$(readelf -h "$1" | grep "Entry point address" | awk '{print $4}')

function display_elf_header_info() {
    echo "ELF Header Information for '$1':"
    echo "----------------------------------------"
    echo "Magic Number: $magic_number"
    echo "Class: $class"
    echo "Byte Order: $byte_order"
    echo "Entry Point Address: $entry_point_address"
}

# llamar a la función propuesta por el ejercicio para mostrar la información
display_elf_header_info "$1"
