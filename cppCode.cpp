#include<iostream> 

#include<fstream> 

#include<cstring> 

#include<cstdlib> 

#defineSize15 

 

usingnamespacestd; 

 

intarr[Size][Size]; 

 

intgetrandom(intmin,intmax)//returnauniformrandomnumberinrangemintomax 

{ 

returnint(((double)rand()/(RAND_MAX+1))*(max-min+1)+min); 

} 

 

intwin(intsize) 

{ 

intx=0,ff=0; 

for(inti=0;i<size;i++) 

{ 

for(intj=0;j<size;j++) 

{ 

if(arr[i][j]!=0) 

{ 

x=arr[i][j]; 

ff=1; 

for(intk=i;k<i+5;k++) 

{ 

if(k==size) 

{ 

ff=0; 

break; 

} 

if(arr[k][j]!=x) 

{ 

ff=0; 

break; 

} 

} 

if(ff) 

returnx; 

ff=1; 

for(intk=j;k<j+5;k++) 

{ 

if(k==size) 

{ 

ff=0; 

break; 

} 

if(arr[i][k]!=x) 

{ 

ff=0; 

break; 

} 

} 

if(ff) 

returnx; 

ff=1; 

intk,l; 

for(k=i,l=j;k<i+5,l<j+5;k++,l++) 

{ 

if(k==size||l==size) 

{ 

ff=0; 

break; 

} 

if(arr[k][l]!=x) 

{ 

ff=0; 

break; 

} 

} 

if(ff) 

returnx; 

ff=1; 

for(k=i,l=j;k<i+5,l>j-5;k++,l--) 

{ 

if(k==size||l==-1) 

{ 

ff=0; 

break; 

} 

if(arr[k][l]!=x) 

{ 

ff=0; 

break; 

} 

} 

if(ff) 

returnx; 

} 

} 

} 

return0; 

} 

 

intcheck(intsize) 

{ 

for(inti=0;i<size;i++) 

{ 

for(intj=0;j<size;j++) 

if(arr[i][j]==0) 

return0; 

} 

return1; 

} 

 

intmain() 

{ 

srand(NULL); 

inttot1=0,tot2=0,tie=0; 

fstreamff; 

ofstreamff1; 

ff.open("input.txt"); 

ff1.open("gomokuResults.txt"); 

while(!ff.eof()) 

{ 

intsize; 

ff>>size; 

ff1<<"size="<<size<<endl; 

for(inti=0;i<size;i++) 

{ 

memset(arr[i],0,sizeof(arr[i])); 

} 

intai1,ai2; 

intfx=1; 

inty=0; 

while(1) 

{ 

if(check(size)) 

break; 

while(1) 

{ 

ai1=getrandom(0,size-1); 

ai2=getrandom(0,size-1); 

if(arr[ai1][ai2]==0) 

break; 

} 

ff1<<"r"<<ai1<<"c"<<ai2<<"alg"<<fx<<endl; 

if(fx==1) 

arr[ai1][ai2]=1; 

else 

arr[ai1][ai2]=2; 

y=win(size); 

if(y!=0) 

break; 

if(fx==1) 

fx=2; 

else 

fx=1; 

} 

/*for(inti=0;i<size;i++) 

{ 

for(intj=0;j<size;j++) 

ff1<<arr[i][j]<<""; 

ff1<<endl; 

}*/ 

if(y==1) 

ff1<<"wins=alg1"<<endl<<endl,tot1++; 

if(y==2) 

ff1<<"wins=alg2"<<endl<<endl,tot2++; 

if(y==0) 

ff1<<"Noonewins"<<endl<<endl,tie++; 

} 

ff1<<"winsalg1="<<tot1<<endl; 

ff1<<"winsalg2="<<tot2<<endl; 

ff1<<"ties="<<tie<<endl; 

return0; 

} 
