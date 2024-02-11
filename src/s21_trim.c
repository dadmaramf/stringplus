#include "s21_string.h"

// trim - возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL

void *s21_trim(const char *src, const char *trim_chars) {
  char *result_str = s21_NULL;

  if (src && trim_chars) {      // Если не пустые
    int len = s21_strlen(src);  // Размер переданной строки
    result_str =
        (char *)calloc((len + 1), sizeof(char));  // Итоговая строка +1(\0)
    int i = 0, j = 0;  // Переменные для циклов и хождению по символам строки

    for (; i < len && s21_strchr(trim_chars, src[i]); ++i)
      ;  // Поиск начальных вхождений символов, как только strchr вернет null
         // цикл закончится
    for (; i < len; ++j)  // Цикл записи новой строки без первого вхожджения
      result_str[j] = src[i++];  // Запись итоговой строки без символа с
                                 // положения i из прошлого цикла

    for (; j != 0 && s21_strchr(trim_chars, result_str[--j]) &&
           j < len;)  // Цикла поиска конечных вхождений символов
      result_str[j] = '\0';  //Заменяем найденный символ на символ конца строки.
  }
  return result_str;
}