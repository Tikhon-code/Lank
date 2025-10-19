g_compiler="$(which g++ 2>/dev/null)"

if [[ $? == 0 ]]; then
    printf "Compiling..."
    mkdir ../bin
    $g_compiler ../src/main.cpp -o ../bin/lank
    compile_staus=$?
    
    if [[ $compile_staus == 0 ]]; then
        printf "\r[OK] Compiling...\n"
        sudo mv ../bin/lank /usr/bin/lank
    else
        printf "[BAD] Compiling...\n"
    fi
else
    printf "Compiler 'g++' not found.\n"
fi
