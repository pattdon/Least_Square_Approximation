#include<iostream>
#include<math.h>
using namespace std;

int n = 0;
int n1 = 0;
int court = 0;
int court1 = 0;

float* x = NULL;
float* f = NULL;
float XAll = 0;
float FAll = 0;
float X2All = 0;
float F2All = 0;
float XFAll = 0;
float A = 0;
float B = 0;
float ansSend = 0;


float XTimeF(){
	float ans = 0;
	 for(int y = 0;y < n;y++){
	 	ans += f[y]*x[y];
	 }
	 cout<<ans<<endl;
	 return ans;
}

float XSumPower2(){
	float ans = 0;
	 for(int y = 0;y < n;y++){
	 	ans += x[y] * x[y];
	 }
	 cout<<ans<<endl;
	 return ans;
}

float FSumPower2(){
	float ans = 0;
	 for(int y = 0;y < n;y++){
	 	ans += f[y]*f[y];
	 }
	 cout<<ans<<endl;
	 return ans;
}

float XSum(){
	float ans = 0;
	 for(int y = 0;y < n;y++){
	 	ans += x[y];
	 }
	 cout<<ans<<endl;
	 return ans;
}

float FSum(){
	float ans = 0;
	 for(int y = 0;y < n;y++){
	 	ans += f[y];
	 }
	 cout<<ans<<endl;
	 return ans;
}

void  inputValueX(){
	
	while( court < n ){
    	cout<<"x["<<court<<"] :: ";
    	cin>>x[court];
    	court++;
	}
	
}

void inputValueY(){
	
    while( court1 < n ){
    	cout<<"fuction["<<court1<<"] :: ";
    	cin>>f[court1];
    	court1++;
	}	
}

void print(){
	cout<<"num of size :: ";
    cin >> n;        // Read in the size
    x = new float[n];  // Allocate n ints and save ptr in a.
    for (int i=0; i<n; i++) {
       x[i] = 0;    // Initialize all elements to zero. 
    }
    
    inputValueX();
    
    f = new float[n];  // Allocate n ints and save ptr in a.
    for (int i1=0; i1 < n; i1++) {
       f[i1] = 0;    // Initialize all elements to zero. 
    }
    
    inputValueY();
}

float findA(){
	float ans = 0;
	ans = ((n * XFAll)-(XAll * FAll))/((n * X2All)-(XAll * XAll));
	cout<<"a ::"<<ans<<endl;
	return ans;
}

float findB(){
	float ans = 0;
	ans = ((X2All * FAll)-(XAll * XFAll))/((n * X2All)-(XAll * XAll));
	cout<<"b ::"<<ans<<endl;
	return ans;
}
float findValueFunction(float x){
	float ans = 0;
	ans = (A*x) + B;
	cout<<"ans ::"<<ans<<endl;
	return ans;
}

float engineProcess(float x){
	print();
	XAll = XSum();
	FAll = FSum();
	X2All = XSumPower2();
	F2All = FSumPower2();
	XFAll = XTimeF();
	A = findA();
	B = findB();
	ansSend = findValueFunction(x);
}

float findAns(){
	float key = 0;
	cout<<"value X ::";
	cin>>key;
	engineProcess(key);
}
int main(){
	findAns();
}
