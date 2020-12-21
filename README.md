# TestGit
Тестовый репозиторий
Прример проекта PIC24 (моргание светодиодом)

## Начало работы с Git
```
git status						- состояние файлов в текущей папке
git add main.c					- добавить файл main.c для отслеживания
git add .						- добавить новые файлы для отслеживания
git rm main.c					- прекратить наблюдение изменений файла main.c

git commit -m 'Добавил весть проект в наблюдение изменений'	- фиксация изменений с комментарием

```

## Удалённый Git

```
git config --global user.name - Показывает имя пользователя
git config --global user.name 'picspb'  - Изменяет имя пользователя
git config --global user.email — Показывает email пользователя
git config --global user.email 'pic_spb@mail.ru' — Изменяет email пользователя


git push origin master      - Заливает текущие локальные коммиты в удаленный репозиторий
git pull      - Забирает изменения с удаленного репозитория в локальный
git clone     - Клонирует проект с удаленного репозитория

```

## Ветвление
```
git branch							- просмотр веток
git branch test						- создание ветки test
git branch -D test					- удаление ветки test
git checkout test 					- переключение на ветку test
git checkout -b test2				- создание и переключение на ветку test2

git merge test						- принять изменения из ветки test в текущую ветку


````
