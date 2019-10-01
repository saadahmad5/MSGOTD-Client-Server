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
#include <string.h>

using namespace std;

#define SERVER_PORT 3399
#define MAX_LINE 256

int main(int argc, char * argv[]) {

    struct sockaddr_in sin;
    char buf[MAX_LINE];
	char fbuf[MAX_LINE];
    char rbuf[MAX_LINE];
	string quit = "quit";
	string msgget = "msgget";
	string loginAcc1 = "login root root01";
	string loginAcc2 = "login john john01";
	string loginAcc3 = "login david david01";
	string loginAcc4 = "login mary mary01";
	string login = "login";
	
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
		

		//cout << "Here:" << buf << endl;
		
		if(strcmp(buf, msgget.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
			continue;
		}
		if(strcmp(buf, quit.c_str()) == 10)
		{
			send (s, buf, len, 0);
			recv (s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << "here" << endl;
			close(s);
			break;
		}
		strcpy(fbuf, buf);
		strncpy(buf,login.c_str(),6);
		buf[MAX_LINE -1] = '\0';
		if (strcmp(buf, login.c_str()) == 0)
		{
			send(s, fbuf, len, 0);
			recv(s, rbuf, sizeof(rbuf), 0);
			cout << rbuf << endl;
		}
		
    }

	cout << "End of Project-1 Client side" << endl;
    

    close(s);
} 
 
