YAMOTD Client-Server Program
		written by:
Grp# 5: Saad Ahmad & Shahriyar Chowdhury
		submitted to:
Dr. Jinhua Guo
		for the course:
CIS 427

Project - 1

README file

This project is created by Saad Ahmad and Shahriyar Chowdhury, student at
University of Michigan for the CIS 427 - Computer Networks course. This
project has two programs; client and server, which work in coordination of
one another. The server program should be running before the client is executed.
The client program requires an IP address as a commandline argument of the server.

How to Compile:
1. Create a directory for the programs.
2. When creating a directory, make sure it has the following files:
	Client.c
	Server.c
	Makefile
3. Go to the directory in terminal and type in "make" command.
4. It should output: 
	g++ -g -c client.c
	g++  -o client client.o
	g++ -g -c server.c
	g++  -o server server.o

5. Now you can run the programs.

How to run:
1. Open a second terminal window.
2. In the first terminal window, type in the command, "./server"
3. It should the send message: "Waiting for a connection"
4. In the second terminal window, type in the next command: "./client 127.0.0.1"
5. Instructions will print on the client window.

Commands: 
1. msgget
This command from client sends a message to server to return the
message of the day. The server has access to file messages.txt and 
returns each message in that file in chronological order.
Ex) Enter a command: msgget
	Reply 4m server: 200 OK
			 Message of the day

2. shutdown
It will allow the user at client side to shutdown the server.
Additionally, the client and server program stops execution.
ONLY ROOT has access to shutdown the server.
Ex) Enter a command: shutdown
    Reply 4m server: 200 OK

3. login username password
It will allow the user at client side to log in to access the server.
The login command is followed by username and password. If the credentials
are authenticated, the user logins, otherwise, wrong username/ password.
Ex) Enter a command: login john john01
    Reply 4m server: 200 Ok

4. logout
It will allow the logged in user to logout from the server. If the user
is not logged in, it says no users logged in
Ex) Enter a command: logout
    Reply 4m server: 200 OK

5. quit 
It will terminate the client connection from server. The server will still
remain awake and will accept other connections from the client.
Ex) Enter a command: quit
    Reply 4m server: 200 Ok

6. msgstore message
It will allow the user to upload one message to the server. The server will save
the message to the messages.txt file. The limit for messages in 20.
Ex) Enter a command: msgstore message
    Reply 4m server: 200 Ok
