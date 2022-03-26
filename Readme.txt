This repository includes some of the problems I have attempted in 
geekforgeeks.
https://auth.geeksforgeeks.org/user/emailtomallesh2013/practice/

UDP directory contains client and server programs to send a file 
from server to client over UDP protocol. server sends number of 
frames required to send.  file to be sent is split into several 
frames by server. Client sends cumulative acknowledgements to server.
Server resends packets when it detects no acknowledgement from client.

usage server:
> ./server [portno]

client:
> ./client [server address] [portno used in server]
ls
get filename
exit
