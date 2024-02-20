#!/bin/sh

# Navigate to the repository directory
cd /Users/samir/.pyenv/versions/3.9.10/lib/python3.9/site-packages/onlinejudge_template_resources/template

# Optional: Add all changes to staging
git add *

# Optional: Commit changes with a generic message
git commit -m "Updated template"

# Push changes to the remote repository
git push
