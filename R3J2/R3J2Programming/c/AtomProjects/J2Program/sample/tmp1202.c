#include<stdio.h>
int space_find(char s[]){
int k=0;
while(s[k]!=0){
	if (s[k]==' ') return k;
	k++;
}
return -1;
}
void shift(char s[],int k){
int i,length;
	for(i=0;s[i]!=0;i++)
		length=i+1;
	for(i=k;i<length;i++)
		s[i]=s[i+1];
}
			
void space_delete(char s[]){
int k=space_find(s);
while(k!=-1) {
	shift(s,k);
	k=space_find(s);
	}
}
	

int main(){
char s[]="This is a pen";
 space_delete(s);
// shift(s,4);
printf("%s",s);
return 0;
}
