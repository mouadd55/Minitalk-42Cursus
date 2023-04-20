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
