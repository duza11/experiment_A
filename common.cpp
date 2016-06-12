#include "common.h"

void SplitString(string & input_str, vector<string> & str_array, int length)
{
	int byte_size;
	int length_temp = 0;
	int now_select = 0;

	char *locale = setlocale(LC_ALL, NULL);
	setlocale(LC_CTYPE, "jpn");

	for (int i = 0; i < input_str.size(); i += byte_size)
	{
		byte_size = mblen(&input_str[i], MB_CUR_MAX);
		length_temp += byte_size;
		if (length_temp == length || length_temp == length + 1 || i == input_str.size() - 1 || (i == input_str.size() - 2 && byte_size == 2))
		{
			if (length_temp == length + 1)
			{
				length_temp -= byte_size;
				byte_size = 0;
			}
			str_array.push_back(input_str.substr(now_select, length_temp));
			now_select += length_temp;
			length_temp = 0;
		}
	}

	setlocale(LC_CTYPE, locale);
}
