![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)
![author](https://img.shields.io/badge/author-AlexGyver-informational.svg)
## ВНИМАНИЕ! ЭТО БЕТА ВЕРСИЯ!
# GyverPortal
Простой конструктор веб интерфейса для esp8266 и ESP32
- Библиотека является обёрткой для стандартной ESP8266WebServer
- Позволяет быстро создать вебморду для управления и настройки своего девайса
- Компактный читаемый код в "скетче", никаких внешних обработчиков и лямбда-функций
- Конструктор использует стандартные HTML формы и CSS, генерирует статические страницы
- Элементы конструктора хранятся во Flash памяти
- Никаких глобальных буферов, всё генерируется на лету
- Простой конструктор - делаем страницы без знаний HTML и CSS
- Приятный дизайн из коробки + тёмная тема
- Адаптировано под мобильные устройства и ПК
- Встроенные инструменты для удобного парсинга значений с формы
- Возможность создать +- динамическую страницу
- Возможность настроить автоматическое обновление значений переменных по действию со страницы
- Компоненты конструктора:
  - Заголовок
  - Подпись
  - Разделитель
  - Перенос строки
  - Блок для объединения компонентов
  - Поле ввода текста
  - Поле ввода пароля
  - Галочка (чекбокс)
  - Выключатель
  - Слайдер
  - Выбор времени
  - Выбор даты
  - Селектор (дропбокс)
  - Кнопка  
  - График (смартфон должен быть подключен к интернету)

### Совместимость
esp8266, esp32

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Документация](#docs)
- [Использование](#usage)
- [Примеры](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **GyverPortal** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/GyverPortal/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
`GyverPortal portal;`

<a id="docs"></a>
## Документация
<details>
<summary>Функции конструктора</summary>

```cpp
// создание страницы
BUILD_BEGIN(строка);                // начать построение. Добавляет начальный HTML код
BUILD_END();                        // завершить построение. Добавляет завершающий HTML код и открывает страницу

// темы
add.THEME(тема);                    // установить тему
GP_DEFAULT  - стандартная тема
GP_LIGHT    - светлая тема
GP_DARK     - тёмная тема

// создание формы
add.FORM_BEGIN(имя);                // начать форму с именем (имя)
add.FORM_END();                     // завершить форму

// пустая форма с одной кнопкой
add.FORM_SUBMIT(имя, текст);        // форма с именем (имя) кнопкой (текст)

// компоненты формы
add.TEXT(имя, подсказка, число);    // поле ввода текста
add.TEXT(имя, подсказка, текст);    // поле ввода текста
add.PASS(имя, подсказка, текст);    // поле ввода пароля
add.CHECK(имя);                     // чекбокс, умолч. выключен
add.CHECK(имя, состояние);          // чекбокс
add.SWITCH(имя);                    // выключатель, умолч. выключен
add.SWITCH(имя, состояние);         // выключатель
add.DATE(имя);                      // ввод даты, умолч. пустой
add.DATE(имя, GPdate);              // ввод даты
add.TIME(имя);                      // ввод времени, умолч. пустой
add.TIME(имя, GPtime);              // ввод времени
add.SELECT(имя, список);            // селектор (дропбокс), элементы списка разделены запятой
add.SELECT(имя, список, активный);  // + текущий активный пункт
add.SLIDER(имя, число, мин, макс);       // слайдер
add.SLIDER(имя, число, мин, макс, шаг);  // слайдер
add.COLOR(имя);                     // выбор цвета, умолч. чёрный
add.COLOR(имя, число);              // выбор цвета
add.SUBMIT(текст);                  // кнопка отправки формы

// прочее для оформления
add.TITLE(текст);                   // заголовок
add.LABEL(текст);                   // подпись (для кнопок, полей, чекбоксов итд)
add.LABEL(число);                   // подпись, число
add.BREAK();                        // перенести строку
add.HR();                           // горизонтальный разделитель
add.BLOCK_BEGIN();                  // начать отрисовку блока
add.BLOCK_END();                    // завершить отрисовку блока

// создание кастомной страницы
GP_BUILD(строка);                   // запустить конструктор (можно вызывать где угодно)
GP_SHOW();                          // отобразить страницу (вызывать только внутри функции конструктора!)
add.PAGE_BEGIN();                   // начальный HTML код
add.PAGE_END();                     // завершающий HTML код
```
</details>

<details>
<summary>Методы класса</summary>

```cpp
void start();                       // запустить портал
void start(WIFI_AP);                // запустить портал с DNS сервером (для AP)
void stop();                        // остановить портал// показать свою страницу
void showPage(String&);             // показать свою страницу
void show();                        // вызвать конструктор и показать страницу
void attachBuild(void*);            // подключить функцию-билдер страницы
void attachAction(void*);           // подключить функцию, которая вызывается при действии в браузере
bool tick();                        // тикер портала. Вернёт true, если портал запущен
bool action();                      // вернёт true, если было действие с браузера
bool form(char* name);              // вернёт true, если действие пришло с указанной формы
bool root();                        // вернёт true, если открыта главная страница (/)

// список автообновления
list.init(количество);              // инициализировать список, указать количество
list.clear();                       // очистить список
list.add(адрес, имя, тип);          // добавить переменную, указать имя компонента и тип
list.add(адрес, имя формы, имя, тип);   // добавить переменную, имя формы, указать имя компонента и тип

// типы для списка
T_CSTR      - массив char
T_STRING    - строка String
T_TIME      - время типа GPtime
T_DATE      - дата типа GPdate
T_CHECK     - boolean, для чекбокса
T_INT8      - целое 1 байт
T_INT       - целое 4 байта
T_FLOAT     - float
T_COLOR     - целое 4 байта, для цвета

// парсеры
String getString(char* name);       // получить String строку с элемента name
char* getChars(char* name);         //получить char* строку с элемента name
void copyStr(char* name, char* dest);   // переписать char строку с элемента name к себе в dest
long getInt(char* name);            // получить целое число с элемента name
float getFloat(char* name);         // получить float число с элемента name
bool getCheck(char* name);          // получить состояние чекбокса с элемента name
GPdate getDate(char* name);         // получить дату с элемента name в формате GPdate
GPtime getTime(char* name);         // получить время с элемента name в формате GPtime
uint32_t getColor(char* name);      // получить цвет с элемента name
uint8_t getSelected(char* name, char* list);    // получить номер выбранного пункта в дроплисте list

int8_t inList(char* name, char* list);  // получить номер, под которым name входит в list (вида "val 1, val 2, val 3")
```
</details>

<details>
<summary>Типы данных</summary>

```cpp
// структура для хранения даты
struct GPdate {
  uint16_t year;
  uint8_t month, day;
};

// структура для хранения времени
struct GPtime {
  uint8_t hour, minute;
};
```
</details>

<a id="usage"></a>
## Базовое использование
### 1. Подготовка конструктора
1. Создаём функцию вида: `void f()`. Далее в ней:
2. Создём пустую строку: `String s;`.
3. Запускаем конструктор: `BUILD_BEGIN(s);`. Передаём созданную строку. Здесь добавляется начальный HTML код.
4. (Опционально) применяем тему: `add.THEME(тема)`, доступные темы см. в документации.
5. Строим страницу, используя конструктор или прибавляя данные к строке.
6. Завершаем работу конструктора: `BUILD_END();`. Здесь добавляется завершающий HTML код и страница отправляется на сервер.

Шаблон функции конструктора:
```cpp
void build() {
  String s;
  BUILD_BEGIN(s);
  add.THEME(GP_LIGHT);
  // собираем страницу
  // ...
  BUILD_END();
}
```

### 1.1 Кастомная страница
Для создания полностью кастомной страницы нужно запустить конструктор `GP_BUILD(s)`, а после завершения построения вызвать `GP_SHOW()`
- `BUILD_BEGIN()` состоит из `GP_BUILD(s)` и `add.PAGE_BEGIN()`
- `BUILD_END()` состоит из `add.PAGE_END()` и `GP_SHOW()`

### 2. Сборка страницы
Основная суть использования форм:
- Форма имеет своё уникальное имя, должно начинаться с **/**
- Внутри формы может быть сколько угодно элементов, но только одна кнопка
- При нажатии на кнопку esp получает имя формы и данные из всех элементов внутри этой формы

Пример с двумя формами, первая может передать текст из окна ввода, вторая - только факт нажатия кнопки:
```cpp
форма_1
    ввод текста
    кнопка
форма_1

форма_2
    кнопка
форма_2
```

В конструкторе GyverPortal это будет выглядеть так:
```cpp
void build() {
  String s;                     // создать строку
  BUILD_BEGIN(s);               // запустить конструктор
  add.THEME(GP_LIGHT);          // применить тему
  
  add.FORM_BEGIN("/login");     // начать форму, передать имя
  add.TEXT("txt", "Login", ""); // ввод текста, подсказка Login, текста нет
  add.BREAK();                  // перенос строки
  add.SUBMIT("Submit");         // кнопка Submit
  add.FORM_END();               // завершить форму
  
  add.FORM_BEGIN("/exit");      // начать форму, передать имя
  add.SUBMIT("Exit");           // кнопка Exit
  add.FORM_END();               // завершить форму
  
  BUILD_END();                  // завершить построение
}
```
![demo](/docs/demo.png)
Все инструменты конструктора описаны в документации выше.

### 3. Подключение конструктора
Передаём в библиотеку нашу функцию-конструктор страницы:
```cpp
portal.attachBuild(build);
```
Библиотека сама будет вызывать её, когда потребуется отобразить страницу. Функций-конструкторов (а следовательно и страниц) может быть несколько и их можно переключать.

### 4. Работа сервера
Для обеспечения работы сервера нужно вызывать `portal.tick()` в цикле программы. Возвращает `true`, если сервер запущен.

### 5. Парсинг действий
- При нажатии любой кнопки в браузере функция `action()` вернёт `true`
- Для поиска формы, с которой пришёл сигнал, используем `form(имя)` - вернёт `true`, если имя совпало
```cpp
if (portal.action()) {
  if (portal.form("/login")) Serial.println("Login!");
  if (portal.form("/exit")) Serial.println("Exit!");
}
```

### 6. Парсинг данных
В библиотеке реализованы готовые инструменты для полученя данных из компонентов формы (см. документацию выше). Например выведем в порт содержимое поля ввода текста:
```cpp
if (portal.action()) {
  if (portal.form("/login")) {
    Serial.println(portal.getString("txt"));
    // где "txt" - имя компонента
  }
}
```

### 7. Создаём GyverPortal глобально
```cpp
GyverPortal portal;
void build() {}

void setup() {
  // подключаемся к точке
  // ...
  portal.attachBuild(build);
  portal.start();
}

void loop() {
  portal.tick();
  if (portal.action()) {
    // ...
  }
}
```

### 8. Создаём GyverPortal локально
```cpp
void build() {}

void f() {
  GyverPortal portal;
  portal.attachBuild(build);
  portal.start();
  
  while (portal.tick()) {
    if (portal.action()) {
      // ...
      
      // для выхода из цикла можно остановить портал
      // например по кнопке из формы
      if (portal.form("/exit")) portal.stop();
    }
  }
}
```
## Дополнительные возможности
### 1. Внешняя функция действия
Вместо ручного опроса `action()` можно подключить свою функцию вида `void f(GyverPortal*)`, она будет вызвана при действии в браузере. 
Эту функцию нужно будет передать в `attachAction()`.
```cpp
void myAction(GyverPortal* p) {
  // имеем доступ к объекту портала, который отправил вызов
  if (p -> form("/exit")) Serial.println("exit");
}

void setup() {
  // ...
  portal.attachAction(myAction);
}
```
### 2. Автоматическое обновление указанных переменных
**[См. пример demoAuto]** Можно указать библиотеке переменные, которые будут автоматически получать новые значения с указанных компонентов страницы.
- Инициализируем список, вызвав `.list.init(количество)`, передаём размер списка в количестве переменных.
- Добавляем переменную по её адресу:
  - `.list.add(&переменная, имя, тип)` - с указанием имени компонента и типа
  - `.list.add(&переменная, форма, имя, тип)` - с указанием имени формы, имени компонента и типа
| Тип данных    | Тип/Компонент | TEXT | PASS | CHECK | SWITCH | DATE | TIME | SLIDER | COLOR | SELECT |
| ------------- | ------------- |:----:|:----:|:-----:|:------:|:----:|:----:|:------:|:-----:|:------:|
| `char[]`      | T_CSTR        |  ✔  |  ✔   |       |        |  ✔  |  ✔  |   ✔   |   ✔   |   ✔   |
| `String`      | T_STRING      |  ✔  |  ✔   |       |        |  ✔  |  ✔  |   ✔   |   ✔   |   ✔   |
| `GPtime`      | T_TIME        |      |      |        |       |      |  ✔  |        |       |        |
| `GPdate`      | T_DATE        |      |      |        |       |  ✔  |      |        |       |        |
| `bool`        | T_CHECK       |      |      |  ✔    |   ✔   |      |      |       |       |        |
| `byte`, `char`| T_INT8        |  ✔  |  ✔  |        |        |      |      |    ✔ |       |        |
| `int`, `long` | T_INT         |  ✔  |  ✔   |       |        |      |      |    ✔ |       |        |
| `float`       | T_FLOAT       |  ✔  |  ✔   |       |        |      |      |    ✔ |       |        |
| `uint32_t`    | T_COLOR       |      |      |       |        |      |      |       |   ✔   |        |

Указанные переменные обновят свои данные при действии с формы с указанным именем. Если имя не указано - компонент будет парситься при действии с любой формы

<a id="example"></a>
## Примеры
```cpp
```

<a id="versions"></a>
## Версии
- v1.0

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!
