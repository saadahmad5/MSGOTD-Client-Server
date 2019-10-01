/*
 * server.c
 */

#include <stdio.h>
#include <iostream>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <netdb.h>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

#define SERVER_PORT 3399
#define MAX_PENDING 5
#define MAX_LINE 256

int main(int argc, char **argv) {

    struct sockaddr_in sin;
    socklen_t addrlen;
    char buf[MAX_LINE];
    int len;
    int s;
    int new_s;
	int i = 0;
	int itotal = 2;
	string messages[20];
	messages[0] = "Anyone who has never made a mistake has never tried anything new\0";
	messages[1] = "If your dreams do not scare you, they are not big enough\0";
	string quit = "quit";
	string msgget = "msgget";
	bool islogin = false;
	string login = "login";
	//
	string loginAcc1 = "login root root01";
	string loginAcc2 = "login john john01";
	string loginAcc3 = "login david david01";
	string loginAcc4 = "login mary mary01";
	
	//
	string temp;
	ifstream ifile;
	
	ifile.open("messages.txt");
	int j = 2;
	if(ifile.is_open())
	{
		getline(ifile, messages[j]);
		messages[j] += '\n';
		messages[j] += '\0';
		while(ifile)
		{	
			//cout << j << " " << messages[j] << endl;
			++j;
			++itotal;
			getline(ifile, messages[j]);
			messages[j] += '\n';
			messages[j] += '\0';
		}
		//cout << itotal;
	}
    /* build address data structure */
    bzero((char *)&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons (SERVER_PORT);

    /* setup passive open */
    if (( s = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(1);
    }

    if ((bind(s, (struct sockaddr *) &sin, sizeof(sin))) < 0) {
		perror("bind");
		exit(1);
    }

    listen (s, MAX_PENDING);

    addrlen = sizeof(sin);
	
	
	
	cout << "Welcome to YAMOTD Project-1 CIS 427 Server Side" << endl;
	
    cout << "The server is up, waiting for connection" << endl;

    /* wait for connection, then receive and print text */
    while (1) {
		if ((new_s = accept(s, (struct sockaddr *)&sin, &addrlen)) < 0) {
			perror("accept");
			exit(1);
		}
		cout << "new connection from " << inet_ntoa(sin.sin_addr) << endl;
	
		while (len = recv(new_s, buf, sizeof(buf), 0)) {
			cout << buf;
			
			if(strcmp(buf, quit.c_str()) == 10)
			{
				temp = "Reply 4m server: 200 OK-Quit\n";
				strcpy(buf, temp.c_str());
				send (new_s, buf, strlen(buf) + 1, 0);
				break;
			}
			if(strcmp(buf, msgget.c_str()) == 10)
			{
				temp = "Reply 4m server: 200 OK\n\t\t ";
				temp += messages[i%itotal];
				temp += "\n";
				strcpy(buf, temp.c_str());
				i++;
			}
			//cout << "*" << strcmp(buf, login.c_str()) << endl;
			//Login Method
			if (strcmp(buf, loginAcc1.c_str()) == 10 ||
				strcmp(buf, loginAcc2.c_str()) == 10 ||
				strcmp(buf, loginAcc3.c_str()) == 10 ||
				strcmp(buf, loginAcc4.c_str()) == 10 )
			{
				temp = "Reply 4m server: 200 OK\n";
				islogin = true;
				strcpy(buf, temp.c_str());
			}
			else if(strcmp(buf, login.c_str()) == 32)
			{
				temp = "Reply 4m server: 410 Wrong UserID or Password\n";
				strcpy(buf, temp.c_str());
			}
		
			send (new_s, buf, strlen(buf) + 1, 0);
		}

		close(new_s);
    }
	
	cout << "End of Project-1 Server side" << endl;
} 
 
