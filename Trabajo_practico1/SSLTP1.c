#include <stdio.h>

// a) Calcular y retornar la longitud de una cadena dada
int size(char str[])
{
  int index = 0;
  while (str[index] != '\0')
  {
    index++;
  }
  return index;
}

// b) Convertir una cadena de dígitos en su equivalente numérico

int power(int base, int exponent)
{
  int result = 1;
  for (int i = 0; i < exponent; i++)
  {
    result *= base;
  }
  return result;
}

int strToInt(char *str)
{
  int result = 0;
  for (int i = 0; i < size(str); i++)
  {
    if (str[0] == 45)
      continue;

    if (str[i] >= 48 && str[i] <= 57)
      // explicación: result += num * 10^(el tamaño del string - posicion - 1)
      result += (str[i] - 48) * (power(10, size(str) - i - 1));
    else
      return -1;
  }
  if (str[0] == 45)
    result *= -1;
  return result;
}

char *toUpperCase(char *str)
{

  char upperString[size(str)];

  for (int i = 0; i < size(str); i++)
  {
    char c = str[i];
    if (c >= 97 && c <= 122)
    {
      upperString[i] = c - 32;
    }
    else
      upperString[i] = c;
  }
  return upperString;
}

/*d) Eliminar de una cadena dada todas las ocurrencias de un carácter dado. */

int countLetters(char *str, char c)
{
  int result = 0;
  for (int i = 0; i < size(str); i++)
  {
    if (c == str[i])
      result++;
  }
  return result;
}

char *purgeChar(char *str, char c)
{
  char result[size(str) - countLetters(str, c)];
  int j = 0;
  for (int i = 0; i < size(str); i++)
  {
    if (str[i] != c)
    {
      result[j] = str[i];
      j++;
    }
  }
  result[j] = '\0';
  return result;
}

// e) Concatenar al final de la primer cadena dada una segunda cadena también dada
char *concatStrings(char *str1, char *str2)
{
  char concated[size(str1) + size(str2)];

  for (int i = 0; i < size(str1); i++)
  {
    concated[i] = str1[i];
  }
  int j = size(str1);
  for (int i = 0; i < size(str2); i++)
  {
    concated[j] = str2[i];
    j++;
  }

  return concated;
}

// f) Modificar en una cadena dada agregando un carácter dado en una posición dada.

char *insertChar(char *str, char c, int pos)
{
  char result[size(str) + 1];
  int j = 0;

  for (int i = 0; i < size(str) + 1; i++)
  {
    if (pos != i)
      result[j] = str[i];
    else
    {
      result[j] = c;
      // Tambien se agrega el caracter del array, que es pisado por el caracter insertado.
      j++;
      result[j] = str[i];
    }
    j++;
  }
  // En caso de que la posición no este definida en el array, se coloca el caracter en la última posición.
  if (pos > size(str) + 1)
  {
    result[size(str)] = c;
    return result;
  }

  return result;
}

int main(void)
{
  // test a
  // printf("%d \n", size("Hola Mundo"));

  // test b
  // printf("%d\n", strToInt("-04241"));

  // test c
  // printf("%s\n", toUpperCase("As673f6"));

  // test d
  // printf("%s", purgeChar("cadenas", 'a'));

  // test e
  // printf("%s",concatStrings("Hola","Mundo"));

  // test f
  // printf("%s",insertChar("Hola Mund", 'O', 4));

  return 0;
}
