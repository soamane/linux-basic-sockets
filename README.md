# Basic implementation of TCP/IP connection (Linux + Windows)
This example was developed as an illustrative implementation of client-server architecture. The client is designed for the Windows x64 operating system, while the server is developed for the Linux operating system.
This project implements communication methods which will be discussed below.

![LZvewHk95Gk](https://github.com/soamane/linux-basic-sockets/assets/143885288/17935094-4b84-40d9-87ad-c18d3a1a1e9f)


# Installing
To clone the repository, you can simply use the universal git cloning method:
```
git clone https://github.com/soamane/linux-basic-sockets.git
```

# Includes
The optional library ```termcolor.h``` is used to visually enhance data output in the Linux terminal.
![preview](preview.jpg)
# Usage
+ **Change the address and port of the endpoint (remote server) in each main.cpp file of the projects.**
  ### Client (main.cpp)
  ```C++
  Client client;
	client.JoinToServer("193.124.114.141", 1337);
  ```
  ### Server (main.cpp)
  ```C++
  Server server;
	server.Start("193.124.114.141", 1337);
  ```
+ **Build the project using any of the available methods**
  - For instance, the server was built using the built-in Linux application development system in Visual Studio 2022.

# Technical information
+ The server code is built on the principle of creating a separate thread for each newly successfully connected client socket. While this isn't considered good practice in reality, it's suitable for small servers with low traffic. This allows the server to handle each connection asynchronously.
+ The repository implements only the most basic functions for communication over the TCP protocol.
A direct approach to reading from and writing to sockets is used. The methods ensure complete packet data transmission from the remote host through cyclic reading and writing. For more details, see the implementation in the ```packethandler.cpp``` file.
