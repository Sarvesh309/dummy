#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
   int cli_tc;
   cli_tc=socket(AF_INET,SOCK_STREAM,0);
   
   struct sockaddr_in s;
   s.sin_family=AF_INET;
   s.sin_port=htons(4001);
   s.sin_addr.s_addr=INADDR_ANY;
   
   int cs=connect(cli_tc,(struct sockaddr *)&s,sizeof(s));
   
   if(cs==-1)
   {
       printf("Error in Connection ");
   }
   else
   {
      printf("Success in connection ");
   }
   
   int a,b,result;
   char op;
   while(1)
   {
      printf("Enter the 1st operand ");
      scanf("%d",&a);
      send(cli_tc,&a,sizeof(a),0);
      
      printf("Enter the 2nd operand ");
      scanf("%d",&b);
      send(cli_tc,&b,sizeof(b),0);
      
      printf("Enter the operator ");
      scanf("%s",&op);
      send(cli_tc,&op,sizeof(op),0);
      
      recv(cli_tc,&result,sizeof(result),0);
      printf("the result is %d ",result);
   }
   
   //close();
   return 0;
}
      
