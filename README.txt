README

Group 5: Saad Ahmed & Shahriyar Chowdhury

How to Compile:
1. Create a directory for the programs.
2. When creating a directory, make sure it has the following files:
	Client.c
	Server.c
	Makefile
3. Go to the directory in linux, type in "make" command.
4. It should output: 
	javac Server.c
	javac Client.c
5. Now you can run the programs.

How to run:
1. Open a second terminal window.
2. In the first terminal window, type in the command, "java Server"
3. It should the send message: "Waiting for a connection"
4. In the second terminal window, type in the next command: "java Client 127.0.0.1"
5. Instructions will print on the client window.

Commands: 
1. MSSGET

2.Shutdown
It will allow the user to shutdown the command.
Ex) Client: shutdown
    Output: "200 Ok"

3.Login
It will allow the user to log in to the server.
Ex) client: loggin john john01
    output: "200 Ok"

4. Logout
It will allow the user to logout of the server.
Ex) client: logout
    output: "200 OK"

5.Quit 
It will terminate the server
Ex) client: quit
    output: "200 Ok"

6.MSGSTORE
It will allow the user to upload one message to the server.
Ex) client: msgstore
    output: "200 Ok"




