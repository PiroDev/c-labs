# Тесты для лабораторной работы №06

## Входные данные

В качестве аргументов командной строки:
- Имя файла;
- Анализируемое поле;
- Значение ключа (опционально).

Во входном файле хранится информация о фильмах, а именно:
- Название кинофильма;
- Фамилия режиссера;
- Год выхода на экран.

## Выходные данные

Если указано значение ключа: информация о кинофильме с искомым значением ключа.
Иначе: упорядоченный массив фильмов.

## Позитивные тесты:

### Передано только анализуруемое поле (сортировка)
- 01 - Сортировка по названию;
- 02 - Сортировка по режиссеру;
- 03 - Сортировка по году выхода на экран.

### Передано и анализируемое поле, и значение ключа (сортировка и бинарный поиск)
- 04 - Бинарный поиск по названию, которое есть в файле;
- 05 - Бинарный поиск по режиссеру, который есть в файле;
- 06 - Бинарный поиск по году выхода на экран, который есть в файле;
- 07 - Бинарный поиск по названию, которого нет в файле;
- 08 - Бинарный поиск по режиссеру, которого нет в файле;
- 09 - Бинарный поиск по году выхода на экран, которого нет в файле.

## Негативные тесты:
- 01 - Программе было передано неверное число аргументов;
- 02 - Программе было передано неверное значение поля для сортировки [и поиска];
- 03 - Программе не удалось прочитать информацию из файла (включая случай несуществующего файла);
- 04 - В файле есть слишком длинное поле;
- 05 - Файл пустой;
- 06 - Программе было передано нечисловое значение года;
- 07 - Программе было передано неположительное значение года;
- 08 - В файле содержится слишком много (> 15) структур.