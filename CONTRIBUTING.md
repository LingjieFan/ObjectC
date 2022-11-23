Welcome to ObjectC and add any new feature you wanted. The process for contributing are in the following:

1. git clone https://github.com/LingjieFan/ObjectC.git 2. git checkout -b your_new_features

3. Do some modifications and fix the bugs.

4. git diff

5. git add .

6. git commit -m "some comments"

7. git push https://github.com/LingjieFan/ObjectC.git your_new_features

    If the main branch has been changed, we recommend the following process labeled as 7.1, 7.2, 7.3 ...

    7.1 git checkout main

    7.2 git pull https://github.com/LingjieFan/ObjectC.git main

    7.3 git checkout your_new_feature

    7.4 git rebase main

    7.5 git push -f https://github.com/LingjieFan/ObjectC.git your_new_feature

8. pull request

9. squash and merge

10. delete the branch your_new_features

11. git checkout main

12. git branch -D your_new_features

13. git pull https://github.com/LingjieFan/ObjectC.git main
