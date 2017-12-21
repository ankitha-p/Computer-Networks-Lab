#include<iostream>
using namespace std;

string getBig(string s){
	string output="0000";
	int len=s.length();
	int j=3;
	for(int i=len-1;i>=0;i--) output[j--]=s[i];
	return output;
}
string getLittle(string s){
	string output="0000";
	int j=2;
	for(int i=0;i<2;i++) output[i]=s[j++];
	j=0;
	for(int i=2;i<4;i++) output[i]=s[j++];
	return output;
}

int getDecimal(string s){
	int output=0;
	int base=1;
	for(int i=3;i>=0;i--){
		int temp=0;
		if(s[i]>=65 && s[i]<=70) temp=10+s[i]-'A';
		else temp=s[i]-'0';
		output=output+base*temp;
		base*=16;
	}
	return output;
}

int main(){
	char ch[2];
	string input;
	cout<<"Enter the input:\t";
	cin>>ch[1]>>ch[0]>>input;
	string big=getBig(input);
	cout<<"BIG-ENDIAN\nHexa decimal format is 0x"<<big<<endl;
	cout<<"Decimal format is "<<getDecimal(big)<<endl;
	string little=getLittle(big);
	cout<<"LITTLE-ENDIAN\nHexa decimal format is 0x"<<little<<endl;
	cout<<"Decimal format is "<<getDecimal(little)<<endl;
	return 0;
}
