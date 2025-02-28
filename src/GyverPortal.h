/*
    Простой конструктор веб интерфейса для esp8266 и ESP32
    Документация:
    GitHub: https://github.com/GyverLibs/GyverPortal
    Возможности:
    - Простой конструктор - делаем страницы без знаний HTML и CSS
    - Библиотека является обёрткой для стандартной ESP8266WebServer
    - Позволяет быстро создать вебморду для управления и настройки своего девайса
    - Компактный читаемый код в "скетче", никаких внешних обработчиков и лямбда-функций
    - Конструктор использует стандартные HTML формы, CSS и javascript
    - Элементы конструктора хранятся во Flash памяти
    - Никаких глобальных буферов, всё генерируется на лету
    - Приятный дизайн из коробки + тёмная тема
    - Адаптировано под мобильные устройства и ПК
    - Встроенные инструменты для удобного парсинга значений с формы
    - Возможность настроить автоматическое обновление значений переменных по действию со страницы
    - Встроенные жабаскрипты для AJAX, работа без обновления всей страницы
    
    v1.0 - релиз
    v1.1 - улучшил графики и стили
    v1.2
    - Блок NUMBER теперь тип number
    - Добавил большое текстовое поле AREA
    - Добавил GPunix
    - Улучшил парсинг
    - Добавил BUTTON_MINI
    - Кнопки могут передавать данные с других компонентов (кроме AREA и чекбоксов)
    - Добавил PLOT_STOCK - статический график с масштабом
    - Добавил AJAX_PLOT_DARK
    - Изменён синтаксис у старых графиков
    - Фичи GPaddUnix и GPaddInt для графиков
    - Убрал default тему
    - Подкрутил стили
    - Добавил окно лога AREA_LOG и функцию лога в целом
    
    v1.3 - переделал GPunix, мелкие фиксы, для списков можно использовать PSTR
    v1.4 - мелкие фиксы, клик по COLOR теперь отправляет цвет
    v1.5 - добавил блок "слайдер+подпись"
    v1.5.1 - мелкий фикс копирования строк
    v1.6 - добавлены инструменты для работы c цветом. Добавил answer() для даты, времени и цвета
    v1.7 - поддержка ESP32
    
    v2.0: Большое обновление! Логика работы чуть изменена, обнови свои скетчи!
    - Много оптимизации/облегчения/ускорения
    - Полная поддержка ESP32
    - Переделана логика опроса действий (более правильно и оптимально + работает на ESP32) с сохранением легаси
    - Убран DateTimeP (не используется в библиотеке) и вынес отдельно в библиотеку DatePack
    - Переделан и облегчен модуль лога (log)
    - Добавлен MDNS, чтобы не искать IP платы в мониторе порта (см. доку)
    - Автоопределение режима работы WiFi. Переделан start() с сохранением легаси (см. доку)
    - Упрощён билдер, строку создавать и передавать не нужно (см. доку)
    - Объект билдера теперь называется GP (вместо add) с сохранением легаси
    - Пофикшены варнинги
    - Добавлены удобства для работы с цветом GPcolor, датой GPdate и временем GPtime
    - Удалены старые функции преобразования цвета и даты-времени (см. доку)
    - Портал теперь возвращает цвет в формате GPcolor, автообновление переменных тоже работает с GPcolor
    - Все примеры протестированы на esp8266 и esp32
    
    v2.1
    - Вернул функции root() и uri() для удобства создания многостраничности
    - Добавлен пример организации многостраничности
    - Добавлена кнопка-ссылка BUTTON_LINK
    - Добавлена авторизация по логину-паролю (см. доку)
    - Добавлено OTA обновление прошивки из браузера, в т.ч. с паролем (см. доку)
    
    v3.0: Очень много всего нового, всё не смог перечислить =)
    - Огромное спасибо DenysChuhlib и DAK85 за идеи и наработки!
    - Добавлен "объектный" режим работы, в котором компоненты удобнее конфигурируются, автоматически получают новые значения и код программы становится сильно компактнее
    - Полностью переписан механизм конструктора, сборка занимает во много раз меньше памяти в SRAM за счёт отправки страницы частями
    - Переделан механизм добавления кастомного кода на страницу
    - Аргументы конструктора теперь принимают const String& - можно передавать строки, const строки, F macro строки
    - Переделаны строковые утилиты
    - Полностью переделан слайдер
    - Убран вариант слайдера с текстом и компонент LABEL_MINI
    - Добавлена возможность задания ширины некоторым компонентам
    - У некоторых компонентов появилась опция "только чтение"
    - Редизайн светодиодов LED GREEN/RED, добавлен LED (красно-зелёный)
    - Добавлен компонент BOX_BEGIN/BOX_END, позволяющий удобно собирать компоненты в группы с нужным размером и выравниванием
    - Добавлен блок LABEL_BLOCK для выделения текста
    - Внутренний AJAX_CLICKS заменён на JS_TOP
    - Переделан основной контейнер страницы для удобства кастомизации под любую ширину интерфейса
    - Добавлен элемент навигации по динамическим вкладкам NAV_TABS (+ NAV_BLOCK_BEGIN и NAV_BLOCK_END)
    - Добавлен элемент навигации с кнопками-ссылками NAV_TABS_LINKS
    - Добавлена поддержка FontAwesome иконок для кнопок и панели навигации https://fontawesome.com/v4/icons/
    - Пофикшена бага при использовании старого сценария опроса действий
    - AJAX_UPDATE переименован в UPDATE с сохранением легаси
    - Добавлен блок FILE_UPLOAD для загрузки файлов на сервер
    - Добавлен удобный механизм скачивания файлов из SPIFFS памяти с поддержкой 33 типов файлов
    - Добавлены блоки для вывода изображений, видео и текстовых файлов из SPIFFS
    - Примеры переименованы и сгруппированы по смыслу, добавлены новые примеры
    - Добавлен механизм request
    - Подключаемым функциям добавлены варианты с адресом на GyverPortal
    - Добавлены более удобные варианты компонента SELECT и способы его опроса (getSelectedIdx)
    - Механизм update теперь работает с SELECT блоками
    - Добавлен шаблон для удобного создания кастомных блоков
    - Исправлена работа кликов и обновлений на подстраницах
    - Добавлена мини кнопка-ссылка + кнопки для скачивания файлов
    - Добавлен оффлайн-режим для графиков (не нужно подключение к Интернет)
    - Добавлен блок для добавления стилей из spiffs
    - SLIDER теперь умеет работать с float, добавлен NUMBER_F для float
    - Добавлен элемент SPINNER
    - AREA теперь отсылает сигнал click
    - Добавлены макросы для удобной сборки блоков
    - И прочее прочее
*/
/*
    TODO
    канвас
    https://www.w3schools.com/html/html5_canvas.asp
    https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API/Tutorial/Drawing_shapes
    https://developer.mozilla.org/ru/docs/Web/API/Canvas_API/Tutorial/Pixel_manipulation_with_canvas
    https://www.w3schools.com/tags/tryit.asp?filename=tryhtml5_canvas_createimagedata
*/

#ifndef _GyverPortal_h
#define _GyverPortal_h
#include <Arduino.h>

#define GP_CACHE_PRD "max-age=86400"        // таймаут кеширования (умолч. 86400 - сутки)

#ifndef GP_NO_DNS
#include <DNSServer.h>
#endif

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer* _gp_s;
#ifndef GP_NO_MDNS
#include <ESP8266mDNS.h>
#endif
#else

#include <WiFi.h>
#include <WebServer.h>
WebServer* _gp_s;
#ifndef GP_NO_MDNS
#include <ESPmDNS.h>
#endif
#endif

#include "themes.h"
#include "log.h"
#include "objects.h"
#include "portal.h"
#include "builder.h"
#include "legacy.h"
#include "buildMacro.h"

String* _GPP;
String* _gp_uri;
int _gp_bufsize;
uint32_t _gp_unix_tmr = 0;
Builder add;    // legacy
Builder GP;

#ifndef GP_NO_OTA
#include "CustomOTA.h"
#endif
#include "custom.h"

#endif
