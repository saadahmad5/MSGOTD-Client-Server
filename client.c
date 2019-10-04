/*
 * client.c
 * Saad Ahmad & Shahriyar Chowdhry
 * Created: Sep 25 2019
 * Updated: Oct 04 2019
 * CIS 427
 */

#include <stdio.h>
#include <iostream>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstdlib>
#include <cstring>
#include <string.h>

using namespace std;

#define SERVER_PORT 3399
#define MAX_LINE 256

int main(int argc, char * argv[]) {


	// Variables
    struct sockaddr_in sin;
    char buf[MAX_LINE];
	char fbuf[MAX_LINE];
    char rbuf[MAX_LINE];
	string quit = "quit";
	string msgget = "msgget";
	string login = "login";
	string logout = "logout";
	string shutdown = "shutdown";
	string msgstore = "msgstore";
    int len;
    int s;

    if (argc < 2) {
		cout << "Usage: client <Server IP Address>" << endl;
		exit(1);
    }

    /* active open */
    if ((s = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
    }

    /* build address data structure */
    bzero((char *)&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr  = inet_addr(argv[1]);
    sin.sin_port = htons (SERVER_PORT);

    if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		perror("connect");
		close(s);
		exit(1);
    }
	
	cout << "Welcome to YAMOTD Project-1 CIS 427 Client Side" << endl;
	

    while (true) 
	{
		// User interaction at client side
 		cout << "Enter a command: ";
		fgets(buf, sizeof(buf), stdin);
		
		// Lowercases all input to unify commands
		for (int i = 0; i < MAX_LINE; i++)
		{
		   buf[i] = tolower(buf[i]);
		}
		
		buf[MAX_LINE -1] = '\0';
		len = strlen(buf) + 1;
		
		// MSGGET
		
		if(strcmp(buf, msgget.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
		}
		
		// QUIT
		
		if(strcmp(buf, quit.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
			close(s);
			break;
		}
		
		// SHUTDOWN
		
		if(strcmp(buf, shutdown.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
			// If server replies this, the client will close too
			string temp = "Reply 4m server: 200 OK\n";
			if(strcmp(rbuf, temp.c_str()) == 0)
			{
				break;
			}
		}
		
		// LOGOUT
		
		if(strcmp(buf, logout.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
		}
		
		// LOGIN user pass
		
		strcpy(fbuf, buf);
		if(strcmp(fbuf,login.c_str()) == 32)
		{
			strncpy(buf,fbuf,6);
			
			if (strcmp(buf, login.c_str()) == 32)
			{
				
				send(s, fbuf, len, 0);
				recv(s, rbuf, sizeof(rbuf), 0);
				cout << rbuf << endl;
			}	
		}
		
		// MSGSTORE message
		
		strcpy(fbuf, buf);
		if(strcmp(fbuf,msgstore.c_str()) == 32)
		{
			strncpy(buf,fbuf,9);
			
			if (strcmp(buf, msgstore.c_str()) == 32)
			{
				send (s, buf, len, 0);
				recv (s, rbuf, sizeof(rbuf), 0);
				cout << rbuf << endl;
			}
		}
		
    }

	cout << "End of Project-1 Client side" << endl;
    

    close(s);
} 
 
