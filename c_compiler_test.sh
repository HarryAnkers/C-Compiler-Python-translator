#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against itself."
    have_compiler=1
fi

working="test_tmp"
mkdir -p ${working}
working_exec="exec_tmp"
mkdir -p ${working_exec}

for DRIVER in test_deliverable/test_cases/*'_driver'.c ; do

    #base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");
    #NAME=$(echo $DRIVER | sed -E -e "s|test_deliverable/testcases")
    #${String%ABC}

    #NAME=$(basename $DRIVER _driver.c)
    driver=$(basename ${DRIVER%.c})
    NAME=$(basename ${DRIVER%_driver.c})
    TESTCODE=test_deliverable/test_cases/$NAME.c
    
    echo "-------------------------------"
    echo " "
    echo "Test case $NAME"
    echo " "

    # Compile ${NAME}.c using the compiler under test into assembly.
    echo "compiling $TESTCODE using ${compiler}..."
    ${compiler} -S $TESTCODE -o ${working}/$NAME-got.s
    if [[ ! -f ${working}/$NAME-got.s ]] ; then
        >&2 echo "ERROR : Your C Compiler failed to compile $TESTCODE into $NAME-got.s"
        TEST_OUTPUT=20
    else
        #Compile ${NAME}_driver.c using MIPS GCC. 
        echo "compiling $DRIVER using mips-linux-gnu-gcc..."                               
        mips-linux-gnu-gcc -c $DRIVER -o ${working}/$driver-got.o
        if [[ ! -f ${working}/$driver-got.o ]] ; then
            >&2 echo "ERROR : mips-linux-gnu-gcc failed to compile $DRIVER into $driver-got.o"
        else
            #Link the generated assembly and the driver object into a MIPS executable.
            echo "linking assembly and driver object..."
            mips-linux-gnu-gcc -static ${working}/$NAME-got.s ${working}/$driver-got.o -o ${working_exec}/$NAME-got
        fi

        if [[ ! -f ${working_exec}/$NAME-got ]] ; then
            >&2 echo "ERROR : mips-linux-gnu-gcc failed in linking $NAME-got.s and $driver-got.o into an executable"
            TEST_OUTPUT=20
        else
            # Run the executable under QEMU
            qemu-mips ${working_exec}/$NAME-got
            TEST_OUTPUT=$?
        fi
    fi

    if [[ $TEST_OUTPUT -eq 20 ]] ; then
        echo " "
        echo "$NAME, Fail, no $NAME-got executable in ${working_exec}"
    elif [[ $TEST_OUTPUT -ne 0 ]] ; then
        echo " "
        echo "$NAME, Fail, Expected "0", got ${TEST_OUTPUT}"
    elif [[ ${have_compiler} -ne 0 ]] ; then
        echo " "
        echo "$NAME, Fail, No C compiler"
    else
        echo " "
        echo "$NAME, Pass"
    fi
        echo " "
        echo "-------------------------------"
        echo " "
done