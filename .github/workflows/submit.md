

The workflow will be named 'Submit' in the 'Actions' section of your repo
If you click on the workflow name in the left side menu, you'll see its runs
name: Submit

The name for a specific run of the workflow; As you see it can use variables
https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions#run-name
run-name: Submit ${{github.sha}} to intra by @${{github.actor}}

Events that trigger the workflow
note the markup used to specify several events with params
on:

workflow_dispatch option allows to launch the workflow manually
+ from a button that appears when you choose the workflow in the 'Actions'
+ from github command line tools gh workflow run submit.yml --ref main
NOTE: the button won't work until the workflow_dispatch option is on main
  workflow_dispatch:

push happens when a commit is pushed to a specified branch
this is especially useful when the main branch is protected
https://docs.github.com/en/repositories/configuring-branches-and-merges-in-your-repository/managing-protected-branches/about-protected-branches
  push:
    branches: main

decribes the jobs; this workflow has one job
jobs:

job name; can't contain spaces
  Submit-to-Intra:

machine to run the job on
    runs-on: ubuntu-latest

steps of the job; this job has one step
    steps:

the job uses a custom action Oktosha/42-submit-action
Look at its code at https://github.com/Oktosha/42-submit-action
stuff after the '@' tells which version to use
it can be a branch name, a tag name or a full commit hash
https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions#example-using-versioned-actions
      - uses: Oktosha/42-submit-action@v0

with property passes inputs to the action
some of the inputs are stored as repo secrets
https://docs.github.com/en/actions/security-guides/encrypted-secrets?tool=webui
        with:
          code-to-submit: kotishell
          intra-repo: ${{ secrets.INTRA_REPO_URL }}
          intra-ssh-key: ${{ secrets.SSH_PRIVATE_KEY_FOR_INTRA }}
