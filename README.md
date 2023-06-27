# libft
Re-writing some useful libc's functions
```C
int    ft_atoi(char const *nptr)                   -> converting a string to a int
void   ft_bzero(void *s, size_t n)                 -> filling 's' ptr as an unsigned char by zeros (null)
void   *ft_calloc(size_t nmemb, size_t size)       -> It's similar to malloc but it's filling the ptr with zeros
char   *ft_itoa(int n)                             -> converting a int to a malloced string
char   **ft_split(char const *s, char c)           -> returning a array with strings that splitted by the char c
char   *ft_strchr(const char *s, int c)            -> if the char 'c' founded in the string s then return a string that start with c and end with end of s (s + i(index of i)) else return NULL
char   *ft_strrchr(const char *s, int c)           -> same as strchr but returns s from righ to the left
char   *ft_strdup(const char *s)                   -> malloc a string with size of (s) and copy the chars in (s) to it then return's it
char   *ft_strjoin(char const *s1, char const *s2) -> returns a malloced string of (s1 + s2)

```
