#!/bin/bash
# Safe launch for crackme5

username="$1"
if [ -z "$username" ]; then
    echo "Usage: $0 username"
    exit 1
fi

# Run crackme5 using keygen output safely
./crackme5 "$username" "$(./keygen5 "$username")
"
