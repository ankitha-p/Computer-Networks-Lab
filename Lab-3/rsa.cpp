#include<iostream>
#include<math.h>
using namespace std;

int getGcd ( int a, int h)
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

string compute(string msg,int key,int n)
{
    string str="";
    for(int i=0;i<msg.length();i++)
    {
        int count=0, val=1,c=int(msg[i]-'0');
        cout<<c;
        while(count++<key)	val=(val*c)%n;
        str=str+ char(val%n+'0');
    }
    return str;
}

int main()
{
	int  p,q;
	cout<<"Enter two prime numbers: ";		//2 random prime numbers
	cin>>p>>q;

	int  n=p*q;
	int  phi = (p-1)*(q-1);

	int  e=2, gcd;

	while(e<phi)   					//pick an e (1<e<phi) such that gcd(e,phi)=1
	{
		gcd = getGcd(e,phi);
		if(gcd==1)	break;
		else		e++;
	}

	int  d=1, s;

	while(1)
	{
		int s = (d*e) % phi;
		if(s==1)	 break;
		else d++;
	}

	string  msg;
	cout<<"\nEnter the number message:";
	cin>>msg;

	string c=compute(msg,e,n);
	string m=compute(c,d,n);

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
