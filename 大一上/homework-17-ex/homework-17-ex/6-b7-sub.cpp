/* 请写入你的信息(忘了写，5%的分数没有了哦) */

#include <iostream>
using namespace std;

/* 函数的原型定义不准变 */
int   tj_strlen(const char *str);
char *tj_strcat(char *s1, const char *s2);
char *tj_strcpy(char *s1, const char *s2);
char *tj_strncpy(char *s1, const char *s2, const int len);
int   tj_strcmp(const char *s1, const char *s2);
int   tj_strcasecmp(const char *s1, const char *s2);
int   tj_strncmp(const char *s1, const char *s2, const int len);
int   tj_strcasencmp(const char *s1, const char *s2, const int len);
char *tj_strupr(char *str);
char *tj_strlwr(char *str);
int   tj_strchr(const char *str, const char ch);
int   tj_strstr(const char *str, const char *substr);
int   tj_strrchr(const char *str, const char ch);
int   tj_strrstr(const char *str, const char *substr);
char *tj_strrev(char *str);

/* ----- 不允许定义任何形式的全局数组!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
int tj_strlen(const char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	int len = 0;
	while (*(str++) != '\0')
		++len;
	return len;
}

char *tj_strcat(char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL)
		return NULL;
	if (s2 == NULL)
		return s1;
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2);
	char *tmps = s1;
	s1 += l1;
	for (int i = 0; i <= l2; ++i)
		*(s1++) = *(s2++);
	return tmps;
}

char *tj_strcpy(char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL)
		return NULL;
	if (s2 == NULL)
	{
		*s1 = '\0';
		return s1;
	}
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2);
	char *tmps = s1;
	for (int i = 0; i <= l2; ++i)
		*(s1++) = *(s2++);
	return tmps;
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
	if (s1 == NULL)
		return NULL;
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2);
	char *tmps = s1;
	if (len < l2)
		l2 = len;
	for (int i = 0; i < l2; ++i)
		*(s1++) = *(s2++);
	return tmps;
}

int tj_strcmp(const char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	for (int i = 0; i <= tl; ++i)
	{
		int dec = *(s1++) - *(s2++);
		if (!dec)
			continue;
		return dec;
	}
	return 0;
}

int tj_strcasecmp(const char *s1, const char *s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	for (int i = 0; i <= tl; ++i)
	{
		char c1 = *(s1++), c2 = *(s2++);
		int dec = c1 - c2;
		if (!dec)
			continue;
		if ((((c1 >= 'A') && (c1 <= 'Z')) || ((c1 >= 'a') && (c1 <= 'z')))
			&& (((c2 >= 'A') && (c2 <= 'Z')) || ((c2 >= 'a') && (c2 <= 'z'))))
		{
			if (dec == 32 || dec == -32)
				continue;
		}
		return dec;
	}
	return 0;
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	if (len <= tl)
		tl = len - 1;
	for (int i = 0; i <= tl; ++i)
	{
		int dec = *(s1++) - *(s2++);
		if (!dec)
			continue;
		return dec;
	}
	return 0;
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL && s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	if (len <= tl)
		tl = len - 1;
	for (int i = 0; i <= tl; ++i)
	{
		char c1 = *(s1++), c2 = *(s2++);
		int dec = c1 - c2;
		if (!dec)
			continue;
		if ((((c1 >= 'A') && (c1 <= 'Z')) || ((c1 >= 'a') && (c1 <= 'z')))
			&& (((c2 >= 'A') && (c2 <= 'Z')) || ((c2 >= 'a') && (c2 <= 'z'))))
		{
			if (dec == 32 || dec == -32)
				continue;
		}
		return dec;
	}
	return 0;
}

char *tj_strupr(char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	int tl = tj_strlen(str);
	char *tmps = str;
	for (int i = 0; i < tl; ++i, ++str)
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
	return tmps;
}

char *tj_strlwr(char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int tl = tj_strlen(str);
	char *tmps = str;
	for (int i = 0; i < tl; ++i, ++str)
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
	return tmps;
}

int tj_strchr(const char *str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int tl = tj_strlen(str);
	for (int i = 0; i < tl; ++i)
		if (*(str++) == ch)
			return i + 1;
	return 0;
}

int tj_strstr(const char *str, const char *substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (substr == NULL)
		return 0;
	int l1 = tj_strlen(str), l2 = tj_strlen(substr);
	for (int i = 0; i < l1; ++i, ++str)
	{
		if (*str != *substr)
			continue;
		if (i + l2 - 1 >= l1)
			break;
		bool f = 1;
		const char * _str = str;
		const char * _substr = substr;
		for (int j = 0; j < l2; ++j)
			if (*(str++) != *(substr++))
			{
				f = 0;
				break;
			}
		if (f)
			return i + 1;
		else
			str = _str, substr = _substr;
	}
	return 0;
}

int tj_strrchr(const char *str, const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int tl = tj_strlen(str);
	str += tl - 1;
	for (int i = tl - 1; i >= 0; --i, --str)
		if (*str == ch)
			return i + 1;
	return 0;
}

int tj_strrstr(const char *str, const char *substr)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (substr == NULL)
		return 0;
	int l1 = tj_strlen(str), l2 = tj_strlen(substr);
	str += l1 - l2;
	for (int i = l1 - l2; i >= 0; --i, --str)
	{
		if (*str != *substr)
			continue;
		bool f = 1;
		const char * _str = str;
		const char * _substr = substr;
		for (int j = 0; j < l2; ++j)
			if (*(str++) != *(substr++))
			{
				f = 0;
				break;
			}
		if (f)
			return i + 1;
		else
			str = _str, substr = _substr;
	}
	return 0;
}

char *tj_strrev(char *str)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return NULL;
	int tl = tj_strlen(str);
	char *tmps = str;
	char *_str = str + tl - 1;
	while (str < _str)
	{
		char tmp = *str;
		*str = *_str;
		*_str = tmp;
		++str, --_str;
	}
	return tmps;
}
