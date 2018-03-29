#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

input_dir="c_translator/formative"

working="tmp/formative"
mkdir -p ${working}

for i in ${input_dir}/*.c ; do
base=$(echo $i | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");

    # Compile the reference C version
    gcc $i -o $working/$base
    
    # Run the reference C version
    $working/$base
    REF_C_OUT=$?

    if [[ ${have_compiler} -eq 0 ]] ; then

        # Run the DUT MIPS version
        $compiler --compile $i -o ${working}/$base.s
        mips-linux-gnu-gcc -static ${working}/$base.s -o ${working}/$base-s-got

        #run the mips Binary
        qemu-mips ${working}/$base-s-got
        GOT_P_OUT=$?


    fi

    if [[ ${have_compiler} -ne 0 ]] ; then
        echo "$base, Fail, No C compiler/translator"
    elif [[ $REF_C_OUT -ne $GOT_P_OUT ]] ; then
        echo "$base, Fail, Expected ${REF_C_OUT}, got ${GOT_P_OUT}"
    else
        echo "$base, Pass"
    fi
done
