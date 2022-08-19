#!/bin/bash

echo $1

git pull
git commit -m "$1"
git push