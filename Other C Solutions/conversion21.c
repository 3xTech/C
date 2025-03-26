#include <stdio.h>

double meter_to_feet(double);
double gram_to_pounds(double);
double f_to_Celcius(double);

int main(void){
    int n;
    char l;
    int i;
    double c;
    double cnv;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%lf %c", &c, &l);
        if(l == 'm'){
            cnv = meter_to_feet(c);
            printf("%.6lf ft\n", cnv);
        }else if(l == 'g'){
            cnv = gram_to_pounds(c);
            printf("%.6lf lbs\n", cnv);
        }else if(l == 'c'){
            cnv = f_to_Celcius(c);
            printf("%.6lf f\n", cnv);
        }
    }
    return 0;
}

double meter_to_feet(double m){
    double result = m * 3.2808;
    return result;
}
double gram_to_pounds(double g){
    double result = g * 0.002205;
    return result;
}
double f_to_Celcius(double c){
    double result = 32 + (1.8 * c);
    return result;
}