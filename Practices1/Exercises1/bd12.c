#include <stdio.h>
#include <string.h>

struct
{
  char empID[10];
  short workHours;
  int salaryPerHr;

} employee;

int main(void)
{
    int i, count;
    float monthlySalary;

    do
    {
    count = 0;
    printf("Input the Employees ID(Max. 10 chars): ");
    scanf("%s", employee.empID);

     for(i = 0; i < strlen(employee.empID); i++)
    {
        if(employee.empID[i] != ' ')
            count++;
    }
    if(count > 10)
    {
        printf("Maximum allowable chars exceeded!\n");
    }
    }
    while(count > 10);

    printf("Input the working hrs: ");
    scanf("%hd", &employee.workHours);

    printf("Salary amount/hr: ");
    scanf("%d", &employee.salaryPerHr);

    monthlySalary = employee.workHours * (int)employee.salaryPerHr;

    printf("Employee's ID = %s\n", employee.empID);
    printf("Salary = U$ %.2f\n", monthlySalary);

}