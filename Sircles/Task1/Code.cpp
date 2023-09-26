#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, r1, x2, y2, r2;
    printf("Input the coordinates of the center of the first circle and its radius: ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Input the coordinates of the center of the second circle and its radius: ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if ((r1 > 0) && (r2 > 0))
    {
        if ((x1 == x2) && (y1 == y2))
        {
            if (r1 == r2)
            {
                printf("The circles coincide");//���������
            }
            else
            {
                printf("One of the circles lies inside the other");//���� ������ �������
            }
        }
        else
        {
            double distance, R, r;
            if (r1 > r2)
            {
                R = r1;
                r = r2;
            }
            else
            {
                R = r2;
                r = r1;//������� ������� � ������� �������
            }
            distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));//���������� ����� ��������
            if (distance == r1 + r2)
            {
                printf("Circles touch at one point outside");//������� �������
            }
            else if (distance > r1 + r2)
            {
                printf("Circles do not intersect");//�� ������������
            }
            else if ((distance < r1 + r2) && (distance > R - r))
            {
                printf("Circles intersect in two points");// ������������ � ���� ������
            }
            else if (distance < R - r)
            {
                printf("One of the circles lies inside the other");//���� ������ �������
            }
            else if (distance == R - r)
            {
                printf("Circles touch at one point inside");//���������� �������
            }

        }
    }
    else
    {
        printf("Incorrect data!"); // �������� �� ������������� ������
    }
    return 0;
}