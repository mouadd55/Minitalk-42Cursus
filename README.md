<div align=center >
<h1>Minitalk</h1>
</div>
<p align="center">
    <img src="https://user-images.githubusercontent.com/49005437/233488325-55f233f9-712c-4b24-968a-c8274b6c3f71.png">
</p>
<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/surfi89/get_next_line?color=blue" />
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

---

## 💡 About the project

> _The purpose of this project is to code a small data exchange program using UNIX signals._

For more detailed information, look at the [**subject of this project**](https://github.com/mouadd55/Minitalk-42Cursus/blob/8c42e6045fb3228c0c6fa277785b01b458ff369b/minitalk.pdf).

## Requirements

>You must create a communication program in the form of a client and a server.
>- The server must be started first. After its launch, it has to print its PID.
>- The client takes two parameters: 1) The server PID 2) The string to send.
>- The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
>- The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
>- Your server should be able to receive strings from several clients in a row without needing to restart.
>- The communication between your client and your server has to be done only using UNIX signals.
>- You can only use these two signals: SIGUSR1 and SIGUSR2.

# Implementation

## Allowed functions

### 1 - Libft

The subject states that [libft](https://github.com/mouadd55/Libft-42Cursus) library can be used!
> You can definitely use your libft.
Reading the subject it can be understood some functions included in the `libft` will be required to fulfill the requirements, as shown below:
> The server must be started first. After its launch, it has to print its PID.
> - The client takes two parameters:
>     - The server PID.
>     - The string to send.
- `ft_atoi()`, to convert the PID argument received from command line to integer type for further processing of signal processing
### 2 - Other functions

Below is made a brief analysis of other functions that can be used.

> In order to complete the mandatory part, you are allowed to use the following functions:
> - write
> - [ft_printf](https://github.com/mouadd55/ft_printf-42Cursus) and any equivalent YOU coded 
> - signal


```c
sig_t signal(int sig, sig_t func);
```
```man
This signal() facility is a simplified interface to the more general sigaction(2) facility.
(...)
some signals instead cause the process receiving them to be stopped, or are simply discarded
if the process has not requested otherwise.  
Except for the SIGKILL and SIGSTOP signals, the signal() function allows for a signal to be 
caught, to be ignored, or to generate an interrupt.
These signals are defined in the file <signal.h>:
           Name             Default Action       Description
     1     SIGHUP           terminate process    terminal line hangup
     2     SIGINT           terminate process    interrupt program 
(...)
     30    SIGUSR1          terminate process    User defined signal 1
     31    SIGUSR2          terminate process    User defined signal 2  
The sig argument specifies which signal was received.  
The func procedure allows a user to choose the action upon receipt of a signal.
The handled signal is unblocked when the function returns and the process continues 
from where it left off when the signal occurred.
For some system calls, if a signal is caught while the call is executing and the call is 
prematurely terminated, the call is automatically restarted.  
Any handler installed with signal(3) will have the SA_RESTART flag set, 
meaning that any restartable system call will not return on receipt of a signal.  
The affected system calls include read(2), write(2), sendto(2), recvfrom(2), sendmsg(2), 
and recvmsg(2) on a communications channel or a low speed device and during a ioctl(2) or wait(2).
However, calls that have already committed are not restarted, but instead return a partial success
(for example, a short read count).  
These semantics could be changed with siginterrupt(3).
     
See sigaction(2) for a list of functions that are considered safe for use in signal handlers.
The previous action is returned on a successful call.  
Otherwise, SIG_ERR is returned and the global variable errno is set to indicate the error.
     
macOS 12.4                      June 7, 2004                      macOS 12.4
```

> - sigaction
```c
#define sa_handler      __sigaction_u.__sa_handler
#define sa_sigaction    __sigaction_u.__sa_sigaction
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
```
```man
The system defines a set of signals that may be delivered to a process.
Signal delivery resembles the occurrence of a hardware interrupt: 
the signal is normally blocked from further occurrence, the current process
context is saved, and a new one is built.  
A process may specify a handler to which a signal is delivered, or specify that 
a signal is to be ignored.
A process may also specify that a default action is to be taken by the
system when a signal occurs.  
A signal may also be blocked, in which case its delivery is postponed until it is unblocked.  
The action to be taken on delivery is determined at the time of delivery.  
Normally, signal handlers execute on the current stack of the process.  
This may be changed, on a per-handler basis, so that signals are taken on a special signal stack.
The sigaction() system call assigns an action for a signal specified by sig.  
If act is non-zero, it specifies an action (SIG_DFL, SIG_IGN, or a handler routine) and mask 
to be used when delivering the specified signal.
If oact is non-zero, the previous handling information for the signal is returned to the user.
Options may be specified by setting sa_flags.  The meaning of the various bits is as follows:
           (...)
           SA_NODEFER      If this bit is set, further occurrences of the
                           delivered signal are not masked during the execution
                           of the handler.
           SA_RESETHAND    If this bit is set, the handler is reset back to
                           SIG_DFL at the moment the signal is delivered.
           SA_RESTART      See paragraph below.
           
           SA_SIGINFO      If this bit is set, the handler function is assumed
                           to be pointed to by the sa_sigaction member of struct
                           sigaction and should match the prototype shown above
                           or as below in EXAMPLES.  This bit should not be set
                           when assigning SIG_DFL or SIG_IGN.
                           
If a signal is caught during the system calls listed below, the call may be
forced to terminate with the error EINTR, the call may return with a data
transfer shorter than requested, or the call may be restarted.  
Restart of pending calls is requested by setting the SA_RESTART bit in sa_flags.  
The affected system calls include (...), write(2) and (...) on a communications channel or a
slow device (such as a terminal, but not a regular file) and during a wait(2) or (...).  
However, calls that have already committed are not restarted, but instead return a partial success 
(for example, a short read count).
NOTE
     The sa_mask field specified in act is not allowed to block SIGKILL or
     SIGSTOP.  Any attempt to do so will be silently ignored.
     The following functions are either reentrant or not interruptible by
     signals and are async-signal safe.  Therefore applications may invoke them,
     without restriction, from signal-catching functions:
     Base Interfaces:
     (...), getpid(), (...), kill(), (...), pause(), (...), sigaction(), sigaddset(), (...),
     sigemptyset(), (...), signal(), (...), sleep(), (...), wait(), (...), write().
     Realtime Interfaces:
     aio_error(), sigpause(), aio_return(), aio_suspend(), sem_post(), sigset().
     ANSI C Interfaces:
     strcpy(), strcat(), strncpy(), strncat(), and perhaps some others.
     
     Extension Interfaces:
     strlcpy(), strlcat().
     All functions not in the above lists are considered to be unsafe with
     respect to signals.  That is to say, the behaviour of such functions when
     called from a signal handler is undefined.  In general though, signal
     handlers should do little more than set a flag; most other actions are not
     safe.
     Also, it is good practice to make a copy of the global variable errno and
     restore it before returning from the signal handler.  This protects against
     the side effect of errno being set by functions called from inside the
     signal handler.
```
> - kill
Using `kill()` to check the PID server input

```man
DESCRIPTION
     The kill() function sends the signal specified by sig to pid, a process or
     a group of processes.  Typically, Sig will be one of the signals specified
     in sigaction(2).  A value of 0, however, will cause error checking to be
     performed (with no signal being sent).  This can be used to check the
     validity of pid.
````
  
This is a nice finding to check the validity of the PID in a robust way, rather than just checking if all the chars are digits.
```c
else if (kill(ft_atoi(argv[1]), 0) < 0)
{
	ft_putstr("\x1B[31m❌INVALID PID");
	return (EXIT_FAILURE);
}
```
  
```man
     If pid is greater than zero:
             Sig is sent to the process whose ID is equal to pid.
     If pid is zero:
             Sig is sent to all processes whose group ID is equal to the process
             group ID of the sender, and for which the process has permission;
             this is a variant of killpg(2).
     If pid is -1:
             If the user has super-user privileges, the signal is sent to all
             processes excluding system processes and the process sending the
             signal.  If the user is not the super user, the signal is sent to
             all processes with the same uid as the user, excluding the process
             sending the signal.  No error is returned if any process could be
             signaled.
```         
    

> - getpid
```c
pid_t getpid(void);
```
```man
DESCRIPTION
     getpid() returns the process ID of the calling process.  The ID is
     guaranteed to be unique and is useful for constructing temporary file
     names.
```

> - malloc
> - free
> - pause
```c
int pause(void);
```
```man
DESCRIPTION
     The pause() function causes the calling thread to pause until a signal is
     received from either the kill(2) function or an interval timer.  (See
     setitimer(2).) Upon termination of a signal handler started during a
     pause(), the pause() call will return.
```
> - sleep
> - usleep
```c
int usleep(useconds_t microseconds);
```
```man
DESCRIPTION
     The usleep() function suspends execution of the calling thread until either
     microseconds have elapsed or a signal is delivered to the
     thread and its action is to invoke a signal-catching function or to
     terminate the process.  System activity or limitations may lengthen the
     sleep by an indeterminate amount.
     This function is implemented using nanosleep(2) by pausing for microseconds
     microseconds or until a signal occurs.  Consequently, in this
     implementation, sleeping has no effect on the state of process timers, and
     there is no special handling for SIGALRM.  Also, this implementation does
     not put a limit on the value of microseconds (other than that limited by
     the size of the useconds_t type); some other platforms require it to be
     less than one million.
```

# Installing and running the project:

1- Clone this repository
	
	git clone https://github.com/mouadd55/Minitalk-42Cursus
2- run `make`
	
	cd Minitalk-42Cursus
   	make
3- `make clean` so that you don't keep those object files that you won't need anymore

	make clean
4- To test the program you just need to launch the "server" and the "client" in different shell tabs with the following:

```shell
$ ./server
```

This will show your PID to make the client work and will stay waiting to receive a message from the "client"

```shell
$ ./client "PID" "Your message string"
```

By launching it, this will show "Your message string" on the server window.

### Makefile Available Targets:  
`make` or `make all` - Makes _client_ and _server_  
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes the executables and all the resulting object files  
`make re` - fclean + all  
`make bonus` - same as `all`, added for subject purposes  
