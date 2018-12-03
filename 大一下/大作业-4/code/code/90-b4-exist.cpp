/* �༶:�����һ�� ѧ��:1652228 ����:����Դ */

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include "cmd_console_tools.h"
#include "90-b4.h"

using namespace std;

bool EncodeSourceData(const char *lpsSource, int ncLength, int nVerGroup, unsigned char *m_byDataCodeWord, int &m_ncDataCodeWordBit)
{
	int m_nBlockLength[2000];
	int m_ncDataBlock;
	unsigned char m_byBlockMode[2000];
	memset(m_nBlockLength, 0, sizeof(m_nBlockLength));

	int i, j;

	// �ɤΥ�`�ɤ�������(�Х���)�@�A���Ƥ��뤫���{��
	for (m_ncDataBlock = i = 0; i < ncLength; ++i)
	{
		BYTE byMode;

		if (i < ncLength - 1 && IsKanjiData(lpsSource[i], lpsSource[i + 1]))
			byMode = QR_MODE_KANJI;
		else if (IsNumeralData(lpsSource[i]))
			byMode = QR_MODE_NUMERAL;
		else if (IsAlphabetData(lpsSource[i]))
			byMode = QR_MODE_ALPHABET;
		else
			byMode = QR_MODE_8BIT;

		if (i == 0)
			m_byBlockMode[0] = byMode;

		if (m_byBlockMode[m_ncDataBlock] != byMode)
			m_byBlockMode[++m_ncDataBlock] = byMode;

		++m_nBlockLength[m_ncDataBlock];

		if (byMode == 3)
		{
			// �h�֤��������ǤϤʤ�	����ӛ�h
			++m_nBlockLength[m_ncDataBlock];
			++i;
		}
	}

	++m_ncDataBlock;

	/////////////////////////////////////////////////////////////////////////
	// �O�Ӥ���Ӣ���֥�`�ɥ֥�å������֥�`�ɥ֥�å��΁K�Ӥ�������ˤ��Y��

	int ncSrcBits, ncDstBits; // Ԫ�Υӥå��L�ȅgһ��Ӣ���֥�`�ɥ֥�å����������ϤΥӥå��L

	int nBlock = 0;

	while (nBlock < m_ncDataBlock - 1)
	{
		int ncJoinFront, ncJoinBehind; // ǰ�᣸�ӥåȥХ��ȥ�`�ɥ֥�å��ȽY�Ϥ������ϤΥӥå��L
		int nJoinPosition = 0; // ���ӥåȥХ��ȥ�`�ɥ֥�å��ȤνY�ϣ�-1=ǰ�ȽY�ϡ�0=�Y�Ϥ��ʤ���1=���ȽY��

							   // �����֣�Ӣ���֡��ޤ��ϡ�Ӣ���֣����֡��΁K��
		if ((m_byBlockMode[nBlock] == 0 && m_byBlockMode[nBlock + 1] == 1) ||
			(m_byBlockMode[nBlock] == 1 && m_byBlockMode[nBlock + 1] == 0))
		{
			// Ԫ�Υӥå��L�ȅgһ��Ӣ���֥�`�ɥ֥�å����������ϤΥӥå��L����^
			ncSrcBits = GetBitLength(m_byBlockMode[nBlock], m_nBlockLength[nBlock], nVerGroup) +
				GetBitLength(m_byBlockMode[nBlock + 1], m_nBlockLength[nBlock + 1], nVerGroup);

			ncDstBits = GetBitLength(1, m_nBlockLength[nBlock] + m_nBlockLength[nBlock + 1], nVerGroup);

			if (ncSrcBits > ncDstBits)
			{
				// ǰ��ˣ��ӥåȥХ��ȥ�`�ɥ֥�å���������ϡ������ȤνY�Ϥ��������ɤ���������å�
				if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 2)
				{
					// ǰ�ˣ��ӥåȥХ��ȥ�`�ɥ֥�å�����
					ncJoinFront = GetBitLength(2, m_nBlockLength[nBlock - 1] + m_nBlockLength[nBlock], nVerGroup) +
						GetBitLength(m_byBlockMode[nBlock + 1], m_nBlockLength[nBlock + 1], nVerGroup);

					if (ncJoinFront > ncDstBits + GetBitLength(2, m_nBlockLength[nBlock - 1], nVerGroup))
						ncJoinFront = 0; // ���ӥåȥХ��ȥ�`�ɥ֥�å��ȤϽY�Ϥ��ʤ�
				}
				else
					ncJoinFront = 0;

				if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 2)
				{
					// ���ˣ��ӥåȥХ��ȥ�`�ɥ֥�å�����
					ncJoinBehind = GetBitLength(m_byBlockMode[nBlock], m_nBlockLength[nBlock], nVerGroup) +
						GetBitLength(2, m_nBlockLength[nBlock + 1] + m_nBlockLength[nBlock + 2], nVerGroup);

					if (ncJoinBehind > ncDstBits + GetBitLength(2, m_nBlockLength[nBlock + 2], nVerGroup))
						ncJoinBehind = 0; // ���ӥåȥХ��ȥ�`�ɥ֥�å��ȤϽY�Ϥ��ʤ�
				}
				else
					ncJoinBehind = 0;

				if (ncJoinFront != 0 && ncJoinBehind != 0)
				{
					// ǰ��I���ˣ��ӥåȥХ��ȥ�`�ɥ֥�å���������Ϥϥǩ`���L���̤��ʤ뷽����
					nJoinPosition = (ncJoinFront < ncJoinBehind) ? -1 : 1;
				}
				else
				{
					nJoinPosition = (ncJoinFront != 0) ? -1 : ((ncJoinBehind != 0) ? 1 : 0);
				}

				if (nJoinPosition != 0)
				{
					// ���ӥåȥХ��ȥ�`�ɥ֥�å��ȤνY��
					if (nJoinPosition == -1)
					{
						m_nBlockLength[nBlock - 1] += m_nBlockLength[nBlock];

						// ��A�򥷥ե�
						for (i = nBlock; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}
					}
					else
					{
						m_byBlockMode[nBlock + 1] = 2;
						m_nBlockLength[nBlock + 1] += m_nBlockLength[nBlock + 2];

						// ��A�򥷥ե�
						for (i = nBlock + 2; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}
					}

					--m_ncDataBlock;
				}
				else
				{
					// Ӣ���֤����֤΁K�Ӥ�gһ��Ӣ���֥�`�ɥ֥�å��˽y��

					if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 1)
					{
						// �Y�Ϥ��褦�Ȥ���֥�å������˾A��Ӣ���֥�`�ɥ֥�å���Y��
						m_nBlockLength[nBlock + 1] += m_nBlockLength[nBlock + 2];

						// ��A�򥷥ե�
						for (i = nBlock + 2; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}

						--m_ncDataBlock;
					}

					m_byBlockMode[nBlock] = 1;
					m_nBlockLength[nBlock] += m_nBlockLength[nBlock + 1];

					// ��A�򥷥ե�
					for (i = nBlock + 1; i < m_ncDataBlock - 1; ++i)
					{
						m_byBlockMode[i] = m_byBlockMode[i + 1];
						m_nBlockLength[i] = m_nBlockLength[i + 1];
					}

					--m_ncDataBlock;

					if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 1)
					{
						// �Y�Ϥ����֥�å���ǰ��Ӣ���֥�`�ɥ֥�å���Y��
						m_nBlockLength[nBlock - 1] += m_nBlockLength[nBlock];

						// ��A�򥷥ե�
						for (i = nBlock; i < m_ncDataBlock - 1; ++i)
						{
							m_byBlockMode[i] = m_byBlockMode[i + 1];
							m_nBlockLength[i] = m_nBlockLength[i + 1];
						}

						--m_ncDataBlock;
					}
				}

				continue; // �F��λ�äΥ֥�å������{��
			}
		}

		++nBlock; // �Υ֥�å����{��
	}

	/////////////////////////////////////////////////////////////////////////
	// �B�A����̤���`�ɥ֥�å��򣸥ӥåȥХ��ȥ�`�ɥ֥�å���

	nBlock = 0;

	while (nBlock < m_ncDataBlock - 1)
	{
		ncSrcBits = GetBitLength(m_byBlockMode[nBlock], m_nBlockLength[nBlock], nVerGroup)
			+ GetBitLength(m_byBlockMode[nBlock + 1], m_nBlockLength[nBlock + 1], nVerGroup);

		ncDstBits = GetBitLength(2, m_nBlockLength[nBlock] + m_nBlockLength[nBlock + 1], nVerGroup);

		// ǰ�ˣ��ӥåȥХ��ȥ�`�ɥ֥�å���������ϡ����}���륤�󥸥��`���֤�p��
		if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 2)
			ncDstBits -= (4 + nIndicatorLen8Bit[nVerGroup]);

		// ���ˣ��ӥåȥХ��ȥ�`�ɥ֥�å���������ϡ����}���륤�󥸥��`���֤�p��
		if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 2)
			ncDstBits -= (4 + nIndicatorLen8Bit[nVerGroup]);

		if (ncSrcBits > ncDstBits)
		{
			if (nBlock >= 1 && m_byBlockMode[nBlock - 1] == 2)
			{
				// �Y�Ϥ���֥�å���ǰ�ˤ��룸�ӥåȥХ��ȥ�`�ɥ֥�å���Y��
				m_nBlockLength[nBlock - 1] += m_nBlockLength[nBlock];

				// ��A�򥷥ե�
				for (i = nBlock; i < m_ncDataBlock - 1; ++i)
				{
					m_byBlockMode[i] = m_byBlockMode[i + 1];
					m_nBlockLength[i] = m_nBlockLength[i + 1];
				}

				--m_ncDataBlock;
				--nBlock;
			}

			if (nBlock < m_ncDataBlock - 2 && m_byBlockMode[nBlock + 2] == 2)
			{
				// �Y�Ϥ���֥�å������ˤ��룸�ӥåȥХ��ȥ�`�ɥ֥�å���Y��
				m_nBlockLength[nBlock + 1] += m_nBlockLength[nBlock + 2];

				// ��A�򥷥ե�
				for (i = nBlock + 2; i < m_ncDataBlock - 1; ++i)
				{
					m_byBlockMode[i] = m_byBlockMode[i + 1];
					m_nBlockLength[i] = m_nBlockLength[i + 1];
				}

				--m_ncDataBlock;
			}

			m_byBlockMode[nBlock] = 2;
			m_nBlockLength[nBlock] += m_nBlockLength[nBlock + 1];

			// ��A�򥷥ե�
			for (i = nBlock + 1; i < m_ncDataBlock - 1; ++i)
			{
				m_byBlockMode[i] = m_byBlockMode[i + 1];
				m_nBlockLength[i] = m_nBlockLength[i + 1];
			}

			--m_ncDataBlock;

			// �Y�Ϥ����֥�å���ǰ�������{��
			if (nBlock >= 1)
				--nBlock;

			continue;
		}

		++nBlock; // �Υ֥�å����{��
	}

	/////////////////////////////////////////////////////////////////////////
	// �ӥå����л�
	int ncComplete = 0; // �I��g�ǩ`��������
	WORD wBinCode;

	m_ncDataCodeWordBit = 0; // �ӥåȅgλ�I������

	memset(m_byDataCodeWord, 0, 2000);

	for (i = 0; i < m_ncDataBlock && m_ncDataCodeWordBit != -1; ++i)
	{
		if (m_byBlockMode[i] == 0)
		{
			/////////////////////////////////////////////////////////////////
			// ���֥�`��

			// ���󥸥��`��(0001b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 1, 4, m_byDataCodeWord);

			// ���������å�
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)m_nBlockLength[i], nIndicatorLenNumeral[nVerGroup], m_byDataCodeWord);

			// �ӥå��б���
			for (j = 0; j < m_nBlockLength[i]; j += 3)
			{
				if (j < m_nBlockLength[i] - 2)
				{
					wBinCode = (WORD)(((lpsSource[ncComplete + j] - '0') * 100) +
						((lpsSource[ncComplete + j + 1] - '0') * 10) +
						(lpsSource[ncComplete + j + 2] - '0'));

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 10, m_byDataCodeWord);
				}
				else if (j == m_nBlockLength[i] - 2)
				{
					// �������Х���
					wBinCode = (WORD)(((lpsSource[ncComplete + j] - '0') * 10) +
						(lpsSource[ncComplete + j + 1] - '0'));

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 7, m_byDataCodeWord);
				}
				else if (j == m_nBlockLength[i] - 1)
				{
					// �������Х���
					wBinCode = (WORD)(lpsSource[ncComplete + j] - '0');

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 4, m_byDataCodeWord);
				}
			}

			ncComplete += m_nBlockLength[i];
		}

		else if (m_byBlockMode[i] == 1)
		{
			/////////////////////////////////////////////////////////////////
			// Ӣ���֥�`��

			// ��`�ɥ��󥸥��`��(0010b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 2, 4, m_byDataCodeWord);

			// ���������å�
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)m_nBlockLength[i], nIndicatorLenAlphabet[nVerGroup], m_byDataCodeWord);

			// �ӥå��б���
			for (j = 0; j < m_nBlockLength[i]; j += 2)
			{
				if (j < m_nBlockLength[i] - 1)
				{
					wBinCode = (WORD)((AlphabetToBinaly(lpsSource[ncComplete + j]) * 45) +
						AlphabetToBinaly(lpsSource[ncComplete + j + 1]));

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 11, m_byDataCodeWord);
				}
				else
				{
					// �������Х���
					wBinCode = (WORD)AlphabetToBinaly(lpsSource[ncComplete + j]);

					m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 6, m_byDataCodeWord);
				}
			}

			ncComplete += m_nBlockLength[i];
		}

		else if (m_byBlockMode[i] == 2)
		{
			/////////////////////////////////////////////////////////////////
			// ���ӥåȥХ��ȥ�`��

			// ��`�ɥ��󥸥��`��(0100b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 4, 4, m_byDataCodeWord);

			// ���������å�
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)m_nBlockLength[i], nIndicatorLen8Bit[nVerGroup], m_byDataCodeWord);

			// �ӥå��б���
			for (j = 0; j < m_nBlockLength[i]; ++j)
			{
				m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)lpsSource[ncComplete + j], 8, m_byDataCodeWord);
			}

			ncComplete += m_nBlockLength[i];
		}
		else // m_byBlockMode[i] == 3
		{
			/////////////////////////////////////////////////////////////////
			// �h�֥�`��

			// ��`�ɥ��󥸥��`��(1000b)
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, 8, 4, m_byDataCodeWord);

			// ���������å�
			m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, (WORD)(m_nBlockLength[i] / 2), nIndicatorLenKanji[nVerGroup], m_byDataCodeWord);

			// �h�֥�`�ɤǥӥå��б���
			for (j = 0; j < m_nBlockLength[i] / 2; ++j)
			{
				WORD wBinCode = KanjiToBinaly((WORD)(((BYTE)lpsSource[ncComplete + (j * 2)] << 8) + (BYTE)lpsSource[ncComplete + (j * 2) + 1]));

				m_ncDataCodeWordBit = SetBitStream(m_ncDataCodeWordBit, wBinCode, 13, m_byDataCodeWord);
			}

			ncComplete += m_nBlockLength[i];
		}
	}

	return (m_ncDataCodeWordBit != -1);
}

