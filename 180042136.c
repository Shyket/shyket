/*
Assalamu Alaikum.
Name: Md.munimul Islam
Roll: 180042136
RSA encryption and decryption
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>



int main()
{
    int c;
    printf("Select:\n1.Genarate Your Key\n2.Encrypt\n3.Decrypt\n");
    scanf("%d",&c);

    if(c==1){
        keyGenerate();
    }
    else if(c==2){
        encrypt();
    }
    else if(c==3){
        decrypt();
    }
    else{
        printf("Error");
    }

    return 0;

}

/*
    pre condition: user will choose 1.


    post condition: public key(n,e) and private key(n,d) will be generated according to the two prime numbers given by the user.
*/

void keyGenerate()
{

    int primeNumber1,primeNumber2,n,z,e,d; // here z=Q(n)

    printf("Give two prime numbers:\n");
    scanf("%d%d",&primeNumber1,&primeNumber2);

    n=primeNumber1*primeNumber2;
    z=(primeNumber1-1)*(primeNumber2-1);
    e=findE(n,z);
    d=findD(e,z);

    //printf("%d %d %d\n",n,z,e);
    printf("Your public keys are: (%d,%d)\n",n,e);
    printf("Decrypt keys are (%d,%d)",n,d);

}

/*
    pre condition: user have to give a string and his public key (n,e).

    post condition: user will get his encrypted string

*/

void encrypt()
{

    char str[100],encryptedString[100];
    int x,n,e,i,P;

    printf("Give your String\n");
    fflush(stdin);
    gets(str);

    printf("Give public key:(n,e)\n");
    scanf("%d%d",&n,&e);

    for(i=0; i<strlen(str); i++)
    {

        if(str[i]==' ')
        {
            encryptedString[i]=str[i];
        }
        else if(str[i]>=97 && str[i]<=122)
        {
            x=(int)str[i];
            x-=96;
            P=x^e;
            encryptedString[i]=((int)P%n)+96;
        }
        else if(str[i]>=65 && str[i]<=90)
        {
            x=(int)str[i];
            x-=64;
            P=x^e;
            encryptedString[i]=((int)P%n)+64;
        }

    }
    encryptedString[i]='\0';
    puts(encryptedString);
}


/*
   pre condition: user will givve his messege and his secret keys


   post condition: user will get the original messege.

*/

void decrypt()
{


    char str[100],decryptedString[100];
    long int n,d,i,x,P;


    printf("Give your String\n");
    fflush(stdin);
    gets(str);

    printf("Give your keys(n,d):\n");
    scanf("%d %d",&n,&d);


    for(i=0; i<strlen(str); i++)
    {

        if(str[i]==' ')
        {
            decryptedString[i]=str[i];
        }
        else if(str[i]>=65 && str[i]<=90)
        {
            x=(int)str[i];
            x-=64;
            P=x^d;
            decryptedString[i]=(P%n)+64;
        }
        else if(str[i]>=97 && str[i]<=122)
        {
            x=(int)str[i];
            x-=96;
            P=x^d;
            decryptedString[i]=(P%n)+96;
        }

    }
    decryptedString[i]='\0';
    puts(decryptedString);
}

/*
   pre condition: this function will take n and Q(n). n=prime1*prime2; Q(n)=(prime1-1)*(prime2-1)


   post condition:will return e. 1<e<=Q(n) . e is co prime with both n and Q(n)

*/
int findE(int n,int z)
{

    int i;

    for(i=2; i<=z; i++)
    {
        if(gcd(i,n)==1 && gcd(i,z)==1)
        {
            return i;
        }
    }
}

/*
   pre condition: this function will take e and q(n) as argument.

   post condition: will return d. d=inverse of(e mod Q(n)) .d will be that value for which d*e mod Q(n)=1 and for this case d!=e.

*/

int findD(int e,int z)
{

    int x;

    for(x=1;; x++)
    {

        if((e*x)%z==1)
        {
            if(x==e)
            {
                continue;
            }
            else
            {
                return x;
            }
        }
    }
}

/*
   pre condition: get two integer as argument.


   post condition: returns the greatest common divisor.

*/

int gcd(int i,int n)
{
    int x,smallNumber,gcd;

    if(i==n)
    {
        return i;
    }
    else if(i<n)
    {
        smallNumber=i;
    }
    else
    {
        smallNumber=n;
    }


    for(x=1; x<=smallNumber; x++)
    {

        if(i%x==0 && n%x==0)
        {
            gcd=x;
        }

    }
    return gcd;
}
