#include <iostream>
#include <assert.h>

//------------------------------
/** @file */
//! computes length of string
//! @param[in] s pointer to string
//! @return length of string s
//------------------------------
int MyStrlen(char* s)
{
    assert(s != NULL);

    int i;

    for (i = 0; *s != '\0'; s++)
    {
        i++;
    }
    return i;
}
//------------------------------------------
//! Copying string what to string where
//! @param[in] where string where copying
//! @param[in] what string that copying
//-------------------------------------------
void MyStrcpy(char* where, char* what)
{
    /* проверка того что указатели существуют */
    assert(where != NULL);
    assert(what != NULL);

    /* проверка того что области памяти не перекрыываются */
    assert(not(where >= what and where <= what + MyStrlen(what) * sizeof(char) or
    where + MyStrlen(where) * sizeof(char) >= what and
    where + MyStrlen(where) * sizeof(char) <= what + MyStrlen(what) * sizeof(char)));

    /* проверка что в целевой строке хватит памяти */
    assert(MyStrlen(where) >= MyStrlen(what));

    int i;

    for (i = 0; *(what + i) != '\0'; i++)
    {
        *(where + i) = *(what + i);
    }
    *(where + i) = '\0';
}

//----------------------------------------------------------
//! Searching first entrance of symbol in string
//! @param[in] str string where searching
//! @param[in] symbol symbol that searching
//! @return pointer to the 1st entrance of symbol in string
//-----------------------------------------------------------

char* MyStrchr(char* str, int symbol)
{
    assert(str != NULL);

    while (*str != '\0')
    {
        if (*str == symbol)
        {
            return str;
        }
        str++;
    }
    return str;
}

//------------------------------------------
//! Concatinate 2 strings
//! @param[in] str1 1st string
//! @param[in] str2 2d string
//! @return pointer to the 1st string concatinated with second string
//-------------------------------------------

char* MyStrcat(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    char* start = str1;
    str1 = str1 + MyStrlen(str1);

    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return start;
}

//-----------------------------------------------------------------------------------------------
//! Starting from the first characters,
//! the strcmp function compares each pair of characters in turn,
//! and this continues until different characters are found or the end of the string is reached.
//! @param[in] str1 1st string
//! @param[in] str2 2d string
//! @return positive number if string1 > string2,negative number overvise, 0 if string1 = string2
//------------------------------------------------------------------------------------------------

int MyStrcmp(char* str1, char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    while (*str1 != '\0')
    {
        if (*str1 != *str2)
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }
}

int main() {
    char s1[4] = "abc";
    char s2[5] = "sadf";
    int p;
    p = MyStrcmp(s2, s2);

    printf("%d", p);
    return 0;
}
