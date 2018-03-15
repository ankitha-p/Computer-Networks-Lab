//Program for RSA asymmetric cryptographic algorithm

#include<iostream>
#include<math.h>

using namespace std;

int getGcd(int a, int h)
{
	int temp;
	while(1)
	{
		temp = a%h;
		if(temp==0)	return h;
		a = h;
		h = temp;
	}
}

int compute(int msg,int key,int n)
{
	int count=0,ans=1;
	while(count++<key)
	{
		ans=(ans*msg)%n;
	}
	return ans%n;
}

int main()
{
	//2 random prime numbers
	int  p,q;
	cout<<"Enter two prime numbers: ";
	cin>>p>>q;

	int  n=p*q;	
	int  phi = (p-1)*(q-1);

	//public key stands for encrypt
	int  e=2;
	int  gcd;
	//pick an e (1<e<phi) such that gcd(e,phi)=1
	while(e<phi)
	{
		gcd = getGcd(e,phi);
		if(gcd==1)	break;
		else		e++;
	}

	//private key d stands for decrypt
	int  d=1,s;

	while(1)
	{
		int s=(d*e)%phi;
		if(s==1) break;
		else d++;
	}
			
	int  msg;
	cout<<"\nEnter the number message:";
	cin>>msg;
	int c=compute(msg,e,n);
	int m=compute(c,d,n);
	cout<<"\nMessage data = "<<msg;
	cout<<"\nP: \t"<<p<<"\tQ:\t"<<q;
	cout<<"\n"<<"n = p*q = "<<n;
	cout<<"\n"<<"Phi(n) = "<<phi;
	cout<<"\n"<<"e = "<<e;
	cout<<"\n"<<"d = "<<d;
	cout<<"\n"<<"Encrypted data = "<<c;
	cout<<"\n"<<"Original Message sent = "<<m<<endl;

	return 0;
}
