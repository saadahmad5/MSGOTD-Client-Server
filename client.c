/*
 * client.c
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

using namespace std;

#define SERVER_PORT 3399
#define MAX_LINE 256

int main(int argc, char * argv[]) {

    struct sockaddr_in sin;
    char buf[MAX_LINE];
    char rbuf[MAX_LINE];
	string quit = "quit";
	string msgget = "msgget";
	string login = "login";
	string 
	
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
	

	
	/* main loop; get and send lines of text */
    while (true) 
	{
		cout << "Enter a command: ";
		fgets(buf, sizeof(buf), stdin);
		
		for (int i = 0; i < MAX_LINE; i++)
		{
		   buf[i] = tolower(buf[i]);
		}
		
		buf[MAX_LINE -1] = '\0';
		len = strlen(buf) + 1;
		if(strcmp(buf, quit.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
			close(s);
			break;
		}
		if(strcmp(buf, msgget.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
		}
		if (strcmp(buf, login_str()) == 10)
		{
			send(s, buf, len, 0);
			recv(s, rbuf, sizeof(rbuf), 0);
			exit (EXIT_FAILURE);
		}
		
    }

	cout << "End of Project-1 Client side" << endl;
    

    close(s);
} 
 
