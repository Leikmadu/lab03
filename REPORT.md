markdown
# Laboratory work II

Данная лабораторная работа посвещена изучению систем контроля версий на примере Git.
```bash
$ open https://git-scm.com
```

## Tasks
- 1. Создать публичный репозиторий с названием lab02 и с лиценцией MIT
- 2. Сгенирировать токен для доступа к сервису GitHub с правами repo
- 3. Ознакомиться со ссылками учебного материала
- 4. Выполнить инструкцию учебного материала
- 5. Составить отчет и отправить ссылку личным сообщением в Slack

## Студент
Малыхин Кирилл Группа: ИУ8-21  
Дата: 20.03.2026  

---

## Tutorial
```bash
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_EMAIL=<адрес_почтового_ящика>
$ export GITHUB_TOKEN=<сгенирированный_токен>
$ alias edit=<nano|vi|vim|subl>
```
```bash
$ cd ${GITHUB_USERNAME}/workspace
$ source scripts/activate
```

```bash
$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https

```bash
$ mkdir projects/lab02 && cd projects/lab02
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
# check your git global settings
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
$ git pull origin master
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin master
```
Добавить на сервисе GitHub в репозитории lab02 файл .gitignore со следующем содержимом:

```bash
*build*/
*install*/
*.swp
.idea/
```
```bash
$ git pull origin master
$ git log
```
```bash
$ mkdir sources
$ mkdir include
$ mkdir examples
$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF
```

```bash
$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF
```
```bash
$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```
```bash
$ edit README.md
```

```bash
$ git status
$ git add .
$ git commit -m"added sources"
$ git push origin master
```
##Report

```bash
$ cd ~/workspace/
$ export LAB_NUMBER=02
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER}.git tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```


## Выполнение домашнего задания

### Part1

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).

Создан репозиторий lab02.
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.

Первый коммит создан.

3. Создайте файл hello_world.cpp в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу Hello world на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку using namespace std;.

```bash
$ cat > hello_world.cpp <<'EOF'
```
4. Добавьте этот файл в локальную копию репозитория.
```bash
git add hello_world.cpp
```
5. Закоммитьте изменения с осмысленным сообщением.
```bash
git commit -m "add hello_world.cpp with bad style"
```
**Вывод:**
```
[main (root-commit) 287ecfa] add hello_world.cpp with bad style
 1 file changed, 8 insertions(+)
 create mode 100644 hello_world.cpp
```
6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение Hello world from @name, где @name имя пользователя.
```bash
cat > hello_world.cpp <<'EOF'
```
**Теперь программа выглядит так**:
```
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello world from " << name << endl;
    return 0;
}
```
7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно git add?
```bash
git commit -am "modify hello_world.cpp"
```
**Вывод:**
```
[main 1d6a635] modify hello_world.cpp
 1 file changed, 4 insertions(+), 1 deletion(-)`
```
Git уже отслеживает все файлы и добавляет их автоматически.

8. Запуште изменения в удалёный репозиторий.
```bash
 git push origin main
```
**Вывод:**
```
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 2 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 823 bytes | 823.00 KiB/s, done.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/Leikmadu/lab02.git
   61e72c7..446f8ca  main -> main
```
9. Проверьте, что история коммитов доступна в удалёный репозитории.

Доступна


## Part II
Note: Работать продолжайте с теми же репоззиториями, что и в первой части задания.

1. В локальной копии репозитория создайте локальную ветку patch1.
```bash
git checkout -b patch1
```

**Вывод:**
```
Switched to a new branch 'patch1'
```
2. Внесите изменения в ветке patch1 по исправлению кода и избавления от using namespace std;.
```bash
cat > hello_world.cpp <<'EOF'
```
Теперь код выглядит так:
```
`#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF
```
3. commit, push локальную ветку в удалённый репозиторий.
```bash
git commit -am "fix: remove 'using namespace std'"
```
**Вывод:**
```
[patch1 9f4a364] fix: remove 'using namespace std'
 1 file changed, 4 insertions(+), 5 deletions(-)
```
4. Проверьте, что ветка patch1 доступна в удалёный репозитории.

На Github  patch1 присутствует.

5. Создайте pull-request patch1 -> master.

Pull-request создан.

6. В локальной копии в ветке patch1 добавьте в исходный код комментарии.
```bash
cat > hello_world.cpp <<'EOF'
```
Теперь код такой:
```
#include <iostream>  // for std::cout and cin                                   #include <string>    // for std::string
/**
 * main function             
 */                                                  
