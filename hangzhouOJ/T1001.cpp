/*         
* Copyright (c) 2012, ��̨��ѧ�����ѧԺ         
* All rights reserved.         
* �ļ����ƣ�test.cpp         
* ���ߣ����׿�      
* ������ڣ�2012 �� 11�� 11 ��         
* �汾�ţ�v1.0              
* ������������         
* �����������༭����������10000���ڵĿ�����������  
* �����������
* �����������         
* �㷨��ƣ���         
*/ 
#include <cmath>        
#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g;  
	cout<<"10000���ڵ����п��������У�"<<endl;
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