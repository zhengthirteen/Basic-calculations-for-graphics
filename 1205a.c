#include<stdio.h>
#define PI 3.14
struct point {//坐标 
 	int x;
 	int y;
	};  
struct shape {
   int shape_kind;// 圆形或者矩形 
   struct point center;
   union {
    struct {   int height,width;   } rectangle;
    struct {   int radius;   } circle;
   } u;
  }s;
double function_1_1(struct shape p)//求图形面积 
{
	return PI*p.u.circle.radius*p.u.circle.radius;
}
int function_1_2(struct shape p)//求图形面积 
{
	return p.u.rectangle.height*p.u.rectangle.width;
}
void function_2(struct shape *p)//平移图形 
{
	int a,b;
	printf("Move r by x units in the x-axis direction and move r by y units in the y-axis:");
	scanf("%d %d",&a,&b);
	(*p).center.x=(*p).center.x+a;
	(*p).center.y=(*p).center.y+b;
	return;
}
void function_3(struct shape *r)//缩放 
{
	double a;
	printf("Enter the zoom factor:");
	scanf("%lf",&a);
	if((*r).shape_kind==1)
	(*r).u.circle.radius=((*r).u.circle.radius)/a;
	else if((*r).shape_kind==2)
	{
		(*r).u.rectangle.height=((*r).u.rectangle.height)/a;
		(*r).u.rectangle.width=((*r).u.rectangle.width)/a;
	}
}
int main(void)
{
	int a;
	struct shape *stu=&s;
	printf("Enter the shape of the graphic (1 is a circle, 2 is a rectangle):");
	scanf("%d",&s.shape_kind);
	printf("Enter the center point(Separated by comma):");
	scanf("%d,%d",&s.center.x,&s.center.y);
	if(s.shape_kind==1)
	{
		printf("Enter the radius:");
		scanf("%d",&s.u.circle.radius);
	}
	else if(s.shape_kind==2)
	{
		printf("Enter a length and a tall, separated by space:");
		scanf("%d %d",&s.u.rectangle.width,&s.u.rectangle.height);
	}
	printf("Choose function(input 1 to 3,and enter additional content to exit the program):");
	while(1){
		scanf("%d",&a);
	switch(a)
	{
		case 1:
		if(s.shape_kind==2)
		printf("area:%d\n",function_1_2(s));
		else if(s.shape_kind==1)
		printf("area:%.2f\n",function_1_1(s));
		break;
		case 2:
		function_2(stu);
		printf("center:(%d,%d)\n",s.center.x,s.center.y);
		break;
		case 3:
		function_3(stu);
		if(s.shape_kind==2)
		printf("width:%d,height:%d\n",s.u.rectangle.width,s.u.rectangle.height);
		else if(s.shape_kind==1)
		printf("radius:%d\n",s.u.circle.radius);
		break;
		default :
		return 0;
	}
	printf("Choose function again:");
	}
}