int main() {
    std::string name;                      // name
    std::cout << "Enter your name: ";      // enter the name                   
    std::getline(std::cin, name);          // reading name     
    std::cout << "Hello world from " << name << std::endl;  // print    
    return 0;                              //ending      
}
```
7. commit, push.
```bash
git commit -am "add comments"
```
**Вывод:**
```
[patch1 0ca7445] add comments
 1 file changed, 13 insertions(+), 10 deletions(-)
```
```bash
git push origin patch1
```
**Вывод:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 508 bytes | 508.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/Leikmadu/lab02.git
   9f4a364..0ca7445  patch1 -> patch1
```
8. Проверьте, что новые изменения есть в созданном на шаге 5 pull-request
Все изменения есть.

9. В удалённый репозитории выполните слияние PR patch1 -> master и удалите ветку patch1 в удаленном репозитории.

Слияние выполнено.

```bash
git checkout main
```
**Вывод:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```
10. Локально выполните pull.

```bash
git pull origin main
```
**Вывод:**
```
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 964 bytes | 964.00 KiB/s, done.
From https://github.com/Leikmadu/lab02
 * branch            main       -> FETCH_HEAD
   446f8ca..976ce26  main       -> origin/main
Updating 446f8ca..976ce26
Fast-forward
 hello_world.cpp | 24 +++++++++++++-----------
 1 file changed, 13 insertions(+), 11 deletions(-)
```
11. С помощью команды git log просмотрите историю в локальной версии ветки master.

```bash
git log
```
**Вывод:**

```
976ce26 (HEAD -> main, origin/main) Merge pull request #1 from Leikmadu/patch1
0ca7445 (origin/patch1, patch1) add comments
9f4a364 fix: remove 'using namespace std'
446f8ca modify hello_world.cpp
ade8536 add hello_world.cpp with bad style
61e72c7 first commit
```
12. Удалите локальную ветку patch1.
```bash
git branch -d patch1
```
**Вывод:**

```
Deleted branch patch1 (was 0ca7445).
```

###Part III
Note: Работать продолжайте с теми же репоззиториями, что и в первой части задания.

1. Создайте новую локальную ветку patch2.
```bash
git checkout -b patch2
```
**Вывод:**
```
Switched to a new branch 'patch2'
```
2. Измените code style с помощью утилиты clang-format. Например, используя опцию -style=Mozilla.

```bash
clang-format -style=Mozilla -i hello_world.cpp
```
3. commit, push, создайте pull-request patch2 -> master.

```bash
git commit -am "format code with Mozilla style"
```
**Вывод:**
```
Switched to a new branch 'patch2'
```
```bash
git push -u origin patch2
```
**Вывод:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 519 bytes | 519.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
remote: 
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/Leikmadu/lab02/pull/new/patch2
remote: 
To https://github.com/Leikmadu/lab02.git
 * [new branch]      patch2 -> patch2
branch 'patch2' set up to track 'origin/patch2'.
```
4. В ветке master в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.

Изменены комментарии.

5. Убедитесь, что в pull-request появились конфликтны.

Конфикты появились, теперь нельзя произвести merge.

6. Для этого локально выполните pull + rebase (точную последовательность команд, следует узнать самостоятельно). Исправьте конфликты.

```bash
git pull origin main --rebase
```
**Вывод:**
```
error: Pulling is not possible because you have unmerged files.
hint: Fix them up in the work tree, and then use 'git add/rm <file>'
hint: as appropriate to mark resolution and make a commit.
fatal: Exiting because of an unresolved conflict.

```
7. Сделайте force push в ветку patch2

```bash
git add hello_world.cpp
git rebase --continue
```
**Вывод:**
```
[detached HEAD 86f0357] format code with Mozilla style
 1 file changed, 18 insertions(+)
Successfully rebased and updated refs/heads/patch2.
```
```bash
git push origin patch2 --force
```
**Вывод:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 681 bytes | 681.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/Leikmadu/lab02.git
 + f59635e...86f0357 patch2 -> patch2 (forced update)
```
8. Убедитеcь, что в pull-request пропали конфликтны.

Все конфикты устранены удаленно через GinHub. Был возвращен прежний вид hello_world.cpp.

9. Вмержите pull-request patch2 -> master.

Merge сделан.



