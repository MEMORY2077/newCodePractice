#include <stdio.h>
int main(){
	float a,b,c;
	scanf("%f %f %f",&a,&b,&c);
	if (a>b){
		if (a<c){
			printf("%.1f %.1f %.1f",b,a,c);
			return 0;
		}
	    else {
	    	if (c>b){
	    		printf("%.1f %.1f %.1f",b,c,a);
	    		return 0;
			}
			else {
				printf("%.1f %.1f %.1f",c,b,a);
				return 0;
				}
		}
	}
	else {
		if (b<c){
			printf("%.1f %.1f %.1f",a,b,c);
			return 0;
		}
		else {
			if (c>a){
				printf("%.1f %.1f %.1f",a,c,b);
				return 0;
			}
			else {
				printf("%.1f %.1 %.1f",c,a,b);
				return 0;
			}
		}
	}
	
}