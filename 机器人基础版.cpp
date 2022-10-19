#include<bits/stdc++.h>
using namespace std;

struct Robot//建一个机器人结构体
{
	string name;
	int blood =200;
	int hurt = 10;
	int bomb = 40;
	
};


void allocate(struct Robot RArray[])//命名它们
{
	string nameseed = "AB";
	for (int i = 0; i < 2; i++)
	{
		RArray[i].name = "Robot_";
		RArray[i].name += nameseed[i];

	}

}

void printTest(struct Robot RArray[])//测试,确认进程,可删
{

	for (int i = 0; i < 2; i++)
	{
		cout <<"小机器人的名字是"<<  RArray[i].name << endl;

	}
}


int main5()
{
	struct Robot RArray[2];

	allocate(RArray);//创建小机器人
	printTest(RArray);//测试
	

	srand((unsigned int)time(NULL));//生成随机数
	int i = 0;
	int j = 1;
	while(RArray[0].blood>0&&RArray[1].blood>0)
	{
		int random = rand();

			if (random % 3 == 0)//打出子弹
			{
				RArray[i].blood = RArray[i].blood - RArray[i].hurt;
				int temp = i;
				i = j;
				 j = temp;
				
			}
			else if (random % 2 == 0)//没打出子弹
			{
				RArray[i].blood = RArray[i].blood;
				int temp = i;
				i = j;
				 j = temp;
			}
			else//炸膛
			{
				RArray[i].blood = RArray[i].blood - RArray[i].bomb;
			}
         
		
	}
	
	string a = "小机器人A获胜啦！";
	string b = "小机器人B获胜啦!";

	cout << "小机器人A的血量是" << RArray[0].blood << "小机器人B的血量是" << RArray[1].blood << endl;//测试,可删

	cout<<(RArray[0].blood > RArray[1].blood ? a : b)<<endl;//最终结果


	return 0;
}