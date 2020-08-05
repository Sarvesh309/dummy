#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
   int a,b,result;
   char op;
   int cli_tc;
   cli_tc=socket(AF_INET,SOCK_STREAM,0);
   
   struct sockaddr_in s;
   s.sin_family=AF_INET;
   s.sin_port=htons(4001);
   s.sin_addr.s_addr=INADDR_ANY;
   
   bind(cli_tc,(struct sockaddr *)&s,sizeof(s));
   
   listen(cli_tc,5);
   
   int ser_accept=accept(cli_tc,NULL,NULL);
   
   while(1)
   {
   
       recv(ser_accept,&a,sizeof(a),0);
       recv(ser_accept,&b,sizeof(b),0);
       recv(ser_accept,&op,sizeof(op),0);
       
       switch(op)
      {
          case '+':
              result=a+b;
              printf("\n The result is %d",result);
              break;
              
          case '-':
              result=a-b;
              printf("\n The result is %d",result);
              break;
              
          case '*':
              result=a*b;
              printf("\n The result is %d",result);
              break;
              
           case '/':
              result=a/b;
              printf("\n The result is %d",result);
              break;
        }
        
        send(ser_accept,&result,sizeof(result),0);
        return 0;    
   }                
   
  } 
