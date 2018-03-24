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

input_dir="test_deliverable/test_cases/inputs"
driver_dir="test_deliverable/test_cases/drivers"


working="test_tmp"
mkdir -p ${working}
working_exec="exec_tmp"
mkdir -p ${working_exec}

for i in ${input_dir}/*.c ; do
    for j in ${driver_dir}/*.c ; do
        
        base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");
        driver=$(echo $i | sed -E -e "s|${driver_dir}/([^.]+)[.]c|\1|g");
        
            if [[ ${have_compiler} -eq 0 ]] ; then
                
                # Compile ${NAME}.c using the compiler under test into assembly.
                echo "compiling $i using ${compiler}..."
                $compiler --compile $i -o ${working}/$base-got.s

                #Compile ${NAME}_driver.c using MIPS GCC. 
                echo "compiling $j using mips-linux-gnu-gcc..."                               
                mips-linux-gnu-gcc -c $j -o ${working}/$driver-got.o

                #Link the generated assembly and the driver object into a MIPS executable.
                echo "linking assembly and driver object..."
                mips-linux-gnu-gcc -static ${working}/$base-got.s ${working}/$driver-got.s -o ${working_exec}/$base-got

                # Run the executable under QEMU
                qemu-mips ${working_exec}/$base-got
                TEST_OUTPUT=$?
            fi
   
        if [[ $TEST_OUTPUT -ne 0 ]] ; then
            echo "$base, Fail, Expected "0", got ${TEST_OUTPUT}"
        elif [[ ${have_compiler} -ne 0 ]] ; then
            echo "$base, Fail, No C compiler"
        else
            echo "$base, Pass"
        fi
    done
done