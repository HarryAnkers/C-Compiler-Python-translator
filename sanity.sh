#!/bin/bash

GROUP=$1
if [[ "${GROUP}" == "" ]] ; then
    echo "No group specified."
    exit 1
fi
HASH=$2
if [[ "${HASH}" == "" ]] ; then
    echo "No hash specified."
    exit 1
fi

# Print out commands executed
set -o xtrace

################################################
## Setup

# Create a completely clean working dir, and
# move into it
WORKING=$(mktemp -d)
cd $WORKING

# Clone a fresh copy of the repository
git clone https://github.com/LangProc/langproc-2017-cw-${GROUP}.git || exit 1

# Move into the repository directory
cd langproc-2017-cw-${GROUP}

# Check out the specific version of the hash
git checkout $HASH || exit 1
# Print out the last commit message
git log -1


# Build the compiler and check it exists
make bin/c_compiler  || exit 1
ls bin/c_compiler    || exit 1

# Create a temporary directory
mkdir sanity-check

######################################################
## Python translation

# Create a minimal c file 
echo "int main(){ return 42; }" > sanity-check/input.c

# Compile it, using the exact command sequence from the spec
bin/c_compiler --translate sanity-check/input.c -o sanity-check/output.py

# Run it, and check the output
python3 sanity-check/output.py
if [[ $? -ne 42 ]] ; then exit 1 ; fi

#######################################################
## C compilation

# Compile it, using the exact command sequence from the spec
bin/c_compiler -S sanity-check/input.c -o sanity-check/output.s

# Assemble and link it using gcc
mips-linux-gnu-gcc -static sanity-check/output.s -o sanity-check/test.elf

# Run it
qemu-mips sanity-check/test.elf
if [[ $? -ne 42 ]] ; then exit 1 ; fi

########################################################
## C test-cases

# Check the test-case for main exists
if [[ ! -f test_deliverable/test_cases/MAIN.c ]] ; then exit 1; fi
if [[ ! -f test_deliverable/test_cases/MAIN_driver.c ]] ; then exit 1; fi

# Compile it using GCC
mips-linux-gnu-gcc -c test_deliverable/test_cases/MAIN.c -o sanity-check/MAIN.o || exit 1
mips-linux-gnu-gcc -c test_deliverable/test_cases/MAIN_driver.c -o sanity-check/MAIN_driver.o || exit 1
mips-linux-gnu-gcc -static sanity-check/MAIN.o sanity-check/MAIN_driver.o -o sanity-check/MAIN.elf || exit 1

# Check that it returns 0 (it should pass with gcc)
qemu-mips sanity-check/MAIN.elf || exit 1

########################################################
## Management documentation

# Has at least one new version of effort-log.csv been commited?
if [[ "$(git log -n 1 --pretty=format:%H -- management/effort-log.csv)" == "eb4cb063af1b78822317712b790a5a4973f04527" ]] ; then exit 1; fi

# Has at least one new version of milestones.csv been commited?
if [[ "$(git log -n 1 --pretty=format:%H -- management/milestones.csv)" == "eb4cb063af1b78822317712b790a5a4973f04527" ]] ; then exit 1; fi

# Has at least one new version of schedule.csv been commited?
if [[ "$(git log -n 1 --pretty=format:%H -- management/schedule.csv)" == "eb4cb063af1b78822317712b790a5a4973f04527" ]] ; then exit 1; fi

# Note that it is up to you to check the content

#######################################################
## Plagiarism, credit, and due-diligence

set +o xtrace

echo ""
echo "Does this repository make use of any source code from"
echo "any other sources except a) the lab spec (this year or last year)"
echo "or b) the cw spec (this year or last year) ?"
echo "This might include:"
echo "- Any test-cases that were not written by the group"
echo "- Code copied and pasted from stack overflow"
echo "- Code found in random web-sites"
echo "- Compilers published by last years students"
echo "- Reference specifications on the internet"
echo ""
echo "(Pick the number of your answer)"

select a in "Yes" "No" ; do
case "$a" in
"No") break;;
"Yes")
echo ""
echo "Is the code appropriately highlighted as copied,"
echo "and credited/acknowledged, either at the point of use"
echo "(for small snippets) or at the project top-level (for"
echo "large components)? Note that for this project it is"
echo "reasonable to add those attributions retro-actively,"
echo "i.e. after they were commited to the code-base."
select a in "Yes" "No" ; do
case $a in 
No )   echo "Then do so." ; exit 1 ;;
Yes )
echo ""
echo "Have you have considered licensing implications for"
echo "your code re-use? So if you re-use code with restrictions,"
echo "e.g. the GPL or CC BY-SA 3.0 (stackoverflow), are you"
echo "compliant?"
select a in "Yes" "No" "NotSure" ; do
case $a in
No )        echo "Then do so." ; exit 1 ;;
NotSure )
echo ""
echo "If you choose to use other's code, it is your job to ensure"
echo "license compliance. For a project like this the bar is low, so"
echo "most likely you only need attribution (e.g. for anything"
echo "copied straight from stackoverflow). In many cases, sites like"
echo "stackoverflow will just provide a template for the solution"
echo "that you then modify, which doesn't require attribution (though"
echo "it is nice to do so). But any time you copy and paste any"
echo "source code at all, you need to decide how it interacts with"
echo "plagiarism - the problem is not the code re-use (that is fine),"
echo "it is trying to pass off other's work as your own."
echo ""
echo "Part of the reason plagiarism is such a big thing in"
echo "engineering education is that copying code without"
echo "correct attribution/licensing in industry will lead"
echo "to lawsuits and getting fired once you enter industry."
echo ""
echo "If you used so much code that"
echo "your project becomes GPL, you'll need to explain why from an"
echo "assesment point of view, let alone the licensing."

exit 1;;
Yes ) break ;;
esac
done
break;;
esac
done
break;;
esac
done

echo ""
echo "Did you find looking at any existing compilers useful,"
echo "in particular repositories made public by previous EIE2"
echo "students?"
select a in "Yes" "No" ; do
case $a in
No )
echo ""
echo "You are one of the few then, as their traffic logs show"
echo "a large number of unique visitors close to the current EIE2"
echo "class size over the last two months."
break ;;
Yes )
echo ""
echo "Would you be willing to star the useful repository/ies in github"
echo "to recognise that it was useful to you? This helps their"
echo "github profile (e.g. for recruitment), and is a generally"
echo "nice thing to do. You might hope that following years"
echo "will do it for yours (assuming you make it public, and it is good),"
echo "for the same reason. There is no impact on marks, as looking at"
echo "other compilers is a good thing to do (it's just directly"
echo "copying code or structure"
echo "that is not)."
select a in "Yes" "No" ; do
case $a in
No )  echo "You're a mean one, Mr. Grinch." ; break ;;
Yes ) echo "Thank you." ; break ;;
esac
done
break;;
esac
done

echo ""
echo "Do you feel appropriately impressed with yourself for designing,"
echo "developing, and delivering a large and quite serious piece of"
echo "software?"
select a in "Yes" "No" ; do
case "$a" in
"No") echo "Well, you should"; break;;
"Yes") echo "Good. Be smug."; break;;
esac
done

echo ""
echo "It appears that hash ${HASH} passed all basic sanity checks,"
echo "the rest is up to you."
