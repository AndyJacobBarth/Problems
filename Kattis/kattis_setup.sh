#!/bin/bash

# Check if a directory name was provided
if [ -z "$1" ]; then
    echo "Usage: $0 <directory_name>"
    exit 1
fi

# If directory exists, assumes user is trying to submit to Kattis
if [ -d "$1" ]; then
    python kattis-cli/submit.py "$1/$1.cpp"
    python kattis-cli/submit.py "$1/$1.py"
    python kattis-cli/submit.py "$1/$1.sh"
else
    # Create files
    mkdir "$1"
    cd "$1"
    touch "$1.md" "$1.sh" "$1.py" "$1.cpp"

    # Create template for files
    echo "# [$1](https://open.kattis.com/problems/$1)" > "$1.md"
    echo "" >> "$1.md"
    echo "## Pseudo code" >> "$1.md"
    echo "" >> "$1.md"
    echo '```' >> "$1.md"
    echo "" >> "$1.md"
    echo '```' >> "$1.md"
    echo "## Time Complexity" >> "$1.md"

    echo "#!/bin/bash" > "$1.sh"

    echo -e "#include <iostream>\n\nint main() {\n  return 0;\n}" >> "$1.cpp"

    ls -al
fi