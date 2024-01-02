#!/bin/bash 

FILE="$HOME/.bashrc"

if [ -f "$FILE" ]; then
echo "export HELLO=$HOSTNAME" >> "$FILE"
echo "LOCAL=$(whoami)" >> "$FILE"
    
else
echo "ERROR: .bashrc file does not exist."
fi

gnome-terminal