bool IsNumeralData(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return true;

	return false;
}
bool IsAlphabetData(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return true;

	if (c >= 'A' && c <= 'Z')
		return true;

	if (c == ' ' || c == '$' || c == '%' || c == '*' || c == '+' || c == '-' || c == '.' || c == '/' || c == ':')
		return true;

	return false;
}
bool IsKanjiData(unsigned char c1, unsigned char c2)
{
	if (((c1 >= 0x81 && c1 <= 0x9f) || (c1 >= 0xe0 && c1 <= 0xeb)) && (c2 >= 0x40))
	{
		if ((c1 == 0x9f && c2 > 0xfc) || (c1 == 0xeb && c2 > 0xbf))
			return false;

		return true;
	}

	return false;
}

unsigned short AlphabetToBinaly(unsigned char c)
{
	if (c >= '0' && c <= '9') return (unsigned char)(c - '0');

	if (c >= 'A' && c <= 'Z') return (unsigned char)(c - 'A' + 10);

	if (c == ' ') return 36;

	if (c == '$') return 37;

	if (c == '%') return 38;

	if (c == '*') return 39;

	if (c == '+') return 40;

	if (c == '-') return 41;

	if (c == '.') return 42;

	if (c == '/') return 43;

	return 44; // c == ':'
}
unsigned short KanjiToBinaly(unsigned short wc)
{
	if (wc >= 0x8140 && wc <= 0x9ffc)
		wc -= 0x8140;
	else // (wc >= 0xe040 && wc <= 0xebbf)
		wc -= 0xc140;

	return (unsigned short)(((wc >> 8) * 0xc0) + (wc & 0x00ff));
}

