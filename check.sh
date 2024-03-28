#! /bin/bash

# Check the git is not up to date
git status 

# if the git don't the newest branch
# use the `git fetch origin` to get the newest branch
#
# Notes: you need to create the new branch to submit your change
# use the `git checkout -b feature-branch`; the "feature-branch" is the branch name
#
# commit the git to the github
# use the `git add .` to add all info
# use the `git commit -m "..."` to add the commit info
# use the `git push -u origin feature-branch` to add the branch
#
# use the `git remote -v` to get the all git url, 
# if the url prefix don't the "git", you need to remove the currently https url and add the git url
#
# use the `ssh -T git@github.com` to check can connect the git service
# if the info is the "Hi, your name", this is the successfully
# else you need to configure you ssh to connect your github account
#
