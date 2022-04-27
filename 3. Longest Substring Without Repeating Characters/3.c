int lengthOfLongestSubstring(char * s){
    int seen[130] = {0};
    if (s[0] == '\0')
	    return 0;
    
    int maxLength = 0;
    char *head = s;
    char *tail = s;
    while (*tail!='\0')
    {
        while(seen[*tail] != 0)
        {
            seen[*head] = 0;
            head ++;
        }
            
        maxLength = (tail - head + 1) > maxLength ? (tail - head + 1) : maxLength;
        seen[*tail] = maxLength;
        tail++;
    }
    return maxLength;
}