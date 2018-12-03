/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��return 0ֻ��һ��ʾ�����ɸı� */

int tj_strlen(const char str[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int p = 0;
	while (str[p])
		++p;
	return p; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strcat(char s1[], const char s2[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2);
	for (int i = 0; i <= l2; ++i)
		s1[l1 + i] = s2[i];
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strcpy(char s1[], const char s2[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2);
	for (int i = 0; i <= l2; ++i)
		s1[i] = s2[i];
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strncpy(char s1[], const char s2[], const int len)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2);
	if (len < l2)
		l2 = len;
	for (int i = 0; i < l2; ++i)
		s1[i] = s2[i];
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strcmp(const char s1[], const char s2[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	for (int i = 0; i <= tl; ++i)
	{
		int dec = s1[i] - s2[i];
		if (!dec)
			continue;
		return dec;
	}
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strcasecmp(const char s1[], const char s2[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	for (int i = 0; i <= tl; ++i)
	{
		int dec = s1[i] - s2[i];
		if (!dec)
			continue;
		if ((((s1[i] >= 'A') && (s1[i] <= 'Z')) || ((s1[i] >= 'a') && (s1[i] <= 'z')))
			&& (((s2[i] >= 'A') && (s2[i] <= 'Z')) || ((s2[i] >= 'a') && (s2[i] <= 'z'))))
		{
			if (dec == 32 || dec == -32)
				continue;
		}
		return dec;
	}
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strncmp(const char s1[], const char s2[], const int len)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	if (len <= tl)
		tl = len - 1;
	for (int i = 0; i <= tl; ++i)
	{
		int dec = s1[i] - s2[i];
		if (!dec)
			continue;
		return dec;
	}
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(s1), l2 = tj_strlen(s2), tl;
	if (l1 < l2)
		tl = l1;
	else
		tl = l2;
	if (len <= tl)
		tl = len - 1;
	for (int i = 0; i <= tl; ++i)
	{
		int dec = s1[i] - s2[i];
		if (!dec)
			continue;
		if ((((s1[i] >= 'A') && (s1[i] <= 'Z')) || ((s1[i] >= 'a') && (s1[i] <= 'z')))
			&& (((s2[i] >= 'A') && (s2[i] <= 'Z')) || ((s2[i] >= 'a') && (s2[i] <= 'z'))))
		{
			if (dec == 32 || dec == -32)
				continue;
		}
		return dec;
	}
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strupr(char str[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int tl = tj_strlen(str);
	for (int i = 0; i < tl; ++i)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strlwr(char str[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int tl = tj_strlen(str);
	for (int i = 0; i < tl; ++i)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strchr(const char str[], char ch)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int tl = tj_strlen(str);
	for (int i = 0; i < tl; ++i)
		if (str[i] == ch)
			return i + 1;
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strstr(const char str[], const char substr[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(str), l2 = tj_strlen(substr);
	for (int i = 0; i < l1; ++i)
	{
		if (str[i] != substr[0])
			continue;
		if (i + l2 - 1 >= l1)
			break;
		bool f = 1;
		for (int j = 0; j < l2; ++j)
			if (str[i + j] != substr[j])
			{
				f = 0;
				break;
			}
		if (f)
			return i + 1;
	}
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strrchr(const char str[], const char ch)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int tl = tj_strlen(str);
	for (int i = tl - 1; i>=0; --i)
		if (str[i] == ch)
			return i + 1;
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strrstr(const char str[], const char substr[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int l1 = tj_strlen(str), l2 = tj_strlen(substr);
	for (int i = l1 - l2; i>=0; --i)
	{
		if (str[i] != substr[0])
			continue;
		bool f = 1;
		for (int j = 0; j < l2; ++j)
			if (str[i + j] != substr[j])
			{
				f = 0;
				break;
			}
		if (f)
			return i + 1;
	}
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}

int tj_strrev(char str[])
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	int tl = tj_strlen(str), lim = (tl - 1) / 2;
	if (!tl)
		return 0;
	for (int i = 0; i <= lim; ++i)
	{
		char tmp = str[i];
		str[i] = str[tl - i - 1];
		str[tl - i - 1] = tmp;
	}
	return 0; //returnֵ�ɸ�����Ҫ�޸�
}
