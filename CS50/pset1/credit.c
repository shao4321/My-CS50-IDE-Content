#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int sumMultiplied, sumNonMultiplied, sum, count=0;
    long num,num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12,num13,num14,num15,num16;
    int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16; //a1 = last digit
    int b1_1,b1_2, b2_1,b2_2, b3_1,b3_2, b4_1,b4_2, b5_1,b5_2, b6_1,b6_2, b7_1,b7_2, b8_1,b8_2, b9_1,b9_2, b10_1,b10_2, b11_1,b11_2, b12_1,b12_2, b13_1,b13_2, b14_1,b14_2, b15_1,b15_2, b16_1,b16_2;
    int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16;
    
    while(count < 13)
    {
        cont: count=0;
        num = get_long("Number: ");
        num1 = num;
        
        do
        {
            count++;
            num /= 10;
        } while(num != 0);
        
        if(count == 15)
        {
        a1 = num1 % 10;  // AMEX (15digits)
        num2 = (num1 - a1) / 10;
        a2 = num2 % 10;
        num3 = (num2 - a2) / 10;
        a3 = num3 % 10;
        num4 = (num3 - a3) / 10;
        a4 = num4 % 10;
        num5 = (num4 - a4) / 10;
        a5 = num5 % 10;
        num6 = (num5 - a5) / 10;
        a6 = num6 % 10;
        num7 = (num6 - a6) / 10;
        a7 = num7 % 10;
        num8 = (num7 - a7) / 10;
        a8 = num8 % 10;
        num9 = (num8 - a8) / 10;
        a9 = num9 % 10;
        num10 = (num9 - a9) / 10;
        a10 = num10 % 10;
        num11 = (num10 - a10) / 10;
        a11 = num11 % 10;
        num12 = (num11 - a11) / 10;
        a12 = num12 % 10;
        num13 = (num12 - a12) / 10;
        a13 = num13 % 10;
        num14 = (num13 - a13) / 10;
        a14 = num14 % 10;
        num15 = (num14 - a14) / 10;
        a15 = num15 % 10;

        c15 = a15*2;
        c13 = a13*2;
        c11 = a11*2;
        c9 = a9*2;
        c7 = a7*2;
        c5 = a5*2;
        c3 = a3*2;
        c1 = a1*2;

        sumMultiplied = c15 + c13 + c11 + c9 + c7 + c5 + c3 + c1;

        if(c15/10 != 0)
        {
            b15_2 = c15 % 10; //last digit of a(n)
            b15_1 = (c15 - b15_2) / 10;

            sumMultiplied = (b15_1 + b15_2) + c13 + c11 + c9 + c7 + c5 + c3 + c1;
        }
        if(c13/10 != 0)
        {
            b13_2 = c13 % 10; //last digit of a(n)
            b13_1 = (c13 - b13_2) / 10;

            sumMultiplied = c15 + (b13_1 + b13_2) + c11 + c9 + c7 + c5 + c3 + c1;
        }
        if(c11/10 != 0)
        {
            b11_2 = c11 % 10; //last digit of a(n)
            b11_1 = (c11 - b11_2) / 10;

            sumMultiplied = c15 + c13 + (b11_1 + b11_2) + c9 + c7 + c5 + c3 + c1;
        }
        if(c9/10 != 0)
        {
            b9_2 = c9 % 10; //last digit of a(n)
            b9_1 = (c9 - b9_2) / 10;

            sumMultiplied = c15 + c13 + c11 + (b9_1 + b9_2) + c7 + c5 + c3 + c1;
        }
        if(c7/10 != 0)
        {
            b7_2 = c7 % 10; //last digit of a(n)
            b7_1 = (c7 - b7_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + (b7_1 + b7_2) + c5 + c3 + c1;
        }
        if(c5/10 != 0)
        {
            b5_2 = c5 % 10; //last digit of a(n)
            b5_1 = (c5 - b5_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + c7 + (b5_1 + b5_2) + c3 + c1;
        }
        if(c3/10 != 0)
        {
            b3_2 = c3 % 10; //last digit of a(n)
            b3_1 = (c3 - b3_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + c7 + c5 + (b3_1 + b3_2) + c1;
        }
        if(c1/10 != 0)
        {
            b1_2 = c1 % 10; //last digit of a(n)
            b1_1 = (c1 - b1_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + c7 + c5 + c3 + (b1_1 + b1_2);
        }
        
        sumNonMultiplied = a14 + a12 + a10 + a8 + a6 + a4 + a2;
        sum = sumMultiplied + sumNonMultiplied;

        if(sum % 10 == 0)
        {
            if(a15 == 3)
            {
                if(a14 == 4 || a14 == 7)
                {
                    printf("AMEX\n");              
                }
                else goto rej;
            }
            else goto rej;
        }
        else 
        {   
            printf("Invalid Number.\n");
            goto cont;
        }
            
        }
        
        else if(count == 16)
        {
        a1 = num1 % 10;  // MC/Visa (16digits)
        num2 = (num1 - a1) / 10;
        a2 = num2 % 10;
        num3 = (num2 - a2) / 10;
        a3 = num3 % 10;
        num4 = (num3 - a3) / 10;
        a4 = num4 % 10;
        num5 = (num4 - a4) / 10;
        a5 = num5 % 10;
        num6 = (num5 - a5) / 10;
        a6 = num6 % 10;
        num7 = (num6 - a6) / 10;
        a7 = num7 % 10;
        num8 = (num7 - a7) / 10;
        a8 = num8 % 10;
        num9 = (num8 - a8) / 10;
        a9 = num9 % 10;
        num10 = (num9 - a9) / 10;
        a10 = num10 % 10;
        num11 = (num10 - a10) / 10;
        a11 = num11 % 10;
        num12 = (num11 - a11) / 10;
        a12 = num12 % 10;
        num13 = (num12 - a12) / 10;
        a13 = num13 % 10;
        num14 = (num13 - a13) / 10;
        a14 = num14 % 10;
        num15 = (num14 - a14) / 10;
        a15 = num15 % 10;
        num16 = (num15 - a15) / 10;
        a16 = num16 % 10;

        c16 = a16*2;
        c14 = a14*2;
        c12 = a12*2;
        c10 = a10*2;
        c8 = a8*2;
        c6 = a6*2;
        c4 = a4*2;
        c2 = a2*2;

        sumMultiplied = c16 + c14 + c12 + c10 + c8 + c6 + c4 + c2;

        if(c16/10 != 0)
        {
            b16_2 = c16 % 10; //last digit of a(n)
            b16_1 = (c16 - b16_2) / 10;

            sumMultiplied = (b16_1 + b16_2) + c14 + c12 + c10 + c8 + c6 + c4 + c2;
        }
        if(c14/10 != 0)
        {
            b14_2 = c14 % 10; //last digit of a(n)
            b14_1 = (c14 - b14_2) / 10;

            sumMultiplied = c16 + (b14_1 + b14_2) + c12 + c10 + c8 + c6 + c4 + c2;
        }
        if(c12/10 != 0)
        {
            b12_2 = c12 % 10; //last digit of a(n)
            b12_1 = (c12 - b12_2) / 10;

            sumMultiplied = c16 + c14 + (b12_1 + b12_2) + c10 + c8 + c6 + c4 + c2;
        }
        if(c10/10 != 0)
        {
            b10_2 = c10 % 10; //last digit of a(n)
            b10_1 = (c10 - b10_2) / 10;

            sumMultiplied = c16 + c14 + c12 + (b10_1 + b10_2) + c8 + c6 + c4 + c2;
        }
        if(c8/10 != 0)
        {
            b8_2 = c8 % 10; //last digit of a(n)
            b8_1 = (c8 - b8_2) / 10;

            sumMultiplied = c16 + c14 + c12 + c10 + (b8_1 + b8_2) + c6 + c4 + c2;
        }
        if(c6/10 != 0)
        {
            b6_2 = c6 % 10; //last digit of a(n)
            b6_1 = (c6 - b6_2) / 10;

            sumMultiplied = c16 + c14 + c12 + c10 + c8 + (b6_1 + b6_2) + c4 + c2;
        }
        if(c4/10 != 0)
        {
            b4_2 = c4 % 10; //last digit of a(n)
            b4_1 = (c4 - b4_2) / 10;

            sumMultiplied = c16 + c14 + c12 + c10 + c8 + c6 + (b4_1 + b4_2) + c2;
        }
        if(c2/10 != 0)
        {
            b2_2 = c2 % 10; //last digit of a(n)
            b2_1 = (c2 - b2_2) / 10;

            sumMultiplied = c16 + c14 + c12 + c10 + c8 + c6 + c4 + (b2_1 + b2_2);
        }
        
        sumNonMultiplied = a15 + a13 + a11 + a9 + a7 + a5 + a3 + a1;
        sum = sumMultiplied + sumNonMultiplied;

        if(sum % 10 == 0)
        {
            if(a16 == 5)
            {
                if(a15 == 1 || a15 == 5)
                {
                    printf("MasterCard\n");                   
                }
                else goto rej;
            }

            if(a16 == 4)
            {
                printf("Visa\n");
            }
            else goto rej;
        }
        
        else 
        {   
            printf("Invalid Number.\n");
            goto cont;
        }
            
        }

        else if(count == 13)
        {
        a1 = num1 % 10;  // Visa (13digits)
        num2 = (num1 - a1) / 10;
        a2 = num2 % 10;
        num3 = (num2 - a2) / 10;
        a3 = num3 % 10;
        num4 = (num3 - a3) / 10;
        a4 = num4 % 10;
        num5 = (num4 - a4) / 10;
        a5 = num5 % 10;
        num6 = (num5 - a5) / 10;
        a6 = num6 % 10;
        num7 = (num6 - a6) / 10;
        a7 = num7 % 10;
        num8 = (num7 - a7) / 10;
        a8 = num8 % 10;
        num9 = (num8 - a8) / 10;
        a9 = num9 % 10;
        num10 = (num9 - a9) / 10;
        a10 = num10 % 10;
        num11 = (num10 - a10) / 10;
        a11 = num11 % 10;
        num12 = (num11 - a11) / 10;
        a12 = num12 % 10;
        num13 = (num12 - a12) / 10;
        a13 = num13 % 10;

        c13 = a13*2;
        c11 = a11*2;
        c9 = a9*2;
        c7 = a7*2;
        c5 = a5*2;
        c3 = a3*2;
        c1 = a1*2;

        sumMultiplied = c13 + c11 + c9 + c7 + c5 + c3 + c1;

        if(c13/10 != 0)
        {
            b13_2 = c13 % 10; //last digit of a(n)
            b13_1 = (c13 - b13_2) / 10;

            sumMultiplied = c15 + (b13_1 + b13_2) + c11 + c9 + c7 + c5 + c3 + c1;
        }
        if(c11/10 != 0)
        {
            b11_2 = c11 % 10; //last digit of a(n)
            b11_1 = (c11 - b11_2) / 10;

            sumMultiplied = c15 + c13 + (b11_1 + b11_2) + c9 + c7 + c5 + c3 + c1;
        }
        if(c9/10 != 0)
        {
            b9_2 = c9 % 10; //last digit of a(n)
            b9_1 = (c9 - b9_2) / 10;

            sumMultiplied = c15 + c13 + c11 + (b9_1 + b9_2) + c7 + c5 + c3 + c1;
        }
        if(c7/10 != 0)
        {
            b7_2 = c7 % 10; //last digit of a(n)
            b7_1 = (c7 - b7_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + (b7_1 + b7_2) + c5 + c3 + c1;
        }
        if(c5/10 != 0)
        {
            b5_2 = c5 % 10; //last digit of a(n)
            b5_1 = (c5 - b5_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + c7 + (b5_1 + b5_2) + c3 + c1;
        }
        if(c3/10 != 0)
        {
            b3_2 = c3 % 10; //last digit of a(n)
            b3_1 = (c3 - b3_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + c7 + c5 + (b3_1 + b3_2) + c1;
        }
        if(c1/10 != 0)
        {
            b1_2 = c1 % 10; //last digit of a(n)
            b1_1 = (c1 - b1_2) / 10;

            sumMultiplied = c15 + c13 + c11 + c9 + c7 + c5 + c3 + (b1_1 + b1_2);
        }
        
        sumNonMultiplied = a12 + a10 + a8 + a6 + a4 + a2;
        sum = sumMultiplied + sumNonMultiplied;

        if(sum % 10 == 0)
        {
            if(a13 == 4)
            {
                printf("Visa\n");
            }
            else goto rej;
        }
        else 
        {   
            printf("Invalid Number.\n");
            goto cont;
        }
            
        }

        else 
        {
            rej: printf("Invalid Number.\n");
            goto cont;
        }
    }
}
