## Note on string and time complexity

```
    // Toggle
    char s1[] = "WeLcOmE";
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s1[i] >= 65 && s1[i] <= 90) // if the char is in upper
        {
            s1[i] += 32; // convert lower
        }
        else if(s1[i] >= 97 && s1[i] <= 122)
        {
            s1[i] -= 32;
        }
    }
```