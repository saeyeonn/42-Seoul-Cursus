<div align=center >
<h1>libft_</h1>
<img src="https://github.com/saeyeonn/42_cursus/blob/main/srcs/libftm.png?raw=true">
</div>

<br/>

##### Your very first own library

##### Summary: This project aims to code a C library regrouping usual functions that you'll be use for all your next projects.


<br>

# Contents

| Chapter | Contents                                          | page |
| :-----: | :------------------------------------------------ | :--: |
|    1    | [**Introduction**](#Chapter-1)                    |  2   |
|    2    | [**Common Instrunctions**](#Chapter-2)            |  3   |
|    3    | [**Mandatory part**](#Chapter-3)                  |  4   |
|   3.1   | [**Technical Considerations**](#Chapter-3-1)      |  4   |
|   3.2   | [**Part 1 - Libc functions**](#Chapter-3-2)       |  5   |
|   3.3   | [**Part 2 - Additional functions**](#Chapter-3-3) |  6   |
|    4    | [**Bonus part**](#Chapter-4)                      |  10  |

<br>

# **Chapter 1**

## Introduction

<br>

##### C programming can be very tedious when one doesn't have access to those highly useful standard functions. This project allows you to re-write those functions, understand them, and learn to use them. This library will help you with all your future C projects. Take the time to expand your `libft_` throughout the year. But always, make sure to check which functions are allowed !


<br>

# **Chapter 2**

## Common Instructions

- ##### Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.

  
- ##### Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.

  
- ##### All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.

  
- ##### If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink.

  
- ##### Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

 
- ##### To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \bonus.{c/h}. Mandatory and bonus part evaluation is done separately.

 
- ##### If your project allows you to use your libft_, you must copy its sources and its associated Makefile in a libft_ folder with its associated Makefile. Your project's Makefile must compile the library by using its Makefile, then compile the project.

- ##### We encourage you to create test programs for your project even though this work won't have to be submitted and won't be graded. It will give you a chance to easily test your work and your peers' work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.

- ##### Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done aft_er your peer-evaluations. If an error happens in any section of your work during Deepthought's grading, the evaluation will stop.

<br>

# Chapter 3

## Mandatory part

| **Program name**          | libft_.a                                                                                          |
| ------------------------- | ------------------------------------------------------------------------------------------------ |
| **Turn in files**         | `*.c, libft_.h, Makefile`                                                                         |
| **Makefile**              | NAME, all, clean, fclean, re                                                                     |
| **External<br>functions** | Detailed below                                                                                   |
| **Description**           | Write your own library:<br>a collection of functions that will be a useful tool for your cursus. |

<br>

## 3.1 Technical considerations

- ##### It is forbidden to declare global variables.


- ##### If you need subfunctions to write a complex function, you should define these subfunctions as `static` to avoid publishing them with your library. It would be a good habit to do this in your future projects as well.


- ##### Submit all files in the root of your repository.


- ##### It is forbidden to submit unused files.

- ##### Every .c must compile with flags.


- ##### You must use the command `ar` to create your library, using the command `libtool` is forbidden.


<br>

## 3.2 Part 1 - Libc functions

##### In this first part, you must re-code a set of the `libc` functions, as defined in their `man`. Your functions will need to present the same prototype and behaviors as the originals. Your functions' names must be prefixed by "`ft_`". For instance, `strlen`becomes`ft_strlen`.
<br>

> ⚠️
>
> ##### Some of the functions' prototypes you have to re-code use the "restrict" qualifier. This keyword is part of the c99 standard. It is therefore forbidden to include it in your prototypes and to compile it with the flag `-std=c99`.
><br>
>

<br>

##### You must re-code the following functions. These function do not need any external functions :


- `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
- `strlen`, `memset`, `bzero`, `memcpy`, `memmove`, `strlcpy`, `strlcat`, `strncmp`
- `toupper`, `tolower`, `strchr`, `strrchr`
- `memchr`, `memcmp`, `strnstr`, `atoi`

##### You must also re-code the following functions, using the function "`malloc`":

- `calloc`, `strdup`

<br>

## 3.3 Part 2 - Additional functions

##### In this second part, you must code a set of functions that are either not included in the `libc`, or included in a different form. Some of these functions can be useful to write Part 1's functions.

<br>

| **Function name**                | ft_substr                                                                                                                                                                                                                                                                                                                                |
| ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `char *ft_substr(char const *s, unsigned int start, sizet len);`                                                                                                                                                                                                                                                                        |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                        |
| **Parameters**                 |s : The string from which to create the substring.<br>start : The start index of the substring in the string 's'.<br>len : The maximum length of the substring.                                                                                                                                                                                                    |
| **Return value**                   | The substring.<br>NULL if the allocation fails.                                                                                                                                                                                                                                                                                          |
| **External<br>functions** | `malloc`                                                                                                                                                                                                                                                                                                                                 |
| **Description**                     | Allocates (with malloc(3)) and returns a substring from the string 's'. The substring begins at index 'start' and is of maximum size 'len'.|

<br>

| **Function name**                | ft_strjoin                                                                                                                                                                                                                                |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `char *ft_strjoin(char const *s1, char const *s2);`                                                                                                                                                                                       |
| **Turn in files**              | -                                                                                                                                                                                                                                         |
| **Parameters**                 | s1: The prefix string.<br>s2: The suffix string.`                                                                                                                                                                  |
| **Return value**                   |The substring.<br>NULL if the allocation fails.                                                                                                                                                                                                     |
| **External functions** | `malloc`                                                                                                                                                                                                                                  |
| **Description**                     | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of 's1' and 's2'.|

<br>

| **Function name**                | ft_strtrim                                                                                                                                                                                                                                                                           |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **Prototype**               | `char *ft_strtrim(char const *s1, char const *set);`                                                                                                                                                                                                                                 |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                    |
| **Parameters**                 | s1: The string to be trimmed.<br>set: The reference set of characters to trim.                                                                                                                                                                                     |
| **Return value**                   |The trimmed string.
<br>NULL if the allocation fails.                                                                                                                                                                                                                                           |
| **External functions** | `malloc`                                                                                                                                                                                                                                                                             |
| **Description**                     | Allocates (with malloc(3)) and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string.|

<br>

| **Function name**                | ft_split                                                                                                                                                                                                                                                                                                                                                                  |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `char **ft_split(char const *s, char c);`                                                                                                                                                                                                                                                                                                                                 |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                                                         |
| **Parameters**                 | s : The string to be split.<br>c : The delimiter character.`                                                                                                                                                                                                                                                                                                                         |
| **Return value**                   | The array of new strings resulting from the split.
<br>NULL if the allocation fails.                                                                                                                                                                                                                                                                                                                   |
| **External functions** | `malloc, free`                                                                                                                                                                                                                                                                                                                                                            |
| **Description**                     | Allocates (with malloc(3)) and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. The array must be ended by a NULL pointer. |

<br>

| **Function name**                | ft_itoa                                                                                                                                                                                                                                                                       |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `char *ft_itoa(int n);`                                                                                                                                                                                                                                                       |
| **Turn in files**              | -                                                                                                                                                                                                                                                                             |
| **Parameters**                 | n : the integer to convert.                                                                                                                                                                                                                             |
| **Return value**                   | The string representing the integer.<br>NULL if the allocation fails.                                                                                                                                                                                                                                  |
| **External functions** | `malloc`                                                                                                                                                                                                                                                                      |
| **Description**                     | Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled. |

<br>

| **Function name**                | ft_strmapi                                                                                                                                                                                                                                                                                                                                                                                                       |
| ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`                                                                                                                                                                                                                                                                                                                                                |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                                                                                                |
| **Parameters**                 | s : The string on which to iterate.<br>f : The function to apply to each character.                                                                                                                                                                                                                                                                                                                                             |
| **Return value**                   |The string created from the successive applications
of 'f'. <br>NULL if the allocation fails.                                                                                                                                                                                                                                                                                                                          |
| **External functions** | `malloc`                                                                                                                                                                                                                                                                                                                                                                                                         |
| **Description**                     | Applies the function 'f' to each character of the string 's' , and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of 'f'.|

<br>

| **Function name**                | ft_striteri                                                                                                                                                                                                                                                                                                                                                                                                    |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_striteri(char *s, void (*f)(unsigned int, char*));`                                                                                                                                                                                                                                                                                                                                                   |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Parameter**                 | s : The string on which to iterate.<br>f : The function to apply to each character.                                                                                                                                                                                                                                                                                                                                           |
| **Return value**                   | -                                                                                                                                                                                                                                                                                                                                                                                                         |
| **External functions** | -                                                                                                                                                                                                                                                                                                                                                                                                         |
| **Description**                     | Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary  |

<br>

| **Function name**                | ft_putcharfd                                                                                                  |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_putcharfd(char c, int fd);`                                                                          |
| **Turn in files**              | -                                                                                                              |
| **Parameter**                 | c : The character to output.<br>fd : The file descriptor on which to write.                                         |
| **Return value**                   | -                                                                                                         |
| **External functions** | `write`                                                                                                        |
| **Description**                     | Outputs the character 'c' to the given file descriptor. |

<br>

| **Function name**                | ft_putstrfd                                                                                                  |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_putstrfd(char *s, int fd);`                                                                         |
| **Turn in files**              | -                                                                                                             |
| **Parameter**                 | s : The string to output.<br>fd : The file descriptor on which to write.                                      |
| **Return value**                   | -                                                                                                        |
| **External functions** | `write`                                                                                                       |
| **Description**                     | Outputs the string 's' to the given file descriptor. |

<br>

| **Function name**                | ft_putendlfd                                                                                                                                         |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_putendlfd(char *s, int fd);`                                                                                                                |
| **Turn in files**              | -                                                                                                                                                     |
| **Parameter**                 | s : The string to output.<br>fd : The file descriptor on which to write.                                                                              |
| **Return value**                   | -                                                                                                                                                |
| **External functions** | `write`                                                                                                                                               |
| **Description**                     | Outputs the string 's' to the given file descriptor, followed by a newline. |

<br>

| **Function name**                | ft_putnbrfd                                                                                                 |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------ |
| **Prototype**               | `void ft_putnbrfd(int n, int fd);`                                                                          |
| **Turn in files**              | -                                                                                                            |
| **Parameter**                 | n : The integer to output.<br>fd : The file descriptor on which to write.                                       |
| **Return value**                   | -                                                                                                       |
| **External functions** | `write`                                                                                                      |
| **Description**                     | Outputs the integer 'n' to the given file descriptor. |

<br>

# Chapter 4

## Bonus part

##### If you completed the mandatory part, you'll enjoy taking it further. You can see this last section as Bonus Points.


##### Having functions to manipulate memory and strings is very useful, but you'll soon discover that having functions to manipulate lists is even more useful.


##### `make bonus` will add the bonus functions to the `libft_.a` library.


##### You'll use the following structure to represent the elements of your list. This structure must be added to your `libft_.h` file.
<br>

```c
typedef struct slist
{
    void          *content;
    struct slist *next;
}              tlist;
```

##### Here is a description of the fields of the tlist struct:


- ##### `content` : The data contained in the element. The `void *` allows to store any kind of data.


- ##### `next` : The next element's address or `NULL` if it's the last element.

##### The following functions will allow you to easily use your lists.


<br>

| **Function name**                | ft_lstnew                                                                                                                                                                                                                                                                                                                                                                                 |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `tlist *ft_lstnew(void *content);`                                                                                                                                                                                                                                                                                                                                                       |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                                                                         |
| **Parameter**                 | content : The content to create the node with.                                                                                                                                                                                                                                                                                                                               |
| **Return value**                   | `The new node`                                                                                                                                                                                                                                                                                                                                                                   |
| **External functions** | `malloc`                                                                                                                                                                                                                                                                                                                                                                                  |
| **Description**                     | Allocates (with malloc(3)) and returns a new element. The variable 'content' is initialized with the value of the parameter 'content'. The variable 'next' is initialized to NULL.\  |

<br>

| **Function name**                | ft_lstaddfront                                                                                         |
| ---------------------------- | ------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_lstaddfront(tlist **lst, tlist *new);`                                                      |
| **Turn in files**              | -                                                                                                       |
| **Parameter**                 | lst : The address of a pointer to the first link of a list.<br> new : The address of a pointer to the node to be added to the list.        |
| **Return value**                   | -                                                                                                  |
| **External functions** | -                                                                                                  |
| **Description**                     | Adds the element 'new' at the beginning of the list. <br>  |

<br>

| **Function name**                | ft_lstsize                                                                              |
| ---------------------------- | --------------------------------------------------------------------------------------- |
| **Prototype**               | `int ft_lstsize(tlist *lst);`                                                          |
| **Turn in files**              | -                                                                                       |
| **Parameter**                 | lst : The beginning of the list.                                                      |
| **Return value**                   | The length of the list                                                                         |
| **External functions** | -                                                                                  |
| **Description**                     | Counts the number of elements in a list.  |

<br>

| **Function name**                | ft_lstlast                                                                                    |
| ---------------------------- | --------------------------------------------------------------------------------------------- |
| **Prototype**               | `tlist *ft_lstlast(tlist *lst);`                                                            |
| **Turn in files**              | -                                                                                             |
| **Parameter**                 | lst : The beginning of the list.                                                            |
| **Return value**                   | Last nodeof the list                                                                     |
| **External functions** | -                                                                                        |
| **Description**                     | Returns the last element of the list. |

<br>

| **Function name**                | ft_lstaddback                                                                                    |
| ---------------------------- | ------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_lstaddback(tlist **lst, tlist *new);`                                                 |
| **Turn in files**              | -                                                                                                 |
| **Parameter**                 | lst : The address of a pointer to the first link of a list.<br>new : The address of a pointer to the node to be added to the list.                 |
| **Return value**                   | -                                                                                            |
| **External functions** | -                                                                                            |
| **Description**                     | Adds the element 'new' at the end of the list.  |

<br>

| **Function name**                |ft_lstdelone                                                                                                                                                                                                                                                                                                                                                      |
| ---------------------------- |--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_lstdelone(tlist *lst, void (*del)(void *));`                                                                                                                                                                                                                                                                                                            |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                                                 |
| **Parameter**                 | lst : The node to free.<br>del : The address of the function used to delete                                                                                                                                                                                                                                                                                             |
| **Return value**                   | -                                                                                                                                                                                                                                                                                                                                                            |
| **External functions** | `free`                                                                                                                                                                                                                                                                                                                                                            |
| **Description**                     | Takes as a parameter an element and frees the memory of the element's content using the function 'del' given as a parameter and free the element. <br> The memory of 'next' must not be freed. |

<br>

| **Function name**                | ft_lstclear                                                                                                                                                                                                                                                                                                                                                 |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_lstclear(tlist **lst, void (*del)(void *));`                                                                                                                                                                                                                                                                                                      |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                                           |
| **Parameter**                 | lst : The address of a pointer to a node.<br>del : The address of the function used to delete the content.                                                                                                                                                                                                                       |
| **Return value**                   | -                                                                                                                                                                                                                                                                                                                                                      |
| **External functions** | `free`                                                                                                                                                                                                                                                                                                                                                      |
| **Description**                     | Deletes and frees the given element and every successor of that element, using the function 'del' and free(3). Finally, the pointer to the list must be set to NULL. |

<br>

| **Function name**                | ft_lstiter                                                                                                                                                                                          |
| ---------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `void ft_lstiter(tlist *lst, void (*f)(void *));`                                                                                                                                                  |
| **Turn in files**              | -                                                                                                                                                                                                   |
| **Parameter**                 | lst : The address of a pointer to a node.
<br>f : The address of the function used to iterate on the list.                                                                                                                                |
| **Return value**                   | -                                                                                                                                                                                              |
| **External functions** | -                                                                                                                                                                                              |
| **Description**                     | Iterates the list 'lst' and applies the function 'f' to the content of each element.|

<br>

| **Function name**             | ft_lstmap                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| ---------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**               | `tlist *ft_lstmap(tlist *lst, void *(*f)(void *), void (*del)(void *));`                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **Turn in files**              | -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| **Parameter**                 | lst : The address of a pointer to a node.<br>f : The address of the function used to iterate on the list.<br>del : The address of the function used to delete the content of a node if needed.                                                                                                                                                                                                                                                                                                                               |
| **Return value**                   | The new list.<br>NULL if the allocation fails.                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| **External functions** | `malloc, free`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| **Description**                     | Iterates the list 'lst' and applies the function 'f' to the content of each element. Creates a new list resulting of the successive applications of the function 'f'. The 'del' function is used to delete the content of an element if needed. |
