# submit.yml

This workflow publishes code to the [42 School](42.fr) intranet
when a push to the main branch happens. It was build during a minishell project in [Codam](codam.nl) in 2023.

Below you'll find comments to the `submit.yml` lines. Commenting right in the YAML file makes it difficult to percieve (especially the indentation levels).

## Name (whole workflow)

You must set the name of your workflow.

```yaml
name: Submit
```
You'll see this name in the 'Actions' section of your repo. If you click on it in the left side menu, you'll see the runs of the workflow.

## Name (specific run)

You may specify the name for each run. You don't have to. But if you want, you can use some variables: https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions#run-name

```yaml
run-name: Submit ${{github.sha}} to intra by @${{github.actor}}
```

## Triggering events (overall)

You can specify one or multiple events to trigger the workflow.

```yaml
on:
  workflow_dispatch:
  push:
    branches: main
```
Multiple events can be enumerated in short form https://docs.github.com/en/actions/using-workflows/triggering-a-workflow#using-multiple-events or in long form https://docs.github.com/en/actions/using-workflows/triggering-a-workflow#using-activity-types-and-filters-with-multiple-events

## Triggering events (workflow_dispatch)

workflow_dispatch option allows to launch the workflow manually

+ from a button that appears when you choose the workflow in the 'Actions'
+ from github command line tools gh workflow run submit.yml --ref main

```yaml
  workflow_dispatch:
```
**NOTE:** The button won't work until the workflow description on the main branch has workflow_dispatch in it.

## Triggering events (push)

Push happens when a commit is pushed to a specified branch

```yaml
  push:
    branches: main
```
The push events works very good with protected branches: https://docs.github.com/en/repositories/configuring-branches-and-merges-in-your-repository/managing-protected-branches/about-protected-branches
When the main branch is protected, a push to it means a successful merge after a properly discussed, checked and approved pull request. A perfect time to publish the work to intra.
  
## Jobs

You can define several job in a workflow, but here we have one job named `Submit-to-Intra`. The job name can't contain spaces.

```yaml
jobs:
  Submit-to-Intra:
```

## Job (Submit-to-Intra)

Job must specify a machine it runs on and a set of steps.

```yaml
  Submit-to-Intra:
    runs-on: ubuntu-latest
    steps:
```

## steps (using action)

Steps are either `run` steps with shell commands or `uses` steps that use some action. This workflow has one step that uses a custom action https://github.com/Oktosha/42-submit-action

```yaml
      - uses: Oktosha/42-submit-action@v0
        with:
          code-to-submit: kotishell
          intra-repo: ${{ secrets.INTRA_REPO_URL }}
          intra-ssh-key: ${{ secrets.SSH_PRIVATE_KEY_FOR_INTRA }}
```

## using action (setting version)

One can specify a version of the action by putting branch name, tag or commit SHA after the `@` symbol in the action reference https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions#example-using-versioned-actions

```yaml
      - uses: Oktosha/42-submit-action@v0
```

A good practice is to use a reference to a specific commit so that your workflow won't break after the action updates.

## using action (giving inputs)

One can give inputs to an action with `with` property. The can be constans, variables or even secrets https://docs.github.com/en/actions/security-guides/encrypted-secrets?tool=webui

```yaml
        with:
          code-to-submit: kotishell
          intra-repo: ${{ secrets.INTRA_REPO_URL }}
          intra-ssh-key: ${{ secrets.SSH_PRIVATE_KEY_FOR_INTRA }}
```