int GetBitLength(BYTE nMode, int ncData, int nVerGroup)
{
	int ncBits = 0;

	switch (nMode)
	{
	case 0:
		ncBits = 4 + nIndicatorLenNumeral[nVerGroup] + (10 * (ncData / 3));
		switch (ncData % 3)
		{
		case 1:
			ncBits += 4;
			break;
		case 2:
			ncBits += 7;
			break;
		default: // case 0:
			break;
		}

		break;

	case 1:
		ncBits = 4 + nIndicatorLenAlphabet[nVerGroup] + (11 * (ncData / 2)) + (6 * (ncData % 2));
		break;

	case 2:
		ncBits = 4 + nIndicatorLen8Bit[nVerGroup] + (8 * ncData);
		break;

	default: // case QR_MODE_KANJI:
		ncBits = 4 + nIndicatorLenKanji[nVerGroup] + (13 * (ncData / 2));
		break;
	}

	return ncBits;
}
int SetBitStream(int nIndex, unsigned short wData, int ncData, unsigned char *m_byDataCodeWord)
{
	int i;

	if (nIndex == -1 || nIndex + ncData > 2000 * 8)
		return -1;

	for (i = 0; i < ncData; ++i)
	{
		if (wData & (1 << (ncData - i - 1)))
		{
			m_byDataCodeWord[(nIndex + i) / 8] |= 1 << (7 - ((nIndex + i) % 8));
		}
	}

	return nIndex + ncData;
}

