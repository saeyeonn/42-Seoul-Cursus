<div align=center >
<h1>ft_printf</h1>
<img src="https://github.com/saeyeonn/42_cursus/blob/main/srcs/ft_printfm.png?raw=true">
</div>

<br/>


##### Because putnbr and putstr aren’t enough


##### _Summary: This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future projects without the fear of being flagged as a cheater._


##### _You will mainly learn how to use variadic arguments._

<br>

# Contents

| Chapter | Contents                              | page |
| :-----: | :------------------------------------ | :--: |
|    1    | [**Introduction**](#Chapter-1)        |  2   |
|    2    | [**Common Instructions**](#Chapter-2) |  3   |
|    3    | [**Mandatory part**](#Chapter-3)      |  4   |
|    4    | [**Bonus part**](#Chapter-4)          |  5   |

<br>

# **Chapter 1**

## Introduction

<br>

##### The versatility of the printf function in C represents a great exercise in programming for us. This project is of moderate difficulty. It will enable you to discover variadic functions in C.


##### The key to a successful ft_printf is a well-structured and good extensible code.


<br>

# **Chapter 2**

## Common Instructions

<br>

- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside._


- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._


- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._


- ##### _If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink._

 

- ##### _Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re._


- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h}. Mandatory and bonus part evaluation is done separately._


- ##### _If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project._

  
- ##### _We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._


- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._


<br>

# **Chapter 3**

## Mandatory part

<br>

| **Program name**            | libftprintf.a                                                                                  |
| --------------------------- |----------------------------------------------------------------------------------------------- |
| **Turn in files**           | \*.c, \*/\*.c, \*.h, \*/\*.h, Makefile                                                         |
| **Makefile**                | all, clean, fclean, re, bonus                                                                  |
| **External <br>functions**  | malloc, free, write, va_start, va_arg, va_copy, va_end                                         |
| **Libft authorized**        | Yes                                                                                            |
| **Description**             | Write a library that contains ft_printf(),<br>a function that will mimic the original printf() |

<br>

- ##### _The prototype of ft_printf should be `int ft_printf(const char *, ...);`_


- ##### _You have to recode the `libc`’s `printf` function_


- ##### _It must not do the buffer management like the real printf_


- ##### _It will manage the following conversions: cspdiuxX%_


- ##### _It will be compared with the real printf_


- ##### _You must use the command `ar` to create your librairy, using the command `libtool` is forbidden._

<br>

##### _A small description of the required conversion:_


- ##### _%c print a single character._


- ##### _%s print a string of characters._

- ##### _%p The void \* pointer argument is printed in hexadecimal._


- ##### _%d print a decimal (base 10) number._


- ##### _%i print an integer in base 10._


- ##### _%u print an unsigned decimal (base 10) number._


- ##### _%x print a number in hexadecimal (base 16), with lowercase._


- ##### _%X print a number in hexadecimal (base 16), with uppercase._


- ##### _%% print a percent sign._


> 💡 <br>
>
> ##### _for more complete references : `man 3 printf / man 3 stdarg`_
><br>

<br>

# Chapter 4

## Bonus part

<br>

- ##### _If the Mandatory part is not perfect don’t even think about bonuses_


- ##### _You don’t need to do all the bonuses_


- ##### _Manage any combination of the following flags: `'-0.'` and minimum field width with all conversions_


- ##### _Manage all the following flags: `'# +'` (yes, one of them is a space)_

> 💡<br>
>
> ##### _If you plan to do bonuses you should think about how to do them from the beginning to avoid a naive approach._
><br>
