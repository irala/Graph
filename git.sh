#!/bin/bash

git status
git pull

echo "Write your comment"
read variable

git add *
git commit -m  "$variable"

git push

