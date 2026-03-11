#!/bin/bash
# setup.sh - pcannonProjectStandards
# Predefines for C and C++ projects
# STD Information: 20260217 - 1.0

echo "This script will setup everything for a C / C++ project"
echo "Press CTRL + C to cancel or return to continue"
read

git clone https://www.github.com/pcannon09/pcannonProjectStandards.git

# Populate
echo ">> Project executable name?"
read exeName

echo ">> Project name?"
read projectName

echo ">> Project prefix?"
read projectPrefix

mkdir -p "inc/$projectName" --verbose

mkdir -p src/lib --verbose
mkdir -p src/core --verbose
mkdir -p src/utils --verbose

mkdir .private/ --verbose

# Move everything to the root of the project
cd pcannonProjectStandards

mv bash/* ../ --verbose

mv c/* "../inc/$projectName/" --verbose
mv cmake/* ../ --verbose
mv private/project.json ../.private/

mkdir -p ../tmp

jq \
	--arg exeName "$exeName" \
	--arg projectName "$projectName" \
	--arg projectPrefix "$projectPrefix" \
	'.exeName = $exeName | .projectName = $projectName | .projectPrefix = $projectPrefix' \
	../.private/project.json > ../tmp/project.tmp.json

mv ../tmp/project.tmp.json ../.private/project.json

echo "# Templates are populated"

cd ..

rm -rf pcannonProjectStandards

