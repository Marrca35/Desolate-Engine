#!/bin/bash

git pull
git commit -a
git commit -m "$1"
git push