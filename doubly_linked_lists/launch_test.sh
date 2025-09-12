#!/bin/bash
# Launch crackme5 safely with the correct key

username="$1"
if [ -z "$username" ]; then
    echo "Usage: $0 username"
    exit 1
fi

# Run crackme5 with the generated key
./crackme5 "$username" "$(./keygen5 "$username")"
