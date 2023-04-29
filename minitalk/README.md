<div align=center >
<h1>minitalk</h1>
<img src="https://github.com/saeyeonn/42_cursus/blob/main/srcs/minitalkn.png?raw=true">
</div>


##### The purpose of this project is to code a small data exchange program using UNIX signals. (Version: 2)



<br>

# Contents

| Chapter | Contents                                         |
| :-----: | :----------------------------------------------- |
|    1    | [**Common Instrunctions**](#Chapter-1)           |
|    2    | [**Project instructions**](#Chapter-2)                     |
|    3    | [**Mandatory Part**](#Chapter-3) |
|    4    | [**Bonus part**](#Chapter-4)                     |


<br>

# **Chapter 1**

## Common Instructions


- ##### Your project must be written in C.

- ##### Your project must be written in accordance with the Norm. If you have bonusfiles/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.

- ##### Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- ##### All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.

- ##### If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.

- ##### Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

- ##### To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file _bonus.{c/h} if the subject does not specify anything else. Mandatory and bonus part evaluation is done separately.

- ##### If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project.

- ##### We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.

- ##### Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

<br>


# **Chapter 2**

## Project instructions

- ##### Name your executable files client and server.

- ##### You have to turn in a Makefile which will compile your source files. It must not relink.

- ##### You can definitely use your libft.

- ##### You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).

- ##### Your program mustn’t have memory leaks.

- ##### You can have one global variable per program (one for the client and one for the server), but you will have to justify their use.

- ##### In order to complete the mandatory part, you are allowed to use the following functions:

> <br>
> ◦ write
> <br>
> ◦ ft_printf and any equivalent YOU coded
> <br>
> ◦ signal
> <br>
> ◦ sigemptyset
> <br>
> ◦ sigaddset
> <br>
> ◦ sigaction
> <br>
> ◦ kill
> <br>
> ◦ getpid
> <br>
> ◦ malloc
> <br>
> ◦ free
> <br>
> ◦ pause
> <br>
> ◦ sleep
> <br>
> ◦ usleep
> <br>
> ◦ exit
> <br>
> <br>

<br>

# Chapter 3

## Mandatory part

<br>

#### You must create a communication program in the form of a client and a server.

- ##### The server must be started first. After its launch, it has to print its PID.

- ##### The client takes two parameters:

> <br>
> ◦ The server PID.
> <br>
> ◦ The string to send.
> <br>
> <br>

<br>

- ##### The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.

- ##### The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.

<br>

><br>
> 💡<br>
>
> ##### 1 second for displaying 100 characters is way too much!
><br>

<br>

- ##### Your server should be able to receive strings from several clients in a row without needing to restart.

- ##### The communication between your client and your server has to be done only using UNIX signals.

- ##### You can only use these two signals: SIGUSR1 and SIGUSR2.

<br>

><br>
> 💡<br>
>
> ##### Linux system does NOT queue signals when you already have pending signals of this type! Bonus time?
><br>



<br>

# Chapter 4

## Bonus part

<br>

#### Bonus list : 

<br>

- ##### The server acknowledges every message received by sending back a signal to the client.

- ##### Unicode characters support!

<br>

><br>
> 💡<br>
>
> ##### The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.
><br>

<br>