void Format_Info(const int m_nVersion, const int nPatternNo, unsigned char(*m_byModuleData)[MAX_MODULESIZE])
{
	int nFormatInfo = 0x10;// H-level
	int m_nSymbleSize = m_nVersion * 4 + 17;
	int i;

	nFormatInfo += nPatternNo;

	int nFormatData = nFormatInfo << 10;

	// ����ӥå����
	for (i = 0; i < 5; ++i)
	{
		if (nFormatData & (1 << (14 - i)))
		{
			nFormatData ^= (0x0537 << (4 - i)); // 10100110111b
		}
	}

	nFormatData += nFormatInfo << 10;

	// �ޥ�����
	nFormatData ^= 0x5412; // 101010000010010b

						   // ����λ�×ʳ��ѥ��`���ܤ�����
	for (i = 0; i <= 5; ++i)
		m_byModuleData[8][i] = (nFormatData & (1 << i)) ? fun_Black : fun_White;

	m_byModuleData[8][7] = (nFormatData & (1 << 6)) ? fun_Black : fun_White;
	m_byModuleData[8][8] = (nFormatData & (1 << 7)) ? fun_Black : fun_White;
	m_byModuleData[7][8] = (nFormatData & (1 << 8)) ? fun_Black : fun_White;

	for (i = 9; i <= 14; ++i)
		m_byModuleData[14 - i][8] = (nFormatData & (1 << i)) ? fun_Black : fun_White;

	// ����λ�×ʳ��ѥ��`��������
	for (i = 0; i <= 7; ++i)
		m_byModuleData[m_nSymbleSize - 1 - i][8] = (nFormatData & (1 << i)) ? fun_Black : fun_White;

	// ����λ�×ʳ��ѥ��`��������
	m_byModuleData[8][m_nSymbleSize - 8] = fun_Black; // �̶����⥸��`��

	for (i = 8; i <= 14; ++i)
		m_byModuleData[8][m_nSymbleSize - 15 + i] = (nFormatData & (1 << i)) ? fun_Black : fun_White;
}
void Version_Info(const int m_nVersion, unsigned char(*m_byModuleData)[MAX_MODULESIZE])
{
	const int m_nSymbleSize = m_nVersion * 4 + 17;
	int i, j;

	if (m_nVersion <= 6)
		return;

	int nVerData = m_nVersion << 12;

	// ����ӥå����
	for (i = 0; i < 6; ++i)
	{
		if (nVerData & (1 << (17 - i)))
		{
			nVerData ^= (0x1f25 << (5 - i));
		}
	}

	nVerData += m_nVersion << 12;

	for (i = 0; i < 6; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			m_byModuleData[m_nSymbleSize - 11 + j][i] = m_byModuleData[i][m_nSymbleSize - 11 + j] =
				(nVerData & (1 << (i * 3 + j))) ? fun_Black : fun_White;
		}
	}

}
