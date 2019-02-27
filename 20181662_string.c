int strlen(const char *str)
{
	int i;
	//NULL이 아닌 문자가 나올 때 까지 증가한 i의 값을 문자열의 길이로 리턴한다. 
	while(*(str + i) != '\0')
	{
		i++;
	}
	return i;
}

char* strcpy(char* to_str, const char* from_str)
{
	int i;
	int len;
	i = 0;
	//to_str의 문자열의 길이를 len으로 구한다. 
	while(*(from_str + i) != '\0')
	{
		i++;
		len++;
	}
	//배열의 각 자리에 대해 from_str의 값을 같은 자리의 to_str 대입시킨다. 
	for(i = 0; i < len; i++)
	{
		*(to_str + i) = *(from_str + i);
	}
	//to_str의 값을 from_str의 값으로 모두 대체한 후 마지막에 NULL을 넣어 문자열의 끝을 알린다.
	*(to_str + len) = '\0';

	return to_str;
}

char* strncpy(char* to_str, const char* from_str, int size)
{
	int i;
	//from_str의 값을 처음부터 size만큼의 값 까지만 to_str에 대입시킨다. 
	for(i = 0; i < size; i++)
	{
		*(to_str + i) = *(from_str + i);
	}
	//(추가구현) 만약 size가 from_str의 길이보다 작다면 NULL문자가 to_str에 들어가지 않으므로 to_str의 값을 from_str의 값으로  size만큼대체시킨 후 마지막에 NULL을 넣어 문자열의 끝을 알린다. 
	if(size < strlen(from_str))
	{
		*(to_str + size) = '\0';
	}
	*(to_str + size) = '\0';
	
	return to_str;
}

int strcmp(const char* string1, const char* string2)
{
	int i;
	int len;
	//string1과 string2 중 더 긴 문자열의 길이를 len으로 설정한다. 
	if(strlen(string1) < strlen(string2))
	{
		len = strlen(string2);
	}
	else
	{
		len = strlen(string1);
	}
	//더 긴 문자열의 길이인 len만큼 두 문자열의 대소관계를 비교한다. string1이 더 크다면 1을, string2가 더 크다면 -1을, len만큼 비교했을 때 모두 같다면 0을 리턴한다. 
	for(i = 0; i < len; i++)
	{
		if(*(string1 + i) - *(string2 + i) < 0)
		{
			return -1;
			
		}
		else if(*(string1 + i) - *(string2 + i) > 0)
		{
			return 1;
			
		}
	}
	return 0;
}

int strncmp(const char* string1, const char* string2, int size)
{
	int len1, len2;
	len1 = 0; len2 = 0;
	int i = 0;
	//string1과 string2의 길이를 각각 len1과 len2로 설정한다. 
	while(*(string1 + i) != '\0')
	{
		i++;
		len1++;
	}
	i = 0;
	while(*(string2 + i) != '\0')
	{
		i++;
		len2++;
	}
	//(추가구현)만약 입력받은 size가 len1이나 len2보다 크다면, len1과 len2 중 더 큰 값을 비교할 size로 설정한다. 
	if(size > len1 || size > len2)
	{
		if(len1 > len2)
		{
			size = len1;
		}
		else
		{
			size = len2;
		}
	}
	//size만큼 두 문자열을 비교해 string1이 string2보다 크다면 1을, 작다면 -1을, 같다면 0을 리턴한다. 
	for(i = 0; i < size; i++)
	{
		if(*(string1+i)!=*(string2+i))
		{
			if((*(string1 + i) - *(string2 + i)) < 0)
			{
				return -1;
			}
			else if((*(string1 + i) - *(string2 + i)) > 0)
			{
				return 1;
			}
		}
	}
	return 0;
	
}

char* strcat(char* string1, const char* string2)
{
	int i = 0;
	int len, len2;
	len = 0; len2 = 0;
	//string1과 string2의 길이를 각각 len과 len2로 설정한다. 
	while(*(string1 + i) != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	while(*(string2 + i) != '\0')
	{
		len2++;
		i++;
	}
	//string1에 할당된 메모리를 len + len2 + 1로 설정한다. len + len2는 두 문자열의 내용을 모두 담기  위함이고, + 1은 문자열의 끝에 NULL을 넣으려는 의도이다. 
	string1 = (char *) realloc(string1, sizeof(char) * (len + len2 + 1));
	//strin1의 기존 NULL문자 자리부터 string2의 내용을 담는다. 내용이 모두 들어간 후 문자열의 끝에 NULL을 넣어준다.
	for(i = 0; i < len2; i++)
	{
		*(string1 + len + i) = *(string2 + i);
	}
	*(string1 + len + i + 1) = '\0';

	return string1;
}

char* strncat(char* string1, const char* string2, int size)
{
	int i = 0;
	int len1 = 0;
	//string1의 길이를 len1으로 설정한다. 
	while(*(string1 + i) != '\0')
	{
		len1++;
		i++;
	}
	i = 0;
	//string1의 길이를 len1 + size + 1로 설정한다. len1 + size는 string1의 내용과 size만큼의 string2의 내용을 담기 위함이다.
	string1 = (char*) realloc(string1, sizeof(char) * (len1 + size + 1));

	for(i = 0; i < size; i++)
	{
		*(string1 + len1 + i) = *(string2 + i);
	}
	*(string1 + len1 + i ) = '\0';

	return string1;
}

char* strtok(char* str, const char* delim)
{
	int i = 0; int j = 0;
	int count = 0;
	int len1 = 0;
	int len2 = 0;
	//str과 delim의 길이를 각각 len1과 len2로 설정한다. 
	while(*(str + i) != '\0')
	{
		len1++;
		i++;
	}
	i = 0;
	while(*(delim + i) != '\0')
	{
		len2++;
		i++;
	}
	//str의 각 문자에 대해서 delim에 있는 각 문자와 같은 문자가 있는지 확인한 후, 같은 문자가 있다면 그 문자를 NULL로 교체한다. 
	for(i = 0; i < len1; i++)
	{
		for(j = 0; j < len2; j++)
		{
			if(*(str + i) == *(delim + j))
			{
				*(str + i) = '\0';
				continue;
			}
		}
	}

	return str;
}

