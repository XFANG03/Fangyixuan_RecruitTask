#include<bits/stdc++.h>
using namespace std;

struct Robot
{
	string name;
	int blood =200;
	int hurt = 10;
	int bomb = 40;
	
};


void allocate(struct Robot RArray[])
{
	string nameseed = "AB";
	for (int i = 0; i < 2; i++)
	{
		RArray[i].name = "Robot_";
		RArray[i].name += nameseed[i];

	}

}

void printTest(struct Robot RArray[])
{

	for (int i = 0; i < 2; i++)
	{
		cout <<"小机器人的名字是"<<  RArray[i].name << endl;

	}
}


int main5()
{
	struct Robot RArray[2];

	allocate(RArray);
	printTest(RArray);
	

	srand((unsigned int)time(NULL));
	int i = 0;
	int j = 1;
	while(RArray[0].blood>0&&RArray[1].blood>0)
	{
		int random = rand();

			if (random % 3 == 0)
			{
				RArray[i].blood = RArray[i].blood - RArray[i].hurt;
				int temp = i;
				i = j;
				 j = temp;
				
			}
			else if (random % 2 == 0)
			{
				RArray[i].blood = RArray[i].blood;
				int temp = i;
				i = j;
				 j = temp;
			}
			else
			{
				RArray[i].blood = RArray[i].blood - RArray[i].bomb;
			}
         
		
	}
	
	string a = "小机器人A获胜啦！";
	string b = "小机器人B获胜啦!";

	cout << "小机器人A的血量是" << RArray[0].blood << "小机器人B的血量是" << RArray[1].blood << endl;

	cout<<(RArray[0].blood > RArray[1].blood ? a : b)<<endl;


	return 0;
}