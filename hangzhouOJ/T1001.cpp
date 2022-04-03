/*         
* Copyright (c) 2012, 烟台大学计算机学院         
* All rights reserved.         
* 文件名称：test.cpp         
* 作者：黄兆宽      
* 完成日期：2012 年 11月 11 日         
* 版本号：v1.0              
* 输入描述：无         
* 问题描述：编辑程序，输出解决10000以内的可逆素数问题  
* 程序输出：略
* 问题分析：略         
* 算法设计：略         
*/ 
#include <cmath>        
#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g;  
	cout<<"10000以内的所有可逆素数有："<<endl;
	for(a=2;a<10000;a++){
	    for(e=2;e<=a/2;e++){
				if(a%e==0){
					break;
				}if(a%e!=0&&e==a/2){
					f=a;
					b=f;
		d=0;
		while(b>0){
			c=b%10;
			d=d*10+c;
			b=b/10;
		}
			for(g=2;g<=d/2;g++){
				if(d%g==0){
					break;
				}if(d%g!=0&&g==d/2){
					cout<<f<<'\t';
					break;
				}
			}
				}
			}
		}
	cout<<endl;
    system("pause");
	return 0;
}